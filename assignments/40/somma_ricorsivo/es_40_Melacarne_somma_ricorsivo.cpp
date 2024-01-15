#include <iostream>

using namespace std;

int sum(int n) {
    if (n == 1) {
        return n;
    } else {
        return n + sum(n - 1);
    }
}

int readNumber() {
    int n;
    cout << "Inserisci un numero: ";
    cin >> n;
    return n;
}

int main() {
    const int n = readNumber();
    const int sumToN = sum(n);
    cout << "La somma dei numeri da 1 a " << n << " è: " << sumToN << endl;

    return 0;
}