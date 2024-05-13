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
        cout << "������ " << i << ": ";
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
        cout << "������ �������� �����!" << endl;
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
        cout << "\n����:" << endl;
        cout << "1. ������� ������� ����" << endl;
        cout << "2. ����� �����" << endl;
        cout << "3. ������� �����, ������������ � �����" << endl;
        cout << "4. �����" << endl;
        cout << "�������� ��������: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\n���-�������:" << endl;
            hashTable.display();
            break;
        case 2:
            cout << "\n������� ����� ��� ������: ";
            cin >> searchWord;
            if (hashTable.search(searchWord)) {
                cout << "����� �������!" << endl;
            }
            else {
                cout << "����� �� �������." << endl;
            }
            break;
        case 3:
            cout << "\n������� ����� ��� �������� ����, ������������ �� ��� �����: ";
            cin >> letter;
            hashTable.removeWordsStartingWith(letter);
            cout << "����� �������." << endl;
            break;
        case 4:
            cout << "����� �� ���������..." << endl;
            break;
        default:
            cout << "�������� �����. ���������� ��� ���." << endl;
        }
    } while (choice != 4);

    return 0;
}
