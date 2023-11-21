#include <iostream>
#include <array>

using namespace std;

constexpr int MAX = 10000;
constexpr int MAX_DIV = 64; // Maximum number of divisors for 10000

// Returns a number between 1 and MAX
int getNumber() {
    int n;
    do {
        cout << "Inserisci un numero: ";

        cin >> n;
        if (n > MAX) {
            cout << "Il numero deve essere minore di " << MAX << endl;
        } else {
            return n;
        }
    } while (true);
}

// Returns n's divisors
constexpr array<int, MAX_DIV> getDivisors(const int &n) {
    array<int, MAX_DIV> divisors{0};
    int *cursor = &divisors[0];

    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            *cursor = i;
            cursor++; // This
        }
    }
    return divisors;
}

// Prints an array till the first 0
void printArr(const array<int, MAX_DIV> &arr) {
    for (int i = 0; i < MAX_DIV; i++) {
        if (arr[i] == 0)
            break;
        cout << i + 1 << ": " << arr[i] << "\n";
    }
}

int main() {
    int n = getNumber();
    array<int, MAX_DIV> divisors = getDivisors(n);

    cout << "I divisori di " << n << " sono:\n";
    printArr(divisors);

    return 0;
}