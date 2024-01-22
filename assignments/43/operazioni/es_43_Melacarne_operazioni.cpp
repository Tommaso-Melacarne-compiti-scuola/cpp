#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void toUpperCase(string &str) {
    for (auto &c: str) {
        c = (char) toupper(c);
    }
}

void swapVowelsWithChar(string &str, const char c) {
    for (auto &ch: str) {
        switch (ch) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                ch = c;
                break;
            default:
                continue;
        }
    }
}

int main() {
    string str = "oggi piove";

    toUpperCase(str);

    cout << str << endl;

    str.append(", domani sarà bel tempo");

    cout << str << endl;

    cout << str.length() << endl;

    swapVowelsWithChar(str, 'i');

    return 0;
}