#include <array>
#include <chrono>
#include <iostream>

using namespace std;

constexpr int CAPACITY = 10000;
constexpr int MAX = 100000;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
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

void fillArray(array<int, CAPACITY> &arr) {
    for (auto &el: arr) {
        el = rand() % MAX;
    }
}

int getNumber() {
    cout << "Inserisci un numero: ";
    int n;
    cin >> n;
    return n;
}

int binarySearch(int arr[], int lhs, int rhs, int x) {
    if (rhs >= lhs) {
        int mid = lhs + (rhs - lhs) / 2;

        if (arr[mid] == x) {
            return mid;
        }

        if (arr[mid] > x) {
            return binarySearch(arr, lhs, mid - 1, x);
        }

        return binarySearch(arr, mid + 1, rhs, x);
    }

    return -1;
}

int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    array<int, CAPACITY> arr{};

    fillArray(arr);

    bubbleSort(arr.data(), arr.size());

    printArray(arr.data(), arr.size());

    int n = getNumber();

    auto start = chrono::high_resolution_clock::now();
    int idxBin = binarySearch(arr.data(), 0, arr.size() - 1, n);
    auto end = chrono::high_resolution_clock::now();
    auto durationBin = chrono::duration_cast<chrono::nanoseconds>(end - start);

    start = chrono::high_resolution_clock::now();
    int idxLin = linearSearch(arr.data(), arr.size(), n);
    end = chrono::high_resolution_clock::now();
    auto durationLin = chrono::duration_cast<chrono::nanoseconds>(end - start);

    if (idxBin != -1) {
        cout << "Il numero " << n << " è stato trovato alla posizione " << idxBin
             << " con la ricerca binaria" << endl;
    } else {
        cout << "Il numero " << n << " non è stato trovato con la ricerca binaria"
             << endl;
    }

    if (idxLin != -1) {
        cout << "Il numero " << n << " è stato trovato alla posizione " << idxLin
             << " con la ricerca lineare" << endl;
    } else {
        cout << "Il numero " << n << " non è stato trovato con la ricerca lineare"
             << endl;
    }

    cout << "Tempo impiegato da una ricerca binaria: " << durationBin.count()
         << "ns" << endl;
    cout << "Tempo impiegato da una ricerca lineare: " << durationLin.count()
         << "ns" << endl;

    return 0;
}
