#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

constexpr int N_CANS = 10;
constexpr array CAN_CONTENTS = {"Coca Cola", "Pepsi", "Fanta", "Sprite", "7Up", "Red Bull", "Monster"};

constexpr int CAN_SIZE = 100;
constexpr int CAN_PRECISION = 10;
constexpr int SHOW_HIGHER_THAN_HEIGHT = 5;

typedef struct {
    // Content of the can
    string contentName;
    // Height of the can in cm
    double height;
    // Range of the can in cm
    double range;
} Can;

template<size_t N>
array<Can, N> getRandomCans() {
    array<Can, N> cans{};

    for (auto &can: cans) {
        can.contentName = CAN_CONTENTS[rand() % CAN_CONTENTS.size()];
        can.height = static_cast<double>(rand() % CAN_SIZE) / CAN_PRECISION;
        can.range = static_cast<double>(rand() % CAN_SIZE) / CAN_PRECISION;
    }

    return cans;
}

enum MenuChoice {
    DISPLAY_SORTED_BY_NAME = 1,
    DISPLAY_SORTED_HIGHER_THAN_N = 2,
    EXIT = 0
};


void sortCansByName(array<Can, N_CANS> &cans) {
    sort(cans.begin(), cans.end(), [](const Can &a, const Can &b) {
        return a.contentName < b.contentName;
    });
}

void displayCan(const Can &can) {
    cout << "Contenuto: " << can.contentName << ", Altezza: " << can.height << ", Raggio: " << can.range << endl;
}

void showAll(const array<Can, N_CANS> &cans) {
    for (const Can &can: cans) {
        displayCan(can);
    }
}

void showAllHigherThanN(const array<Can, N_CANS> &cans, double n) {
    for (const Can &can: cans) {
        if (can.height > n) {
            displayCan(can);
        }
    }
}

MenuChoice getChoice() {
    cout << "1. Mostra le lattine ordinate per nome\n"
            "2. Mostra le lattine ordinate per nome con altezza maggiore di N\n"
            "0. Esci\n"
            "Scelta:";
    int choice;
    cin >> choice;
    return static_cast<MenuChoice>(choice);
}

void displayMenu(array<Can, N_CANS> cans) {
    MenuChoice choice = getChoice();
    switch (choice) {
        case DISPLAY_SORTED_BY_NAME: {
            sortCansByName(cans);
            showAll(cans);
            break;
        }
        case DISPLAY_SORTED_HIGHER_THAN_N: {
            showAllHigherThanN(cans, SHOW_HIGHER_THAN_HEIGHT);
            break;
        }
        default:
            break;

    }
}


int main() {
    srand(time(nullptr));
    array<Can, N_CANS> cans = getRandomCans<N_CANS>();

    cout << "Lattine generate casualmente" << endl;
    showAll(cans);

    displayMenu(cans);

    return 0;
}