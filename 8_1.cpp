/* Дан список L. Получить вектор V вещественных чисел, содержащий значения среднего
арифметического для всех пар соседних элементов исходного списка (количество элементов
вектора V должно быть на 1 меньше количества элементов списка L). Например, для исходного
списка 1, 3, 4, 6 полученный вектор должен содержать значения 2.0, 3.5, 5.0. Использовать
алгоритм adjacent_difference с итератором вставки и функциональным объектом, а также
функцию-член erase для вектора V. */

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <sstream>
#include <string>

using namespace std;

int main() {    
    list<int> L;
    string input_line;
    
    cout << "Введите элементы списка L (минимум 2 числа через пробел):" << endl;
    getline(cin, input_line);
    
    stringstream ss(input_line);
    int num;
    while (ss >> num) {
        L.push_back(num);
    }
    
    if (L.size() < 2) {
        cout << "Ошибка: список должен содержать не менее 2 элементов!" << endl;
        return 1;
    }
    
    cout << "Исходный список L: ";
    for (auto x : L) cout << x << " ";
    cout << endl;
    
    vector<double> V;
    
    adjacent_difference(L.begin(), L.end(), back_inserter(V),
                       [](int a, int b) { return (a + b) / 2.0; });
    
    V.erase(V.begin());
    
    cout << "Вектор V со средними значениями: ";
    for (auto x : V) cout << x << " ";
    cout << endl;
    
    return 0;
}