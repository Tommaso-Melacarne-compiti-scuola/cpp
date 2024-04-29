#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <random>
#include <ranges>

using namespace std;

constexpr int PLAYERS = 4;

constexpr int N_CARDS = 52 * 2 + 4;
constexpr int CARDS_PER_PLAYER = 11;
constexpr int JOKER_VALUE = 0;
constexpr int N_RANKS = 13;

constexpr int N_SUITS = 5;
const array<string, N_SUITS> SUITS = {"🃟", "♠", "♥", "♦", "♣"};

enum Suit {
    JOKER = 0,
    SPADES = 1,
    HEARTS = 2,
    DIAMONDS = 3,
    CLUBS = 4
};

typedef struct {
    int value;
    Suit suit;
} Card;

typedef struct {
    vector<Card> cards;
} Player;

using Deck = vector<Card>;

typedef struct {
    Deck deck;
    vector<Player> players;
} Game;

void shuffleDeck(Deck &deck) {
    auto rng = std::default_random_engine{};
    std::shuffle(deck.begin(), deck.end(), rng);
}

Deck initDeck() {
    Deck deck;
    deck.reserve(N_CARDS);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < N_RANKS; j++) {
            for (int suit = 0; suit < N_SUITS; suit++) {
                Card card{
                        .value = j,
                        .suit = static_cast<Suit>(suit)
                };
                deck.push_back(card);
            }
        }
    }


    for (int i = 0; i < 4; i++) {
        Card joker{
                .value = JOKER_VALUE,
                .suit = Suit::JOKER
        };
        deck.push_back(joker);
    }

    shuffleDeck(deck);

    return deck;
}

vector<Player> initPlayers() {
    vector<Player> players;
    players.reserve(PLAYERS);

    for (int i = 0; i < PLAYERS; i++) {
        Player player;
        player.cards.reserve(CARDS_PER_PLAYER);
        players.push_back(player);
    }

    return players;
}

void assignCardsToPlayers(Deck &deck, vector<Player> &players) {
    for (int i = 0; i < PLAYERS; i++) {
        for (int j = 0; j < CARDS_PER_PLAYER; j++) {
            players[i].cards.push_back(deck.back());
            deck.pop_back();
        }
    }

    deck.shrink_to_fit();
}

Game initGame() {
    Game game{
            .deck = initDeck(),
            .players = initPlayers()
    };

    assignCardsToPlayers(game.deck, game.players);

    return game;
}

void sortCardsByValue(vector<Card> &cards) {
    sort(cards.begin(), cards.end(), [](const Card &a, const Card &b) {
        return a.value < b.value;
    });
}

void sortAllPlayersCardsByValue(vector<Player> &players) {
    for (auto &player: players) {
        sortCardsByValue(player.cards);
    }
}

string getSuitStringFromSuit(Suit suit) {
    return SUITS[suit];
}

string getCardFromSuitAndValue(int value, Suit suit) {
    if (suit == Suit::JOKER) {
        return getSuitStringFromSuit(suit);
    }

    return to_string(value) + getSuitStringFromSuit(suit);
}

void displayAllPlayersCardsSortedByValue(vector<Player> &players) {
    sortAllPlayersCardsByValue(players);
    for (const auto &[i, player]: std::ranges::views::enumerate(players)) {
        cout << "Player " << i + 1 << " cards: ";
        for (const auto &card: player.cards) {
            cout << getCardFromSuitAndValue(card.value, card.suit) << " ";
        }
        cout << endl;
    }
}

int main() {
    Game game = initGame();

    displayAllPlayersCardsSortedByValue(game.players);

    return 0;
}
