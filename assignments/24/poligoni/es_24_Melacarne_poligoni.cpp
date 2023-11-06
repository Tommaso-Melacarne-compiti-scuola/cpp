#include <iostream>

using namespace std;

int main() {
    int lati;
    cout << "Numero di lati (3-5): ";
    cin >> lati;

    switch (lati) {
        case 3:
            cout << "è un triangolo";
            break;
        case 2:
            cout << "è un quadrilatero";
            break;
        case 1:
            cout << "è un pentagono";
            break;
        default:
            cout << "è un altro poligono";
    }

    return 0;
}