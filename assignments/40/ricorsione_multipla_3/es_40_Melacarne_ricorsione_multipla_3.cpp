#include <iostream>

using namespace std;

int getMenuOption() {
    int option;
    cout << "1) Massimo comune divisore\n"
            "2) Verifica se due numeri interi positivi sono primi tra loro\n"
            "3) Resto della divisione tra un intero positivo e un altro\n"
            "Scegli un'opzione: ";
    cin >> option;
    return option;
}


tuple<int, int> getTwoPositiveNumbers() {
    int a, b;
    while (true) {
        cout << "Inserisci il primo numero: ";
        cin >> a;
        if (a > 0) {
            break;
        }
        cout << "Il numero deve essere positivo\n";
    }
    while (true) {
        cout << "Inserisci il secondo numero: ";
        cin >> b;
        if (b > 0) {
            break;
        }
        cout << "Il numero deve essere positivo\n";
    }
    return make_tuple(a, b);
}


int gcd(int a, int b) {
    if (a == b || b == 0) {
        return a;
    }
    if (a == 0) {
        return b;
    }
    if (a > b) {
        return gcd(a - b, b);
    }
    return gcd(a, b - a);
}

int areCoprime(int a, int b) {
    if (gcd(a, b) == 1) {
        return true;
    }
    return false;
}

int remainder(int a, int b) {
    if (a < b) {
        return a;
    }
    return remainder(a - b, b);
}

void GCDMenuOption() {
    const auto [a, b] = getTwoPositiveNumbers();

    const int gcdResult = gcd(a, b);
    cout << "Il massimo comune divisore tra " << a << " e " << b << " è: " << gcdResult << endl;
}

void coprimeBetweenMenuOption() {
    const auto [a, b] = getTwoPositiveNumbers();

    const bool coprimeResult = areCoprime(a, b);
    if (coprimeResult) {
        cout << a << " e " << b << " sono primi tra loro" << endl;
    } else {
        cout << a << " e " << b << " non sono primi tra loro" << endl;
    }
}

void remainderMenuOption() {
    const auto [a, b] = getTwoPositiveNumbers();

    const int remainderResult = remainder(a, b);
    cout << "Il resto della divisione tra " << a << " e " << b << " è: " << remainderResult << endl;
}


int main() {
    const int option = getMenuOption();
    switch (option) {
        case 1:
            GCDMenuOption();
            break;
        case 2:
            coprimeBetweenMenuOption();
            break;
        case 3:
            remainderMenuOption();
            break;
        default:
            cout << "Opzione non valida" << endl;
    }

    return 0;
}