#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setlocale(LC_ALL, "ukr");

    vector<int> arr;
    int choiceArr;
    cout << "Оберіть масив:\n1 - стандартний\n2 - власний\n> ";
    cin >> choiceArr;

    if (choiceArr == 1)
        arr = { 0,1,3,4,5,2,1,-4,-1,10,55 };
    else {
        int n; cout << "Кількість елементів: "; cin >> n;
        arr.resize(n);
        cout << "Введіть елементи: ";
        for (int& x : arr) cin >> x;
    }

    // Усі операції з масивом у вигляді лямбда-функцій
    vector<pair<string, function<void()>>> ops = {
        {"Елементи з парними індексами", [&]{ for (size_t i=0;i<arr.size();i+=2) cout<<arr[i]<<" "; }},
        {"Всі елементи",                  [&]{ for (int x:arr) cout<<x<<" "; }},
        {"Елементи до -1",                [&]{ for (int x:arr){ if(x==-1)break; cout<<x<<" "; } }},
        {"Парні елементи",                [&]{ for (int x:arr) if(x%2==0) cout<<x<<" "; }},
        {"Елементи у зворотному порядку", [&]{ for (auto it=arr.rbegin();it!=arr.rend();++it) cout<<*it<<" "; }}
    };

    int choice;
    do {
        cout << "\nМеню функцій:\n";
        for (int i = 0; i < (int)ops.size(); ++i)
            cout << i + 1 << " - " << ops[i].first << '\n';
        cout << "0 - Вихід\n> ";
        cin >> choice;

        if (choice > 0 && choice <= (int)ops.size()) {
            cout << ops[choice - 1].first << ": ";
            ops[choice - 1].second();
            cout << "\n";
        } else if (choice != 0) cout << "Невірний вибір!\n";

    } while (choice != 0);

    cout << "Вихід...\n";
}
