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

int getSecondMaximumPos(const int arr[], int len) {
    int max = arr[0];
    int secondMax = arr[1];
    if (secondMax > max) {
        swap(max, secondMax);
    }

    for (int i = 2; i < len; i++) {
        if (arr[i] > max) {
            secondMax = max;
            max = arr[i];
        } else if (arr[i] > secondMax) {
            secondMax = arr[i];
        }
    }

    return secondMax;
}

void getSecondTallerOfEachRow(const int matrix[ROWS][COLS], int secondTallerOfRows[ROWS]) {
    for (int i = 0; i < ROWS; i++) {
        secondTallerOfRows[i] = getSecondMaximumPos(matrix[i], COLS);
    }
}

void printSecondTaller(const int secondTaller[ROWS]) {
    for (int i = 0; i < ROWS; i++) {
        cout << "La seconda altezza massima della riga " << i << " è " << secondTaller[i] << endl;
    }
}

void getSecondShorterOfEachColumn(const int matrix[ROWS][COLS], int secondShorterOfCols[COLS]) {
    for (int i = 0; i < COLS; i++) {
        int column[ROWS];
        for (int j = 0; j < ROWS; j++) {
            column[j] = matrix[j][i];
        }
        secondShorterOfCols[i] = getSecondMaximumPos(column, ROWS);
    }
}

void printSecondShorter(const int secondShorter[COLS]) {
    for (int i = 0; i < COLS; i++) {
        cout << "La seconda altezza minima della colonna " << i << " è " << secondShorter[i] << endl;
    }
}
int main() {
    srand(time(nullptr));

    int matrix[ROWS][COLS];
    getRandomMatrix(matrix);

    cout << "Matrice generata:\n";
    printMatrix(matrix);

    int secondTallerOfRows[ROWS];
    getSecondTallerOfEachRow(matrix, secondTallerOfRows);
    printSecondTaller(secondTallerOfRows);

    int secondShorterOfCols[COLS];
    getSecondShorterOfEachColumn(matrix, secondShorterOfCols);
    printSecondShorter(secondShorterOfCols);

    return 0;
}