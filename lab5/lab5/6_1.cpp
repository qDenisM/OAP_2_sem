#include <iostream>
#include <cstring>
#include <windows.h>

using namespace std;

// ������������ ��� ����� ����������
enum CarBrand
{
    Toyota,
    Honda,
    Ford,
    BMW,
    Mercedes
};

// ������������ ��� ���� ������
enum BodyType
{
    Sedan,
    SUV,
    Hatchback,
    Coupe
};

// ��������� ��� ���� ������� � �������������� �������� ����
struct Date
{
    unsigned int day : 5;
    unsigned int month : 4;
    unsigned int year : 11;
};

// ��������� ��� ����������
struct Car
{
    CarBrand brand;
    char color[20];
    unsigned int serialNumber;
    Date manufactureDate;
    BodyType bodyType;
    Date lastInspectionDate;
    char owner[50];
};

// ������� ��� ����� ������ �� ���������� � ����������
void inputCar(Car& car)
{
    cout << "������� ����� ���������� (0 - Toyota, 1 - Honda, 2 - Ford, 3 - BMW, 4 - Mercedes): ";
    int brand;
    cin >> brand;
    car.brand = static_cast<CarBrand>(brand);

    cout << "������� ���� ����������: ";
    cin.ignore(); // ������� ����� ����� ����� �������������� getline
    cin.getline(car.color, sizeof(car.color));

    cout << "������� ��������� �����: ";
    cin >> car.serialNumber;

    cout << "������� ���� ������� (���� ����� ���): ";
    int day, month, year;
    cin >> day >> month >> year;

    car.manufactureDate.day = static_cast<unsigned int>(day);
    car.manufactureDate.month = static_cast<unsigned int>(month);
    car.manufactureDate.year = static_cast<unsigned int>(year);

    cout << "������� ��� ������ (0 - �����, 1 - �����������, 2 - �������, 3 - ����): ";
    int bodyType;
    cin >> bodyType;
    car.bodyType = static_cast<BodyType>(bodyType);

    cout << "������� ���� ���������� ���������� (���� ����� ���): ";
    int inspectionDay, inspectionMonth, inspectionYear;
    cin >> inspectionDay >> inspectionMonth >> inspectionYear;

    car.lastInspectionDate.day = static_cast<unsigned int>(inspectionDay);
    car.lastInspectionDate.month = static_cast<unsigned int>(inspectionMonth);
    car.lastInspectionDate.year = static_cast<unsigned int>(inspectionYear);

    cout << "������� ���������: ";
    cin.ignore(); // ������� ����� ����� ����� �������������� getline
    cin.getline(car.owner, sizeof(car.owner));
}

// ������� ��� ������ ������ �� ���������� �� �����
void displayCar(const Car& car)
{
    cout << "����� ����������: ";
    switch (car.brand)
    {
    case Toyota:
        cout << "Toyota";
        break;
    case Honda:
        cout << "Honda";
        break;
    case Ford:
        cout << "Ford";
        break;
    case BMW:
        cout << "BMW";
        break;
    case Mercedes:
        cout << "Mercedes";
        break;
    }
    cout << endl;

    cout << "���� ����������: " << car.color << endl;
    cout << "��������� �����: " << car.serialNumber << endl;
    cout << "���� �������: " << car.manufactureDate.day << "." << car.manufactureDate.month << "." << car.manufactureDate.year << endl;

    cout << "��� ������: ";
    switch (car.bodyType)
    {
    case Sedan:
        cout << "�����";
        break;
    case SUV:
        cout << "�����������";
        break;
    case Hatchback:
        cout << "�������";
        break;
    case Coupe:
        cout << "����";
        break;
    }
    cout << endl;

    cout << "���� ���������� ����������: " << car.lastInspectionDate.day << "." << car.lastInspectionDate.month << "." << car.lastInspectionDate.year << endl;
    cout << "��������: " << car.owner << endl;
}

// ������� ��� ������ ���������� �� ���������� ������
Car findCarBySerialNumber(const Car cars[], int size, unsigned int serialNumber)
{

    for (int i = 0; i < size; ++i)
    {
        if (cars[i].serialNumber == serialNumber)
        {
            return cars[i];
        }
    }

    // ���� ���������� �� ������, ���������� ������ ����������
    Car emptyCar = { Toyota, "", 0, {0, 0, 0}, Sedan, {0, 0, 0}, "" };
    return emptyCar;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int MAX_CARS = 5;
    Car cars[MAX_CARS];
    int carCount = 0;
    int choice;


    do
    {
        cout << "\n����:" << endl;
        cout << "1. �������� ����������" << endl;
        cout << "2. ������� ������ �����������" << endl;
        cout << "3. ����� �� ���������� ������" << endl;
        cout << "0. �����" << endl;
        cout << "�������� ��������: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (carCount < MAX_CARS)
            {
                inputCar(cars[carCount]);
                carCount++;
            }
            else
            {
                cerr << "���������� ������������ ���������� �����������." << endl;
            }
            break;
        case 2:
            for (int i = 0; i < carCount; ++i)
            {
                displayCar(cars[i]);
                cout << "------------------------------" << endl;
            }
            break;
        case 3:
            if (carCount > 0)
            {
                unsigned int searchSerialNumber;
                cout << "������� ��������� ����� ��� ������: ";
                cin >> searchSerialNumber;

                Car foundCar = findCarBySerialNumber(cars, carCount, searchSerialNumber);
                if (foundCar.serialNumber != 0)
                {
                    displayCar(foundCar);
                }
                else
                {
                    cerr << "���������� � ��������� ��������� ������� �� ������." << endl;
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
