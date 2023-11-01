#include <iostream>

using namespace std;

int main() {
    const int n_multiples = 12;

    int n;
    cout << "Inserisci un numero: ";
    cin >> n;

    for (int i = 1; i <= n_multiples; i++) {
        cout << n << " * " << i << " = " << n * i << "\n";
    }

    return 0;
}