#include <iostream>

using namespace std;


string getString() {
    string s;
    cout << "Inserisci una stringa: ";
    cin >> s;
    return s;
}

bool containsDoubleLetter(const string &s) {
    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] == s[i + 1]) {
            return true;
        }
    }

    return false;
}

int main() {
    const string s = getString();

    if (containsDoubleLetter(s)) {
        cout << "La stringa contiene una lettera doppia" << endl;
    } else {
        cout << "La stringa non contiene una lettera doppia" << endl;
    }

    return 0;
}