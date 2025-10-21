/* Дано целое число K (> 0), текстовый файл с именем name1, содержащий английские слова, 
и строка name2. Записать в текстовый файл с именем name2 все слова из исходного файла, 
длина которых не превосходит K, сохранив исходный порядок их следования и располагая 
каждое слово на новой строке. Использовать алгоритм remove_copy_if. */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;

int main() {    
    int K;
    cout << "Введите K (> 0): ";
    cin >> K;
    
    if (K <= 0) {
        cout << "Ошибка: K должно быть больше 0!" << endl;
        return 1;
    }
    
    string input_file = "input.txt";
    string output_file = "output.txt";
    
    ifstream in(input_file);
    if (!in.is_open()) {
        cout << "Ошибка: не удалось открыть файл " << input_file << endl;
        return 1;
    }
    
    ofstream out(output_file);

    remove_copy_if(istream_iterator<string>(in),
                  istream_iterator<string>(),
                  ostream_iterator<string>(out, "\n"),
                  [K](const string& word) { return word.length() > K; });
    
    in.close();
    out.close();
    
    cout << "Файл " << output_file << " создан с словами длиной <= " << K << endl;
    
    return 0;
}