#include <iostream>

using namespace std;

const int nStart = 10;
const int nEnd = 100;
const int coefficient = 5;

int main() {
    int sum = 0;

    for (int i = nStart + 1; i < nEnd; i += coefficient) {
        sum += i;
    }

    cout << "La somma dei multipli di " << coefficient << " tra " << nStart << " e " << nEnd << " e': " << sum << "\n";

    return 0;
}