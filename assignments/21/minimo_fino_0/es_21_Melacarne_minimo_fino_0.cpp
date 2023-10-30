#include <iostream>

using namespace std;

int main() {
    int min = 0;

    while (true) {
        int n;
        cout << "Inserisci un numero: ";
        cin >> n;

        if (n < min) {
            min = n;
        } else {
            break;
        }
    }

    cout << "Il minimo è " << min << "\n";

    return 0;
}