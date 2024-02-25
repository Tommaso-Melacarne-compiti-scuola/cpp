#include <iostream>
#include <array>

using namespace std;

constexpr int SIZE = 10;

array<array<int, SIZE>, SIZE> getMatrixZigZag() {
    array<array<int, SIZE>, SIZE> matrix;
    int counter = 1;
    for (int i = 0; i < SIZE; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < SIZE; j++) {
                matrix[i][j] = counter;
                counter++;
            }
        } else {
            for (int j = SIZE - 1; j >= 0; j--) {
                matrix[i][j] = counter;
                counter++;
            }
        }
    }
    return matrix;
}

array<array<int, SIZE>, SIZE> getMatrixDiagonal() {
    array<array<int, SIZE>, SIZE> matrix;

    int outerCounter = 1;

    for (auto &row: matrix) {
        int innerCounter = outerCounter;

        for (auto &col: row) {
            col = innerCounter;
            innerCounter++;
        }

        outerCounter++;
    }

    return matrix;
}

array<array<int, SIZE>, SIZE> getMatrixTranslated() {
    array<array<int, SIZE>, SIZE> matrix;

    for (int i = 0; i < SIZE; i++) {
        int num = i + 1;
        for (int j = 0; j < SIZE; j++) {
            matrix[i][j] = num;
            if (i > j) {
                num--;
            } else {
                num++;
            }
        }
    }

    return matrix;
}

array<array<int, SIZE>, SIZE> getMatrixPyramid() {
    array<array<int, SIZE>, SIZE> matrix;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i < j && i < SIZE - j) {
                matrix[i][j] = i + 1;
            } else if (i >= j && i < SIZE - j) {
                matrix[i][j] = j + 1;
            } else if (i >= j && i >= SIZE - j) {
                matrix[i][j] = SIZE - i;
            } else {
                matrix[i][j] = SIZE - j;
            }
        }
    }

    return matrix;
}

array<array<int, SIZE>, SIZE> getMatrixSpiral() {
    array<array<int, SIZE>, SIZE> matrix;

    int startRow = 0, startCol = 0;
    int endRow = SIZE - 1, endCol = SIZE - 1;
    int counter = 1;

    while (startRow <= endRow && startCol <= endCol) {
        for (int i = startCol; i <= endCol; i++) {
            matrix[startRow][i] = counter++;
        }
        startRow++;

        for (int i = startRow; i <= endRow; i++) {
            matrix[i][endCol] = counter++;
        }
        endCol--;

        for (int i = endCol; i >= startCol; i--) {
            matrix[endRow][i] = counter++;
        }
        endRow--;

        for (int i = endRow; i >= startRow; i--) {
            matrix[i][startCol] = counter++;
        }
        startCol++;
    }

    return matrix;
}

array<array<int, SIZE>, SIZE> getMatrixDoubleStep() {
    array<array<int, SIZE>, SIZE> matrix;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int min = i < j ? i : j;
            min = min < SIZE - i ? min : SIZE - i - 1;
            min = min < SIZE - j - 1 ? min : SIZE - j - 1;
            matrix[i][j] = min + 1;
        }
    }

    return matrix;
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
    array<array<int, SIZE>, SIZE> matrix;

    cout << "Matrice zig zag: " << endl;
    matrix = getMatrixZigZag();
    printMatrix(matrix);

    cout << "Matrice diagonale: " << endl;
    matrix = getMatrixDiagonal();
    printMatrix(matrix);

    cout << "Matrice traslata: " << endl;
    matrix = getMatrixTranslated();
    printMatrix(matrix);

    cout << "Matrice a piramide azteca: " << endl;
    matrix = getMatrixPyramid();
    printMatrix(matrix);

    cout << "Matrice a spirale: " << endl;
    matrix = getMatrixSpiral();
    printMatrix(matrix);

    cout << "Matrice a doppi gradini: " << endl;
    matrix = getMatrixDoubleStep();
    printMatrix(matrix);

    return 0;
}