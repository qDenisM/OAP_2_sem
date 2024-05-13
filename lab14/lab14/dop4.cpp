#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

const int TABLE_SIZE = 100;


struct HashTableItem {
    int key;
    bool filled;
    HashTableItem() : key(0), filled(false) {}
};


struct HashTable {
    vector<HashTableItem> table;
    HashTable() : table(TABLE_SIZE) {}

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }


    void insert(int key) {
        int index = hashFunction(key);
        while (table[index].filled) {
            index = (index + 1) % TABLE_SIZE;
        }
        table[index].key = key;
        table[index].filled = true;
    }


    bool search(int key, int& comparisons) {
        int index = hashFunction(key);
        while (table[index].filled) {
            comparisons++;
            if (table[index].key == key) {
                return true;
            }
            index = (index + 1) % TABLE_SIZE;
        }
        return false;
    }
};


void buildHashTableFromFile(HashTable& hashTable, const string& filename) {
    ifstream file(filename);
    int number;
    while (file >> number) {
        hashTable.insert(number);
    }
    file.close();
}

int main() {
    HashTable hashTable;

    int choice;
    do {
        cout << "����:" << endl;
        cout << "1. ��������� ���-������� �� �����" << endl;
        cout << "2. ����� ����� � ���-�������" << endl;
        cout << "3. �����" << endl;
        cout << "��� �����: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string filename;
            cout << "������� �������� �����: ";
            cin >> filename;
            buildHashTableFromFile(hashTable, filename);
            break;
        }
        case 2: {
            int number;
            cout << "������� ����� ��� ������: ";
            cin >> number;
            int comparisons = 0;
            bool found = hashTable.search(number, comparisons);
            if (found) {
                cout << "����� �������." << endl;
            }
            else {
                cout << "����� �� �������." << endl;
            }
            break;
        }
        case 3: {
            cout << "����� �� ���������..." << endl;
            break;
        }
        default: {
            cout << "�������� �����. ���������� �����." << endl;
            break;
        }
        }
    } while (choice != 3);

    return 0;
}
