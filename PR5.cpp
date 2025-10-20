#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Train {
    int number;             // номер потяга
    char destination[30];   // станція призначення
    char departure[10];     // час відправки
    float time;             // час у дорозі (години)
};

int main() {
    const int n = 5;
    Train trains[n];
    ofstream fout("trains.txt", ios::out);

    cout << "Введіть дані про потяги, що відправляються зі станції Здолбунів:\n";
    for (int i = 0; i < n; i++) {
        cout << "\nПотяг №" << i + 1 << endl;
        cout << "Номер потяга: ";
        cin >> trains[i].number;
        cout << "Станція призначення: ";
        cin >> trains[i].destination;
        cout << "Час відправки (год:хв): ";
        cin >> trains[i].departure;
        cout << "Час у дорозі (годин): ";
        cin >> trains[i].time;

        fout << trains[i].number << " "
             << trains[i].destination << " "
             << trains[i].departure << " "
             << trains[i].time << endl;
    }
    fout.close();

    ifstream fin("trains.txt", ios::in);
    cout << "\nПотяги, що йдуть до Львова:\n";
    Train t;
    while (fin >> t.number >> t.destination >> t.departure >> t.time) {
        if (strcmp(t.destination, "Львів") == 0 || strcmp(t.destination, "Lviv") == 0)
            cout << "№" << t.number << "  "
                 << t.destination << "  "
                 << t.departure << "  "
                 << t.time << " год." << endl;
    }
    fin.close();

    return 0;
}