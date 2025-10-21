/* Дан вектор V, элементами которого являются английские слова, набранные заглавными
буквами. Определить суммарную длину слов, начинающихся с одной и той же буквы, и вывести
все различные буквы, с которых начинаются элементы вектора V, вместе с суммарной длиной
этих элементов (в алфавитном порядке букв); длину выводить сразу после соответствующей
буквы. Использовать вспомогательное отображение M, ключами которого являются начальные
буквы элементов вектора V, а значениями — суммарная длина этих элементов. При заполнении
отображения M не использовать условные конструкции (достаточно операций индексирования
[], инкремента и функции-члена size для строк). Элементы вектора V (при заполнении
отображения M) и элементы отображения M (при выводе полученных результатов) перебирать
в цикле с параметром-итератором соответствующего контейнера.*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>

using namespace std;

int main() {    
    vector<string> V;
    string input_line;
    
    cout << "Введите английские слова заглавными буквами (через пробел):" << endl;
    getline(cin, input_line);
    
    stringstream ss(input_line);
    string word;
    while (ss >> word) {
        V.push_back(word);
    }
    
    if (V.empty()) {
        cout << "Ошибка: не введено ни одного слова!" << endl;
        return 1;
    }
    
    cout << "Исходный вектор V: ";
    for (const auto& word : V) cout << word << " ";
    cout << endl;
    
    map<char, int> M;
    
    for (const auto& word : V) {
        if (!word.empty()) {
            char first_letter = word[0];
            M[first_letter] += word.size();
        }
    }
    
    cout << "Результат:" << endl;
    for (const auto& pair : M) {
        cout << pair.first << " - " << pair.second << endl;
    }
    
    return 0;
}

// APPLE BANANA ANT BALL CAT CAR DOG