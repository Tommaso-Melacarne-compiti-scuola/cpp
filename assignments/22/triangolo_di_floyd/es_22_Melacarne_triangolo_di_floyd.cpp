#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Inserisci un numero: ";
    cin >> n;

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            cout << " " << count;
            count++;
        }
        cout << "\n";
    }

    return 0;
}

