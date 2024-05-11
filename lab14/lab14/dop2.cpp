#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

class HashTable {
private:
    static const int SIZE = 20;
    list<string> table[SIZE];
    int hashFunction(const string& word);

public:
    void insert(const string& word);
    void display();
    bool search(const string& word);
    void removeWordsStartingWith(char letter);
};

int HashTable::hashFunction(const string& word) {
    int sum = 0;
    for (char c : word) {
        sum += c;
    }
    return sum % SIZE;
}

void HashTable::insert(const string& word) {
    int index = hashFunction(word);
    table[index].push_back(word);
}

void HashTable::display() {
    for (int i = 0; i < SIZE; ++i) {
        cout << "Ячейка " << i << ": ";
        for (const string& word : table[i]) {
            cout << word << " ";
        }
        cout << endl;
    }
}

bool HashTable::search(const string& word) {
    int index = hashFunction(word);
    return find(table[index].begin(), table[index].end(), word) != table[index].end();
}

void HashTable::removeWordsStartingWith(char letter) {
    for (int i = 0; i < SIZE; ++i) {
        table[i].remove_if([=](const string& word) {
            return word[0] == letter;
            });
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    HashTable hashTable;
    ifstream file("text.txt");

    if (!file.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return 1;
    }

    string word;
    while (file >> word) {
        hashTable.insert(word);
    }

    file.close();

    int choice;
    char letter;
    string searchWord;

    do {
        cout << "\nМеню:" << endl;
        cout << "1. Вывести таблицу слов" << endl;
        cout << "2. Поиск слова" << endl;
        cout << "3. Удалить слова, начинающиеся с буквы" << endl;
        cout << "4. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\nХеш-таблица:" << endl;
            hashTable.display();
            break;
        case 2:
            cout << "\nВведите слово для поиска: ";
            cin >> searchWord;
            if (hashTable.search(searchWord)) {
                cout << "Слово найдено!" << endl;
            }
            else {
                cout << "Слово не найдено." << endl;
            }
            break;
        case 3:
            cout << "\nВведите букву для удаления слов, начинающихся на эту букву: ";
            cin >> letter;
            hashTable.removeWordsStartingWith(letter);
            cout << "Слова удалены." << endl;
            break;
        case 4:
            cout << "Выход из программы..." << endl;
            break;
        default:
            cout << "Неверный выбор. Попробуйте еще раз." << endl;
        }
    } while (choice != 4);

    return 0;
}
