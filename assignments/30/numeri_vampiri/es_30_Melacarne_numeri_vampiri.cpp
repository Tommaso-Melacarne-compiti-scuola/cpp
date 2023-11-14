#include <iostream>
#include <array>
#include <optional>

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

bool checkFang(int fang, const array<int, 4> &n) {
    for (int digit: n) {
        if (fang % 10 == digit) {
            fang /= 10;
        } else {
            return false;
        }
    }
    return true;
}

int factorial(const int n) {
    long factor = 1;
    for (int i = 1; i <= n; ++i)
        factor *= i;
    return (int) factor;
}

optional<tuple<int, int>> getFang(const array<int, 4> &n, const int &nInt) {
    int fang1, fang2;
    int runs = (int) n.size();

    for (int i = 0; i < runs; i++) {
        for (int j = 0; j < runs; j++) {
            fang1 = n[i] * 10 + n[j];
            cout << "fang1: " << fang1 << endl;
            fang2 = n[(i + 1) % n.size()] * 10 + n[(j + 1) % n.size()];
            cout << "fang2: " << fang2 << endl;
            cout << "--" << endl;
            if (fang1 * fang2 == nInt
                && checkFang(fang1, n)
                && checkFang(fang2, n)
                && fang1 != fang2) {
                cout << fang1 << " * " << fang2 << " = " << nInt << endl;
                return make_tuple(fang1, fang2);
            }
        }
    }
    return nullopt;
}

int factorial(unsigned long n) {

}

bool isVampire(const array<int, 4> &n, const int &nInt) {
    return getFang(n, nInt).has_value();
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