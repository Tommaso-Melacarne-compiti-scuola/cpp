#include <iostream>
#include <array>

using namespace std;


constexpr int CARS = 5;
const array<int, CARS> ages = {15, 18, 20, 17, 22};
const array<string, CARS> names = {"Alice", "Bob", "Charlie", "David", "Eve"};

void printBiggerThan(const array<int, CARS> &a, const array<string, CARS> &n) {
    for (int i = 0; i < CARS; i++) {
        if (a[i] >= 18) {
            cout << n[i] << " is an adult" << endl;
        }
    }
}

int main() {
    printBiggerThan(ages, names);

    return 0;
}