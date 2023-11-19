#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

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

array<int, 4> numToArray(int n) {
    array<int, 4> digits{};
    for (int &digit: digits) {
        digit = n % 10;
        n /= 10;
    }
    return digits;
}

bool isVampire(const array<int, 4> &n, const int &nInt) {
    array<int, 4> fangs{};

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (j != i) {
                for (int k = 0; k < 4; ++k) {
                    if (k != i && k != j) {
                        for (int l = 0; l < 4; ++l) {
                            if (l != i && l != j && l != k) {
                                fangs[0] = n[i] * 10 + n[j];
                                fangs[1] = n[k] * 10 + n[l];

                                if (nInt == fangs[0] * fangs[1]) {
                                    cout << fangs[0] << " * " << fangs[1] << " = " << nInt << endl;
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return false;
}

void printVampire(const array<int, 4> &n, const int &nInt) {
    if (isVampire(n, nInt)) {
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