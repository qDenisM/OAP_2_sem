#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    setlocale(LC_CTYPE, "Russian");
    ifstream file1("FILE1.txt");
    ofstream file2("FILE2.txt");
    string line;
    int count = 0;

    if (file1.is_open() && file2.is_open()) {
        while (getline(file1, line)) {
            bool containsDigit = false;
            for (char c : line) {
                if (isdigit(c)) {
                    containsDigit = true;
                    break;
                }
            }

            if (!containsDigit) {
                file2 << line << endl;
                if (line[0] == 'A') {
                    count++;
                }
            }
        }

        file1.close();
        file2.close();

        cout << "Количество строк, начинающихся на букву 'А' в файле FILE2: " << count << endl;
    }
    else {
        cout << "Не удалось открыть файлы." << endl;
    }

    return 0;
}
