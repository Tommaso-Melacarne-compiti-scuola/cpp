#include <iostream>
#include <array>

using namespace std;

constexpr int SIZE = 30;
constexpr int MAX = 1000;

array<int, SIZE> getRandomArray() {
    array<int, SIZE> arr;

    for (auto &e: arr) {
        e = rand() % MAX;
    }

    return arr;
}

void sortArray(array<int, SIZE> &arr) {
    for (int i = 0; i < SIZE - 1; i++) {
        bool swapped = false;
        for (int j = i + 1; j < SIZE - i - 1; j++) {
            if (arr[i] > arr[j]) {
                swapped = true;
                swap(arr[i], arr[j]);
            }
        }
        if (!swapped) {
            break;
        }
    }
}

void printArray(const array<int, SIZE> &arr) {
    cout << "[";
    for (int i = 0; i < SIZE - 1; i++) {
        if (arr[i] % 2 == 0) {
            cout << arr[i] << ", ";
        }
    }
    cout << arr[SIZE - 1] << "]" << endl;
}

int main() {
    array<int, SIZE> arr = getRandomArray();

    sortArray(arr);
    printArray(arr);

    return 0;
}