#include <iostream>
#include <array>

using namespace std;

constexpr int CAPACITY = 10;

void readArrayNoDuplicates(array<int, CAPACITY> &arr) {
    for (int i = 0; i < CAPACITY; i++) {
        int tmp = rand() % 10;
        for (int j = 0; j < i; j++) {
            if (arr[j] == tmp) {
                i--;
                break;
            } else {
                arr[i] = tmp;
            }
        }
    }
}

void printArray(const array<int, CAPACITY> &arr) {
    for (int i = 0; i < CAPACITY; i++) {
        cout << i << ": " << arr[i] << "\n";
    }
    cout << "\n";
}

int main() {
    srand(time(nullptr));
    array<int, CAPACITY> numbers{};

    readArrayNoDuplicates(numbers);

    printArray(numbers);

    return 0;
}