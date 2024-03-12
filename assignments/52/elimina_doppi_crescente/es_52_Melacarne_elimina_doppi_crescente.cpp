#include <iostream>
#include <array>

using namespace std;

constexpr int SIZE = 30;
constexpr int MAX = 100;

array<int, SIZE> getRandomArray() {
    array<int, SIZE> arr;

    for (auto &e: arr) {
        e = rand() % MAX;
    }

    return arr;
}

void deleteLessThan(array<int, SIZE> &arr) {
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = i + 1; j < SIZE; j++) {
            if (arr[i] == arr[j]) {
                arr[i] = 0;
            }
        }
    }
}

void sortArray(array<int, SIZE> &arr) {
    for (int i = 0; i < SIZE - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swapped = true;
                swap(arr[j], arr[j + 1]);
            }
        }
        if (!swapped) {
            break;
        }
    }
}

void printArray(const array<int, SIZE> &arr) {
    int firstIdx;

    for (int i = 0; i < SIZE; i++) {
        if (arr[i] != 0) {
            firstIdx = i;
            break;
        }
    }

    cout << "[";
    for (int i = firstIdx; i < SIZE - 1; i++) {
        cout << arr[i] << ", ";
    }
    cout << arr[SIZE - 1] << "]" << endl;
}

int main() {
    array<int, SIZE> arr = getRandomArray();

    deleteLessThan(arr);

    sortArray(arr);

    printArray(arr);

    return 0;
}