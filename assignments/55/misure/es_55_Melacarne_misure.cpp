#include <iostream>
#include <array>
#include <chrono>

using namespace std;

constexpr int MAX = 100;
constexpr array<int, 5>
        benchmarkSizes = {20, 50, 100, 500, 1000};

constexpr int maxOfArrLengths() {
    int max = 0;
    for (auto len: benchmarkSizes) {
        if (len > max) {
            max = len;
        }
    }
    return max;
}

constexpr int CAPACITY = maxOfArrLengths();


array<int, CAPACITY> getArr() {
    array<int, CAPACITY> arr{};
    for (auto &e: arr) {
        e = rand() % MAX;
    }
    return arr;
}

//void printArray(const array<int, CAPACITY> &arr, const int len) {
//    cout << "[";
//    for (int i = 0; i < len; i++) {
//        cout << arr[i] << ", ";
//    }
//    cout << arr[len - 1] << "]" << endl;
//}
//
//void printArrays(const array<int, CAPACITY> &arr) {
//    for (auto len: benchmarkSizes) {
//        cout << "Array di lunghezza " << len << ": " << endl;
//        printArray(arr, len);
//    }
//}

void bubbleSort(array<int, CAPACITY> &arr, const int len) {
    for (int i = 0; i < len - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < len - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

void insertionSort(array<int, CAPACITY> &arr, const int len) {
    for (int i = 1; i < len; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(array<int, CAPACITY> &arr, const int len) {
    for (int i = 0; i < len - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < len; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

void benchmarkSorts(array<int, CAPACITY> &arr) {
    // An array of function pointers to the sorting functions
    array<void (*)(array<int, CAPACITY> &, const int), 3> sortFns{
            bubbleSort,
            insertionSort,
            selectionSort
    };

    array<string, 3> sortNames{
            "Bubble Sort",
            "Insertion Sort",
            "Selection Sort"
    };

    // An array of arrays of integers to sort
    array<array<int, CAPACITY>, sortFns.size()> arrays{};
    arrays.fill(arr);


    for (auto len: benchmarkSizes) {
        cout << "Array di lunghezza " << len << "\n";
        for (int i = 0; i < sortFns.size(); i++) {
            auto start = chrono::high_resolution_clock::now();
            sortFns[i](arrays[i], len);
            auto end = chrono::high_resolution_clock::now();
            cout << "Tempo impiegato da " << sortNames[i] << ": ";
            cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "ns" << endl;
        }
    }
}


int main() {
    srand(time(nullptr));

    array<int, CAPACITY> unorderedArr = getArr();

//    cout << "Array non ordinati:\n";
//    printArrays(unorderedArr);

    benchmarkSorts(unorderedArr);


    return 0;
}