#include <iostream>

using namespace std;

int main() {
    double side1, side2;
    do {
        cout << "Inserire il lato 1: ";
        cin >> side1;

        if (side1 <= 0)
            cout << "Il lato deve essere maggiore di 0\n";
        else
            break;
    } while (true);

    do {
        cout << "Inserire il lato2: ";
        cin >> side2;

        if (side2 <= 0)
            cout << "Il lato deve essere maggiore di 0\n";
        else
            break;
    } while (true);


    double perimeter = 2 * (side1 + side2);
    double area = side1 * side2;

    cout << "\nPerimetro: " << perimeter;
    cout << "\nArea: " << area;
}