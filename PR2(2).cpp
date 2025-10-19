#include <iostream>
#include <cmath>
#include <iomanip>
#include <map>
#include <functional>

using namespace std;

const double PI = 3.141592653589793;


double func1(double x) {
    if (x <= 0) throw invalid_argument("x поза областю визначення!");
    if (x <= 0.25) return fabs(log10(PI / 16.0 - x));
    if (x < 1)     return pow(x * x - 0.8, -3.14);
    return acos(x / 4.0);
}

void func2() {
    cout << fixed << setprecision(6);
    for (double x = 0.2; x <= 10.0 + 1e-9; x += 0.8)
        cout << "x=" << setw(6) << x << "  y=" << (x + cos(2 * x)) / (x + 2) << '\n';
}

double func3(double z) {
    if (z < -2 || z > 3) throw invalid_argument("z поза областю визначення!");
    return (z <= 0.5) ? z - sin(z) : atan(1.0 / (z - 0.3));
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setlocale(LC_ALL, "ukr");

    map<int, function<void()>> tasks{
        {1, [] {
            double x; cout << "Введіть x: "; cin >> x;
            cout << "y = " << func1(x) << '\n';
        }},
        {2, func2},
        {3, [] {
            double z; cout << "Введіть z: "; cin >> z;
            cout << "w = " << func3(z) << '\n';
        }}
    };

    for (int choice;;) {
        cout << "\nОберіть функцію:\n"
                "1 - Завдання 1\n"
                "2 - Завдання 2\n"
                "3 - Завдання 3\n"
                "0 - Вихід\n> ";
        if (!(cin >> choice) || choice == 0) break;

        try {
            if (tasks.count(choice)) {
                tasks[choice]();
            } else {
                cout << "Неправильний вибір!\n";
            }
        } catch (const exception& e) {
            cout << "Помилка: " << e.what() << '\n';
        }
    }
    cout << "Вихід...\n";
}
