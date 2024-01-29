#include <iostream>

using namespace std;

constexpr int ROWS = 4;
constexpr int COLS = 3;

// Gets the size of a matrix from the user
tuple<int, int> getSize() {
    int rows, cols;
    cout << "Inserisci il numero di righe: ";
    cin >> rows;
    cout << "Inserisci il numero di colonne: ";
    cin >> cols;
    return {rows, cols};
}


// Gets a matrix from the user
void getMatrix(int matrix[ROWS][COLS], const int rows, const int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Inserisci l'elemento [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// Swaps two rows of a matrix
void swapRows(int matrix[ROWS][COLS], const int row1, const int row2) {
    for (int i = 0; i < COLS; i++) {
        swap(matrix[row1][i], matrix[row2][i]);
    }
}

// Swaps the odd rows with the even rows
void swapRowsOddEven(int matrix[ROWS][COLS], const int rows) {
    for (int i = 0; i < rows - 1; i += 2) {
        swapRows(matrix, i, i + 1);
    }
}

// Prints a given matrix
void printMatrix(const int matrix[ROWS][COLS], const int rows, const int cols) {
    for (int i = 0; i < rows; i++) {
        cout << "[";
        for (int j = 0; j < cols - 1; j++) {
            cout << matrix[i][j] << ", ";
        }
        cout << matrix[i][cols - 1] << "]" << endl;
    }
}


int main() {
    int matrix[ROWS][COLS];

    auto [rows, cols] = getSize();

    getMatrix(matrix, rows, cols);

    cout << "Matrice inserita: \n";
    printMatrix(matrix, rows, cols);

    swapRowsOddEven(matrix, rows);

    cout << "Matrice modificata: \n";
    printMatrix(matrix, rows, cols);

    return 0;
}