#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

constexpr int GRID_SIZE = 3;

constexpr string filename = "tris.txt";

enum Field {
    X = 2,
    O = 1,
    EMPTY = 0
};

enum Player {
    PLAYER_1 = Field::X,
    PLAYER_2 = Field::O
};

// grid_decl is required for the struct definition
typedef struct grid_decl_ {
    array<array<Field, GRID_SIZE>, GRID_SIZE> fields{Field::EMPTY};
} Grid;

typedef struct game_decl_ {
    Grid grid;
    Player currentPlayer{Player::PLAYER_1};
} Game;


constexpr Game initGame() {
    return Game{};
}

void saveGame(const Game &game) {
    ofstream fileStream(filename, ios::binary);

    if (!fileStream.is_open()) {
        cout << "Errore durante l'apertura del file\n";
        return;
    }

    // Write grid
    fileStream.write(reinterpret_cast<const char *>(&game.grid.fields), sizeof(game.grid.fields));
    // Write currentPlayer
    fileStream.write(reinterpret_cast<const char *>(&game.currentPlayer), sizeof(game.currentPlayer));

    fileStream.close();
}

Game loadGame() {
    Game game;
    ifstream fileStream(filename, ios::binary);

    if (!fileStream.is_open()) {
        cout << "Errore durante l'apertura del file\n";
        return game;
    }

    // Read grid
    fileStream.read(reinterpret_cast<char *>(&game.grid.fields), sizeof(game.grid.fields));
    // Read currentPlayer
    fileStream.read(reinterpret_cast<char *>(&game.currentPlayer), sizeof(game.currentPlayer));

    fileStream.close();

    return game;
}

enum MainMenuChoice {
    NEW_GAME = 1,
    CONTINUE = 2,
    EXIT = 0
};

MainMenuChoice getChoice() {
    int choice;
    cout << "1) Nuova partita\n"
            "2) Continua\n"
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
            "3) Esci\n"
            "Scelta: ";
    cin >> choice;
    return static_cast<GameChoice>(choice);
}

void switchPlayer(Game &game) {
    game.currentPlayer = game.currentPlayer == Player::PLAYER_1 ? Player::PLAYER_2 : Player::PLAYER_1;
}

void printGrid(const Grid &grid) {
    for (const auto &row: grid.fields) {
        for (const auto &field: row) {
            switch (field) {
                case Field::X:
                    cout << "X";
                    break;
                case Field::O:
                    cout << "O";
                    break;
                case Field::EMPTY:
                    cout << " ";
                    break;
            }
            cout << "|";
        }
        cout << endl;
    }
}

bool isWinningMove(const Grid &grid, const Field &player_field) {
    auto [fields] = grid;

    // check horizontally
    for (const auto &row: fields) {
        for (int i = 0; i < GRID_SIZE; i++) {
            if (row[i] != player_field) {
                break;
            }

            if (i == GRID_SIZE - 1) {
                return true;
            }
        }
    }

    // check vertically
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (fields[j][i] != player_field) {
                break;
            }

            if (j == GRID_SIZE - 1) {
                return true;
            }
        }
    }

    // check diagonally
    for (int i = 0; i < GRID_SIZE; i++) {
        if (fields[i][i] != player_field) {
            break;
        }
        if (i == GRID_SIZE - 1) {
            return true;
        }
    }

    return false;
}

bool isDraw(const Grid &grid) {
    for (const auto &row: grid.fields) {
        for (const auto &field: row) {
            if (field == Field::EMPTY) {
                return false;
            }
        }
    }
    return true;
}

typedef struct {
    int x;
    int y;
} FieldCoords;

FieldCoords getCoords(int currentPlayerId) {
    FieldCoords coords;

    string currentPlayer = currentPlayerId == Player::PLAYER_1 ? "X" : "O";

    do {
        cout << "Giocatore " << currentPlayer << " inserisci la coordinata x: ";
        cin >> coords.x;

        if (coords.x < 0 || coords.x >= GRID_SIZE) {
            cout << "Coordinata x non valida\n";
        } else {
            break;
        }
    } while (true);

    do {
        cout << "Giocatore " << currentPlayer << " inserisci la coordinata y: ";
        cin >> coords.y;

        if (coords.y < 0 || coords.y >= GRID_SIZE) {
            cout << "Coordinata y non valida\n";
        } else {
            break;
        }
    } while (true);

    return coords;
}

void play(Game &game) {
    FieldCoords coords;
    do {
        printGrid(game.grid);
        coords = getCoords(game.currentPlayer);

        if (game.grid.fields[coords.x][coords.y] != Field::EMPTY) {
            cout << "La casella è già occupata\n";
        } else {
            break;
        }
    } while (true);

    game.grid.fields[coords.x][coords.y] = game.currentPlayer == Player::PLAYER_1 ? Field::X : Field::O;

    if (isWinningMove(game.grid, game.currentPlayer == Player::PLAYER_1 ? Field::X : Field::O)) {
        printGrid(game.grid);
        cout << "Il giocatore " << (game.currentPlayer == Player::PLAYER_1 ? "X" : "O") << " ha vinto!\n";
        return;
    }

    if (isDraw(game.grid)) {
        printGrid(game.grid);
        cout << "Pareggio!\n";
        return;
    }

    switchPlayer(game);
}

int main() {
    Game game;

    bool exit = false;
    do {
        switch (getChoice()) {
            case NEW_GAME:
                cout << "Nuova partita\n";
                game = initGame();
                exit = true;
                break;
            case CONTINUE:
                cout << "Continua\n";
                game = loadGame();
                exit = true;
                break;
            case EXIT:
                cout << "Uscita\n";
                exit = true;
                break;
            default:
                cout << "Scelta non valida\n";
                break;
        }
    } while (!exit);


    exit = false;
    do {
        switch (getGameChoice()) {
            case PLAY:
                cout << "Gioca\n";
                play(game);
                break;
            case SAVE:
                cout << "Salva\n";
                saveGame(game);
                break;
            case EXIT_GAME:
                cout << "Uscita\n";
                exit = true;
                break;
            default:
                cout << "Scelta non valida\n";
                break;
        }
    } while (!exit);

    return 0;
}