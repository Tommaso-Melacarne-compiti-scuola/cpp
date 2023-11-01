#include <iostream>

using namespace std;

int main() {
    const int questionsAsked = 20;
    const int points = 30;
    const int answersToGive = 3;

    const int pointsIfEasyRight = 2;
    const int pointsIfEasyWrong = -4;
    const int pointsIfDifficultRight = 4;
    const int pointsIfDifficultWrong = -2;

    int easyRight = 0;
    int easyWrong = 0;
    int difficultRight = 0;
    int difficultWrong = 0;



    cout << "Domande facili giuste: " << easyRight << endl;
    cout << "Domande facili sbagliate: " << easyWrong << endl;
    cout << "Domande difficili giuste: " << difficultRight << endl;
    cout << "Domande difficili sbagliate: " << difficultWrong << endl;

    return 0;
}