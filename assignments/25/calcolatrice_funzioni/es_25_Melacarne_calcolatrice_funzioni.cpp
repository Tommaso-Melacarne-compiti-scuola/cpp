#include <iostream>

using namespace std;

double sum(double  a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    return a / b;
}

int menu() {
    int operation;
    cout << "Operazione da eseguire (0-4):"
         << "\n0. Esci"
         << "\n1. Addizione"
         << "\n2. Sottrazione"
         << "\n3. Moltiplicazione"
         << "\n4. Divisione"
         << "\nOperazione: ";
    cin >> operation;

    return operation;
}

int main() {
    do {
        int operation = menu();

        double a, b;
        switch (operation) {
            case 0:
                return 0;
            case 1:
                cout << "Inserisci il primo addendo: ";
                cin >> a;
                cout << "Inserisci il secondo addendo: ";
                cin >> b;
                a = sum(a, b);
                break;
            case 2:
                cout << "Inserisci il minuendo: ";
                cin >> a;
                cout << "Inserisci il sottraendo: ";
                cin >> b;
                a = subtract(a, b);
                break;
            case 3:
                cout << "Inserisci il primo fattore: ";
                cin >> a;
                cout << "Inserisci il secondo fattore: ";
                cin >> b;
                a = multiply(a, b);
                break;
            case 4:
                cout << "Inserisci il dividendo: ";
                cin >> a;
                cout << "Inserisci il divisore: ";
                cin >> b;
                a = divide(a, b);
                break;
        }

        if (system("CLS")) system("clear");

        cout << "Il risultato è: " << a << "\n\n";

    } while (true);
}


