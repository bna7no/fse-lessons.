#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;

void task1() {
    const int n = 17;
    vector<double> X(n);

    cout << "Оберiть спосiб введення:\n1 - Готовий масив\n2 - Власний масив\n> ";
    int choice; cin >> choice;

    if (choice == 1)
        X = { 2.3,4.0,8.9,6.3,4.9,7.8,6.5,5.1,3.8,4.0,-3.0,-5.1,-7.2,-1.5,-0.8,2.0,-4.6 };
    else if (choice == 2) {
        cout << "Введiть " << n << " елементiв:\n";
        for (int i = 0; i < n; i++) { cout << "X[" << i + 1 << "] = "; cin >> X[i]; }
    } else return (void)cout << "Невiрний вибiр\n";

    double sum = 0;
    for (int i = 1; i < n; i += 2) if (X[i] < 0) sum += X[i];
    cout << "Сума вiд’ємних елементiв на парних мiсцях = " << sum << '\n';
}

void task2() {
    int m, n;
    cout << "Введiть кiлькiсть векторiв (m<=6): "; cin >> m;
    cout << "Введiть розмiрнiсть (n<7): "; cin >> n;

    vector<vector<double>> A(m, vector<double>(n));
    cout << "Введiть координати векторiв:\n";
    for (int i = 0; i < m; i++) {
        cout << "Вектор " << i + 1 << ": ";
        for (double& x : A[i]) cin >> x;
    }

    vector<double> lengths(m);
    for (int i = 0; i < m; i++)
        lengths[i] = sqrt(inner_product(A[i].begin(), A[i].end(), A[i].begin(), 0.0));

    int minIndex = min_element(lengths.begin(), lengths.end()) - lengths.begin();

    cout << fixed << setprecision(4) << "\nДовжини векторiв:\n";
    for (int i = 0; i < m; i++)
        cout << "Вектор " << i + 1 << " -> " << lengths[i] << '\n';

    cout << "\nМiнiмальна довжина має вектор №" << minIndex + 1
         << " = " << lengths[minIndex] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setlocale(LC_ALL, "ukr");

    for (int choice;;) {
        cout << "\nОберiть завдання:\n1 - Масив\n2 - Матриця векторiв\n0 - Вихiд\n> ";
        cin >> choice;
        if (choice == 0) break;
        else if (choice == 1) task1();
        else if (choice == 2) task2();
        else cout << "Невiрний вибiр!\n";
    }
    cout << "Вихiд...\n";
}
