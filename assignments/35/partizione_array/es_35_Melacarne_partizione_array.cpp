#include <iostream>
#include <array>

using namespace std;

constexpr int N = 10;

array<int, N> getRandomArray() {
    array<int, N> arr{};
    for (auto &e: arr) {
        e = rand() % 100;
    }
    return arr;
}

void printArray(array<int, N> arr) {
    for (auto &e: arr) {
        cout << e << "\n";
    }
}


int partition(int arr[], int start, int end)
{
    int pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }

    // Giving a pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    // Sorting left and right parts of the pivot element
    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) {
            i++;
        }

        while (arr[j] > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}


int main() {
    srand(time(nullptr));
    array<int, N> numbers = getRandomArray();

    cout << "Array prima della partizione: \n";
    printArray(numbers);

    int pivotBeginningPos = rand() % N;
    int pivot = numbers[pivotBeginningPos];
    cout << "Elemento casuale: " << pivot << "\n";

//    for (int i = 0; i < N; i++) {
//        if (numbers[i] < pivot) {
//            swap(numbers[i], pivot);
//        }
//    }

    cout << "Array dopo la partizione: \n";
    printArray(numbers);

    return 0;
}