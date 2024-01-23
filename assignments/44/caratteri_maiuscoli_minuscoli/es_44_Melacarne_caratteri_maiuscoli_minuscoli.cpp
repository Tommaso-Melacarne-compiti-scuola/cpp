#include <iostream>

using namespace std;

constexpr int MAX_LEN = 100;

bool containsBothUpperAndLowerCase(const string &s) {
    bool containsUpper = false;
    bool containsLower = false;
    for (auto &c: s) {
        if (isupper(c)) {
            containsUpper = true;
        } else if (islower(c)) {
            containsLower = true;
        }
    }
    return containsUpper && containsLower;
}

string getString(int max_len) {
    do {
        string s;
        cout << "Inserisci una stringa: ";
        getline(cin, s); // Using getline() to allow spaces in the string
        if (s.length() > max_len) {
            cout << "La stringa inserita è troppo lunga. Riprova." << endl;
            continue;
        } else if (!containsBothUpperAndLowerCase(s)) {
            cout << "La stringa inserita non contiene sia caratteri maiuscoli che minuscoli. Riprova." << endl;
            continue;
        } else {
            return s;
        }
    } while (true);
}

void normalizeString(string &s) {
    bool wordStart = true;
    for (auto &c: s) {
        if (wordStart && isalpha(c)) {
            c = (char) toupper(c);
            wordStart = false;
        } else if (isspace(c)) {
            wordStart = true;
        }
    }
}

int main() {
    string s = getString(MAX_LEN);

    cout << "La stringa modificata è: " << s << endl;

    return 0;
}