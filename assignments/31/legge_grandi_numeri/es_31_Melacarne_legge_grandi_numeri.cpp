#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

constexpr int FACES = 6;


int main() {
    srand(time(nullptr));

    cout << "Inserisci il numero di generazioni: ";
    int n;
    cin >> n;

    int arr[FACES] = {0};

    for (int i = 0; i < n; i++) {
        int randN = rand() % FACES;

        arr[randN]++;
    }

    for (int i = 0; i < FACES; i++) {
        cout << i + 1 << " = " << arr[i] << "\n";
    }

    return 0;
}