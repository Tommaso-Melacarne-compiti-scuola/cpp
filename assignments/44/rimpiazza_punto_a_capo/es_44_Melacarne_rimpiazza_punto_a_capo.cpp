#include <iostream>

using namespace std;

constexpr int MAX_LEN = 100;

string getString(int max_len) {
    do {
        string s;
        cout << "Inserisci una stringa: ";
        getline(cin, s); // Using getline() to allow spaces in the string
        if (s.length() > max_len) {
            cout << "La stringa inserita è troppo lunga. Riprova." << endl;
            continue;
        } else {
            return s;
        }
    } while (true);
}

void replaceAllChar(string &s, char old_char, char new_char) {
    for (auto &c: s) {
        if (c == old_char) {
            c = new_char;
        }
    }
}

int main() {
    string s = getString(MAX_LEN);

    replaceAllChar(s, '.', '\n');

    cout << "La stringa modificata è: " << s << endl;

    return 0;
}