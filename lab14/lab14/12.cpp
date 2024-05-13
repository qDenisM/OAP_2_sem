#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;

const int TABLE_SIZE = 10;

struct Tenant {
    int apartmentNumber;
    char name[50];
    Tenant* next;
};

class HashTable {
private:
    Tenant* table[TABLE_SIZE];

    int hash(int key) {
        return key % TABLE_SIZE;
    }

    int hash(const char* str) {
        int hashValue = 0;
        while (*str) {
            hashValue ^= *str++;
        }
        return hashValue % TABLE_SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = nullptr;
        }
    }

    void insert(int apartmentNumber, const char* name) {
        int index = hash(apartmentNumber);
        Tenant* newTenant = new Tenant;
        newTenant->apartmentNumber = apartmentNumber;
        strcpy_s(newTenant->name, sizeof(newTenant->name), name);
        newTenant->next = table[index];
        table[index] = newTenant;
    }

    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            Tenant* current = table[i];
            cout << "Хеш " << i << ": ";
            while (current != nullptr) {
                cout << "[" << current->apartmentNumber << ", " << current->name << "] ";
                current = current->next;
            }
            cout << endl;
        }
    }

    void runMenu() {
        int choice;
        do {
            cout << "\nМеню:\n";
            cout << "1. Добавить жильца\n";
            cout << "2. Вывести всех жильцов\n";
            cout << "0. Выйти\n";
            cout << "Выберите действие: ";
            cin >> choice;

            switch (choice) {
            case 1: {
                int apartmentNumber;
                char name[50];
                cout << "Введите номер квартиры: ";
                cin >> apartmentNumber;
                cout << "Введите имя жильца: ";
                cin.ignore(); // Clear input buffer
                cin.getline(name, 50);
                insert(apartmentNumber, name);
                break;
            }
            case 2: {
                display();
                break;
            }
            case 0: {
                cout << "Выход из программы.\n";
                break;
            }
            default: {
                cout << "Неверный ввод. Попробуйте снова.\n";
                break;
            }
            }
        } while (choice != 0);
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    HashTable ht;

    ht.runMenu();

    return 0;
}
