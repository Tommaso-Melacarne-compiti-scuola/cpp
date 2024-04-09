#include <iostream>

using namespace std;

typedef struct {
    char ring;
    char zone;
    char sector;
    char orientation;
    int place;
} bookedEntry;

int main() {
    bookedEntry arr[] = {
            {
                    'A',
                    'Z',
                    'S',
                    'N',
                    123
            },
            {
                    'B',
                    'Z',
                    'S',
                    'N',
                    123
            }
    };

    cout << "Ring\tZone\tSector\tOrientation\tPlace" << endl;
    for (auto & item : arr) {
        cout << item.ring << "\t" << item.zone << "\t" << item.sector << "\t" << item.orientation << "\t" << item.place << endl;
    }

    return 0;
}
