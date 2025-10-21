/* Даны числа A и B и векторы V1 и V2. Добавить в начало каждого вектора 5 элементов 
со значениями A, а в конец — 5 элементов со значениями B. При преобразовании вектора 
V1 использовать два вызова алгоритма fill_n с функциями inserter и back_inserter 
(данные функции возвращают итераторы вставки), при преобразовании вектора V2 
использовать два вызова функции-члена insert.
Замечание. Второй способ является более эффективным. */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <string>

using namespace std;

int main() {    
    vector<int> V1, V2;
    string input_line;
    int num;
    
    cout << "Введите элементы вектора V1 (через пробел):" << endl;
    getline(cin, input_line);
    stringstream ss1(input_line);
    while (ss1 >> num) V1.push_back(num);
    
    cout << "Введите элементы вектора V2 (через пробел):" << endl;
    getline(cin, input_line);
    stringstream ss2(input_line);
    while (ss2 >> num) V2.push_back(num);
    
    int A, B;
    cout << "Введите число A для добавления в начало: ";
    cin >> A;
    cout << "Введите число B для добавления в конец: ";
    cin >> B;
    cin.ignore();
    
    cout << "Исходный вектор V1: ";
    for (auto x : V1) cout << x << " ";
    cout << "\nИсходный вектор V2: ";
    for (auto x : V2) cout << x << " ";
    cout << endl;
    
    fill_n(inserter(V1, V1.begin()), 5, A);
    fill_n(back_inserter(V1), 5, B);
    
    V2.insert(V2.begin(), 5, A);
    V2.insert(V2.end(), 5, B);
    
    cout << "Вектор V1: ";
    for (auto x : V1) cout << x << " ";
    cout << "\nВектор V2: ";
    for (auto x : V2) cout << x << " ";
    cout << endl;
    
    return 0;
}