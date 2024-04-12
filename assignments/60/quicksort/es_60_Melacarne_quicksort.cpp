#include <iostream>
#include <array>

using namespace std;

constexpr int CAPACITY = 10;

template<size_t size>
void printArray(const array<int, size> arr) {
    cout << "[";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

template<size_t size>
int partition(array<int, size> &arr, int s, int e) {
    int pivotIndex = s;
    int pivot = arr[s];
    cout << "Pivot: " << pivot << "\nIndice Pivot: " << pivotIndex << endl;
    while (s < e) {
        while (arr[s] <= pivot) {
            s++;
        }
        while (arr[e] > pivot) {
            e--;
        }
        if (s < e) {
            cout << "Scambio " << arr[s] << " (idx: " << s << ") con " << arr[e] << " (idx: " << e << ")" << "\n";
            swap(arr[s], arr[e]);
        }
    }
    cout << "Scambio " << arr[pivotIndex] << " (idx: " << pivotIndex << ") con " << arr[e] << " (idx: " << e
         << ") (nuovo q)\n";
    swap(arr[pivotIndex], arr[e]);
    return e;
}

template<size_t size>
void quickSort(array<int, size> &arr, const int s, const int e) {
    if (s < e) {
        cout << "Chiamata ricorsiva con s: " << s << " e e: " << e << "\nVettore: ";
        printArray(arr);
        int q = partition(arr, s, e);
        quickSort(arr, s, q - 1);
        quickSort(arr, q + 1, e);
    }
}

template<size_t size>
array<int, size> getRandomArray() {
    array<int, CAPACITY> arr{};
    for (int &i: arr) {
        i = rand() % 100;
    }
    return arr;
}

int main() {
    srand(time(nullptr));

    array<int, CAPACITY> arr = getRandomArray<CAPACITY>();

    cout << "Array prima dell'ordinamento: ";
    printArray(arr);

    quickSort(arr, 0, arr.size() - 1);

    cout << "Array dopo l'ordinamento: ";
    printArray(arr);

    return 0;
}