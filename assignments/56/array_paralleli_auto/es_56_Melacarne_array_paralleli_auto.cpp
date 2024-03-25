#include <iostream>
#include <array>

using namespace std;

constexpr int CARS = 20;
constexpr int MINSPEED = 180;
constexpr int MAXSPEED = 220;
const array<string, CARS> namesIn = {"Verstappen", "Perez", "Hamilton", "Alonso", "Leclerc", "Norris", "Sainz",
                                     "Russell", "Plates", "Stroll", "Gasly", "Ocon", "Albon", "Tsunoda", "Bottas",
                                     "Hulkenberg", "Ricciardo", "Zhou", "Magnussen", "Lawson"};

void printArrays(const array<double, CARS> &arr1, const array<string, CARS> &arr2) {
    for (int i = 0; i < CARS; i++) {
        cout << arr1[i] << " " << arr2[i] << endl;
    }
}

array<double, CARS> getRandomSpeedsBetween(const int min, const int max) {
    array<double, CARS> speeds{};
    for (int i = 0; i < CARS; i++) {
        speeds[i] = min + (rand() % (max - min + 1));
    }
    return speeds;
}

void getMaximumSpeed(const array<double, CARS> &speeds, const array<string, CARS> &names) {
    double maxSpeed = speeds[0];
    string maxName = names[0];
    for (int i = 1; i < CARS; i++) {
        if (speeds[i] > maxSpeed) {
            maxSpeed = speeds[i];
            maxName = names[i];
        }
    }
    cout << "Il pilota più veloce è " << maxName << " con una velocità di " << maxSpeed << " km/h" << endl;
}


int main() {
    array<double, CARS> carSpeeds = getRandomSpeedsBetween(MINSPEED, MAXSPEED);
    array<string, CARS> carNames = namesIn;

    printArrays(carSpeeds, carNames);

    getMaximumSpeed(carSpeeds, carNames);

    return 0;
}