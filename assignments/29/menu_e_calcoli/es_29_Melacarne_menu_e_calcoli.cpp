#include <iostream>

using namespace std;

int readNumber() {
    int n;
    cout << "Inserisci un numero: ";
    cin >> n;
    return n;
}

void consecutiveEqual(int &consecutiveEqualCount) {
    int precedentN = 0;

    do {
        int n = readNumber();

        if (n == 0) {
            return;
        } else {
            if (n == precedentN) {
                consecutiveEqualCount++;
            }
            precedentN = n;
        }
    } while (true);
}

void secondDivisor(int &secondDivisorCount) {
    int precedentN = 0;

    do {
        int n = readNumber();

        if (n == 0) {
            return;
        } else {
            if (precedentN % n == 0) {
                secondDivisorCount++;
            }
            precedentN = n;
        }
    } while (true);
}

void printMessage(const int &consecutiveEqualCount, const int &secondDivisorCount) {
    if (consecutiveEqualCount == secondDivisorCount) {
        cout
                << "Ci sono lo stesso numero di coppie di numeri consecutivi uguali e coppie in cui il secondo numero è divisore del primo\n";
    } else if (consecutiveEqualCount > secondDivisorCount) {
        cout << "Ci sono più coppie di numeri consecutivi uguali\n";
    } else {
        cout << "Ci sono più coppie in cui il secondo numero è divisore del primo\n";
    }
}

void bothPairs(int &consecutiveEqualCount, int &secondDivisorCount) {
    int n = readNumber();
    if (n == 0) {
        return;
    }
    int precedentN = n;

    do {
        n = readNumber();

        if (n == 0) {
            return;
        } else {
            if (precedentN % n == 0) {
                secondDivisorCount++;
            }
            if (n == precedentN) {
                consecutiveEqualCount++;
            }
            precedentN = n;
        }
    } while (true);
}


int main() {
    int consecutiveEqualCount = 0, secondDivisorCount = 0;

    do {
        int scelta;
        cout << "Inserisci una delle opzioni del menu: \n"
             << "0. Esci dal programma \n"
             << "1. Calcolo del numero di coppie di numeri consecutivi uguali \n"
             << "2. Calcolo del numero di coppie in cui il secondo numero è divisore del primo\n"
             << "3. Visualizzazione di un messaggio che dica quale tipo di coppie tra le due tipologie indicate è presente un numero maggiore\n"
             << "4. Calcolo del numero di coppie in cui il secondo numero è divisore del primo OPPURE del numero di coppie di numeri consecutivi uguali\n"
             << "Scelta: ";
        cin >> scelta;

        switch (scelta) {
            case 0:
                return 0;
            case 1:
                consecutiveEqual(consecutiveEqualCount);
                break;
            case 2:
                secondDivisor(secondDivisorCount);
                break;
            case 3:
                printMessage(consecutiveEqualCount, secondDivisorCount);
                break;
            case 4:
                bothPairs(consecutiveEqualCount, secondDivisorCount);
                break;
            default:
                cout << "Scelta non valida, riprova\n";
                break;
        }
    } while (true);
}
