#include <iostream>
#include <fstream>

using namespace std;


struct Node {
    int data;
    Node* next;
};


class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }


    void append(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    
    void remove(int value) {
        if (head == nullptr) {
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* prev = nullptr;
        Node* curr = head;

        while (curr != nullptr && curr->data != value) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr) {
            return; 
        }

        prev->next = curr->next;
        delete curr;
    }

    
    bool search(int value) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == value) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    
    void saveToFile(const string& filename) {
        ofstream outFile(filename);
        if (outFile.is_open()) {
            Node* temp = head;
            while (temp != nullptr) {
                outFile << temp->data << " ";
                temp = temp->next;
            }
            outFile.close();
            cout << "Список успешно записан в файл " << filename << endl;
        }
        else {
            cout << "Ошибка открытия файла для записи" << endl;
        }
    }

    
    void readFromFile(const string& filename) {
        ifstream inFile(filename);
        if (inFile.is_open()) {
            int value;
            clear(); 
            while (inFile >> value) {
                append(value);
            }
            inFile.close();
            cout << "Список успешно считан из файла " << filename << endl;
        }
        else {
            cout << "Ошибка открытия файла для чтения" << endl;
        }
    }

    
    int sumOfNegativeTwoDigitElements() {
        int sum = 0;
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data < 0 && temp->data >= -99 && temp->data <= -10) {
                sum += temp->data;
            }
            temp = temp->next;
        }
        return sum;
    }

    
    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    LinkedList list;

    int choice;
    do {
        cout << "\nМеню:" << endl;
        cout << "1. Добавить элемент" << endl;
        cout << "2. Удалить элемент" << endl;
        cout << "3. Поиск элемента" << endl;
        cout << "4. Вывести список" << endl;
        cout << "5. Записать список в файл" << endl;
        cout << "6. Считать список из файла" << endl;
        cout << "7. Посчитать сумму отрицательных двузначных элементов" << endl;
        cout << "8. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;


        switch (choice) {
        case 1: {
            int value;
            cout << "Введите значение элемента для добавления: ";
            cin >> value;
            list.append(value);
            break;
        }
        case 2: {
            int value;
            cout << "Введите значение элемента для удаления: ";
            cin >> value;
            list.remove(value);
            break;
        }
        case 3: {
            int value;
            cout << "Введите значение элемента для поиска: ";
            cin >> value;
            if (list.search(value)) {
                cout << "Элемент найден в списке" << endl;
            }
            else {
                cout << "Элемент не найден в списке" << endl;
            }
            break;
        }
        case 4: {
            cout << "Список: ";
            list.display();
            break;
        }
        case 5: {
            string filename;
            cout << "Введите имя файла для записи списка: ";
            cin >> filename;
            list.saveToFile(filename);
            break;
        }
        case 6: {
            string filename;
            cout << "Введите имя файла для чтения списка: ";
            cin >> filename;
            list.readFromFile(filename);
            break;
        }
        case 7: {
            int sum = list.sumOfNegativeTwoDigitElements();
            if (sum != 0) {
                cout << "Сумма отрицательных двузначных элементов: " << sum << endl;
            }
            else {
                cout << "Отрицательных двузначных элементов в списке нет" << endl;
            }
            break;
        }
        case 8:
            cout << "Выход из программы..." << endl;
            break;
        default:
            cout << "Попробуйте снова." << endl;
        }
    } while (choice != 8);

    return 0;
}
