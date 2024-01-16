#include <iostream>
#include <string>
#include <optional>

using namespace std;

// Returns the number of consecutive characters that are equal
int getConsecutiveNumber(const string &s1, const string &s2) {
    int count = 0;
    int maxCount = 0;
    for (int i = 0; i < s1.length() && i < s2.length(); i++) {
        if (s1[i] == s2[i]) {
            count++;
        } else {
            if (count > maxCount) {
                maxCount = count;
            }
            count = 0;
        }
    }

    return maxCount;
}

string getString() {
    string s;
    cout << "Inserisci una stringa: ";
    cin >> s;
    return s;
}

int main() {
    const string s1 = getString();
    const string s2 = getString();

    const int countConsecutive = getConsecutiveNumber(s1, s2);

    if (countConsecutive == 0) {
        cout << "Le stringhe non hanno caratteri uguali consecutivi" << endl;
    } else {
        cout << "Le stringhe hanno " << countConsecutive << " caratteri uguali consecutivi" << endl;
    }


    return 0;
}