#include <iostream>
#include <array>

using namespace std;

constexpr int N = 10;

array<int, N> getRandomArray() {
    array<int, N> arr{};
    for (auto &e: arr) {
        e = rand() % 99 + 1;
    }
    return arr;
}

void printArray(array<int, N> arr) {
    for (auto &e: arr) {
        cout << e << "\n";
    }
}

void partition(array<int, N> &arr) {
    int pivotIdx = rand() % N;
    int pivotValue = arr[pivotIdx];

    cout << "Elemento pivot: " << pivotValue << "\n";

    array<int, N> res{};

    int minorCursor = 0;
    int majorCursor = N - 1;

    // Fills the array with the elements minor and major than the pivot
    for (const auto &e: arr) {
        if (e < pivotValue) {
            res[minorCursor] = e;
            minorCursor++;
        } if (e > pivotValue) {
            res[majorCursor] = e;
            majorCursor--;
        }
    }

    // Fills the array with the elements equal to the pivot
    for (int i = minorCursor; i <= majorCursor; i++) {
        res[i] = pivotValue;
    }

    arr = res;
}

int main() {
    srand(time(nullptr));
    array<int, N> numbers = getRandomArray();

    cout << "Array prima della partizione: \n";
    printArray(numbers);

    partition(numbers);

    cout << "Array dopo la partizione: \n";
    printArray(numbers);

    return 0;
}