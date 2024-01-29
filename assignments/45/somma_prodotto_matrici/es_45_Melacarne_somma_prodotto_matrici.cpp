#include <iostream>

using namespace std;

// The size of the square matrices
constexpr int N = 3;

// Gets a matrix from the user
void getMatrix(int matrix[N][N], const int rows, const int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Inserisci l'elemento [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// Prints a given matrix
void printMatrix(const int matrix[N][N], const int rows, const int cols) {
    for (int i = 0; i < rows; i++) {
        cout << "[";
        for (int j = 0; j < cols - 1; j++) {
            cout << matrix[i][j] << ", ";
        }
        cout << matrix[i][cols - 1] << "]" << endl;
    }
}

// Sums two matrices
void sumMatrices(const int matrixA[N][N], const int matrixB[N][N], int matrixSum[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrixSum[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

// Multiplies two matrices
void multiplyMatrices(const int matrixA[N][N], const int matrixB[N][N], int matrixProduct[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
                // The element at row i and column j of the product matrix is the sum of the products of the elements of row i of matrix A and column j of matrix B
                for (int k = 0; k < N; k++) {
                    matrixProduct[i][j] += matrixA[i][k] * matrixB[k][j];
                }
        }
    }
}

int main() {
    cout << "Inserisci gli elementi della matrice A:\n";
    int matrixA[N][N];
    getMatrix(matrixA, N, N);

    cout << "Inserisci gli elementi della matrice B:\n";
    int matrixB[N][N];
    getMatrix(matrixB, N, N);

    cout << "Matrice A:\n";
    printMatrix(matrixA, N, N);
    cout << "Matrice B:\n";
    printMatrix(matrixB, N, N);

    int matrixSum[N][N];
    sumMatrices(matrixA, matrixB, matrixSum);

    cout << "Somma delle matrici:\n";
    printMatrix(matrixSum, N, N);

    int matrixProduct[N][N];
    multiplyMatrices(matrixA, matrixB, matrixProduct);

    cout << "Prodotto delle matrici:\n";
    printMatrix(matrixProduct, N, N);

    return 0;
}