#include <iostream>
#include <array>

using namespace std;

constexpr int NUMBER_OF_TABLES = 6;
constexpr int ROWS_PER_TABLE = 3;
constexpr int COLUMNS_PER_TABLE = 9;
constexpr int NUMBERS_PER_ROW = 5;
constexpr int MAX_TWO_IN_A_ROW = COLUMNS_PER_TABLE * NUMBER_OF_TABLES;

// Generate a random number between 1 and 90 (included)
int genNumber() {
    return rand() % 90 + 1;
}

// Generate a random number between min and max (both included)
int genNumberBetween(const int &min, const int &max) {
    return rand() % (max - min + 1) + min;
}

// Returns the range of numbers for a given position
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

// Returns if a number is already present in the same column
bool
isNumberAlreadyInColumn(const array<array<int, COLUMNS_PER_TABLE>, ROWS_PER_TABLE> &table, const int &position,
                        const int &n) {
    for (int i = 0; i < ROWS_PER_TABLE; i++) {
        if (table[i][position] == n) {
            return true;
        }
    }

    return false;
}

// Returns a number for a given position
int getNumberForPosition(const array<array<int, COLUMNS_PER_TABLE>, ROWS_PER_TABLE> &table, const int &position) {
    int min, max;
    tie(min, max) = getPositionRange(position);

    int n = genNumberBetween(min, max - 1);

    while (isNumberAlreadyInColumn(table, position, n)) {
        n = genNumberBetween(min, max);
    }

    return n;
}

// Returns a new table row
auto getRow(const array<array<int, COLUMNS_PER_TABLE>, ROWS_PER_TABLE> &table) {
    array<int, COLUMNS_PER_TABLE> row{0};

    for (int i = 0; i < NUMBERS_PER_ROW; i++) {
        int position = rand() % COLUMNS_PER_TABLE;
        while (row[position] != 0) {
            position = rand() % COLUMNS_PER_TABLE;
        }

        int n = getNumberForPosition(table, position);

        row[position] = n;
    }

    return row;
}

// Returns a new table
auto getTable() {
    array<array<int, COLUMNS_PER_TABLE>, ROWS_PER_TABLE> table{0};

    for (auto &row: table) {
        row = getRow(table);
    }

    return table;
}

// Returns new tables
auto getTables() {
    array<array<array<int, COLUMNS_PER_TABLE>, ROWS_PER_TABLE>, NUMBER_OF_TABLES> tables{0};

    for (auto &table: tables) {
        table = getTable();
    }

    return tables;
}

// Prints the tables
void printTables(const array<array<array<int, COLUMNS_PER_TABLE>, ROWS_PER_TABLE>, NUMBER_OF_TABLES> &tables) {
    for (auto table: tables) {
        for (auto row: table) {
            for (auto n: row) {
                if (n == 0) {
                    cout << "-- ";
                } else if (n == -1) {
                    cout << "XX ";
                } else {
                    cout << n << " ";
                }
            }
            cout << endl;
        }
        cout << endl;
    }
}

// Adds a number to the tables
void
addNumberToTables(array<array<array<int, COLUMNS_PER_TABLE>, ROWS_PER_TABLE>, NUMBER_OF_TABLES> &tables, const int &n) {
    // i = table
    // j = row
    // k = column
    for (int i = 0; i < NUMBER_OF_TABLES; i++) {
        for (int j = 0; j < ROWS_PER_TABLE; j++) {
            for (int k = 0; k < COLUMNS_PER_TABLE; k++) {
                if (tables[i][j][k] == n) {
                    cout << "Numero " << n << " trovato nella tabella " << i + 1 << " alla posizione " <<
                         "(" << j + 1 << ", " << k + 1 << ")\n";
                    tables[i][j][k] = -1;
                }
            }
        }
    }
    cout << "Numero " << n << " non trovato in nessuna tabella\n";
}

// Returns the count of CONSECUTIVE -1 in a row, also returns the first number of the combination
tuple<int, int> getConsecutiveCrossedOutNumbers(const array<int, COLUMNS_PER_TABLE> &row) {
    int count = 0;
    int firstNum = 0;
    bool isFirstNumSet = false;

    for (int i = 0; i < COLUMNS_PER_TABLE; i++) {
        if (row[i] == -1) {
            count++;
            if (!isFirstNumSet) {
                firstNum = i;
                isFirstNumSet = true;
            }
        } else {
            if (count) {
                break;
            } else {
                firstNum = 0;
                isFirstNumSet = false;
            }
        }
    }

    return make_tuple(count, firstNum);
}


// Returns if there is a row with 3 numbers crossed out
bool checkTables(const array<array<array<int, COLUMNS_PER_TABLE>, ROWS_PER_TABLE>, NUMBER_OF_TABLES> &tables,
                 array<tuple<int, int, int>, MAX_TWO_IN_A_ROW> &combinations, int &combinationsCursor) {
    for (int i = 0; i < NUMBER_OF_TABLES; i++) {
        for (int j = 0; j < ROWS_PER_TABLE; j++) {

            int count, firstNumCol;
            tie(count, firstNumCol) = getConsecutiveCrossedOutNumbers(tables[i][j]);

            if (count == 2) {
                // Check if the number was previously extracted and counted as a combination
                bool alreadyExtracted = false;
                for (int k = 0; k < combinationsCursor; k++) {
                    int extractedNumberTable, extractedNumberRow, extractedNumberCol;
                    tie(extractedNumberTable, extractedNumberRow, extractedNumberCol) = combinations[k];
                    if (extractedNumberTable == i && extractedNumberRow == j && extractedNumberCol == firstNumCol) {
                        alreadyExtracted = true;
                        break;
                    }
                }

                if (!alreadyExtracted) {
                    combinations[combinationsCursor] = make_tuple(i, j, firstNumCol);
                    combinationsCursor++;
                    cout << "Hai fatto un ambo nella tabella " << i + 1 << " alla riga " << j + 1 << " e colonna " <<
                         firstNumCol + 1 << "!\n";
                }
            } else if (count == 3) {
                cout << "Hai fatto una terna!\n";
                return true;
            }
        }
    }
    return false;
}

array<tuple<int, int, int>, MAX_TWO_IN_A_ROW> getNewCombinationsArray() {
    array<tuple<int, int, int>, MAX_TWO_IN_A_ROW> combinations{};

    for (auto &combination: combinations) {
        combination = make_tuple(0, 0, 0);
    }

    return combinations;
}


int main() {
    srand(time(nullptr));

    auto tables = getTables();

    cout << "Le tue tabelle: " << endl;
    printTables(tables);

    auto combinations = getNewCombinationsArray();
    int combinationsCursor = 0;

    do {
        int extractedNumber = genNumber();
        cout << "Numero estratto: " << extractedNumber << endl;
        addNumberToTables(tables, extractedNumber);

        printTables(tables);

        if (checkTables(tables, combinations, combinationsCursor)) {
            break;
        }

        cout << "Premi invio per continuare..." << endl;
        cin.get();
    } while (true);

    return 0;
}