#include <iostream>
#include <array>

using namespace std;

constexpr int NUMBERS = 30;

array<int, NUMBERS> getRandomArray() {
    array<int, NUMBERS> numbers{};
    for (int i = 0; i < NUMBERS; i++) {
        numbers[i] = rand() % 100;
    }
    return numbers;
}

tuple<array<int, NUMBERS>, array<int, NUMBERS>> run(array<int, NUMBERS> &numbers) {
    array<int, NUMBERS> even{};
    array<int, NUMBERS> odd{};
    int evenCursor = 0;
    int oddCursor = 0;

    for (const auto &num: numbers) {
        if (num % 2 == 0) {
            even[evenCursor] = num;
            evenCursor++;
        } else {
            odd[oddCursor] = num;
            oddCursor++;
        }
    }

    return make_tuple(even, odd);
}

void printArray(array<int, NUMBERS> &numbers) {
    for (int i = 0; i < numbers.size(); i++) {
        cout << i << ": " << numbers[i] << "\n";
    }
}


int main() {
    array<int, NUMBERS> numbers = getRandomArray();
    auto result = run(numbers);
    array<int, NUMBERS> even = get<0>(result);
    array<int, NUMBERS> odd = get<1>(result);

    cout << "Array pari:\n";
    printArray(even);

    cout << "Array dispari:\n";
    printArray(odd);

    return 0;
}