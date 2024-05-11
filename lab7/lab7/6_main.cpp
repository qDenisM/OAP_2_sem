#include <iostream>
#include "6.h"
#include <limits>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    Stack stack;
    int choice;

    do {
        cout << "\n����\n";
        cout << "1. ��������\n";
        cout << "2. �������\n";
        cout << "3. ��������� ���������� '��������' ���������\n";
        cout << "4. �������� ����\n";
        cout << "5. �������� � ����\n";
        cout << "6. ��������� �� �����\n";
        cout << "0. �����\n";
        cout << "�������� �����: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
        case 1: {
            int data;
            cout << "������� ��������: ";
            cin >> data;
            stack.push(data);
            break;
        }
        case 2: {
            int data = stack.pop();
            if (data != INT_MIN) {
                cout << "��������� ��������: " << data << endl;
            }
            break;
        }
        case 3: {
            int count = stack.countEqualNeighbors();
            cout << "���������� '��������' ���������: " << count << endl;
            break;
        }
        case 4: {
            stack.clear();
            cout << "���� ������." << endl;
            break;
        }
        case 5: {
            stack.saveToFile("stack.txt");
            cout << "���� ������� � ����.";
            break;
        }
        case 6: {
            stack.readFromFile("stack.txt");
            cout << "���� ������� �� �����.";
            break;
        }
        case 0: {
            cout << "����� �� ���������..." << endl;
            break;
        }
        default:
            cout << "�������� �����. ���������� �����." << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}
