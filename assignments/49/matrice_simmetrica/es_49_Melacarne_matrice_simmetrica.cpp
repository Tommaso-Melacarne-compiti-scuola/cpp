#include <iostream>
#include <array>

using namespace std;

constexpr int SIZE = 3;


array<array<int, SIZE>, SIZE> readMatrix() {
    array<array<int, SIZE>, SIZE> matrix;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << "Inserisci l'elemento [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
    return matrix;
}

bool checkSymmetry(const array<array<int, SIZE>, SIZE> matrix) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                return false;
            }
        }
    }
    return true;
}

void printMatrix(const array<array<int, SIZE>, SIZE> matrix) {
    for (int i = 0; i < SIZE; i++) {
        cout << "[";
        for (int j = 0; j < SIZE - 1; j++) {
            cout << matrix[i][j] << ", ";
        }
        cout << matrix[i][SIZE - 1] << "]" << endl;
    }
}

int main() {
    array<array<int, SIZE>, SIZE> matrix = readMatrix();

    bool symmetric = checkSymmetry(matrix);

    if (symmetric) {
        cout << "La matrice è simmetrica rispetto alla diagonale principale" << endl;
    } else {
        cout << "La matrice non è simmetrica rispetto alla diagonale principale" << endl;
    }

    cout << "Matrice originale" << endl;
    printMatrix(matrix);

    return 0;
}