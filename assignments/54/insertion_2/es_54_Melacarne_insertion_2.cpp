#include <iostream>
#include <array>

using namespace std;

constexpr int CAPACITY = 30;
constexpr int MAX = 20;

int getRandom() {
    return rand() % (MAX * 2) - MAX;
}

void shiftRight(array<int, CAPACITY> &arr, const int len, const int idx) {
    for (int i = len - 1; i > idx; i--) {
        arr[i] = arr[i - 1];
    }
    return;
}

void orderedInsert(array<int, CAPACITY> &arr, int &len, const int n) {
    for (int i = 0; i < len; i++) {
        if (n < arr[i]) {
            len++;
            shiftRight(arr, len, i);
            arr[i] = n;
            return;
        }
    }
    arr[len] = n;
    len++;
    return;
}

void insertNumbers(array<int, CAPACITY> &arr, int &len) {
    for (int i = 0; i < CAPACITY; i++) {
        int n = getRandom();
        orderedInsert(arr, len, n);
    }
    return;
}

void printArray(const array<int, CAPACITY> &arr, const int len) {
    cout << "[";
    for (int i = 0; i < len - 1; i++) {
        cout << arr[i] << ", ";
    }
    cout << arr[len - 1] << "]" << endl;
    return;
}

int main() {
    array<int, CAPACITY> arr;
    int len = 0;

    insertNumbers(arr, len);

    cout << "Array: ";
    printArray(arr, len);

    return 0;
}