#include <iostream>

using namespace std;

int main() {
    int n;
    double sum = 0;

    do {
        cout << "Inserisci il numero di numeri che vuoi sommare: ";
        cin >> n;

        if (n < 0)
            cout << "Il numero di numeri da sommare non puo' essere negativo!\n";
        else
            break;
    } while (true);

    for (int i = 0; i < n; i++) {
        double num;
        cout << "Inserisci il numero " << i << ": ";
        cin >> num;

        sum += num;
    }

    cout << "La somma e': " << sum << "\n";

    return 0;
}