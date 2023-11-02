#include <iostream>

using namespace std;

int main() {
    const int questionsAsked = 20;
    const int points = 30;
    const int answersToGive = 3;
    int answersGiven = 0;

    const int pointsIfEasyRight = 2;
    const int pointsIfEasyWrong = -4;
    const int pointsIfDifficultRight = 4;
    const int pointsIfDifficultWrong = -2;


    for (int easyRight = 0; easyRight < questionsAsked; easyRight++) {
        for (int easyWrong = 0; easyWrong < questionsAsked; easyWrong++) {
            for (int difficultRight = 0; difficultRight < questionsAsked; difficultRight++) {
                for (int difficultWrong = 0; difficultWrong < questionsAsked; difficultWrong++) {
                    int score = easyRight * pointsIfEasyRight +
                                easyWrong * pointsIfEasyWrong +
                                difficultRight * pointsIfDifficultRight +
                                difficultWrong * pointsIfDifficultWrong;

                    if (score == points) {
                        cout << "Risposta corretta " << answersGiven + 1 << ":\n";
                        cout << "\tDomande facili giuste: " << easyRight << "\n";
                        cout << "\tDomande facili sbagliate: " << easyWrong << "\n";
                        cout << "\tDomande difficili giuste: " << difficultRight << "\n";
                        cout << "\tDomande difficili sbagliate: " << difficultWrong << "\n";
                        answersGiven++;
                        if (answersGiven == answersToGive) {
                            return 0;
                        }
                    }
                }
            }
        }
    }

    return 0;
}