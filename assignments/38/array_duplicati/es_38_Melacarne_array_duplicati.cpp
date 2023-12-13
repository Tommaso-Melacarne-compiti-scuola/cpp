#include <iostream>
#include <array>

using namespace std;

constexpr int CAPACITY = 10;

void readArray(array<int, CAPACITY> &arr) {
    for (int i = 0; i < CAPACITY; i++) {
        cout << "Inserisci il numero in posizione " << i << ": ";
        cin >> arr[i];
    }
}

void copyDuplicatesToArray(array<int, CAPACITY> &arr, array<int, CAPACITY> &duplicates, int &duplicateLength) {
    for (int i = 0; i < CAPACITY; i++) {
        for (int j = i + 1; j < CAPACITY; j++) {
            if (arr[i] == arr[j]) {
                duplicates[duplicateLength] = arr[i];
                duplicateLength++;
            }
        }
    }
}

void printArray(const array<int, CAPACITY> &arr, const int &length) {
    for (int i = 0; i < length; i++) {
        cout << i << ": " << arr[i] << endl;
    }
    cout << endl;
}


int main() {
    array<int, CAPACITY> numbers{};

    readArray(numbers);

    array<int, CAPACITY> duplicates{};
    int duplicateLength = 0;

    copyDuplicatesToArray(numbers, duplicates, duplicateLength);

    cout << "I numeri inseriti sono: \n";
    printArray(numbers, CAPACITY);

    cout << "I duplicati sono: \n";
    printArray(duplicates, duplicateLength);

    return 0;
}