#include <iostream>

using namespace std;

int main() {

    int n;
    cout << "Inserisci un numero: ";
    cin >> n;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += i;
    }
    cout << "Il doppio della somma dei primi " << n << " numeri è: " << sum * 2 << "\n";

    return 0;
}