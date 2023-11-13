#pragma clang diagnostic push
// Suppress warnings about the use of srand() and rand()
#pragma ide diagnostic ignored "cert-msc50-cpp"
#pragma ide diagnostic ignored "cert-msc51-cpp"

#include <iostream>
#include <cstdlib>

using namespace std;

// The Jacobean date day
constexpr int DAY_JACOBEAN = 25;
// The Jacobean date month
constexpr int MONTH_JACOBEAN = 7;

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
        cout << "Inserisci l'anno (1-9999): ";
        cin >> year;
        if (year < 1 || year > 9999) {
            cout << "L'anno deve essere compreso tra 1 e 9999\n";
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

// Returns the first day of the year for the given year (1 = Monday, 7 = Sunday)
constexpr int getFirstDayOfYear(const int &year) {
    const int firstTwoDigits = year / 100;
    const int lastTwoDigits = year % 100;

    int C = 0; // Value never actually gets read, but uninitialized variables are disallowed in constexpr functions
    switch (firstTwoDigits % 4) {
        case 0:
            C = (year % 4 == 0) ? 5 : 6;
            break;
        case 1:
            C = 4;
            break;
        case 2:
            C = 2;
            break;
        case 3:
            C = 0;
            break;
    }

    const int K = (lastTwoDigits + (lastTwoDigits - 1) / 4) % 7;

    return (C + K) % 7 + 1;
}


// Returns the day of the week for the given date (1 = Monday, 7 = Sunday)
constexpr int getDayOfWeek(const int &day, const int &month, const int &year, const int &firstDayOfTheYear) {
    const int N[] = {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};

    const int leapAdj = isLeap(year) ? 1 : 0;

    return ((day + N[month - 1 + leapAdj]) % 7) + firstDayOfTheYear - 1;
}

// Returns true if the given year is Jacobean (25/7 is a Sunday)
constexpr bool isJacobean(const int &year, const int &firstDayOfTheYear) {
    return getDayOfWeek(DAY_JACOBEAN, MONTH_JACOBEAN, year, firstDayOfTheYear) == 7;
}

// Prints out a message if the given year is Jacobean or not
void printJacobean(const int &year, const int &firstDayOfTheYear) {
    if (isJacobean(year, firstDayOfTheYear)) {
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

// Prints out the given day of the week (1 = Monday, 7 = Sunday)
void printFirstDayOfTheYear(const int &firstDayOfTheYear) {
    cout << "Il primo giorno dell'anno è: ";
    switch (firstDayOfTheYear) {
        case 1:
            cout << "Lunedì";
            break;
        case 2:
            cout << "Martedì";
            break;
        case 3:
            cout << "Mercoledì";
            break;
        case 4:
            cout << "Giovedì";
            break;
        case 5:
            cout << "Venerdì";
            break;
        case 6:
            cout << "Sabato";
            break;
        case 7:
            cout << "Domenica";
            break;
        default:
            cout << "Errore";
    }
    cout << "\n";
}

int main() {
    int day, month, year;
    getDate(day, month, year);
    printDate(day, month, year);

    const int firstDayOfTheYear = getFirstDayOfYear(year);
    printFirstDayOfTheYear(firstDayOfTheYear);

    printJacobean(year, firstDayOfTheYear);

    printHowManyDaysToJacobeanDate(day, month, year);

    return 0;
}

#pragma clang diagnostic pop