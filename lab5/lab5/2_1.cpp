#include <iostream>                    
#include <fstream> 
#include <string> 
#include <windows.h>
using namespace std;

struct date {
    unsigned int MonthDay : 6;    // 0..31  (6 bits)
    unsigned int Month : 5;    // 0..12  (5 bits)
    unsigned int Year : 12;    // 0..4095 (12 bits)
};
enum mf { MALE, FEMALE };


struct citizen {
    string name = "";
    string surname = "";
    string address = "";

    mf sex;
    date DOB;
};

citizen inputCitizen()
{
    citizen c;
    cout << "������� ���: ";
    cin >> c.name;
    cout << "������� �������: ";
    cin >> c.surname;
    cout << "������� �����: ";
    cin >> c.address;
    cout << "������� ���(1 - �������, 2 - �������): ";
    unsigned int n = 0;
    cin >> n;
    c.sex = static_cast<mf>(n);
    cout << "������� ���� ������ ��������: ";
    cin >> n;
    c.DOB.MonthDay = n;
    cout << "������� ����� ��������: ";
    cin >> n;
    c.DOB.Month = n;
    cout << "������� ��� ��������: ";
    cin >> n;
    c.DOB.Year = n;
    return c;
}

void outputCitizen(citizen c) {
    cout << "���: " << c.name << endl;
    cout << "�������: " << c.surname << endl;
    cout << "�����: " << c.address << endl;
    switch (c.sex)
    {
    case MALE:
    {cout << "���: �������" << endl; break; }
    case FEMALE:
    {cout << "���: �������" << endl; break; }
    }
    cout << "���� ��������: " << c.DOB.MonthDay << "." << c.DOB.Month << "." << c.DOB.Year << endl;
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    citizen citizens[500];
    int choice = 0, citizensCount = 0;
    bool readElements = false;
    do
    {
        cout << "�������:" << endl;
        cout << "1 - ��� ������ � ����������" << endl;
        cout << "2 - ��� ������ �� �����" << endl;
        cout << "3 - ��� ������ �� �������" << endl;
        cout << "4 - ��� �������� ���������� �� �������" << endl;
        cout << "5 - ��� ������ �� ���� ��������" << endl;
        cout << "6 - ��� ������" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "������� ���������� �������: ";
            cin >> citizensCount;
            for (int i = 0; i < citizensCount; ++i)
            {
                citizens[i] = inputCitizen();
            }
            readElements = true;
        }
        break;
        case 2:
            if (readElements)
            {
                cout << "���������� �������: " << citizensCount << endl;
                for (int i = 0; i < citizensCount; ++i)
                {
                    outputCitizen(citizens[i]);
                }
            }
            else { cout << "��� ����������� ������" << endl; }
            break;

        case 3:
            if (readElements) {
                string surname;
                cout << "���� ������� ��� ������:" << endl;
                cin >> surname;
                {
                    int num;
                    bool is = true;
                    for (int i = 0; i < citizensCount; ++i)
                    {
                        if (citizens[i].surname == surname)
                        {
                            num = i;
                            break;
                            is = false;
                        }
                    }
                    if (is)
                    {
                        cout << "��������� �� ������" << endl;
                    }
                    else
                    {
                        outputCitizen(citizens[num]);
                    }
                }
            }
            else { cout << "��� ����������� ������" << endl; }
            break;

        case 4:
            if (readElements) {
                string surname;
                cout << "���� ������� ��� ��������:" << endl;
                cin >> surname;
                {
                    int num;
                    bool is = true;
                    for (int i = 0; i < citizensCount; ++i)
                    {
                        if (citizens[i].surname == surname)
                        {
                            num = i;
                            break;
                            is = false;
                        }
                    }
                    if (is)
                    {
                        cout << "��������� �� ������" << endl;
                    }
                    else
                    {
                        citizensCount--;
                        for (int i = num; i < citizensCount; ++i)
                        {
                            citizens[i] = citizens[i + 1];
                        }
                    }
                }
            }
            else { cout << "��� ����������� ������" << endl; }
            break;


        case 5:
            if (readElements) {
                string surname;
                cout << "���� ������� ��� ������:" << endl;
                cin >> surname;
                {
                    int num;
                    bool is = true;
                    for (int i = 0; i < citizensCount; ++i)
                    {
                        if (citizens[i].surname == surname)
                        {
                            num = i;
                            break;
                            is = false;
                        }
                    }
                    if (is)
                    {
                        cout << "��������� �� ������" << endl;
                    }
                    else
                    {
                        outputCitizen(citizens[num]);
                    }
                }
            }
            else { cout << "��� ����������� ������" << endl; }
            break;

        case 6:
            if (readElements) {
                unsigned int year;
                cout << "���� ���� ��� ��������:" << endl;
                cin >> year;
                {
                    bool is = true;
                    for (int i = 0; i < citizensCount; ++i)
                    {
                        if (citizens[i].DOB.Year == year)
                        {
                            outputCitizen(citizens[i]);
                            is = false;
                        }
                    }
                    if (is)
                    {
                        cout << "�������� �� �������" << endl;
                    }
                }
            }
            else { cout << "��� ����������� ������" << endl; }
            break;

        }
    } while (choice != 6);
}
