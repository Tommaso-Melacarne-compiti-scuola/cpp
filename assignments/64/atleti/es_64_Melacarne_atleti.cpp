#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int N_ATHLETES = 15;
constexpr int MAX_TIME = 10000;
constexpr int PRECISION = 100;

typedef struct {
    double time;
} Athlete;

template<size_t N>
array<Athlete, N> getRandomAthletes() {
    array<Athlete, N> athletes{};

    for (auto &athlete: athletes) {
        athlete.time = static_cast<double>(rand() % MAX_TIME) / PRECISION;
    }

    return athletes;
}

template<size_t N>
void printAthletes(const array<Athlete, N> &athletes) {
    for (const Athlete &athlete: athletes) {
        cout << athlete.time << endl;
    }
}

template<size_t N>
array<Athlete, N> getRandomSortedAthletes() {
    auto athletes = getRandomAthletes<N>();

    std::sort(athletes.begin(), athletes.end(), [](const Athlete &a, const Athlete &b) {
        return a.time > b.time;
    });

    return athletes;
}

template<typename T, size_t N>
void shiftRightDiscard(array<T, N> &arr, int pos) {
    for (int i = N - 1; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
}


void pushAthleteOrdered(array<Athlete, N_ATHLETES> &athletes, const Athlete &athlete) {
    int i = 0;
    while (i < N_ATHLETES && athletes[i].time > athlete.time) {
        i++;
    }

    shiftRightDiscard(athletes, i);
    athletes[i] = athlete;
}

Athlete getAthlete() {
    cout << "Inserisci un atleta: ";
    double time;
    cin >> time;

    return {.time = time};
}

int main() {
    array<Athlete, N_ATHLETES> athletes = getRandomSortedAthletes<N_ATHLETES>();

    cout << "Array prima della modifica:\n";
    printAthletes(athletes);

    Athlete athlete = getAthlete();

    pushAthleteOrdered(athletes, athlete);

    cout << "Array dopo la modifica:\n";
    printAthletes(athletes);

    return 0;
}