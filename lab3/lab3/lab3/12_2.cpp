#include <iostream>
#include <fstream>
#include <cstdlib>
#include <windows.h>

using namespace std;

void writeToFile(const char* filename, const char* data) {
    ofstream file(filename);
    if (file.is_open()) {
        const char* ptr = data;
        while (*ptr != '\0') {
            file.put(*ptr);
            ++ptr;
        }
        file.close();
    }
    else {
        cerr << "Невозможно открыть файл для записи." << endl;
    }
}

void readAndPrintOddNumbers(const char* filename) {
    ifstream file(filename);
    if (file.is_open()) {
        char character;
        char number[100];
        int numberIndex = 0;

        while (file.get(character)) {
            if (isdigit(character)) {
                number[numberIndex++] = character;
            }
            else if (numberIndex > 0) {
                number[numberIndex] = '\0';
                int num = atoi(number); 
                if (num % 2 != 0) {
                    cout << num << " ";
                }
                numberIndex = 0;
            }
        }

        
        if (numberIndex > 0) {
            number[numberIndex] = '\0';
            int num = atoi(number);
            if (num % 2 != 0) {
                cout << num << " ";
            }
        }

        file.close();
    }
    else {
        cerr << "Невозможно открыть файл для чтения." << endl;
    }
}


int main() {
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Введите строку символов (цифры и слова, разделенные пробелами): ";
    char inputString[100];
    char character;
    int index = 0;

    while (cin.get(character) && character != '\n' && index < 99) {
        inputString[index++] = character;
    }
    inputString[index] = '\0';

    const char* filename = "data.txt";
    writeToFile(filename, inputString);

    cout << "Нечетные числа из файла: ";
    readAndPrintOddNumbers(filename);

    return 0;
}