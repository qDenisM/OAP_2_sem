#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Word {
    string keyword;
    string helpMessage;
};

const int TABLE_SIZE = 20;
vector<vector<Word>> hashTable(TABLE_SIZE);

int hashFunction(const string& keyword) {
    int hash = 0;
    for (char c : keyword) {
        hash += c;
    }
    return hash % TABLE_SIZE;
}

void addWord(const string& keyword, const string& helpMessage) {
    int index = hashFunction(keyword);
    hashTable[index].push_back({ keyword, helpMessage });
}
void addOrUpdateWord(const string& keyword, const string& helpMessage) {
    int index = hashFunction(keyword);
    for (auto& word : hashTable[index]) {
        if (word.keyword == keyword) {
            cout << "Подсказка обновляется..." << endl;
            word.helpMessage = helpMessage;
            return;
        }
    }

    // Слово не найдено, не добавляем его
    cout << "Зарезервированное слово не найдено." << endl;
}


void displayHelp(const string& keyword) {
    int index = hashFunction(keyword);
    for (const auto& word : hashTable[index]) {
        if (word.keyword == keyword) {
            cout << "Подсказка для " << keyword << ": " << word.helpMessage << endl;
            return;
        }
    }
    cout << "Зарезервированное слово: " << keyword << endl;
}

void displayTable() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        cout << "Ячейка " << i << ": ";
        for (const auto& word : hashTable[i]) {
            cout << word.keyword << " ";
        }
        cout << endl;
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    addWord("int", "Зарезервированное слово для целочисленного значение.");
    addWord("float", "Зарезервированное слово для чисел с плавающей точкой.");
    addWord("for", "Зарезервированное слово для loop iteration");
    addWord("while", "Зарезервированное слово для loop iteration");
    addWord("if", "Зарезервированное слово для conditional statement");
    addWord("else", "Зарезервированное слово для conditional statement");
    addWord("return", "Зарезервированное слово для returning a value from a function");
    addWord("switch", "Зарезервированное слово для switch statement");
    addWord("case", "Зарезервированное слово для case in switch statement");
    addWord("break", "Зарезервированное слово для breaking out of a loop or switch statement");
    addWord("continue", "Зарезервированное слово для continuing to the next iteration of a loop");
    addWord("void", "Зарезервированное слово показывает что a function does not return a value");
    addWord("const", "Зарезервированное слово показывает что a variable is constant");
    addWord("static", "Зарезервированное слово показывает что a variable or function is static");
    addWord("class", "Зарезервированное слово для defining a class");
    addWord("struct", "Зарезервированное слово для defining a struct");
    addWord("enum", "Зарезервированное слово для defining an enumeration");
    addWord("namespace", "Зарезервированное слово для defining a namespace");
    addWord("using", "Зарезервированное слово для using a namespace");
    addWord("public", "Зарезервированное слово для public access in a class or struct");
    addWord("private", "Зарезервированное слово для private access in a class or struct");
    addWord("protected", "Зарезервированное слово для protected access in a class or struct");

    int choice;
    string keyword, helpMessage;

    do {
        cout << "1. Обновить подсказку" << endl;
        cout << "2. Вывести подсказка для зарезервированного слова" << endl;
        cout << "3. Вывести все зарезервированные слова" << endl;
        cout << "4. Выход" << endl;
        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введите зарезервированное слово: ";
            cin >> keyword;
            cout << "Введите подсказку: ";
            cin.ignore(); // clear buffer
            getline(cin, helpMessage);
            addOrUpdateWord(keyword, helpMessage);
            break;
        case 2:
            cout << "Введите зарезервированное слово для отображения подсказки: ";
            cin >> keyword;
            displayHelp(keyword);
            break;
        case 3:
            displayTable();
            break;
        case 4:
            cout << "Выход из программы..." << endl;
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова" << endl;
            break;
        }

    } while (choice != 4);

    return 0;
}
