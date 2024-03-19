#include <iostream>

using namespace std;

constexpr int ROWS = 10;
constexpr int COLS = 10;
constexpr int MAX = 100;

constexpr int SIZE = ROWS * COLS;

void fillMatrixRandom(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = rand() % MAX;
        }
    }
    return;
}


void bubbleSort(int *arr, const int len) {
    for (int i = 0; i < len - 1; i++) {
        bool guard = false;
        for (int j = 0; j < len - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                guard = true;
            }
        }
        if (!guard) {
            break;
        }
    }
    return;
}

void printMatrix(const int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        cout << "[";
        for (int j = 0; j < COLS - 1; j++) {
            cout << matrix[i][j] << ", ";
        }
        cout << matrix[i][COLS - 1] << "]" << endl;
    }

    return;
}

int getChoice() {
    cout << "1. Rigenera casualmente la matrice\n"
            "2. Ordina tutte le righe\n"
            "3. Ordina tutte le colonne\n"
            "4. Ordina tutta la matrice per righe\n"
            "5. Ordina tutta la matrice per colonne\n"
            "6. Stampa la matrice\n"
            "0. Esci\n"
            "Scelta:\n";
    int choice;
    cin >> choice;
    return choice;
}

void sortAllRows(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        bubbleSort(matrix[i], COLS);
    }
    return;
}

void sortAllCols(int matrix[ROWS][COLS]) {
    for (int i = 0; i < COLS; i++) {
        int column[ROWS];
        for (int j = 0; j < ROWS; j++) {
            column[j] = matrix[j][i];
        }
        bubbleSort(column, ROWS);
        for (int j = 0; j < ROWS; j++) {
            matrix[j][i] = column[j];
        }
    }
    return;
}

void sortEntireMatrixByRows(int matrix[ROWS][COLS]) {
    bubbleSort((int *) matrix, SIZE);
    return;
}

void sortEntireMatrixByCols(int matrix[ROWS][COLS]) {
    int arr[SIZE];
    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < ROWS; j++) {
            arr[i * ROWS + j] = matrix[j][i];
        }
    }
    bubbleSort(arr, SIZE);
    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < ROWS; j++) {
            matrix[j][i] = arr[i * ROWS + j];
        }
    }
    return;
}

void menu(int matrix[ROWS][COLS]) {
    do {
        int choice = getChoice();

        switch (choice) {
            case 1: { // Randomly regenerate the matrix
                fillMatrixRandom(matrix);
                break;
            }
            case 2: { // Sort all rows
                sortAllRows(matrix);
                break;
            }
            case 3: { // Sort all columns
                sortAllCols(matrix);
                break;
            }
            case 4: { // Sort the entire matrix by rows
                sortEntireMatrixByRows(matrix);
                break;
            }
            case 5: { // Sort the entire matrix by columns
                sortEntireMatrixByCols(matrix);
                break;
            }
            case 6: { // Print the matrix
                printMatrix(matrix);
                break;
            }
            case 0: { // Exit
                return;
            }
            default: { // Invalid choice
                cout << "Scelta non valida" << endl;
                break;
            }
        }
    } while (true);
}

int main() {
    srand(time(NULL));

    int matrix[ROWS][COLS];

    menu(matrix);

    return 0;
}