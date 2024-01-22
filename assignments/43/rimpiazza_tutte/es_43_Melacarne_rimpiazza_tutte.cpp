#include <iostream>

using namespace std;

string getString(const string &message) {
    string s;
    cout << message;
    getline(cin, s); // Using getline() to allow spaces in the string
    return s;
}

void substitute_all(string &strText, const string &strOld, const string &strNew) {
    unsigned long long idx;
    do {
        idx = strText.find(strOld);
        // string::npos is returned when the substring is not found
        if (idx == string::npos) {
            return;
        }
        strText.replace(idx, strOld.length(), strNew);
    } while (idx < strText.length());
}


int main() {
    string strText = getString("Inserisci la stringa strText: ");
    const string strOld = getString("Inserisci la stringa strOld: ");
    const string strNew = getString("Inserisci la stringa strNew: ");

    substitute_all(strText, strOld, strNew);

    cout << "La stringa strText modificata è: " << strText << endl;

    return 0;
}