#include <iostream>

using namespace std;

string getString() {
    string s;
    cout << "Inserisci una stringa: ";
    getline(cin, s); // Using getline() to allow spaces in the string
    return s;
}

void toFarfallino(string &s) {
    for (int i = 0; i < s.length(); i++) {
        switch (s[i]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                s.insert(i + 1, "f");
                i++;
                break;
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                s.insert(i + 1, "F");
                i++;
                break;
            default:
                continue;
        }
    }
}

int main() {
    string s = getString();

    toFarfallino(s);

    cout << s << endl;

    return 0;
}