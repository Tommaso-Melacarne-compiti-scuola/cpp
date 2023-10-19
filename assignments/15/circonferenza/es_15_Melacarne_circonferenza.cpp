#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double radius;

    do {
        cout << "Inserire il raggio: ";
        cin >> radius;

        if (radius <= 0)
            cout << "Il raggio deve essere maggiore di 0" << endl;
        else
            break;
    } while (true);

    double area = M_PI * pow(radius, 2);
    double volume = (4 / 3) * M_PI * pow(radius, 3);

    cout << "\nL'area del cerchio è: " << area;
    cout << "\nIl volume della sfera con lo stesso raggio è: " << volume;
}