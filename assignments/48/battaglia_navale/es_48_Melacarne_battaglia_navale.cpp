#include <iostream>
#include <array>
#include <limits>

using namespace std;

constexpr int DIM_ROW = 10;
constexpr int DIM_COL = DIM_ROW;

// Number of boats available
constexpr int NUM_BOATS = 6;
// Sizes of the boats
constexpr int BOAT_SIZES[NUM_BOATS] = {4, 3, 3, 2, 2, 1};

// Clears the console, works on both Windows and Unix systems
void clearConsole() {
    system("clear");
}

// A single Cell of the table: can be a boat, a boat hit or none
enum Cell {
    boat_hit = -1,
    none = 0,
    boat1 = 1,
    boat2 = 2,
    boat3 = 3,
    boat4 = 4,
    boat5 = 5,
    boat6 = 6,
};

// Overloads the << operator for the Cell enum, needed to print the enum character to display the table
std::ostream &operator<<(std::ostream &os, const Cell cell) {
    switch (cell) {
        case Cell::boat1:
            os << '1';
            break;
        case Cell::boat2:
            os << '2';
            break;
        case Cell::boat3:
            os << '3';
            break;
        case Cell::boat4:
            os << '4';
            break;
        case Cell::boat5:
            os << '5';
            break;
        case Cell::boat6:
            os << '6';
            break;
        case Cell::boat_hit:
            os << 'X';
            break;
        case Cell::none:
            os << ' ';
            break;
    }
    return os;
}

// Tables for both players
array<array<array<Cell, DIM_COL>, DIM_ROW>, 2> tables;

// Prints the table
void printTable(const array<array<Cell, DIM_COL>, DIM_ROW> table) {
    cout << "    ";
    for (int i = 0; i < DIM_ROW; i++) {
        cout << i << " ";
    }
    cout << endl << "    ";
    for (int i = 0; i < DIM_ROW * 2 - 1; i++) {
        cout << "-";
    }
    cout << endl;
    for (int i = 0; i < DIM_ROW; i++) {
        cout << i << " | ";

        for (int j = 0; j < DIM_COL; j++) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
}

// Clears both tables, setting all the slots to none
constexpr void clearTables() {
    for (auto &row: tables[0])
        row.fill(Cell::none);

    for (auto &row: tables[1])
        row.fill(Cell::none);

}

// Orientation of the boat
enum Orientation {
    vertical = 0,
    horizontal = 1
};

bool checkIfBoatCanBeAdded(const int startingRow, const int startingCol, const int endingRow, const int endingCol,
                           array<array<Cell, DIM_COL>, DIM_ROW> &table) {
    // Check if the boat is inside the board
    if (endingRow > DIM_ROW || endingCol > DIM_COL) {
        return false;
    }

    // Check if the boat is not overlapping with other boats
    for (int i = startingRow; i <= endingRow; i++) {
        for (int j = startingCol; j <= endingCol; j++) {
            if (table[i][j] != Cell::none) {
                return false;
            }
        }
    }

    return true;
}



// Adds a boat to the board, returns true if created successfully, otherwise returns false
bool addBoat(int startingRow, int startingCol, const int boatDim, const Orientation orientation,
             const int boatNumber,
             array<array<Cell, DIM_COL>, DIM_ROW> &table) {
    // Swap the starting row and column for a more intuitive input
    swap(startingRow, startingCol);

    // The current boat we are adding
    Cell boatCell;
    switch (boatNumber) {
        case 1:
            boatCell = Cell::boat1;
            break;
        case 2:
            boatCell = Cell::boat2;
            break;
        case 3:
            boatCell = Cell::boat3;
            break;
        case 4:
            boatCell = Cell::boat4;
            break;
        case 5:
            boatCell = Cell::boat5;
            break;
        case 6:
            boatCell = Cell::boat6;
            break;
        default:
            return false;
    }

    // Calculate the ending coordinates of the boat
    int endingRow, endingCol;
    switch (orientation) {
        case Orientation::vertical:
            endingRow = startingRow + boatDim - 1;
            endingCol = startingCol;
            break;
        case Orientation::horizontal:
            endingRow = startingRow;
            endingCol = startingCol + boatDim - 1;
            break;
    }

    // Check if the boat can be added
    if (!checkIfBoatCanBeAdded(startingRow, startingCol, endingRow, endingCol, table)) {
        return false;
    }

    // Add the boat to the board
    for (int i = startingRow; i <= endingRow; i++) {
        for (int j = startingCol; j <= endingCol; j++) {
            table[i][j] = boatCell;
        }
    }

    return true;
}

// Overloads the >> operator for the Orientation enum, needed to read the orientation from the user
std::istream &operator>>(std::istream &is, Orientation &orientation) {
    char orientationInput;
    is >> orientationInput;

    switch (orientationInput) {
        case 'o':
            orientation = Orientation::horizontal;
            break;
        case 'v':
            orientation = Orientation::vertical;
            break;
        default:
            is.setstate(std::ios_base::failbit);
    }

    return is;
}

// Menu to add a boat to the board
void addBoatMenu(int &startingCol, int &startingRow, Orientation &orientation, const int boatDim) {
    do {
        cout << "Inserisci la colonna di partenza: ";
        cin >> startingCol;
        if (startingCol < 0 || startingCol >= DIM_ROW) {
            cout << "Colonna non valida (0-" << DIM_ROW - 1 << ")" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        } else {
            break;
        }
    } while (true);

    do {
        cout << "Inserisci la riga di partenza: ";
        cin >> startingRow;
        if (startingRow < 0 || startingRow >= DIM_COL) {
            cout << "Riga non valida (0-" << DIM_COL - 1 << ")" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        } else {
            break;
        }
    } while (true);

    // If the boat is 1x1, the orientation is not needed
    if (boatDim == 1) {
        orientation = Orientation::horizontal;
        return;
    }

    do {
        cout << "Inserisci l'orientamento (o/v): ";
        cin >> orientation;
        if (cin.fail()) {
            cout << "Orientamento non valido" << endl;
            // Clear the input buffer and ignore
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        } else {
            break;
        }
    } while (true);
}

// Checks if a player has won, returns true if a player has won, otherwise returns false
bool playerWon() {
    // Set to true if player 1 has at least one boat
    bool foundBoatsPlayer1 = false;

    for (auto &row: tables[0]) {
        for (auto &cell: row) {
            switch (cell) {
                case Cell::boat1:
                case Cell::boat2:
                case Cell::boat3:
                case Cell::boat4:
                case Cell::boat5:
                case Cell::boat6:
                    foundBoatsPlayer1 = true;
                    break;
                default:
                    continue;
            }
        }
    }

    // Set to true if player 2 has at least one boat
    bool foundBoatsPlayer2 = false;
    for (auto &row: tables[1]) {
        for (auto &cell: row) {
            switch (cell) {
                case Cell::boat1:
                case Cell::boat2:
                case Cell::boat3:
                case Cell::boat4:
                case Cell::boat5:
                case Cell::boat6:
                    foundBoatsPlayer2 = true;
                    break;
                default:
                    continue;
            }
        }
    }

    return !foundBoatsPlayer1 || !foundBoatsPlayer2;
}

// Prints both tables
void printBothTables() {
    cout << "Campo player 1: \n";
    printTable(tables[0]);

    cout << "Campo player 2: \n";
    printTable(tables[1]);
}


// Gets a table from the user
void getTableFromUser(array<array<Cell, DIM_COL>, DIM_ROW> &table, const int playerNumber) {
    cout << "Inserisci il campo del player " << playerNumber << endl;
    for (int i = 0; i < NUM_BOATS; i++) {
        int startingRow, startingCol, boatDim;
        Orientation orientation;
        clearConsole();
        cout << "Inserisci la barca " << i + 1 << " di " << NUM_BOATS << " (di dimensione " << BOAT_SIZES[i] << ")"
             << endl;
        boatDim = BOAT_SIZES[i];

        addBoatMenu(startingRow, startingCol, orientation, boatDim);

        bool addedBoat = addBoat(startingRow, startingCol, boatDim, orientation, i + 1, table);
        // clearConsole();
        if (!addedBoat) {
            cout << "Impossibile aggiungere la barca, ripeti l'inserimento per favore" << endl;
            i--;
        }

        cout << "Campo player " << playerNumber << ":" << endl;
        printTable(table);
    }
}

// Asks the player for the coordinates to fireAtCoordinates at
pair<int, int> getFireCoordinates(const int playerNumber) {
    cout << "Player " << playerNumber << " è il tuo turno!" << endl;
    int col, row;
    do {
        cout << "Player " << playerNumber << " Inserisci la colonna: ";
        cin >> col;
        if (col < 0 || col >= DIM_ROW) {
            cout << "Colonna non valida" << endl;
            continue;
        } else {
            break;
        }
    } while (true);

    do {
        cout << "Player " << playerNumber << " Inserisci la riga: ";
        cin >> row;
        if (row < 0 || row >= DIM_COL) {
            cout << "Riga non valida" << endl;
            continue;
        } else {
            break;
        }
    } while (true);

    return {col, row};
}


// Fires at the given coordinates, returns true if a boat was hit, otherwise returns false
bool fireAtCoordinates(const int col, const int row, array<array<Cell, DIM_COL>, DIM_ROW> &table) {
    switch (table[row][col]) {
        case Cell::boat1:
        case Cell::boat2:
        case Cell::boat3:
        case Cell::boat4:
        case Cell::boat5:
        case Cell::boat6:
            table[row][col] = Cell::boat_hit;
            return true;
        default:
            return false;
    }
}

// Populates a table with random boats
void getRandomTable(array<array<Cell, DIM_COL>, DIM_ROW> &table) {
    for (int i = 0; i < NUM_BOATS; i++) {
        int startingRow, startingCol, boatDim;
        Orientation orientation;
        boatDim = BOAT_SIZES[i];

        do {
            startingRow = rand() % DIM_ROW;
            startingCol = rand() % DIM_COL;
            orientation = static_cast<Orientation>(rand() % 2);
        } while (!addBoat(startingRow, startingCol, boatDim, orientation, i + 1, table));
    }
}

int getStartMenuOption() {
    cout << "Benvenuto in Battaglia Navale!\n"
            "Selezione una delle seguenti opzioni:\n"
            "1. Inizia il gioco inserendo le barche\n"
            "2. Inizia il gioco con barche random\n"
            "3. Esci\n";
    int choice;
    do {
        cout << "Scelta: ";
        cin >> choice;
        if (choice < 1 || choice > 3) {
            cout << "Scelta non valida" << endl;
            continue;
        } else {
            break;
        }
    } while (true);

    return choice;
}


void startMenu() {
    int choice = getStartMenuOption();

    switch (choice) {
        case 1:
            for (int i = 0; i < 2; i++) {
                getTableFromUser(tables[i], i + 1);
                clearConsole();
            }
            break;
        case 2:
            for (auto &table: tables) {
                getRandomTable(table);
            }
            clearConsole();
            break;
        case 3:
            exit(0);
    }

    cout << "Entrambi i giocatori hanno inserito le loro barche, inizia il gioco!\n"
            "Campi iniziali: \n";
    printBothTables();
}


int main() {
    srand(time(nullptr));
    clearTables();

    startMenu();

    int turn = 0;
    do {
        int thisTurnPlayer = turn % 2;

        auto [col, row] = getFireCoordinates(thisTurnPlayer + 1);

        int thisTurnOtherPlayer = (thisTurnPlayer + 1) % 2;
        bool hit = fireAtCoordinates(col, row, tables[thisTurnOtherPlayer]);

        if (hit) {
            cout << "Hai colpito una barca!" << endl;
        } else {
            cout << "Nessuna barca colpita" << endl;
        }

        turn++;


        if (playerWon()) {
            cout << "Player " << thisTurnPlayer + 1 << " ha vinto!" << endl;
            break;
        }

        printBothTables();

        clearConsole();
    } while (true);

    return 0;
}