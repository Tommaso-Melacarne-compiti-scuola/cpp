#include <iostream>
#include <array>

using namespace std;

constexpr int N = 10;

int getFillMenuOption() {
    int choice;
    do {
        cout << "Scegli un opzione:\n" <<
             "1) Riempi il vettore di numeri casuali\n" <<
             "2) Riempi il vettore manualmente\n" <<
             "Scelta: ";
        cin >> choice;

        if (choice < 1 || choice > 2) {
            cout << "Scelta non valida, riprova\n";
        } else {
            break;
        }
    } while (true);

    return choice;
}

array<int, N> manuallyFill() {
    array<int, N> arr{};

    for (int i = 0; i < N; i++) {
        cout << "Inserisci il " << i << "° numero: ";
        cin >> arr[i];
    }
    return arr;
}

array<int, N> randomFill() {
    array<int, N> arr{};

    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 100;
    }
    return arr;
}



int getOrderMenuOption() {
    int choice;
    do {
        cout << "Scegli un opzione:\n" <<
             "1) Ordinamento da sinistra a destra\n" <<
             "2) Ordinamento da destra a sinistra\n"
             "Scelta: ";
        cin >> choice;

        if (choice < 1 || choice > 2) {
            cout << "Scelta non valida, riprova\n";
        } else {
            break;
        }
    } while (true);

    return choice;
}

void printLeftToRightOrder(array<int, N> arr) {
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
}

void printRightToLeftOrder(array<int, N> arr) {
    for (int i = N - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
}

int main() {
    array<int, N> arr{};

    switch (getFillMenuOption()) {
        case 1:
            arr = randomFill();
            break;
        case 2:
            arr = manuallyFill();
            break;
        default:
            __builtin_unreachable(); // Hint the compiler that this is unreachable
    }

    switch (getOrderMenuOption()) {
        case 1:
            printLeftToRightOrder(arr);
            break;
        case 2:
            printRightToLeftOrder(arr);
            break;
        default:
            __builtin_unreachable();
    }

    return 0;
}