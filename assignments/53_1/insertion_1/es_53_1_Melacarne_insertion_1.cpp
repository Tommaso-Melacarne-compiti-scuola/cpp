#include <iostream>
#include <array>

using namespace std;

constexpr int CAPACITY = 30;
constexpr int MAX = 20;

int getRandom() {
    return rand() % (MAX * 2) - MAX;
}

void shiftRight(array<int, CAPACITY> &arr, const int len, const int idx) {
    for (int i = len; i > idx; i--) {
        arr[i] = arr[i - 1];
    }
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

void insertNumbers(array<int, CAPACITY> &positive, array<int, CAPACITY> &negative,
                   int &positiveLen, int &negativeLen) {
    for (int i = 0; i < CAPACITY; i++) {
        int n = getRandom();
        if (n >= 0) {
            orderedInsert(positive, positiveLen, n);
        } else {
            orderedInsert(negative, negativeLen, n);
        }
    }
}

void printArray(const array<int, CAPACITY> &arr, const int len) {
    cout << "[";
    for (int i = 0; i < len - 1; i++) {
        cout << arr[i] << ", ";
    }
    cout << arr[len - 1] << "]" << endl;
}

int main() {
    array<int, CAPACITY> positive;
    array<int, CAPACITY> negative;
    int positiveLen = 0, negativeLen = 0;

    insertNumbers(positive, negative, positiveLen, negativeLen);

    cout << "Positivi: ";
    printArray(positive, positiveLen);

    cout << "Negativi: ";
    printArray(negative, negativeLen);

    return 0;
}