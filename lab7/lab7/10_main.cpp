#include <iostream>
#include "10.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    Stack stack;
    int choice, value, low, high;

    while (true) {
        cout << "\n����:\n";
        cout << "1. ��������\n";
        cout << "2. �������\n";
        cout << "3. ������� ����\n";
        cout << "4. �������� � ����\n";
        cout << "5. ��������� �� �����\n";
        cout << "6. ��������� ���� �� ����� � �������� ���������\n";
        cout << "7. ��������\n";
        cout << "8. �����\n";
        cout << "�������� �����: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "������� ��������: ";
            cin >> value;
            stack.push(value);
            break;
        case 2:
            cout << "��������� ��������: " << stack.pop() << "\n";
            break;
        case 3:
            stack.printStack();
            break;
        case 4:
            stack.saveToFile("stack.txt");
            cout << "���� ������� � ����.\n";
            break;
        case 5:
            stack.readFromFile("stack.txt");
            cout << "���� �������� �� �����.\n";
            break;
        case 6:
            cout << "������� ������ ���������: ";
            cin >> low;
            cout << "������� ����� ���������: ";
            cin >> high;
            if (stack.isInRange(low, high)) {
                cout << "��� ������� ���� ������� ��������� � �������� ���������.\n";
            }
            else {
                cout << "�� ���� ������� �� ��������� � �������� ���������.\n";
            }
            break;
        case 7:
            stack.clear();
            cout << "���� ������.\n";
            break;
        case 8:
            cout << "����� �� ���������...\n";
            return 0;
        default:
            cout << "�������� �����. ���������� �����.\n";
        }
    }

    return 0;
}
