#include <iostream>
#include <array>

using namespace std;

constexpr int N = 10000;
constexpr char ASTERISK = '*';

int getNumberOfNumbers() {
    int n;
    do {
        cout << "Inserisci il numero di numeri: ";
        cin >> n;
    } while (n < 1 || n > N);
    return n;
}

array<int, N> getArray(int logicSize) {
    array<int, N> arr{};
    for (int i = 0; i < logicSize; i++) {
        cout << "Inserisci il " << i << "° numero: ";
        cin >> arr[i];
    }
    return arr;
}

void printAsterisks(int n) {
    for (int i = 0; i < n; i++) {
        cout << ASTERISK;
    }
}

void printArrayAsAsterisks(array<int, N> arr, int logicSize) {
    for (int i = 0; i < logicSize; i++) {
        cout << "vetA[" << i << "]: ";
        printAsterisks(arr[i]);
        cout << "\n";
    }
}

int main() {
    int logicSize = getNumberOfNumbers();

    array<int, N> arr = getArray(logicSize);

    printArrayAsAsterisks(arr, logicSize);

    return 0;
}