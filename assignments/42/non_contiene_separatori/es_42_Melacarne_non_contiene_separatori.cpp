#include <iostream>

using namespace std;

constexpr char SEPARATORS[] = {' ', '.', ',', ';', '!', '?'};

string getString() {
    string s;
    cout << "Inserisci una stringa: ";
    cin >> s;
    return s;
}

bool containsSeparator(const string &s) {
    for (const auto c: s) {
        // Using switch because it's faster than a for loop iterating through SEPARATORS
        switch (c) {
            case SEPARATORS[0]:
            case SEPARATORS[1]:
            case SEPARATORS[2]:
            case SEPARATORS[3]:
            case SEPARATORS[4]:
            case SEPARATORS[5]:
                return true;
            default:
                continue;
        }
    }

    return false;
}

void printSeparators() {
    cout << "I separatori sono: ";
    for (int i = 0; i < sizeof(SEPARATORS) - 1; i++) {
        cout << "\'" << SEPARATORS[i] << "\', ";
    }
    cout << "\'" << SEPARATORS[sizeof(SEPARATORS) - 1] << "\'" << endl;
}

int main() {
    const string s = getString();

    if (containsSeparator(s)) {
        cout << "La stringa contiene separatori" << endl;
        printSeparators();
    } else {
        cout << "La stringa non contiene separatori" << endl;
        printSeparators();
    }

    return 0;
}