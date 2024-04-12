#include <iostream>
#include <array>

using namespace std;

template<size_t size>
int partition(array<int, size> &arr, int s, int e) {
    int pivotIndex = s;
    int pivot = arr[s];
    while (s < e) {
        while (arr[s] <= pivot) {
            s++;
        }
        while (arr[e] > pivot) {
            e--;
        }
        if (s < e) {
            swap(arr[s], arr[e]);
        }
    }
    swap(arr[pivotIndex], arr[e]);
    return e;
}

template<size_t size>
void quickSort(array<int, size> &arr, const int s, const int e) {
    if (s < e) {
        int q = partition(arr, s, e);
        quickSort(arr, s, q - 1);
        quickSort(arr, q + 1, e);
    }
}

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

int main() {
    array<int, 8> arr = {3, 7, 8, 5, 2, 1, 9, 5};

    cout << "Array prima dell'ordinamento: ";
    printArray(arr);

    quickSort(arr, 0, arr.size() - 1);

    cout << "Array dopo l'ordinamento: ";
    printArray(arr);

    return 0;
}