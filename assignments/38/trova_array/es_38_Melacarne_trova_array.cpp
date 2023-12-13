#include <iostream>
#include <array>
#include <optional>

using namespace std;

constexpr int CAPACITY = 10;

array<int, CAPACITY> getArrayFromUser() {
    array<int, CAPACITY> arr{};
    for (int i = 0; i < CAPACITY; i++) {
        cout << "Inserisci il numero in posizione " << i << ": ";
        cin >> arr[i];
    }
    return arr;
}

int getNumberToSearch() {
    int n;
    cout << "Inserisci il numero da cercare: ";
    cin >> n;
    return n;
}

optional<int> getPositionOfNumber(const array<int, CAPACITY> &arr, const int &n) {
    for (int i = 0; i < CAPACITY; i++) {
        if (arr[i] == n) {
            return i;
        }
    }
    return nullopt;
}

int main() {
    srand(time(nullptr));

    array<int, CAPACITY> arr = getArrayFromUser();

    int n = getNumberToSearch();

    optional<int> position = getPositionOfNumber(arr, n);

    if (position.has_value()) {
        cout << "Il numero " << n << " si trova in posizione " << position.value() << endl;
    } else {
        cout << "Il numero " << n << " non si trova nell'array" << endl;
    }

    return 0;
}