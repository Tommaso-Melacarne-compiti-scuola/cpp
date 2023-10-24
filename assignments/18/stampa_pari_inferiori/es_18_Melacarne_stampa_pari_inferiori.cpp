#include <iostream>

using namespace std;

int main() {
    int n;

    do {
        cout << "Inserisci un numero: ";
        cin >> n;

        if (n < 0)
            cout << "Il numero non puo' essere negativo!\n";
        else
            break;
    } while (true);

    cout << "I numeri pari inferiori a " << n << " sono:\n";

    for (int i = 0; i < n; i += 2) {
        cout << i << "\n";
    }

    return 0;
}