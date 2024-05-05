#include <iostream>
#include <array>
#include <vector>
#include <ranges>

using namespace std;

constexpr int DESC_LEN = 10;
constexpr int AMOUNT_MAX = 1000;
constexpr int AMOUNT_PRECISION = 100;
constexpr int START_YEAR = 2024;
constexpr int HOW_MANY_YEARS = 10;

typedef struct {
    int day;
    int month;
    int year;
} Date;

enum MovementType {
    DEPOSIT,
    WITHDRAWAL
};

typedef struct {
    Date date;
    string description;
    double amount;
    MovementType type;
} Movement;


string getRandomString(int len) {
    static constexpr string_view CHARACTERS =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";

    std::string s;
    s.reserve(len);

    for (int i = 0; i < len; i++) {
        s += CHARACTERS[rand() % CHARACTERS.size()];
    }

    return s;
}

Date getRandomDate() {
    constexpr array<int, 12> DAYS_IN_MONTH = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    constexpr int MONTHS_IN_YEAR = 12;

    Date date{
            .day = rand() % DAYS_IN_MONTH[rand() % MONTHS_IN_YEAR],
            .month = rand() % MONTHS_IN_YEAR,
            .year = START_YEAR + rand() % HOW_MANY_YEARS
    };

    return date;
}


Movement generateRandomMovement() {
    Movement movement{
            .date = getRandomDate(),
            .description = getRandomString(DESC_LEN),
            .amount = static_cast<double>(rand() % AMOUNT_MAX) / AMOUNT_PRECISION,
            .type = static_cast<MovementType>(rand() % 2)
    };

    return movement;
}

enum MenuChoice {
    ADD_MOVEMENT = 1,
    PRINT_BALANCE = 2,
    PRINT_REPORT = 3,
    EXIT = 0
};

MenuChoice getChoice() {
    cout << "1. Aggiungi movimento casuale\n"
            "2. Stampa saldo\n"
            "3. Stampa report\n"
            "0. Esci\n"
            "Scelta: ";
    int choice;
    cin >> choice;
    return static_cast<MenuChoice>(choice);
}

void addMovement(vector<Movement> &movements) {
    movements.push_back(generateRandomMovement());
}

double getBalance(const vector<Movement> &movements) {
    double balance = 0;
    for (const Movement &movement: movements) {
        balance += movement.type == DEPOSIT ? movement.amount : -movement.amount;
    }
    return balance;
}

string getMovementTypeDisplay(const MovementType &type) {
    return type == DEPOSIT ? "Deposito" : "Prelievo";
}

void printMovement(const Movement &movement) {
    cout << "\tData: " << movement.date.day << "/" << movement.date.month << "/" << movement.date.year <<
         "\n\tDescrizione: " << movement.description <<
         "\n\tImporto: " << movement.amount <<
         "\n\tTipo: " << getMovementTypeDisplay(movement.type) << endl;
}

void printReport(const vector<Movement> &movements) {
    for (const auto [idx, movement]: std::ranges::views::enumerate(movements)) {
        cout << "Movimento " << idx + 1 << endl;
        printMovement(movement);
    }
}

int main() {
    srand(time(nullptr));
    vector<Movement> movements;

    do {
        MenuChoice choice = getChoice();
        switch (choice) {
            case ADD_MOVEMENT: {
                addMovement(movements);
                break;
            }
            case PRINT_BALANCE: {
                cout << "Saldo: " << getBalance(movements) << endl;
                break;
            }
            case PRINT_REPORT: {
                printReport(movements);
                break;
            }
            case EXIT: {
                return 0;
            }
        }
    } while (true);
}