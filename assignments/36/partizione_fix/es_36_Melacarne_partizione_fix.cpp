#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

const int MAX_ARRAY = 1000;

int leggiNum() {
    int n;
    do {
        cout << "Inserire il numero massimo degli elementi: ";
        cin >> n;
    } while (n < 0 || n > MAX_ARRAY);
    return n;
}

void generaArray(int v[], int n) {
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 10;         // 0 to 99
    }
}

void stampaArray(int v[], int n) {
    for (int i = 0; i < n; i++) {
        cout << v[i] << "\n";
    }
}

bool esisteInArray(int v[], int n, int cerca) {
    for (int i = 0; i < n; i++) {
        if (v[i] == cerca) {
            return true;
        }
    }
    return false;
}

int leggiNumeroCompresoInArray(int v[], int n) {
    int num_part;
    bool esiste = false;
    do {
        cout << "Inserire il numero da utilizzare per partizionare l'array ";
        cin >> num_part;
        esiste = esisteInArray(v, n, num_part);
        if (!esiste) {
            cout << "Numero non presente in array";
        }
    } while (!esiste);
    return num_part;
}

void partiziona(const int vInit[], int vPart[], int n, int numPart) {
    int nMinori = 0;
    for (int i = 0; i < n; i++) {
        if (vInit[i] <= numPart) nMinori++;
    }
    vPart[nMinori - 1] = numPart;
    bool trovatoUguale = false;
    int indiceMinori = 0, indiceMaggiori = nMinori;
    for (int i = 0; i < n; i++) {
        if (vInit[i] == numPart && !trovatoUguale) {
            trovatoUguale = true;
        } else if (vInit[i] <= numPart) {
            vPart[indiceMinori] = vInit[i];
            indiceMinori++;
        } else if (vInit[i] > numPart) {
            vPart[indiceMaggiori] = vInit[i];
            indiceMaggiori++;
        }
    }
}


int main() {
    srand(time(NULL)); //inizializzo il generatore di numeri casuali (da eseguire solo 1 volta)
    int lungLogica, numPart;
    int vInit[MAX_ARRAY];
    int vPart[MAX_ARRAY];

    lungLogica = leggiNum(); //leggo quanti numeri voglio generare
    generaArray(vInit, lungLogica);
    stampaArray(vInit, lungLogica);
    numPart = leggiNumeroCompresoInArray(vInit, lungLogica);
    partiziona(vInit, vPart, lungLogica, numPart);
    stampaArray(vPart, lungLogica);

}