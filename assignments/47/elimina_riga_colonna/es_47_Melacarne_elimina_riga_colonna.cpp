#include <iostream>

using namespace std;

constexpr int ROWS = 3;
constexpr int COLS = 4;

// Populates a matrix with random numbers
void getRandomMatrix(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

// Prints a given matrix
void printMatrix(const int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        cout << "[";
        for (int j = 0; j < COLS - 1; j++) {
            cout << matrix[i][j] << ", ";
        }
        cout << matrix[i][COLS - 1] << "]" << endl;
    }
}

// Returns the sum of all the elements of a matrix except the one at the given row and column
int getTotalSumExceptGiven(const int matrix[ROWS][COLS], const int row, const int col) {
    int sum = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == row || j == col) {
                continue;
            }
            sum += matrix[i][j];
        }
    }
    return sum;
}

// Gets a value from the user less than or equal to the given max value
int getUserValue(const string &message, const int maxValue) {
    do {
        int value;
        cout << message;
        cin >> value;
        if (value < 0 || value > maxValue) {
            cout << "Valore non valido. Inserisci un valore compreso tra 0 e " << maxValue << endl;
        } else {
            return value;
        }
    } while (true);
}

int main() {
    srand(time(nullptr));

    int matrix[ROWS][COLS];

    getRandomMatrix(matrix);

    cout << "La matrice generata è:\n";
    printMatrix(matrix);

    const int row = getUserValue("Inserisci la riga da eliminare: ", ROWS - 1);
    const int col = getUserValue("Inserisci la colonna da eliminare: ", COLS - 1);

    cout << "La somma degli elementi della matrice escludendo la riga " << row << " e la colonna " << col << " è: "
         << getTotalSumExceptGiven(matrix, row, col) << "\n";
    getTotalSumExceptGiven(matrix, row, col);

    return 0;
}