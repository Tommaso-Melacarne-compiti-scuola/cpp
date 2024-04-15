#include <iostream>
#include <vector>

using namespace std;

constexpr int FLOORS = 5;
constexpr int ROOMS = 10;

enum RoomType {
    LOWER,
    MIDDLE,
    UPPER
};

int getPriceByType(RoomType type) {
    switch (type) {
        case LOWER:
            return 1;
        case MIDDLE:
            return 2;
        case UPPER:
            return 3;
    }
}

typedef struct {
    vector<int> people;
    RoomType type;
} Room;

typedef struct {
    vector<Room> rooms;
} Floor;

typedef struct {
    vector<Floor> floors;
} Hotel;


int main() {

    return 0;
}