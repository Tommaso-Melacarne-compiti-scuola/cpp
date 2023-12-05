#include <iostream>
#include <array>

using namespace std;

constexpr int N = 10;


array<int, N> getArray() {
    array<int, N> arr{};
    for(int i = 0; i < N; i++) {
        cout << "Inserisci il " << i << "° numero: ";
        cin >> arr[i];
    }
    return arr;
}

void printArrayReverse(array<int, N> arr) {
    for(int i = N - 1; i >= 0; i--) {
        cout << arr[i] << "\n";
    }
}

int main() {
    array<int, N> numbers = getArray();
    printArrayReverse(numbers);

    return 0;
}