#include <iostream>
#include <array>

using namespace std;

constexpr int NUMBER_OF_TABLES = 6;

// Generate a random number between 1 and 90 (included)
int genNumber() {
    return rand() % 90 + 1;
}

// Generate a random number between min and max (both included)
int genNumberBetween(const int &min, const int &max) {
    return rand() % (max - min + 1) + min;
}

tuple<int, int> getPositionRange(const int &position) {
    int min, max;

    if (position == 0) {
        min = 1;
        max = 9;
    } else if (position == 9) {
        min = 80;
        max = 90;
    } else {
        min = position * 10;
        max = min + 9;
    }

    return make_tuple(min, max);
}

bool
checkIfNumberIsAlreadyPresentInTheSameColumn(const array<array<int, 9>, 3> &table, const int &position, const int &n) {
    for (int i = 0; i < 3; i++) {
        if (table[i][position] == n) {
            return true;
        }
    }

    return false;
}

int getNumberForPosition(const array<array<int, 9>, 3> &table, const int &position) {
    int min, max;
    tie(min, max) = getPositionRange(position);

    int n = genNumberBetween(min, max - 1);

    while (checkIfNumberIsAlreadyPresentInTheSameColumn(table, position, n)) {
        n = genNumberBetween(min, max);
    }

    return n;
}


auto getRow(const array<array<int, 9>, 3> &table) {
    array<int, 9> row{0};

    constexpr int NUMS_IN_ROW = 5;
    for (int i = 0; i < NUMS_IN_ROW; i++) {
        int position = rand() % 9;
        while (row[position] != 0) {
            position = rand() % 9;
        }

        int n = getNumberForPosition(table, position);

        row[position] = n;
    }

    return row;
}


auto getTable() {
    array<array<int, 9>, 3> table{0};

    for (int i = 0; i < 3; i++) {
        table[i] = getRow(table);
    }

    return table;
}

void printTable(const array<array<int, 9>, 3> &table) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 9; j++) {
            if (table[i][j] == 0) {
                cout << "-- ";
            } else if (table[i][j] == -1) {
                cout << "XX ";
            } else {
                cout << table[i][j] << " ";
            }
        }
        cout << endl;
    }
}

void addTableNumber(array<array<int, 9>, 3> &table, const int &n) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 9; j++) {
            if (table[i][j] == n) {
                cout << "Numero " << n << " trovato nella tabella " << i + 1 << " alla posizione " << j + 1 << endl;
                table[i][j] = -1;
                return;
            }
        }
    }
}

// Returns if there is a row with 3 numbers crossed out
bool checkTables(const array<array<array<int, 9>, 3>, NUMBER_OF_TABLES> &tables) {
    for (auto &table: tables) {
        for (auto &row: table) {
            int count = 0;
            for (auto n: row) {
                if (n == -1) {
                    count++;
                }
            }

            if (count == 2) {
                cout << "Hai fatto un ambo!";
            } else if (count == 3) {
                cout << "Hai fatto una terna!";
                return true;
            }
        }
    }
    return false;
}


int main() {
    srand(time(nullptr));

    auto tables = array<array<array<int, 9>, 3>, NUMBER_OF_TABLES>{0};
    for (auto &table: tables) {
        table = getTable();
    }

    cout << "Le tue tabelle: " << endl;
    for (auto table: tables) {
        printTable(table);
        cout << endl;
    }

    do {
        int n = genNumber();
        cout << "Numero estratto: " << n << endl;
        for (auto &table: tables) {
            addTableNumber(table, n);
            printTable(table);
            cout << endl;
        }

        if (checkTables(tables)) {
            break;
        }

        cout << "Premi invio per continuare..." << endl;
        cin.get();
    } while (true);

    return 0;
}