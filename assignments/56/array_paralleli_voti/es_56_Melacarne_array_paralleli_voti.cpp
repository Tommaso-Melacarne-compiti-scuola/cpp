#include <iostream>
#include <array>

using namespace std;

constexpr int PEOPLE = 10;
const array<int, PEOPLE> votesIn = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const array<string, PEOPLE> namesIn = {"Alpha", "Bravo", "Charlie", "Delta", "Echo", "Foxtrot", "Golf", "Hotel",
                                       "India", "Juliet"};

void printBiggerOrEqualThan(const array<int, PEOPLE> &peopleAges, const array<string, PEOPLE> &peopleNames, double n) {
    for (int i = 0; i < PEOPLE; i++) {
        if (peopleAges[i] > n) {
            cout << peopleNames[i] << " has better than average votes" << endl;
        }
    }
}


void bubbleSortTwoArrays(array<int, PEOPLE> &arr1, array<string, PEOPLE> &arr2) {
    for (int i = 0; i < PEOPLE - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < PEOPLE - i - 1; j++) {
            if (arr1[j] < arr1[j + 1]) {
                swap(arr1[j], arr1[j + 1]);
                swap(arr2[j], arr2[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

double calculateAvgs(const array<int, PEOPLE> &arr) {
    int sum = 0;
    for (int i = 0; i < PEOPLE; i++) {
        sum += arr[i];
    }
    double avg = (double) sum / PEOPLE;

    return avg;
}

void printArrays(const array<int, PEOPLE> &arr1, const array<string, PEOPLE> &arr2) {
    for (int i = 0; i < PEOPLE; i++) {
        cout << arr1[i] << " " << arr2[i] << endl;
    }
}

int main() {
    array<int, PEOPLE> votes = votesIn;
    array<string, PEOPLE> names = namesIn;

    bubbleSortTwoArrays(votes, names);

    printArrays(votes, names);

    double avg = calculateAvgs(votes);

    printBiggerOrEqualThan(votes, names, avg);


    return 0;
}