#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>


using namespace std;

const int CAPACITY = 10000;

void printArray(const array<int, CAPACITY> &arr, const int &length) {
    for (int i = 0; i < length; i++) {
        if (arr[i] == 0) {
            break;
        }
        cout << i << ": " << arr[i] << endl;
    }
    cout << endl;
}

void freeIdxByShiftingRight(array<int, CAPACITY> &arr, const int &idx, const int &length) {
    for (int i = length; i > idx; i--) {
        arr[i] = arr[i - 1];
    }
}

void appendToArrayInOrder(array<int, CAPACITY> &arr, const int &n, int &length) {
    int i = 0;
    while (arr[i] < n && i < length) {
        i++;
    }

    freeIdxByShiftingRight(arr, i, length);
    arr[i] = n;
    length++;
}

int getNumberOfNumbersToInsert() {
    int n;
    cout << "Inserisci il numero dei numeri che vuoi inserire: ";
    cin >> n;
    return n;
}

int main() {
    srand(time(nullptr));
    int length = 0;

    array<int, CAPACITY> numbers{};

    int n = getNumberOfNumbersToInsert();

    for (int i = 0; i < n; i++) {
        int randomNumber = rand() % 100;

        appendToArrayInOrder(numbers, randomNumber, length);
    }

    printArray(numbers, length);

    return 0;
}