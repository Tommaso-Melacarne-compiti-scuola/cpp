#include <iostream>

using namespace std;

int main() {
    double a, b;

    cout << "Il valore 1 e': ";
    cin >> a;
    cout << "Il valore 2 e': ";
    cin >> b;

    bool order;
    cout << "Scrivi \"true\" se vuoi i numeri in ordine crescente, \"false\" se vuoi i numeri in ordine decrescente: ";
    cin >> order;


    double major, minor;
    if (a > b) {
        major = a;
        minor = b;
    } else {
        major = b;
        minor = a;
    }

    if (order) {
        cout << major << ", " << minor << "\n";
    } else {
        cout << minor << ", " << major << "\n";
    }


    return 0;
}