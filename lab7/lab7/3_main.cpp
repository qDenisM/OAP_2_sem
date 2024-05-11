#include <iostream>
#include <fstream>
#include <string>
#include <malloc.h>
#include "3.h"

using namespace std;

int menu()
{
    int n;
    cout << endl;
    cout << " 1. ���������� �����" << endl;
    cout << " 2. �������� �����" << endl;
    cout << " 3. ����� �����" << endl;
    cout << " 4. ����� �����" << endl;
    cout << " 5. ������ ����� � ����" << endl;
    cout << " 6. ���������� ����� �� �����" << endl;
    cout << " 7. ������� �����" << endl;
    cout << " 8. �������� ������� �������������� ��������: " << endl;
    cout << " 0. �����" << endl;
    cout << "������� �����: ";
    cin >> n;
    cout << endl;
    return n;
}

int main()
{
    setlocale(LC_ALL, "rus");
    comp* top = NULL; 
    float n;

    while (true)
    {
        switch (menu())
        {
        case 1:
            cout << "������� �����: ";
            cin >> n;
            push(&top, n);
            break;
        case 2:
            pop(&top);
            break;
        case 3:
            cout << "������� �����, ������� ����� �����: ";
            cin >> n;
            find(top, n);
            break;
        case 4:
            print(top);
            break;
        case 5:
            toFile(top);
            break;
        case 6:
            fromFile(&top);
            break;
        case 7:
            clear(&top);
            break;
        case 8:
            printFirstPositiveElement(&top);
            break;
        case 0:
            return 0;
            break;
        default:
            break;
        }
    }
    return 0;
}
