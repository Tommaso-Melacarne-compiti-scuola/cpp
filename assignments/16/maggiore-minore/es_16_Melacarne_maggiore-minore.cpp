#include <iostream>

using namespace std;

int main() {
    double a, b;

    cout << "Inserisci il primo numero: ";
    cin >> a;
    cout << "Inserisci il secondo numero: ";
    cin >> b;

    if (a == b)
        cout << "I due numeri sono uguali\n";
    else if (a > b)
        cout << "Il maggiore e': " << a << "\n";
    else
        cout << "Il maggiore e': " << b << "\n";


    return 0;
}