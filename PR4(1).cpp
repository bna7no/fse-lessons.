#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

struct Student {
    string name;
    int marks[4]; // 0 - інформ, 1 - матем, 2 - фізика, 3 - програмування
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setlocale(LC_ALL, "ukr");

    vector<Student> group = {
        {"Іванчук С.О.", {4,3,3,4}},
        {"Панченко І.А.", {5,4,4,5}},
        {"Заєць О.М.", {3,4,4,4}},
        {"Вельбицький П.О.", {4,3,3,3}},
        {"Сидоренко В.Р.", {2,3,3,2}},
        {"Кравченко З.І.", {3,5,4,5}},
        {"Якубів Р.Н.", {5,4,4,3}},
        {"Зоренко П.М.", {4,2,3,3}},
        {"Берестяк Г.С.", {4,5,5,5}},
        {"Дячик Н.С.", {5,5,4,4}}
    };

    const string subjects[] = { "Інформатика", "Вища матем.", "Фізика", "Програмування" };
    double sum[4] = {};

    cout << left << setw(4) << "№" << setw(20) << "Прізвище";
    for (auto& s : subjects) cout << setw(15) << s;
    cout << "\n" << string(70, '-') << "\n";

    int i = 1;
    for (auto& st : group) {
        cout << left << setw(4) << i++ << setw(20) << st.name;
        for (int j = 0; j < 4; j++) {
            cout << setw(15) << st.marks[j];
            sum[j] += st.marks[j];
        }
        cout << '\n';
    }

    cout << string(70, '-') << "\n" << setw(24) << "Середній бал:";
    for (int j = 0; j < 4; j++)
        cout << setw(15) << fixed << setprecision(2) << sum[j] / group.size();
    cout << '\n';
}
