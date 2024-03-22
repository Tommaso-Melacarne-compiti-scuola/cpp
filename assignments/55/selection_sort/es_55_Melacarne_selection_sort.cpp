#include <iostream>
#include <array>

using namespace std;


constexpr int SIZE = 10000;
constexpr int MAX = 10000;

array<int, SIZE> getArr() {
    array<int, SIZE> arr{};
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % MAX;
    }
    return arr;
}

// Finds the index of the smallest element in the array
int findSmallestIdx(array<int, SIZE> arr, int start, int end) {
    int minIdx = start;
    for (int i = start + 1; i < end; i++) {
        if (arr[i] < arr[minIdx]) {
            minIdx = i;
        }
    }
    return minIdx;
}

void selectionSort(array<int, SIZE> &arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        int minIdx = findSmallestIdx(arr, i, (int) arr.size());
        swap(arr[i], arr[minIdx]);
    }
}

void printArray(const array<int, SIZE> arr) {
    cout << "[";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main() {
    srand(time(nullptr));

    array<int, SIZE> arr = getArr();

    cout << "Array generato: ";
    printArray(arr);

    selectionSort(arr);

    cout << "Array ordinato: ";
    printArray(arr);

    return 0;
}