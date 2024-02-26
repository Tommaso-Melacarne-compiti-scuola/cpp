#include <iostream>
#include <array>

using namespace std;

constexpr int SIZE = 6;
constexpr int HALF_SIZE = SIZE / 2;

array<string, SIZE> getTeams() {
    array<string, SIZE> teams;

    for (int i = 0; i < teams.size(); i++) {
        cout << "Inserisci il nome della squadra " << i + 1 << ": ";
        cin >> teams[i];
    }

    return teams;
}

void rightCircularShiftExceptFirst(array<string, SIZE> &teams) {
    string temp = teams[SIZE - 1];
    for (int i = SIZE - 1; i > 1; i--) {
        teams[i] = teams[i - 1];
    }
    teams[1] = temp;
}

void generateMatches(array<string, SIZE> teams) {
    for (int i = 0; i < SIZE - 1; i++) {
        cout << "Giornata " << i + 1 << endl;
        for (int j = 0; j < HALF_SIZE; j++) {
            string a = teams[j];
            string b = teams[SIZE - 1 - j];

            if (a != b) {
                cout << a << " vs " << b << endl;
            }
        }
        rightCircularShiftExceptFirst(teams);
    }
}

int main() {
    array<string, SIZE> teams = getTeams();

    generateMatches(teams);

    return 0;
}