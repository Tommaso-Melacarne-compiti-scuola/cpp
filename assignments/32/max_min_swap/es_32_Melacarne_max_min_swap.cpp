#include <iostream>
#include <cstdlib>
#include <ctime>
#include <array>

using namespace std;

constexpr int NUMS = 10;

// Returns a random array of size NUMS
array<int, NUMS> getRandomArray() {
    array<int, NUMS> arr{};
    for (int &i: arr) {
        i = rand() % 100;
    }
    return arr;
}

// Prints the array
void printArray(const array<int, NUMS> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << i << " = " << arr[i] << endl;
    }
}

// Swaps the max value with the min value
void swapMaxWithMin(array<int, NUMS> &arr) {
    int *pmax = nullptr;
    int *pmin = nullptr;

    for (int &i: arr) {
        if (pmax == nullptr || *pmax < i) {
            pmax = &i;
        }
        if (pmin == nullptr || *pmin > i) {
            pmin = &i;
        }
    }

    swap(*pmax, *pmin);
}

int main() {
    srand(time(nullptr));
    array<int, NUMS> array = getRandomArray();

    cout << "Array prima dello swap:\n";
    printArray(array);

    swapMaxWithMin(array);

    cout << "Array dopo lo swap:\n";
    printArray(array);

    return 0;
}