#include <iostream>
#include <fstream>

using namespace std;

struct Node {
    float data;
    Node* next;
    Node(float val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}

    void addElement(float val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void deleteElement(float val) {
        Node* temp = head;
        Node* prev = nullptr;
        while (temp && temp->data != val) {
            prev = temp;
            temp = temp->next;
        }
        if (!temp) {
            cout << "Элемент не найден." << endl;
            return;
        }
        if (!prev) {
            head = temp->next;
        }
        else {
            prev->next = temp->next;
        }
        delete temp;
    }

    void searchElement(float val) {
        Node* temp = head;
        int pos = 0;
        while (temp && temp->data != val) {
            temp = temp->next;
            pos++;
        }
        if (!temp) {
            cout << "Элемент не найден." << endl;
            return;
        }
        cout << "Элемент находится на позиции: " << pos << endl;
    }

    void displayList() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void writeToFile(const string& filename) {
        ofstream outfile(filename);
        if (!outfile.is_open()) {
            cerr << "Невозможно открыть файл для записи." << endl;
            return;
        }
        Node* temp = head;
        while (temp) {
            outfile << temp->data << " ";
            temp = temp->next;
        }
        outfile.close();
    }

    void readFromFile(const string& filename) {
        ifstream infile(filename);
        if (!infile.is_open()) {
            cerr << "Невозможно открыть файл для чтения." << endl;
            return;
        }
        float val;
        while (infile >> val) {
            addElement(val);
        }
        infile.close();
    }

    float calculateAverage() {
        Node* temp = head;
        float sum = 0;
        int count = 0;
        while (temp) {
            if (temp->data > 0) {
                sum += temp->data;
                count++;
            }
            temp = temp->next;
        }
        if (count == 0) {
            cout << "Положительных элементов не найдено." << endl;
            return 0;
        }
        return sum / count;
    }

    void clear() {
        Node* temp;
        while (head) {
            temp = head->next;
            delete head;
            head = temp;
        }
    }

    ~LinkedList() {
        Node* temp;
        while (head) {
            temp = head->next;
            delete head;
            head = temp;
        }
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    LinkedList list;
    int choice;
    float element;
    string filename;

    do {
        cout << "\nМеню:\n"
            << "1. Добавить элемент\n"
            << "2. Удалить элемент\n"
            << "3. Найти элемент\n"
            << "4. Вывести лист\n"
            << "5. Записать в файл\n"
            << "6. Прочитать с файла\n"
            << "7. Найти среднее арифметическое положительных элементов\n"
            << "8. Выход\n"
            << "Выберите пункт: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введите элемент: ";
            cin >> element;
            list.addElement(element);
            break;
        case 2:
            cout << "Введите элемент: ";
            cin >> element;
            list.deleteElement(element);
            break;
        case 3:
            cout << "Введите элемент: ";
            cin >> element;
            list.searchElement(element);
            break;
        case 4:
            list.displayList();
            break;
        case 5:
            cout << "Введите название файла для записи: ";
            cin >> filename;
            list.writeToFile(filename);
            break;
        case 6:
            list.clear(); 
            cout << "Введите название файла для чтения: ";
            cin >> filename;
            list.readFromFile(filename);
            break;
        case 7:
            cout << "Среднее арифметическое положительных элементов: " << list.calculateAverage() << endl;
            break;
        case 8:
            cout << "Выход из программы..." << endl;
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова." << endl;
        }
    } while (choice != 8);

    return 0;
}
