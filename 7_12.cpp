/* Дан вектор V с четным количеством элементов. Известно, что первая половина вектора 
уже отсортирована по возрастанию. Отсортировать все элементы вектора по возрастанию,
выполнив вначале сортировку его второй половины алгоритмом sort, а затем слияние обеих
половин алгоритмом inplace_merge. Выводить новое содержимое вектора V после применения
каждого алгоритма. */

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

int main() {    
    vector<int> V;
    string input_line;
    
    cout << "Введите элементы вектора V (четное количество чисел через пробел):" << endl;
    getline(cin, input_line);
    
    stringstream ss(input_line);
    int num;
    while (ss >> num) {
        V.push_back(num);
    }
    
    if (V.size() % 2 != 0) {
        cout << "Ошибка: вектор должен иметь четное количество элементов! Введено: " << V.size() << endl;
        return 1;
    }
    
    if (V.empty()) {
        cout << "Ошибка: вектор пустой!" << endl;
        return 1;
    }

    auto mid = V.begin() + V.size() / 2;

    if (!is_sorted(V.begin(), mid)) {
        cout << "Ошибка: первая половина вектора не отсортирована по возрастанию!" << endl;
        return 1;
    }
    
    cout << "Исходный вектор V: ";
    for (auto x : V) cout << x << " ";
    cout << endl;
    
    sort(mid, V.end());
    
    cout << "После сортировки второй половины: ";
    for (auto x : V) cout << x << " ";
    cout << endl;
    
    inplace_merge(V.begin(), mid, V.end());
    
    cout << "После слияния половин: ";
    for (auto x : V) cout << x << " ";
    cout << endl;
    
    return 0;
}