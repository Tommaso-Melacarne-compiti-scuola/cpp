#include <iostream>

using namespace std;

constexpr int DAYS_IN_WEEK = 7;
constexpr int PERIOD_PER_DAY = 5;
constexpr int MAX_TEMP = 40;

const string DAYS_NAMES[] = {"LUN", "MAR", "MER", "GIO", "VEN", "SAB", "DOM"};
const string PERIOD_NAMES[] = {"11:00", "12:00", "13:00", "14:00", "15:00"};

void populateRandomWeekMatrix(double matrix[DAYS_IN_WEEK][PERIOD_PER_DAY]) {
    constexpr int DOUBLE_MAX_TEMP = MAX_TEMP * 2;
    for (int i = 0; i < DAYS_IN_WEEK; i++) {
        for (int j = 0; j < PERIOD_PER_DAY; j++) {
            matrix[i][j] = rand() % DOUBLE_MAX_TEMP / 2.0;
        }
    }
}

void printTemperatures(const double matrix[DAYS_IN_WEEK][PERIOD_PER_DAY]) {
    for (int i = 0; i < DAYS_IN_WEEK; i++) {
        cout << DAYS_NAMES[i] << ": ";
        for (int j = 0; j < PERIOD_PER_DAY; j++) {
            cout << matrix[i][j] << "°C ";
        }
        cout << endl;
    }
}

void printAbsoluteMaxTemp(const double matrix[DAYS_IN_WEEK][PERIOD_PER_DAY]) {
    int day, period;
    double maxTemp;

    for (int i = 0; i < DAYS_IN_WEEK; i++) {
        for (int j = 0; j < PERIOD_PER_DAY; j++) {
            if (matrix[i][j] > maxTemp) {
                maxTemp = matrix[i][j];
                day = i;
                period = j;
            }
        }
    }

    cout << "La temperatura massima assoluta è " << maxTemp << "°C, registrata il giorno " << DAYS_NAMES[day]
         << " alle ore " << PERIOD_NAMES[period] << endl;

}


void printAvgTempByPeriod(const double matrix[DAYS_IN_WEEK][PERIOD_PER_DAY]) {
    double avgTemp[PERIOD_PER_DAY];

    for (int i = 0; i < PERIOD_PER_DAY; i++) {
        double sum = 0;
        for (int j = 0; j < DAYS_IN_WEEK; j++) {
            sum += matrix[j][i];
        }
        avgTemp[i] = (double) sum / DAYS_IN_WEEK;
    }

    for (int i = 0; i < PERIOD_PER_DAY; i++) {
        cout << "La temperatura media registrata alle ore " << PERIOD_NAMES[i] << " è " << avgTemp[i] << "°C" << endl;
    }
}

int main() {
    srand(time(nullptr));

    double matrix[DAYS_IN_WEEK][PERIOD_PER_DAY];

    populateRandomWeekMatrix(matrix);

    printTemperatures(matrix);

    printAbsoluteMaxTemp(matrix);
    printAvgTempByPeriod(matrix);

    return 0;
}