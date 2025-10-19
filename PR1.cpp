#include <iostream>
#include <cmath>
#include <iomanip>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    double x;
    cout << "Введіть x (0 < x < 1): ";
    if (!(cin >> x)) {
        cerr << "Помилка вводу\n";
        return 1;
    }

    if (!(x > 0.0 && fabs(x) < 1.0)) {
        cerr << "Помилка: x має задовольняти 0 < x < 1.\n";
        return 1;
    }

    double ln_x = log(x);
    double exp_arg = x*x*x - x*x - 4.0 * ln_x;
    double term1 = exp(exp_arg);

    double tanx = tan(x);
    if (fabs(tanx) < 1e-12) {
        cerr << "Помилка: tan(x) близький до 0, ctg(x) не визначений.\n";
        return 1;
    }
    double term2 = 1.0 / tanx;

    double inside_lg = 1.0 - x*x;
    if (inside_lg <= 0.0) {
        cerr << "Помилка: аргумент lg(1-x^2) <= 0.\n";
        return 1;
    }
    double term3 = log10(inside_lg);

    double y = term1 + term2 - term3;

    cout << fixed << setprecision(10);
    cout << "y = " << y << endl;

    system("pause");
    return 0;
}
