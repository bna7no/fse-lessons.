#include <iostream>
#include <iomanip>
using namespace std;

class Time {
private:
    int h, m, s;

    // Перевірка правильності значень
    void normalize() {
        if (s >= 60) { m += s / 60; s %= 60; }
        if (m >= 60) { h += m / 60; m %= 60; }
        if (s < 0) { int borrow = (-s + 59) / 60; m -= borrow; s += 60 * borrow; }
        if (m < 0) { int borrow = (-m + 59) / 60; h -= borrow; m += 60 * borrow; }
        if (h < 0) h = (h % 24 + 24) % 24;
        if (h >= 24) h %= 24;
    }

public:
    // Конструктори
    Time() : h(0), m(0), s(0) {}
    Time(int hh, int mm, int ss) : h(hh), m(mm), s(ss) { normalize(); }

    // Деструктор
    ~Time() { cout << "\nОб'єкт Time знищено\n"; }

    // Ввід і вивід
    void input() {
        cout << "Введіть години, хвилини, секунди: ";
        cin >> h >> m >> s;
        normalize();
    }

    void output() const {
        cout << setfill('0') << setw(2) << h << ":"
             << setw(2) << m << ":" << setw(2) << s;
    }

    // Обчислення часу до кінця доби
    void timeToMidnight() const {
        int totalSec = 24 * 3600 - (h * 3600 + m * 60 + s);
        int hh = totalSec / 3600;
        int mm = (totalSec % 3600) / 60;
        int ss = totalSec % 60;
        cout << "\nДо кінця доби залишилось: "
             << hh << " год " << mm << " хв " << ss << " с.\n";
    }

    // Перевантаження операторів + і -
    Time operator+(const Time& t) const {
        Time res(h + t.h, m + t.m, s + t.s);
        res.normalize();
        return res;
    }

    Time operator-(const Time& t) const {
        Time res(h - t.h, m - t.m, s - t.s);
        res.normalize();
        return res;
    }
};

int main() {
    setlocale(LC_ALL, "ukr");

    cout << "=== Робота з класом Time ===\n";

    Time t1, t2;
    cout << "\nПерший час:\n";
    t1.input();
    cout << "\nДругий час:\n";
    t2.input();

    cout << "\nПерший час: "; t1.output();
    cout << "\nДругий час: "; t2.output();

    Time sum = t1 + t2;
    cout << "\n\nСума часу: "; sum.output();

    Time diff = t1 - t2;
    cout << "\nРізниця часу: "; diff.output();

    cout << "\n";
    t1.timeToMidnight();

    cout << "\n";
    return 0;
}