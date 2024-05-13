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
            cout << "������ ������� ������� � ���� " << filename << endl;
        }
        else {
            cout << "������ �������� ����� ��� ������" << endl;
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
            cout << "������ ������� ������ �� ����� " << filename << endl;
        }
        else {
            cout << "������ �������� ����� ��� ������" << endl;
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
        cout << "\n����:" << endl;
        cout << "1. �������� �������" << endl;
        cout << "2. ������� �������" << endl;
        cout << "3. ����� ��������" << endl;
        cout << "4. ������� ������" << endl;
        cout << "5. �������� ������ � ����" << endl;
        cout << "6. ������� ������ �� �����" << endl;
        cout << "7. ��������� ����� ������������� ���������� ���������" << endl;
        cout << "8. �����" << endl;
        cout << "�������� ��������: ";
        cin >> choice;


        switch (choice) {
        case 1: {
            int value;
            cout << "������� �������� �������� ��� ����������: ";
            cin >> value;
            list.append(value);
            break;
        }
        case 2: {
            int value;
            cout << "������� �������� �������� ��� ��������: ";
            cin >> value;
            list.remove(value);
            break;
        }
        case 3: {
            int value;
            cout << "������� �������� �������� ��� ������: ";
            cin >> value;
            if (list.search(value)) {
                cout << "������� ������ � ������" << endl;
            }
            else {
                cout << "������� �� ������ � ������" << endl;
            }
            break;
        }
        case 4: {
            cout << "������: ";
            list.display();
            break;
        }
        case 5: {
            string filename;
            cout << "������� ��� ����� ��� ������ ������: ";
            cin >> filename;
            list.saveToFile(filename);
            break;
        }
        case 6: {
            string filename;
            cout << "������� ��� ����� ��� ������ ������: ";
            cin >> filename;
            list.readFromFile(filename);
            break;
        }
        case 7: {
            int sum = list.sumOfNegativeTwoDigitElements();
            if (sum != 0) {
                cout << "����� ������������� ���������� ���������: " << sum << endl;
            }
            else {
                cout << "������������� ���������� ��������� � ������ ���" << endl;
            }
            break;
        }
        case 8:
            cout << "����� �� ���������..." << endl;
            break;
        default:
            cout << "���������� �����." << endl;
        }
    } while (choice != 8);

    return 0;
}
