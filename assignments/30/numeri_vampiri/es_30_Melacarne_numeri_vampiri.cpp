#include <iostream>
#include <array>
#include <algorithm>
#include <optional>

using namespace std;

// Reads a 4-digit number from stdin
int readNumber() {
    do {
        cout << "Inserisci un numero (4 cifre): ";
        int n;
        cin >> n;
        if (n < 1000 || n > 9999) {
            cout << "Il numero deve avere 4 cifre" << endl;
        } else {
            return n;
        }
    } while (true);
}

// Returns an array of 4 digits from a 4-digit number
constexpr array<int, 4> numToArray(int n) {
    array<int, 4> digits{};
    for (int &digit: digits) {
        digit = n % 10;
        n /= 10;
    }
    return digits;
}

// Returns a tuple of the two fangs if the number is a vampire number, otherwise returns nullopt
constexpr optional<tuple<int, int>> isVampire(const array<int, 4> &digits, const int &n) {
    for (int i = 0; i < digits.size(); ++i) {
        for (int j = 0; j < digits.size(); ++j) {
            if (j != i) { // These if clauses avoid using the same digit twice
                for (int k = 0; k < digits.size(); ++k) {
                    if (k != i && k != j) {
                        for (int l = 0; l < digits.size(); ++l) {
                            if (l != i && l != j && l != k) {
                                int fang1 = digits[i] * 10 + digits[j];
                                int fang2 = digits[k] * 10 + digits[l];

                                if (n == fang1 * fang2) {
                                    return make_tuple(fang1, fang2);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return nullopt;
}

// Prints the fangs if the number is a vampire number, otherwise prints that the number is not a vampire number
void printVampire(const array<int, 4> &digits, const int &n) {
    auto fangs = isVampire(digits, n);
    if (fangs.has_value()) {
        cout << get<0>(fangs.value()) << " + " << get<1>(fangs.value()) << " = " << n << endl;
        cout << "Il numero è un numero vampiro" << endl;
    } else {
        cout << "Il numero non è un numero vampiro" << endl;
    }
}

int main() {
    int n = readNumber();
    array<int, 4> digits = numToArray(n);
    printVampire(digits, n);

    return 0;
}