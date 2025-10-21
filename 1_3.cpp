/* Дан набор целых чисел с четным количеством элементов. Заполнить вектор V 
исходными числами, вывести вначале вторую половину элементов вектора V, 
а затем первую половину (в каждой половине порядок элементов не изменять).*/

#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int main() {
    vector<int> V;
    string input_line;
    
    cout << "Введите целые числа через пробел (четное количество):" << endl;
    getline(cin, input_line);
    
    stringstream ss(input_line);
    int num;
    while (ss >> num) {
        V.push_back(num);
    }
    
    if (V.size() % 2 != 0) {
        cout << "Ошибка: количество элементов должно быть четным! " << endl;
        return 1;
    }
    
    if (V.empty()) {
        cout << "Ошибка: не введено ни одного числа!" << endl;
        return 1;
    }
    
    cout << "Все элементы вектора: ";
    for (auto x : V) cout << x << " ";
    cout << endl;
    
    cout << "Результат: ";
    
    for (auto it = V.begin() + V.size()/2; it != V.end(); ++it) {
        cout << *it << " ";
    }

    for (auto it = V.begin(); it != V.begin() + V.size()/2; ++it) {
        cout << *it << " ";
    }
    
    return 0;
}