#include <iostream>

using namespace std;

const char VOCALS[] = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
const int MINIMUM_CONSONANTS = 3;

string getString() {
    string s;
    cout << "Inserisci una stringa: ";
    cin >> s;
    return s;
}


// Returns `true` if the string contains at least n consecutive consonants.
bool checkIfStringContainsNConsecutiveConsonants(const string &str, int n) {
    int count = 0;
    for (const auto c : str) {
        bool isVocal = false;
        for (const auto vocal : VOCALS) {
            if (c == vocal) {
                isVocal = true;
                break;
            }
        }
        if (!isVocal) {
            count++;
        } else {
            count = 0;
        }
        if (count == n) {
            return true;
        }
    }
    return false;
}

int main() {
    const string str = getString();

    if (checkIfStringContainsNConsecutiveConsonants(str, MINIMUM_CONSONANTS)) {
        cout << "La stringa contiene almeno tre consonanti consecutive" << endl;
    } else {
        cout << "La stringa non contiene almeno tre consonanti consecutive" << endl;
    }


    return 0;
}