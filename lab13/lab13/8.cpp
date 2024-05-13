#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

struct Entry {
    string key;
    int hTag;
    bool deleted;
};

class HashTable {
private:
    Entry* table;
    int size;
    int capacity;
    const double LOAD_FACTOR_THRESHOLD = 0.5;

    int hashFunction(const string& key) {
        int hash = 0;
        for (char ch : key) {
            hash += static_cast<int>(ch);
        }
        return hash % capacity;
    }

    void rehash() {
        int newCapacity = capacity * 2;
        Entry* newTable = new Entry[newCapacity];
        for (int i = 0; i < capacity; ++i) {
            if (!table[i].key.empty() && !table[i].deleted) {
                int index = hashFunction(table[i].key);
                while (!newTable[index].key.empty()) {
                    index = (index + 1) % newCapacity;
                }
                newTable[index] = table[i];
            }
        }
        delete[] table;
        table = newTable;
        capacity = newCapacity;
    }

public:
    HashTable(int initialCapacity) : size(0), capacity(initialCapacity) {
        table = new Entry[capacity];
    }

    ~HashTable() {
        delete[] table;
    }

    void insert(const string& key) {
        if (static_cast<double>(size) / capacity >= LOAD_FACTOR_THRESHOLD) {
            cout << "��������� ������� ���-�������. ��������� ��: " << capacity << ", ������: " << size << endl;
            rehash();
            cout << "��������� �����: " << capacity << endl;
        }

        int index = hashFunction(key);
        while (!table[index].key.empty() && !table[index].deleted) {
            index = (index + 1) % capacity;
        }
        table[index].key = key;
        table[index].hTag = index;
        table[index].deleted = false;
        size++;
    }

    bool search(const string& key) {
        int index = hashFunction(key);
        while (!table[index].key.empty() && (table[index].key != key || table[index].deleted)) {
            index = (index + 1) % capacity;
        }
        return !table[index].key.empty() && !table[index].deleted;
    }

    void remove(const string& key) {
        int index = hashFunction(key);
        while (!table[index].key.empty() && (table[index].key != key || table[index].deleted)) {
            index = (index + 1) % capacity;
        }
        if (!table[index].key.empty() && !table[index].deleted) {
            table[index].key.clear();
            table[index].deleted = true;
            size--;
            cout << "���� ������." << endl;
        }
        else {
            cout << "���� �� ������." << endl;
        }
    }

    void printTable() {
        cout << "���-�������:" << endl;
        for (int i = 0; i < capacity; ++i) {
            if (!table[i].key.empty() && !table[i].deleted) {
                cout << "[" << i << "]: " << table[i].key << endl;
            }
        }
    }

    int getSize() {
        return size;
    }

    void printMenu() {
        cout << "1. �������� ����" << endl;
        cout << "2. ����� �����" << endl;
        cout << "3. ������� ����" << endl;
        cout << "4. ������� ���-�������" << endl;
        cout << "5. ������� ������ ���-�������" << endl;
        cout << "6. �����" << endl;
    }

    void processMenu() {
        int choice;
        string key;
        do {
            printMenu();
            cout << "�������� ��������: ";
            cin >> choice;
            switch (choice) {
            case 1:
                cout << "������� ���� ��� �������: ";
                cin >> key;
                insert(key);
                break;
            case 2:
                cout << "������� ���� ��� ������: ";
                cin >> key;
                cout << (search(key) ? "���� ������" : "���� �� ������") << endl;
                break;
            case 3:
                cout << "������� ���� ��� ��������: ";
                cin >> key;
                remove(key);
                break;
            case 4:
                printTable();
                break;
            case 5:
                cout << "������ ���-�������: " << getSize() << endl;
                break;
            case 6:
                cout << "����� �� ���������..." << endl;
                break;
            default:
                cout << "�������� �����. ���������� �����." << endl;
            }
        } while (choice != 6);
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    HashTable hashTable(16);
    hashTable.processMenu();

    return 0;
}
