/* Дан вектор V0, целое число N (> 0) и набор векторов V1, …, VN. Известно, что размер 
вектора V0 не превосходит размера любого из векторов V1, …, VN. Найти количество векторов 
VI, I = 1, …, N, в которых содержатся все элементы вектора V0 (без учета их повторений). 
Использовать алгоритм includes, применяя его в цикле к двум множествам, одно из которых 
создано на основе вектора V0, а другое на очередной итерации содержит элементы очередного 
из векторов VI, I = 1, …, N. */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

int main() {    
    vector<int> V0;
    vector<vector<int>> vectors;
    string input_line;
    int num_vectors;
    
    cout << "Введите элементы базового вектора V0 (через пробел):" << endl;
    getline(cin, input_line);
    stringstream ss0(input_line);
    int num;
    while (ss0 >> num) V0.push_back(num);
    
    cout << "Введите количество векторов для проверки: ";
    cin >> num_vectors;
    cin.ignore();
    
    for (int i = 0; i < num_vectors; ++i) {
        vector<int> current_vec;
        cout << "Введите элементы вектора " << i+1 << " (через пробел):" << endl;
        getline(cin, input_line);
        stringstream ss(input_line);
        while (ss >> num) current_vec.push_back(num);
        vectors.push_back(current_vec);
    }
    
    cout << "Базовый вектор V0: ";
    for (auto x : V0) cout << x << " ";
    cout << endl;
    
    set<int> S0(V0.begin(), V0.end());
    int count = 0;
    
    for (size_t i = 0; i < vectors.size(); ++i) {
        set<int> S_i(vectors[i].begin(), vectors[i].end());
        if (includes(S_i.begin(), S_i.end(), S0.begin(), S0.end())) {
            count++;
            cout << "Вектор " << i+1 << " содержит все элементы V0" << endl;
        }
    }
    
    cout << "Количество векторов, содержащих все элементы V0: " << count << endl;
    
    return 0;
}