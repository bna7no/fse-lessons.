#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <iomanip>
#include <limits>
using namespace std;

void matrixTask() {
    constexpr int ROWS = 8, COLS = 5;
    vector<vector<int>> mat(ROWS, vector<int>(COLS));

    cout << "Matrix " << ROWS << "x" << COLS
         << "\n1 - random (10..99), 2 - manual: ";

    int mode;
    while (!(cin >> mode) || (mode != 1 && mode != 2)) {
        cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter 1 or 2: ";
    }

    mt19937 rng(static_cast<unsigned>(
        chrono::high_resolution_clock::now().time_since_epoch().count()));
    uniform_int_distribution<int> dist(10, 99);

    for (auto &row : mat)
        for (int &x : row)
            if (mode == 1) {
                x = dist(rng);
            } else {
                while (!(cin >> x)) {
                    cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid. Try again: ";
                }
            }

    cout << "\nMatrix:\n";
    for (const auto &row : mat) {
        for (int x : row) cout << setw(4) << x;
        cout << '\n';
    }
}

void arrayTask() {
    int arr[] = {0, 1, 3, 4, 5, 2, 1, -4, -1, 10, 55};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "\nOriginal array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";

    cout << "\nReversed array: ";
    for (int i = n - 1; i >= 0; i--) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    cout << "Choose task:\n";
    cout << "1 - Matrix creation and display\n";
    cout << "2 - Reverse array output\n";
    cout << "Your choice: ";

    int choice;
    while (!(cin >> choice) || (choice != 1 && choice != 2)) {
        cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter 1 or 2: ";
    }

    cout << endl;
    if (choice == 1)
        matrixTask();
    else
        arrayTask();

    return 0;
}
