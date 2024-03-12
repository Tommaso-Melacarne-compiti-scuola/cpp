#include <iostream>

using namespace std;

constexpr int MONTHS_LENGTH = 12;
constexpr char MONTHS[MONTHS_LENGTH] = {'A', 'B', 'C', 'D', 'E', 'H', 'L', 'M', 'P', 'R', 'S', 'T'};


string getCode() {
    string code;
    cout << "Inserisci il codice fiscale: ";
    cin >> code;
    return code;
}

bool isMonthValid(char month) {
    for (char m : MONTHS) {
        if (month == m) {
            return true;
        }
    }
    return false;
}

int isCodeValid(string code) {
    // Check if the name and surname are valid
    for (int i = 0; i < 7; i++) {
        if (!isalpha(code[i])) {
            cout << "Errore alla posizione " << i << ": " << code[i] << " non è una lettera" << endl;
            return false;
        }
    }

    // Check if the year is valid
    for (int i = 7; i < 9; i++) {
        if (!isdigit(code[i])) {
            cout << "Errore alla posizione " << i << ": " << code[i] << " non è un numero" << endl;
            return false;
        }
    }

    // Check if the month is valid
    isMonthValid(code[9]);

    // Check if the day is valid
    for (int i = 10; i < 12; i++) {
        if (!isdigit(code[i])) {
            cout << "Errore alla posizione " << i << ": " << code[i] << " non è un numero" << endl;
            return false;
        }
    }

    // Check if the city code is valid
    for (int i = 12; i < 15; i++) {
        if (!isdigit(code[i])) {
            cout << "Errore alla posizione " << i << ": " << code[i] << " non è un numero" << endl;
            return false;
        }
    }

    // Check if the control code is valid
    if (!isalpha(code[15])) {
        cout << "Errore alla posizione 15: " << code[15] << " non è una lettera" << endl;
        return false;
    }

    return true;
}

int main() {
    string code = getCode();

    if (code.length() != 16) {
        cout << "Il codice fiscale deve essere lungo 16 caratteri" << endl;
        return -1;
    }

    if (isCodeValid(code)) {
        cout << "Il codice fiscale è valido" << endl;
        return 0;
    } else {
        cout << "Il codice fiscale non è valido" << endl;
        return -1;
    }
}