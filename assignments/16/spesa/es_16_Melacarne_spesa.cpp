#include <iostream>

using namespace std;

int main() {
    double spesa;

    do {
        cout << "Inserisci la spesa non scontata: ";
        cin >> spesa;

        if (spesa < 0)
            cout << "La spesa non puo' essere negativa!\n";
        else
            break;
    } while (true);

    if (spesa > 50)
        spesa *= .95;
    else
        spesa *= .9;

    cout << "La spesa scontata e': " << spesa << "\n";

    return 0;
}