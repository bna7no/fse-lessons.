#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void task33() {
    const int N = 5;
    double a[N];
    cout << "\n[Завдання 33] Введення і вивід масиву дійсних чисел\n";
    cout << "Введіть 5 дійсних чисел:\n";
    for (int i = 0; i < N; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
    cout << "\nВведений масив:\n";
    for (int i = 0; i < N; i++) cout << a[i] << " ";
    cout << endl;
}

void task35() {
    cout << "\n[Завдання 35] Пошук заданого числа в масиві\n";
    int n;
    cout << "Введіть кількість елементів масиву: ";
    cin >> n;
    double a[100];
    cout << "Введіть елементи масиву:\n";
    for (int i = 0; i < n; i++) cin >> a[i];
    double x;
    cout << "Введіть число для пошуку: ";
    cin >> x;

    bool found = false;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            cout << "Число знайдено на позиції " << i << endl;
            found = true;
        }
    }
    if (!found) cout << "Число не знайдено.\n";
}

void task38() {
    cout << "\n[Завдання 38] Інверсія рядка\n";
    cin.ignore(); // щоб очистити буфер після попередніх cin
    string s;
    cout << "Введіть рядок: ";
    getline(cin, s);
    reverse(s.begin(), s.end());
    cout << "Інвертований рядок: " << s << endl;
}

int main() {
    setlocale(0, ".1251"); // підтримка української мови в Windows консолі

    int choice;
    do {
        cout << "\n==============================\n";
        cout << "Виберіть завдання:\n";
        cout << "1 - Завдання 33 (масив дійсних чисел)\n";
        cout << "2 - Завдання 35 (пошук у масиві)\n";
        cout << "3 - Завдання 38 (інверсія рядка)\n";
        cout << "0 - Вихід\n";
        cout << "==============================\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
            case 1: task33(); break;
            case 2: task35(); break;
            case 3: task38(); break;
            case 0: cout << "Вихід із програми.\n"; break;
            default: cout << "Неправильний вибір!\n";
        }
    } while (choice != 0);

    return 0;
}
