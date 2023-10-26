#include <iostream>

using namespace std;

const int finalSum = 200;

int main() {

    int sum = 0;
    int i = 0;
    for (; sum < finalSum; i++) {
        cout << "Inserisci un numero: ";
        int n;
        cin >> n;
        sum += n;
    }
    cout << "Il numero dei numeri inseriti è stato: " << i << "\n";

    return 0;
}