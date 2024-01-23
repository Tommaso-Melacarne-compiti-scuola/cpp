#include <iostream>

using namespace std;

constexpr int NUM_COORDS = 3;

string getString() {
    string s;
    cout << "Inserisci una stringa: ";
    getline(cin, s); // Using getline() to allow spaces in the string
    return s;
}

void printPoint(const double coords[], int len, int pointIdx) {
    cout << "P" << pointIdx << ": (";
    for (int i = 0; i < len - 1; i++) {
        cout << coords[i] << ", ";
    }
    cout << coords[len - 1] << ")" << endl;
}

void parsePoint(const string &s, int pointIdx) {
    int coordCursor = 0;
    double coords[NUM_COORDS] = {0};
    int coordStart = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ',') {
            auto coord = s.substr(coordStart, i - coordStart);
            coords[coordCursor] = stod(coord);
            coordCursor++;
            coordStart = i + 1;
        }
    }
    coords[coordCursor] = stod(s.substr(coordStart, s.length() - coordStart));

    printPoint(coords, NUM_COORDS, pointIdx);
}


void parsePoints(const string &s) {
    // A number indicating P1, P2, P3, ...
    int pointIdx = 1;
    int pointStart = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            auto point = s.substr(pointStart, i - pointStart);
            parsePoint(point, pointIdx);
            pointIdx++;
            pointStart = i + 1;
        }
    }
    auto point = s.substr(pointStart, s.length() - pointStart);
    parsePoint(point, pointIdx);
}

int main() {
    string s = getString();

    parsePoints(s);

    return 0;
}