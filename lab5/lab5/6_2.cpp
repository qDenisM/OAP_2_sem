#include <iostream>
#include <cstring>
#include <windows.h>

using namespace std;

// ������������ ��� ��������� ����������
enum Position
{
    Manager,
    Engineer,
    Accountant,
    Technician
};

// ��������� ��� ����
struct Date
{
    unsigned int day;
    unsigned int month;
    unsigned int year;
};

// ��������� ��� ����������
struct Employee
{
    char fullName[50];
    char education[50];
    char specialty[50];
    char department[50];
    Position position;
    double salary;
    Date employmentDate;
};

// ������� ��� ����� ������ � ���������� � ����������
void inputEmployee(Employee& emp)
{
    cout << "������� �.�.�. ���������: ";
    cin.ignore();
    cin.getline(emp.fullName, sizeof(emp.fullName));

    cout << "������� ����������� ���������: ";
    cin.getline(emp.education, sizeof(emp.education));

    cout << "������� ������������� ���������: ";
    cin.getline(emp.specialty, sizeof(emp.specialty));

    cout << "������� ������������� ���������: ";
    cin.getline(emp.department, sizeof(emp.department));

    cout << "������� ��������� ��������� (0 - ��������, 1 - �������, 2 - ���������, 3 - ������): ";
    int position;
    cin >> position;
    emp.position = static_cast<Position>(position);

    cout << "������� ����� ���������: ";
    cin >> emp.salary;

    cout << "������� ���� ����������� �� ����������� (���� ����� ���): ";
    cin >> emp.employmentDate.day >> emp.employmentDate.month >> emp.employmentDate.year;
}

// ������� ��� ������ ������ � ���������� �� �����
void displayEmployee(const Employee& emp)
{
    cout << "�.�.�. ���������: " << emp.fullName << endl;
    cout << "�����������: " << emp.education << endl;
    cout << "�������������: " << emp.specialty << endl;
    cout << "�������������: " << emp.department << endl;

    cout << "���������: ";
    switch (emp.position)
    {
    case Manager:
        cout << "��������";
        break;
    case Engineer:
        cout << "�������";
        break;
    case Accountant:
        cout << "���������";
        break;
    case Technician:
        cout << "������";
        break;
    }
    cout << endl;

    cout << "�����: " << emp.salary << endl;
    cout << "���� ����������� �� �����������: " << emp.employmentDate.day << "." << emp.employmentDate.month << "." << emp.employmentDate.year << endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int MAX_EMPLOYEES = 5;
    Employee employees[MAX_EMPLOYEES];
    int employeeCount = 0;
    int choice;

    do
    {
        cout << "\n����:" << endl;
        cout << "1. �������� ����������" << endl;
        cout << "2. ������� ������ �����������" << endl;
        cout << "3. ����� �� ���������" << endl;
        cout << "0. �����" << endl;
        cout << "�������� ��������: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (employeeCount < MAX_EMPLOYEES)
            {
                inputEmployee(employees[employeeCount]);
                employeeCount++;
            }
            else
            {
                cerr << "���������� ������������ ���������� �����������." << endl;
            }
            break;
        case 2:
            for (int i = 0; i < employeeCount; ++i)
            {
                displayEmployee(employees[i]);
                cout << "------------------------------" << endl;
            }
            break;
        case 3:
            if (employeeCount > 0)
            {
                int searchPosition;
                cout << "������� ��������� ��� ������ (0 - ��������, 1 - �������, 2 - ���������, 3 - ������): ";
                cin >> searchPosition;


                cout << "\n���������� � ����������: ";
                switch (static_cast<Position>(searchPosition))
                {
                case Manager:
                    cout << "��������" << endl;
                    break;
                case Engineer:
                    cout << "�������" << endl;
                    break;
                case Accountant:
                    cout << "���������" << endl;
                    break;
                case Technician:
                    cout << "������" << endl;
                    break;
                }

                bool found = false;
                for (int i = 0; i < employeeCount; ++i)
                {
                    if (employees[i].position == static_cast<Position>(searchPosition))
                    {
                        displayEmployee(employees[i]);
                        cout << "------------------------------" << endl;
                        found = true;
                    }
                }

                if (!found)
                {
                    cerr << "����������� � ��������� ���������� �� �������." << endl;
                }
            }
            else
            {
                cerr << "������ ����������� ����." << endl;
            }
            break;
        case 0:
            cout << "��������� ���������." << endl;
            break;
        default:
            cerr << "������������ �����. ���������� �����." << endl;
        }
    } while (choice != 0);

    return 0;
}
