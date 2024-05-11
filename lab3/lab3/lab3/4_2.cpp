#include <iostream> 
#include <fstream> 
#include <string> 
using namespace std; 


void WriteToFile(const string& fileName) {
    ofstream file(fileName); 
    if (file.is_open()) { 
        string line; 
        cout << "Введите строку\n"; 
        getline(cin, line); 
        file << line; 
        file.close(); 
    }
    else {
        cout << "Не удалось открыть файл"; 
    }
}


void ReadFromFile(const string& fileName) {
    ifstream file(fileName); 
    string line, word, LongestWord; 
    int LongestWordLength = 0; 

    if (file.is_open()) { 
        getline(file, line); 
        for (char c : line) { 
            if (c != ' ') { 
                word += c; 
            }
            else { 
                if (word.length() > LongestWordLength) { 
                    LongestWord = word; 
                    LongestWordLength = word.length(); 
                }
                word = ""; 
            }
        }
        if (word.length() > LongestWordLength) { 
            LongestWord = word; 
            LongestWordLength = word.length();         }

        cout << "Самое длинное слово: " << LongestWord << endl; 
        cout << "Длина этого слова: " << LongestWordLength << endl; 
        file.close(); 
    }
    else {
        cout << "Не удалось открыть файл"; 
    }
}

int main() { 
    setlocale(LC_CTYPE, "Russian"); 

    string fileName = "FILE.txt"; 

    WriteToFile(fileName); 
    ReadFromFile(fileName);

    return 0; 
}
