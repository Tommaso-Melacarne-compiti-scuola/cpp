#include <iostream>

using namespace std;

int main() {
    int n;
    double max = 0;

    do {
        cout << "Inserisci il numero di numeri di cui vuoi trovare il massimo: ";
        cin >> n;

        if (n < 0)
            cout << "Il numero di numeri di cui trovare il massimo non puo' essere negativo!\n";
        else
            break;
    } while (true);

    for (int i = 0; i < n; i++) {
        double num;
        cout << "Inserisci il numero " << i << ": ";
        cin >> num;

        if (num > max)
            max = num;
    }

    cout << "La somma e': " << max << "\n";

    return 0;
}