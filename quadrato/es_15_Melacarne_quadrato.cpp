#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double side;
    do {
        cout << "Inserire il lato: ";
        cin >> side;

        if (side <= 0)
            cout << "Il lato deve essere maggiore di 0\n";
        else
            break;
    } while (true);

    double perimeter = side * 4;
    double area = pow(side, 2);
    double volume = pow(side, 3);

    cout << "\nPerimetro: " << perimeter;
    cout << "\nArea: " << area;
    cout << "\nVolume: " << volume;
}