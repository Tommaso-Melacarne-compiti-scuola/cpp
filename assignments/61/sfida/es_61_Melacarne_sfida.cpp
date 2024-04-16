#include <iostream>
#include <array>
#include <optional>

using namespace std;

constexpr int DAYS = 7;
constexpr int RANDOM_MOD = 1000;
constexpr int RANDOM_PRECISION_FACTOR = 100;

typedef struct {
    double profit;
    double loss;
    optional<double> dayBalance;
    optional<double> progressiveBalance;
} Day;

void computeDailyBalances(array<Day, DAYS> &days) {
    for (auto &day: days) {
        if (!day.dayBalance) {
            day.dayBalance = day.profit - day.loss;
        }
    }
}

void computeProgressiveBalances(array<Day, DAYS> &days, double startingBalance = 0) {
    double lastDayBalance = startingBalance;
    for (auto &day: days) {
        if (!day.progressiveBalance) {
            day.progressiveBalance = lastDayBalance + day.dayBalance.value();
        }
        lastDayBalance = day.progressiveBalance.value();
    }
}

void computeBalances(array<Day, DAYS> &days, double startingBalance = 0) {
    computeDailyBalances(days);
    computeProgressiveBalances(days, startingBalance);
}

typedef struct {
    array<Day, DAYS> days;
    double startingBalance;
} InputData;

InputData getRandomDayInput() {
    array<Day, DAYS> days{};
    for (auto &day: days) {
        day.profit = (rand() % RANDOM_MOD) / (double) RANDOM_PRECISION_FACTOR;
        day.loss = (rand() % RANDOM_MOD) / (double) RANDOM_PRECISION_FACTOR;
    }

    auto randomStartingBalance = (rand() % RANDOM_MOD) / (double) RANDOM_PRECISION_FACTOR;

    computeBalances(days, randomStartingBalance);

    return InputData{
            .days = days,
            .startingBalance = randomStartingBalance
    };
}

void printTable(const InputData &data) {
    auto days = data.days;
    cout << "Starting Balance: " << data.startingBalance << endl;
    for (int i = 0; i < DAYS; i++) {
        cout << "Day " << i + 1 << " - Profit: " << days[i].profit << " - Loss: " << days[i].loss
             << " - Daily Balance: " << days[i].dayBalance.value() << " - Progressive Balance: "
             << days[i].progressiveBalance.value() << endl;
    }
}


int main() {
    srand(time(nullptr));

    InputData randomDayInput = getRandomDayInput();

    printTable(randomDayInput);

    return 0;
}