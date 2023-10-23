#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a, b, c, delta;

    cout << "Inserisci a: ";
    cin >> a;

    cout << "Inserisci b: ";
    cin >> b;

    cout << "Inserisci c: ";
    cin >> c;

    delta = pow(b, 2) - 4 * a * c;

    if (delta < 0) {
        cout << "Equazione impossibile: delta negativo, x non appartiene all'insieme dei numeri reali.\n";
    } else if (delta == 0) {
        double x = -b / (2 * a);

        cout << "x = " << x << " DOPPIA\n";
    } else {
        double x1, x2, sqrtDelta = sqrt(delta);

        x1 = (-b + sqrtDelta) / (2 * a);
        x2 = (-b - sqrtDelta) / (2 * a);

        cout << "x1 = " << x1 << "\n";
        cout << "x2 = " << x2 << "\n";
    }

    return 0;
}