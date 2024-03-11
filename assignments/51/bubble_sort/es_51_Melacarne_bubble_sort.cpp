#include <iostream>
#include <array>

using namespace std;

array<int, 100> get_random_array() {
    array<int, 100> arr;
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = rand() % 100 + 1;
    }
    return arr;
}

void bubble_sort(array<int, 100> &arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = 0; j < arr.size() - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void print_array(const array<int, 100> &arr) {
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
    array<int, 100> arr = get_random_array();

    cout << "Array prima dell'ordinamento: ";
    print_array(arr);

    bubble_sort(arr);
    cout << "Array dopo l'ordinamento: ";
    print_array(arr);

    return 0;
}