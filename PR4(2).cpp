#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setlocale(LC_ALL, "ukr");

    const int N = 15;
    vector<string> A(N);

    cout << "Введіть " << N << " рядків:\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // щоб прибрати \n після setlocale
    for (auto& s : A) getline(cin, s);

    auto minIt = min_element(A.begin(), A.end(), [](auto& a, auto& b){ return a.size() < b.size(); });
    auto maxIt = max_element(A.begin(), A.end(), [](auto& a, auto& b){ return a.size() < b.size(); });
    iter_swap(minIt, maxIt);

    cout << "\nМасив після обміну:\n";
    for (auto& s : A) cout << s << '\n';
}
