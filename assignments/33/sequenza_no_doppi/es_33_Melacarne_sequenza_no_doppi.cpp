#include <iostream>
#include <array>

using namespace std;

constexpr int NUMBERS = 10;

int getNumber() {
    int n;
    cout << "Inserisci un numero: ";
    cin >> n;
    return n;
}

array<int, NUMBERS> run() {
    array<int, NUMBERS> numbersInserted{0};
    int cursor = 0;

    for (int i = 0; i < NUMBERS; i++) {
        int n = getNumber();

        bool toInsert = true;
        for (int number : numbersInserted) {
            if (number == n) {
                toInsert = false;
                break;
            }
        }

        // Append number
        if (toInsert) {
            numbersInserted[cursor] = n;
            cursor++;
        }
    }

    return numbersInserted;
}

void printArray(const array<int, NUMBERS> &arr) {
    for (int i = 0; i < NUMBERS; i++) {
        if (arr[i] == 0)
            break;
        cout << i << " = " << arr[i] << endl;
    }
}

int main() {
    const array<int, NUMBERS> arr = run();
    printArray(arr);

    return 0;
}