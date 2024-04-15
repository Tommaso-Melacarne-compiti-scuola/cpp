#include <iostream>
#include <vector>

using namespace std;

int getNumberOfBookings() {
    int n;
    cout << "Inserisci il numero di prenotazioni: ";
    cin >> n;
    return n;
}

enum PartType {
    CLASS_BIG = 0,
    CLASS_SMALL = 1,
};

istream &operator>>(istream &basicIstream, PartType &partType) {
    int input;
    basicIstream >> input;
    partType = static_cast<PartType>(input);
    return basicIstream;
}

int getPartSizeFromType(PartType type) {
    switch (type) {
        case CLASS_BIG:
            return 8;
        case CLASS_SMALL:
            return 6;
    }
}

typedef struct {
    string name;
    string surname;
} Passenger;

typedef struct {
    vector<Passenger> passengers;
    PartType type;
} Part;

typedef struct {
    vector<Part> parts;
} Wagon;

typedef struct {
    vector<Wagon> wagons;
} Train;

int main() {
    Train train;
    int n = getNumberOfBookings();

    for (int i = 0; i < n; i++) {
        Passenger passenger;
        cout << "Inserisci il nome del passeggero: ";
        cin >> passenger.name;
        cout << "Inserisci il cognome del passeggero: ";
        cin >> passenger.surname;

        PartType type;
        cout << "Inserisci la classe del passeggero (0 per la classe grande (8 posti), 1 per la classe piccola): ";
        cin >> type;

        Part part;
        part.passengers.push_back(passenger);
        part.type = type;

        Wagon wagon;
        wagon.parts.push_back(part);

        train.wagons.push_back(wagon);
    }

    return 0;
}