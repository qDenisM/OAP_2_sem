#include <iostream>
#include <string>
#include <algorithm>
#include <windows.h>

using namespace std;


struct TRAIN {
    string destination; 
    int trainNumber;    
    string departureTime; 
};


bool isTimeLater(const string& time1, const string& time2) {

    int hour1 = stoi(time1.substr(0, 2));
    int minute1 = stoi(time1.substr(3, 2));
    int hour2 = stoi(time2.substr(0, 2));
    int minute2 = stoi(time2.substr(3, 2));


    if (hour1 > hour2) {
        return true;
    }
    else if (hour1 < hour2) {
        return false;
    }


    return minute1 > minute2;
}



bool compareDestinations(const TRAIN& a, const TRAIN& b) {
    return a.destination < b.destination;
}

int main() {
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    TRAIN trains[8]; 
    string currentTime; 

    
    cout << "������� ������ � �������:\n";
    for (int i = 0; i < 8; ++i) {
        cout << "����� " << i + 1 << ":\n";
        cout << "�������� ������ ����������: ";
        cin >> trains[i].destination;
        cout << "����� ������: ";
        cin >> trains[i].trainNumber;
        cout << "����� ����������� (� ������� ��:��): ";
        cin >> trains[i].departureTime;
    }

    sort(trains, trains + 8, compareDestinations);

    cout << "\n������� �����, ����� �������� ����� ����� ������ (� ������� ��:��): ";
    cin >> currentTime;

    bool found = false; 

    
    cout << "\n������, �������������� ����� " << currentTime << ":\n";
    for (int i = 0; i < 8; ++i) {
        if (isTimeLater(trains[i].departureTime, currentTime)) {
            cout << "�������� ������ ����������: " << trains[i].destination << endl;
            cout << "����� ������: " << trains[i].trainNumber << endl;
            cout << "����� �����������: " << trains[i].departureTime << endl << endl;
            found = true;
        }
    }
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
    if (!found) {
        cout << "�������, �������������� ����� " << currentTime << ", �� �������.\n";
    }

    return 0;
}
