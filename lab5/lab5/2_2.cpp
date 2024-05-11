#include <iostream>                    
#include <fstream> 
#include <string> 
#include <windows.h>
using namespace std;

union number {
    short s;
    int i;
    long l;
    long long ll;
};

struct train {
    number num;
    string destination = "";
    string travelDays = "";
    string arrival = "";
    string departure = "";

};

train inputTrain()
{
    train c;
    cout << "������� ����� ������: ";
    cin >> c.num.ll;
    cout << "������� ����� ����������: ";
    cin >> c.destination;
    cout << "������� ��� ����������: ";
    cin.ignore();
    getline(cin, c.travelDays);
    //cin >> c.travelDays;
    cout << "������� ����� ��������: ";
    cin >> c.arrival;
    cout << "������� ����� �����������: ";
    cin >> c.departure;

    return c;
}

void outputTrain(train c) {
    cout << "����� ������: " << c.num.ll << endl;
    cout << "����� ����������: " << c.destination << endl;
    cout << "��� ����������: " << c.travelDays << endl;
    cout << "����� ��������: " << c.arrival << endl;
    cout << "����� �����������: " << c.departure << endl;
}

train inputfTrain(ifstream& in) {
    train c;
    in >> c.num.ll;
    in >> c.destination;
    in.ignore();
    getline(in, c.travelDays);
    //in >> c.travelDays;
    in >> c.arrival;
    in >> c.departure;
    return c;
}

void outputfTrain(ofstream& out, train c) {
    out << "����� ������: " << c.num.ll << endl;
    out << "����� ����������: " << c.destination << endl;
    out << "��� ����������: " << c.travelDays << endl;
    out << "����� ��������: " << c.arrival << endl;
    out << "����� �����������: " << c.departure << endl;
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    train trains[500];
    int choice = 0, trainsCount = 0;
    bool readElements = false;
    do
    {
        cout << "�������:" << endl;
        cout << "1 - ��� ����� � ����������" << endl;
        cout << "2 - ��� ������ �� �����" << endl;
        cout << "3 - ��� ������ �� �������" << endl;
        cout << "4 - ��� ����� � �����" << endl;
        cout << "5 - ��� ������ � ����" << endl;
        cout << "6 - ��� ������" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "������� ���������� �������: ";
            cin >> trainsCount;
            for (int i = 0; i < trainsCount; ++i)
            {
                trains[i] = inputTrain();
            }
            readElements = true;
        }
        break;
        case 2:
            if (readElements)
            {
                cout << "���������� �������: " << trainsCount << endl;
                for (int i = 0; i < trainsCount; ++i)
                {
                    outputTrain(trains[i]);
                }
            }
            else { cout << "��� ����������� ������" << endl; }
            break;

        case 3:
            if (readElements) {
                string destination;
                cout << "���� ������� ��� ������:" << endl;
                cin >> destination;
                {
                    int num;
                    bool is = true;
                    for (int i = 0; i < trainsCount; ++i)
                    {
                        if (trains[i].destination == destination)
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
                        outputTrain(trains[num]);
                    }
                }
            }
            else { cout << "��� ����������� ������" << endl; }
            break;

        case 4:
        {
            ifstream in("save.txt");
            in >> trainsCount;
            for (int i = 0; i < trainsCount; ++i)
            {
                trains[i] = inputfTrain(in);
            }
            readElements = true;
            in.close();
        }
        break;

        case 5:
            if (readElements) {
                ofstream out("save.txt");
                out << "���������� �������: " << trainsCount << endl;
                for (int i = 0; i < trainsCount; ++i)
                {
                    outputfTrain(out, trains[i]);
                }
                out.close();
            }
            else { cout << "��� ����������� ������" << endl; }
            break;

        }
    } while (choice != 6);
}
