#include <iostream>
#include <vector>

using namespace std;

constexpr int NUM_RESULTS = 14;

typedef struct {
    int day;
    int month;
    int year;
} date;

typedef struct {
    int code;
    date d;
    int results[NUM_RESULTS];
} card;

typedef struct {
    int year;
    int month;
} inputQuery;

inputQuery getInputQuery() {
    cout << "Inserisci la data della giocata da cercare" << endl;
    inputQuery query;
    cout << "Inserisci l'anno della giocata: ";
    cin >> query.year;
    cout << "Inserisci il mese della giocata: ";
    cin >> query.month;
    return query;
}

vector<card> findCards(const vector<card> &cards, const inputQuery query) {
    vector<card> foundCards;
    for (auto & c : cards) {
        if (c.d.year == query.year && c.d.month == query.month) {
            foundCards.push_back(c);
        }
    }
    return foundCards;
}


void printCard(const card c) {
    cout << "Codice: " << c.code << endl;
    cout << "Data: " << c.d.day << "/" << c.d.month << "/" << c.d.year << endl;
    cout << "Risultati:\n";
    for (int i = 0; i < NUM_RESULTS; i++) {
        cout << "Partita " << i + 1 << ": " << c.results[i] << "\n";
    }
    cout << endl;
}

void printCards(const vector<card> &cards) {
    for (int i = 0; i < cards.size(); i++) {
        cout << "Schedina " << i + 1 << ":\n";
        printCard(cards[i]);
    }
}

int main() {
    const vector<card> arr = {
            {
                    {
                            1,
                            {1, 1, 2021},
                            {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14}
                    },
                    {
                            2,
                            {1, 2, 2021},
                            {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14}
                    }
            }
    };

    cout << "Schedine disponibili: " << endl;
    printCards(arr);

    inputQuery query = getInputQuery();
    vector<card> cards = findCards(arr, query);

    if (cards.empty()) {
        cout << "Nessuna schedina trovata" << endl;
    } else {
        cout << cards.size() << " schedine trovate" << endl;
        printCards(cards);
    }

    return 0;
}