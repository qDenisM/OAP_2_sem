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

    
    cout << "Введите данные о поездах:\n";
    for (int i = 0; i < 8; ++i) {
        cout << "Поезд " << i + 1 << ":\n";
        cout << "Название пункта назначения: ";
        cin >> trains[i].destination;
        cout << "Номер поезда: ";
        cin >> trains[i].trainNumber;
        cout << "Время отправления (в формате ЧЧ:ММ): ";
        cin >> trains[i].departureTime;
    }

    sort(trains, trains + 8, compareDestinations);

    cout << "\nВведите время, после которого нужно найти поезда (в формате ЧЧ:ММ): ";
    cin >> currentTime;

    bool found = false; 

    
    cout << "\nПоезда, отправляющиеся после " << currentTime << ":\n";
    for (int i = 0; i < 8; ++i) {
        if (isTimeLater(trains[i].departureTime, currentTime)) {
            cout << "Название пункта назначения: " << trains[i].destination << endl;
            cout << "Номер поезда: " << trains[i].trainNumber << endl;
            cout << "Время отправления: " << trains[i].departureTime << endl << endl;
            found = true;
        }
    }
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
    if (!found) {
        cout << "Поездов, отправляющихся после " << currentTime << ", не найдено.\n";
    }

    return 0;
}
