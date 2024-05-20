#include <iostream>
#include <vector>
#include <ranges>
#include <random>
#include <fstream>

#define DEBUG true

using namespace std;

constexpr int N_SYMBOLS = 32;
const array<char, N_SYMBOLS> symbols{
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
        'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
        'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
        'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F'
};
constexpr int N_CARDS = N_SYMBOLS * 2;

enum Player {
    PLAYER_1 = 0,
    PLAYER_2 = 1
};

typedef struct {
    char symbol;
} Card;

typedef struct game_decl {
    vector<Card> cards;
    int player1Score = 0;
    int player2Score = 0;
    Player currentPlayer = PLAYER_1;
} Game;

constexpr vector<Card> generateCards() {
    vector<Card> cards;
    cards.reserve(N_CARDS);

    for (const auto &symbol: symbols) {
        cards.push_back(Card{symbol});
    }

    for (const auto &symbol: symbols) {
        cards.push_back(Card{symbol});
    }

    return cards;
}

const vector<Card> cardsToInsert = generateCards();

Game initGame() {
    Game game;
    game.cards = cardsToInsert;

    auto rng = default_random_engine{};
    shuffle(game.cards.begin(), game.cards.end(), rng);

    return game;
}

void printCards(const Game &game) {
    for (int i = 0; i < N_CARDS; i++) {
        cout << i << " ";
    }
    cout << endl;

    for (const auto &card: game.cards) {
        cout << card.symbol << "  ";
    }
    cout << endl;
}

void saveGame(const Game &game) {
    ofstream fileStream("memory_game.txt", ios::binary);

    if (!fileStream.is_open()) {
        cout << "Errore durante l'apertura del file\n";
        return;
    }

    // Write cards
    fileStream.write(reinterpret_cast<const char *>(game.cards.data()),
                     game.cards.size() * sizeof(Card)); // NOLINT(*-narrowing-conversions)

    fileStream.close();
}

Game loadGame() {
    Game game;
    ifstream fileStream("memory_game.txt", ios::binary);

    if (!fileStream.is_open()) {
        cout << "Errore durante l'apertura del file\n";
        throw runtime_error("File not found");
    }

    // Read cards
    fileStream.read(reinterpret_cast<char *>(game.cards.data()),
                    game.cards.size() * sizeof(Card)); // NOLINT(*-narrowing-conversions)

    fileStream.close();

    return game;
}

enum MainMenuChoice {
    NEW = 1,
    LOAD = 2,
    EXIT = 0
};

MainMenuChoice getChoice() {
    int choice;
    cout << "1) Nuova partita\n"
            "2) Carica partita\n"
            "0) Esci\n"
            "Scelta: ";
    cin >> choice;
    return static_cast<MainMenuChoice>(choice);
}

enum GameChoice {
    PLAY = 1,
    SAVE = 2,
    EXIT_GAME = 0
};

GameChoice getGameChoice() {
    int choice;
    cout << "1) Gioca\n"
            "2) Salva\n"
            "0) Esci\n"
            "Scelta: ";
    cin >> choice;
    return static_cast<GameChoice>(choice);
}

void printCardsHidden(const Game &game) {
#ifdef DEBUG
    printCards(game);
#endif

    for (const auto &card: game.cards) {
        cout << (card.symbol == '-' ? '-' : '*') << "  ";
    }
    cout << endl;
}


void increasePlayerScore(Game &game, Player player) {
    switch (player) {
        case Player::PLAYER_1:
            game.player1Score++;
            break;
        case Player::PLAYER_2:
            game.player2Score++;
            break;
        default:
            __builtin_unreachable();
    }
}

Card revealCard(Game &game, const string &cardN) {
    int position;
    do {
        cout << "Inserisci la posizione della" << cardN << " carta da scoprire: ";
        cin >> position;

        if (position >= 0 && position < N_CARDS) {
            break;
        }

        cout << "Posizione non valida\n";
    } while (true);

    Card card = game.cards[position];
    cout << "Carta scelta: " << card.symbol << endl;

    return card;
}

bool cmpCard(const Card &first, const Card &second) {
    return first.symbol == second.symbol;
}

void switchPlayer(Game &game) {
    game.currentPlayer = game.currentPlayer == Player::PLAYER_1 ? Player::PLAYER_2 : Player::PLAYER_1;
}

void markCardAsRevealed(Game &game, const Card &card) {
    for (auto &c: game.cards) {
        if (c.symbol == card.symbol) {
            c = Card{'-'};
        }
    }
}

void playerPlay(Game &game) {
    cout << "Turno giocatore " << (game.currentPlayer == Player::PLAYER_1 ? "1" : "2") << endl;

    Card firstCard = revealCard(game, " prima");
    Card secondCard = revealCard(game, " seconda");

    if (cmpCard(firstCard, secondCard)) {
        cout << "Carte uguali\n";
        markCardAsRevealed(game, firstCard);
        markCardAsRevealed(game, secondCard);
        increasePlayerScore(game, game.currentPlayer);
    } else {
        cout << "Carte diverse\n";
        switchPlayer(game);
    }
}

bool isGameOver(const Game &game) {
    return game.player1Score + game.player2Score == N_CARDS / 2;
}

void startGame(Game &game) {
    bool exit = false;

    do {
        printCardsHidden(game);
        GameChoice choice = getGameChoice();

        switch (choice) {
            case PLAY:
                playerPlay(game);
                break;
            case SAVE:
                saveGame(game);
                break;
            case EXIT_GAME:
                exit = true;
                break;
        }

        if (isGameOver(game)) {
            cout << "Partita terminata\n"
                    "Punteggio giocatore 1: " << game.player1Score
                 << "Punteggio giocatore 2: " << game.player2Score << "\n";
            exit = true;
        }
    } while (!exit);
}

int main() {
    Game game{};

    bool exit = false;
    do {
        MainMenuChoice choice = getChoice();

        switch (choice) {
            case NEW:
                game = initGame();
                startGame(game);
                break;
            case LOAD:
                try {
                    game = loadGame();
                } catch (const runtime_error &e) {
                    cout << "Errore durante il caricamento del file\n";
                }
                startGame(game);
                break;
            case EXIT:
                exit = true;
                break;
        }
    } while (!exit);

    return 0;
}