#pragma clang diagnostic push
// Suppress warnings about the use of srand() and rand()
#pragma ide diagnostic ignored "cert-msc50-cpp"
#pragma ide diagnostic ignored "cert-msc51-cpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// The Jacobean date day
constexpr int DAY_JACOBEAN = 25;
// The Jacobean date month
constexpr int MONTH_JACOBEAN = 7;

// The rule holds only for the years between these two values
constexpr int VALIDITY_STARTING_YEAR = 1900;
constexpr int VALIDITY_ENDING_YEAR = 2100;

// Gets a valid date from the user
void getDate(int &day, int &month, int &year) {
    do {
        cout << "Inserisci il giorno (1-31): ";
        cin >> day;
        if (day < 1 || day > 31) {
            cout << "Il giorno deve essere compreso tra 1 e 31\n";
        } else {
            break;
        }
    } while (true);

    do {
        cout << "Inserisci il mese (1-12): ";
        cin >> month;
        if (month < 1 || month > 12) {
            cout << "Il mese deve essere compreso tra 1 e 12\n";
        } else {
            break;
        }
    } while (true);

    do {
        cout << "Inserisci l'anno (" << VALIDITY_STARTING_YEAR << "-" << VALIDITY_ENDING_YEAR << "): ";
        cin >> year;
        if (year < VALIDITY_STARTING_YEAR || year > VALIDITY_ENDING_YEAR) {
            cout << "L'anno deve essere compreso tra " << VALIDITY_STARTING_YEAR << " e " << VALIDITY_ENDING_YEAR
                 << "\n";
        } else {
            break;
        }
    } while (true);
}

// Prints the given date
void printDate(int &day, int &month, int &year) {
    cout << "La data inserita è: " << day << "/" << month << "/" << year << "\n";
}

// Returns true if the given year is a leap year
constexpr bool isLeap(const int &year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Returns the number of days from the beginning of the year to the given date
constexpr int getDaysFromDate(const int &day, const int &month, const int &year) {
    int totalDays = 0;

    totalDays += day;
    for (int i = 1; i < month; i++) {
        switch (i) {
            case 2:
                if (isLeap(year)) {
                    totalDays += 29;
                } else {
                    totalDays += 28;
                }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                totalDays += 30;
                break;
            default:
                totalDays += 31;
        }
    }

    return totalDays;
}

// Returns true if the given year is Jacobean (25/7 is a Sunday)
constexpr bool isJacobean(const int &year) {
    int firstYear = 1909;
    const int cadence[] = {6, 5, 6, 11};
    // Exceptions, these years are not included in the cadence
    const int exceptions[] = {1938, 2022};

    for (int i = 0; firstYear <= year; i++) {
        if (year == firstYear) {
            return true;
        }
        for (int exception: exceptions) {
            if (year == exception) {
                return true;
            }
        }
        firstYear += cadence[i % 4];
    }

    return false;
}

// Prints out a message if the given year is Jacobean or not
void printJacobean(const int &year) {
    if (isJacobean(year)) {
        cout << "L'anno " << year << " è giacobeo\n";
    } else {
        cout << "L'anno " << year << " non è giacobeo\n";
    }
}

// Returns the number of days between the given date and the Jacobean date
constexpr int calculateHowManyDaysToJacobeanDate(const int &day, const int &month, const int &year) {
    const int totalDays1 = getDaysFromDate(day, month, year);
    const int totalDays2 = getDaysFromDate(DAY_JACOBEAN, MONTH_JACOBEAN, year);
    return abs(totalDays2 - totalDays1);
}

// Prints out the number of days between the given date and the Jacobean date
void printHowManyDaysToJacobeanDate(const int &day, const int &month, const int &year) {
    const int days = calculateHowManyDaysToJacobeanDate(day, month, year);
    cout << "Tra oggi e la data giacobea ci sono " << days << " giorni\n";
}

int main() {
    srand(time(nullptr));

    int day, month, year;
    getDate(day, month, year);
    printDate(day, month, year);

    printJacobean(year);

    printHowManyDaysToJacobeanDate(day, month, year);

    return 0;
}

#pragma clang diagnostic pop