#include <iostream>
#include <array>

using namespace std;

#pragma ide diagnostic ignored "ConstantParameter" // IDE warning about passing a const array by value

template<size_t NUMBERS>
constexpr void run(const array<int, NUMBERS> n, const char character) {
    // Here I compute the margins for the frames
    array<int, n.size()> marginsStart{};
    marginsStart[0] = 0;
    for (int i = 1; i < marginsStart.size(); i++) {
        marginsStart[i] = (n[0] - n[i]) / 2;
    }

    array<int, n.size()> marginsEnd{};
    for (int i = 0; i < marginsEnd.size(); i++) {
        marginsEnd[i] = n[0] - marginsStart[i] - 1; // -1 because the last index is n[0] - 1
    }

    // Here I print the frames
    for (int i = 0; i < n[0]; i++) {
        for (int j = 0; j < n[0]; j++) {
            bool drewCharacter = false; // Guard to avoid printing multiple spaces

            for (int k = 0; k < n.size(); k++) {
                int thisMarginStart = marginsStart[k];
                int thisMarginEnd = marginsEnd[k];

                // >= is used here to print the vertexes
                if (((i == thisMarginStart || i == thisMarginEnd) && (j > thisMarginStart && j < thisMarginEnd)) ||
                    ((j == thisMarginStart || j == thisMarginEnd) && (i >= thisMarginStart && i <= thisMarginEnd))) {
                    cout << character;
                    drewCharacter = true;
                }
            }

            if (!drewCharacter) {
                cout << ' ';
            }

//            Code above generates code like this for n[3] = {12, 8, 4}
//
//            if (i == 0 || i == 11 || j == 0 || j == 11) {
//                cout << character;
//            } else if (((i == 2 || i == 9) && (j > 2 && j < 9)) || ((j == 2 || j == 9) && (i >= 2 && i <= 9))) {
//                cout << character;
//            } else if (((i == 4 || i == 7) && (j > 4 && j < 7)) || ((j == 4 || j == 7) && (i >= 4 && i <= 7))) {
//                cout << character;
//            } else {
//                cout << ' ';
//            }
        }
        cout << "\n";
    }
}

int main() {
    const array<int, 4> n = {12, 8, 4};
    const char character = '*';

    run<n.size()>(n, character);

    return 0;
}