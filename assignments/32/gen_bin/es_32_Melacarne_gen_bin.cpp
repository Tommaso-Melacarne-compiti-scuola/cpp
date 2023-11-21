#include <iostream>
#include <array>

using namespace std;

constexpr int MAX = 255;
constexpr int ARR_SIZE = 8;


array<int, ARR_SIZE> getBinaryArray(int n) {
    array<int, ARR_SIZE> binArray{};

    for (int i = 0; i < ARR_SIZE; i++) {
        binArray[i] = n % 2;
        n /= 2;
    }

    return binArray;
}

void printBinaryArray(const array<int, ARR_SIZE> &arr) {
    for (int i = ARR_SIZE - 1; i >= 0; i--) {
        cout << arr[i];
    }
    cout << "\n";
}


int main() {
    srand(time(nullptr));
    int n = rand() % MAX;
    array<int, ARR_SIZE> binArray = getBinaryArray(n);

    cout << "Il numero " << n << " in binario è: ";
    printBinaryArray(binArray);

    return 0;
}