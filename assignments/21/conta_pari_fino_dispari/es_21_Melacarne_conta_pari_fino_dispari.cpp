#include <iostream>

using namespace std;

int main() {
    int count = 0;
    while (true) {
        int n;
        cout << "Inserisci un numero: ";
        cin >> n;

        if (n % 2 == 0) {
            count++;
        } else {
            break;
        }
    }

    cout << "Hai inserito " << count << " numeri pari.\n";

    return 0;
}