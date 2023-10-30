#include <iostream>

using namespace std;

int main() {
    int min = 0;

    while (true) {
        int n;
        cout << "Inserisci un numero: ";
        cin >> n;

        if (n == 0) {
            break;
        }

        if (n < min || min == 0) {
            min = n;
        }
    }

    cout << "Il minimo è " << min << "\n";

    return 0;
}