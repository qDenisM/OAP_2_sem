#include <iostream>
#include <fstream>

using namespace std;

class Node {
public:
    float data;
    Node* next;

    Node(float val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void addElement(float val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void removeElement(float val) {
        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr && current->data != val) {
            prev = current;
            current = current->next;
        }

        if (current != nullptr) {
            if (prev == nullptr) {
                head = current->next;
            }
            else {
                prev->next = current->next;
            }
            delete current;
        }
    }

    bool findElement(float val) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == val) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void printList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void writeToFile(const string& filename) {
        ofstream file(filename);
        if (file.is_open()) {
            Node* current = head;
            while (current != nullptr) {
                file << current->data << " ";
                current = current->next;
            }
            file.close();
        }
        else {
            cout << "Unable to open file" << endl;
        }
    }

    void readFromFile(const string& filename) {
        ifstream file(filename);
        if (file.is_open()) {
            float val;
            while (file >> val) {
                addElement(val);
            }
            file.close();
        }
        else {
            cout << "Unable to open file" << endl;
        }
    }

    float findProduct() {
        float product = 1.0;
        Node* current = head;
        while (current != nullptr) {
            if (current->data < 10) {
                product *= current->data;
            }
            current = current->next;
        }
        return product;
    }

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    LinkedList list;
    int choice;
    float value;
    string filename;

    do {
        cout << "1. Добавить элемент" << endl;
        cout << "2. Удалить элемент" << endl;
        cout << "3. Поиск элемента" << endl;
        cout << "4. Вывод списка" << endl;
        cout << "5. Запись списка в файл" << endl;
        cout << "6. Считывание списка из файла" << endl;
        cout << "7. Найти произведение элементов < 10" << endl;
        cout << "8. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введите значение элемента: ";
            cin >> value;
            list.addElement(value);
            break;
        case 2:
            cout << "Введите значение элемента для удаления: ";
            cin >> value;
            list.removeElement(value);
            break;
        case 3:
            cout << "Введите значение элемента для поиска: ";
            cin >> value;
            if (list.findElement(value)) {
                cout << "Элемент найден" << endl;
            }
            else {
                cout << "Элемент не найден" << endl;
            }
            break;
        case 4:
            cout << "Список: ";
            list.printList();
            break;
        case 5:
            cout << "Введите имя файла для записи: ";
            cin >> filename;
            list.writeToFile(filename);
            break;
        case 6:
            cout << "Введите имя файла для чтения: ";
            cin >> filename;
            list.readFromFile(filename);
            break;
        case 7:
            cout << "Произведение элементов < 10: " << list.findProduct() << endl;
            break;
        case 8:
            break;
        default:
            cout << "Некорректный ввод" << endl;
        }
    } while (choice != 8);

    return 0;
}
