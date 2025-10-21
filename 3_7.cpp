/* Даны списки L1 и L2, имеющие четное количество элементов. Поменять местами первую
половину исходного списка L1 и вторую половину исходного списка L2. Использовать два
вызова функции-члена splice. */

#include <iostream>
#include <list>
#include <sstream>
#include <string>

using namespace std;

int main() {    
    list<int> L1, L2;
    string input_line;
    int num;
    
    cout << "Введите элементы списка L1 (четное количество чисел через пробел):" << endl;
    getline(cin, input_line);
    stringstream ss1(input_line);
    while (ss1 >> num) L1.push_back(num);
    
    cout << "Введите элементы списка L2 (четное количество чисел через пробел):" << endl;
    getline(cin, input_line);
    stringstream ss2(input_line);
    while (ss2 >> num) L2.push_back(num);
    
    if (L1.size() % 2 != 0 || L2.size() % 2 != 0) {
        cout << "Ошибка: оба списка должны иметь четное количество элементов!" << endl;
        return 1;
    }
    
    cout << "Исходный список L1: ";
    for (auto x : L1) cout << x << " ";
    cout << "\nИсходный список L2: ";
    for (auto x : L2) cout << x << " ";
    cout << endl;
    
    auto L1_mid = L1.begin();
    advance(L1_mid, L1.size() / 2);
    list<int> temp1(L1.begin(), L1_mid);
    
    auto L2_mid = L2.begin();
    advance(L2_mid, L2.size() / 2);
    list<int> temp2(L2_mid, L2.end());
    
    L1.erase(L1.begin(), L1_mid);
    L2.erase(L2_mid, L2.end());

    L1.splice(L1.begin(), temp2);
    L2.splice(L2.end(), temp1);
    
    cout << "Список L1 после обмена: ";
    for (auto x : L1) cout << x << " ";
    cout << "\nСписок L2 после обмена: ";
    for (auto x : L2) cout << x << " ";
    cout << endl;
    
    return 0;
}