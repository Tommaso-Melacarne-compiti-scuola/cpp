#include <iostream>

using namespace std;

const char VOCALS[] = {'A', 'E', 'I', 'O', 'U'};

string getString() {
    string s;
    cout << "Inserisci una stringa: ";
    cin >> s;
    return s;
}


// Returns `true` if the string contains at least one uppercase vocal.
bool checkIfStringContainsVocal(const string &str) {
    for (const auto c : str) {
        for (const auto vocal : VOCALS) {
            if (c == vocal) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    const string str = getString();

    if (checkIfStringContainsVocal(str)) {
        cout << "La stringa contiene almeno una vocale maiuscola" << endl;
    } else {
        cout << "La stringa non contiene nessuna vocale maiuscola" << endl;
    }

    return 0;
}