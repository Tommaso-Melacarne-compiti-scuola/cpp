#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>

using namespace std;

constexpr int CAPACITY = 1000;

int printMenuAndGetOption() {
    int option;
    cout << "1) Scegli la lunghezza di un array e lo riempi con numeri casuali\n"
            "2) Scegli la lunghezza di un array e lo riempi con numeri inseriti dall'utente\n"
            "3) Stampa l'array\n"
            "4) Stampa il minore nell'array\n"
            "5) Stampa il maggiore nell'array\n"
            "6) Stampa la media degli elementi\n"
            "7) Stampa il numero che si ripete più volte indicando quante volte si ripete\n"
            "8) Fai lo shift a destra a partire da una posizione scelta dall'utente\n"
            "9) Fai lo shift a sinistra a partire da una posizione scelta dall'utente\n"
            "0) Esci\n"
            "Scegli un'opzione: ";
    cin >> option;
    return option;
}

int getArrLength() {
    do {
        int arrLength;
        cout << "Inserisci la lunghezza dell'array: ";
        cin >> arrLength;
        if (arrLength > 0) {
            return arrLength;
        }
        cout << "La lunghezza deve essere maggiore di 0\n";
    } while (true);
}


void fillWithRandomNumbers(array<int, CAPACITY> &arr, int &arrLength) {
    for (int i = 0; i < arrLength; i++) {
        arr[i] = rand() % 100;
    }
}

void fillWithUserInput(array<int, CAPACITY> &arr, int &arrLength) {
    for (int i = 0; i < arrLength; i++) {
        cout << "Inserisci il numero in posizione " << i << ": ";
        cin >> arr[i];
    }
}

void printArray(const array<int, CAPACITY> &arr, const int &arrLength) {
    for (int i = 0; i < arrLength; i++) {
        cout << i << ": " << arr[i] << endl;
    }
    cout << endl;
}

void printMin(const array<int, CAPACITY> &arr, const int &arrLength) {
    int min = arr[0];
    for (int i = 1; i < arrLength; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    cout << "Il minimo è: " << min << endl;
}

void printMax(const array<int, CAPACITY> &arr, const int &arrLength) {
    int max = arr[0];
    for (int i = 1; i < arrLength; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    cout << "Il massimo è: " << max << endl;
}

void printAverage(const array<int, CAPACITY> &arr, const int &arrLength) {
    int sum = 0;
    for (int i = 0; i < arrLength; i++) {
        sum += arr[i];
    }
    const double avg = (double) sum / arrLength;
    cout << "La media è: " << avg << endl;
}

void printMostRepeatedNumber(const array<int, CAPACITY> &arr, const int &arrLength) {
    int mostRepeatedNumber = arr[0];
    int mostRepeatedNumberCount = 0;
    for (int i = 0; i < arrLength; i++) {
        int currentNumber = arr[i];
        int currentNumberCount = 0;
        for (int j = 0; j < arrLength; j++) {
            if (arr[j] == currentNumber) {
                currentNumberCount++;
            }
        }
        if (currentNumberCount > mostRepeatedNumberCount) {
            mostRepeatedNumber = currentNumber;
            mostRepeatedNumberCount = currentNumberCount;
        }
    }
    cout << "Il numero che si ripete più volte è: " << mostRepeatedNumber << " e si ripete " << mostRepeatedNumberCount
         << " volte" << endl;
}

int getShiftStartIdx(const int &arrLength) {
    int shiftStartIdx;
    do {
        cout << "Inserisci l'indice da cui vuoi fare lo shift: ";
        cin >> shiftStartIdx;
    } while (shiftStartIdx < 0 || shiftStartIdx >= arrLength);
    return shiftStartIdx;
}

void shiftRight(array<int, CAPACITY> &arr, const int &arrLength, const int &shiftStartIdx) {
    for (int i = arrLength - 1; i >= shiftStartIdx; i--) {
        arr[i + 1] = arr[i];
    }
}

void shiftLeft(array<int, CAPACITY> &arr, const int &arrLength, const int &shiftStartIdx) {
    for (int i = shiftStartIdx; i < arrLength; i++) {
        arr[i] = arr[i + 1];
    }
}

int main() {
    srand(time(nullptr));
    array<int, CAPACITY> arr{};
    int arrLength = 0;

    do {
        const int option = printMenuAndGetOption();
        if (arrLength == 0 && option > 2) {
            cout << "ATTENZIONE: l'array non è stato riempito con numeri casuali o con numeri inseriti dall'utente\n";
        }

        switch (option) {
            case 0:
                return 0;
            case 1:
                arrLength = getArrLength();
                fillWithRandomNumbers(arr, arrLength);
                break;
            case 2:
                arrLength = getArrLength();
                fillWithUserInput(arr, arrLength);
                break;
            case 3:
                printArray(arr, arrLength);
                break;
            case 4:
                printMin(arr, arrLength);
                break;
            case 5:
                printMax(arr, arrLength);
                break;
            case 6:
                printAverage(arr, arrLength);
                break;
            case 7:
                printMostRepeatedNumber(arr, arrLength);
                break;
            case 8:
                shiftRight(arr, arrLength, getShiftStartIdx(arrLength));
                break;
            case 9:
                shiftLeft(arr, arrLength, getShiftStartIdx(arrLength));
                break;
            default:
                cout << "Opzione non valida" << endl;
                break;
        }
    } while (true);
}