/* Даны вектор V и список L. Каждый исходный контейнер содержит не менее 5 элементов.
Вставить после элемента списка с порядковым номером 5 первые 5 элементов вектора в
обратном порядке. Использовать один вызов функции-члена insert */

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

int main() {
    vector<int> V;
    list<int> L;
    string input_line;
    
    cout << "Введите элементы вектора V (минимум 5 чисел через пробел):" << endl;
    getline(cin, input_line);
    stringstream ss_v(input_line);
    int num;
    while (ss_v >> num) {
        V.push_back(num);
    }
    
    if (V.size() < 5) {
        cout << "Ошибка: вектор должен содержать не менее 5 элементов!" << endl;
        return 1;
    }
    
    cout << "Введите элементы списка L (минимум 5 чисел через пробел):" << endl;
    getline(cin, input_line);
    stringstream ss_l(input_line);
    while (ss_l >> num) {
        L.push_back(num);
    }
    
    if (L.size() < 5) {
        cout << "Ошибка: список должен содержать не менее 5 элементов!" << endl;
        return 1;
    }
    
    cout << "\nИсходный вектор V: ";
    for (auto x : V) cout << x << " ";
    cout << "\nИсходный список L: ";
    for (auto x : L) cout << x << " ";
    cout << endl;
    
    auto list_it = L.begin();
    advance(list_it, 5);
    L.insert(list_it, V.rbegin() + (V.size() - 5), V.rend());
    
    cout << "Список L после вставки: ";
    for (auto x : L) cout << x << " ";
    cout << endl;
    
    return 0;
}