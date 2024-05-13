#include <iostream>
#include <windows.h>

using namespace std;

const int MAX_SANATORIUMS = 100;
const int MAX_NAME_LENGTH = 100;
const int MAX_LOCATION_LENGTH = 100;
const int MAX_PROFILE_LENGTH = 100;

struct Sanatorium {
    char name[MAX_NAME_LENGTH];
    char location[MAX_LOCATION_LENGTH];
    char profile[MAX_PROFILE_LENGTH];
    int availability;
};

void inputSanatoriumData(Sanatorium sanatoriums[], int count) {
    for (int i = 0; i < count; i++) {
        cout << "Введите информацию о санатории #" << i + 1 << endl;

        cout << "Название санатория: ";
        cin.ignore();
        cin.getline(sanatoriums[i].name, MAX_NAME_LENGTH);

        cout << "Место расположения: ";
        cin.getline(sanatoriums[i].location, MAX_LOCATION_LENGTH);

        cout << "Лечебный профиль: ";
        cin.getline(sanatoriums[i].profile, MAX_PROFILE_LENGTH);

        cout << "Количество путевок: ";
        cin >> sanatoriums[i].availability;
    }
}

void sortSanatoriums(Sanatorium sanatoriums[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(sanatoriums[j].name, sanatoriums[j + 1].name) > 0) {
                swap(sanatoriums[j], sanatoriums[j + 1]);
            }
        }
    }
}

void printSanatoriumsByProfile(const Sanatorium sanatoriums[], int count, const char* profile) {
    bool found = false;

    cout << "Санатории с лечебным профилем \"" << profile << "\":" << endl;

    for (int i = 0; i < count; i++) {
        if (strcmp(sanatoriums[i].profile, profile) == 0) {
            cout << "Название санатория: " << sanatoriums[i].name << endl;
            cout << "Место расположения: " << sanatoriums[i].location << endl;
            cout << "Количество путевок: " << sanatoriums[i].availability << endl;
            cout << endl;

            found = true;
        }
    }

    if (!found) {
        cout << "Нет санаториев с лечебным профилем \"" << profile << "\"" << endl;
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int sanatoriumCount;
    cout << "Введите количество санаториев: ";
    cin >> sanatoriumCount;

    Sanatorium sanatoriums[MAX_SANATORIUMS];

    inputSanatoriumData(sanatoriums, sanatoriumCount);
    
    sortSanatoriums(sanatoriums, sanatoriumCount);
    
    char profile[MAX_PROFILE_LENGTH];
    cout << "Введите лечебный профиль: ";
    cin.ignore();
    cin.getline(profile, MAX_PROFILE_LENGTH);
    printSanatoriumsByProfile(sanatoriums, sanatoriumCount, profile);

    return 0;
}