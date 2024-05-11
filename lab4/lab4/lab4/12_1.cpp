#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;

struct Country {
    string name;
    string capital;
    int population;
    double area;
    string presidentLastName;
};

const int MAX_COUNTRIES = 3;
Country countries[MAX_COUNTRIES];
int numCountries = 0;

void addCountry() {
    if (numCountries < MAX_COUNTRIES) {
        cout << "Введите название государства: ";
        cin >> countries[numCountries].name;
        cout << "Введите столицу: ";
        cin >> countries[numCountries].capital;
        cout << "Ввежите население: ";
        cin >> countries[numCountries].population;
        cout << "Введите площадь: ";
        cin >> countries[numCountries].area;
        cout << "Введите фамилию президента: ";
        cin >> countries[numCountries].presidentLastName;
        numCountries++;
    }
    else {
        cout << "Достигнуто максимальное значение государств" << endl;
    }
}

void displayCountries() {
    for (int i = 0; i < numCountries; ++i) {
        cout << "Государство: " << countries[i].name << endl;
        cout << "Столица: " << countries[i].capital << endl;
        cout << "Население: " << countries[i].population << endl;
        cout << "Площадь: " << countries[i].area << endl;
        cout << "Фамилия президента: " << countries[i].presidentLastName << endl;
        cout << endl;
    }
}

void deleteCountry(string countryName) {
    bool found = false;
    for (int i = 0; i < numCountries; ++i) {
        if (countries[i].name == countryName) {
            found = true;
            for (int j = i; j < numCountries - 1; ++j) {
                countries[j] = countries[j + 1];
            }
            numCountries--;
            cout << "Государство " << countryName << " удалено успешно." << endl;
            break;
        }
    }
    if (!found) {
        cout << "Название государства не найдено." << endl;
    }
}

void searchCountry(string countryName) {
    bool found = false;
    for (int i = 0; i < numCountries; ++i) {
        if (countries[i].name == countryName) {
            found = true;
            cout << "Государство: " << countries[i].name << endl;
            cout << "Столица: " << countries[i].capital << endl;
            cout << "Население: " << countries[i].population << endl;
            cout << "Площадь: " << countries[i].area << endl;
            cout << "Фамилия президента: " << countries[i].presidentLastName << endl;
            cout << endl;
            break;
        }
    }
    if (!found) {
        cout << "Название государства не найдено." << endl;
    }
}

void writeToFile(string filename) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        for (int i = 0; i < numCountries; ++i) {
            outFile << countries[i].name << " "
                << countries[i].capital << " "
                << countries[i].population << " "
                << countries[i].area << " "
                << countries[i].presidentLastName << endl;
        }
        outFile.close();
        cout << "Данные успешно записаны в файл." << endl;
    }
    else {
        cout << "Невозможно открыть файл." << endl;
    }
}

void readFromFile(string filename) {
    ifstream inFile(filename);
    if (inFile.is_open()) {
        numCountries = 0; 
        while (!inFile.eof()) {
            inFile >> countries[numCountries].name
                >> countries[numCountries].capital
                >> countries[numCountries].population
                >> countries[numCountries].area
                >> countries[numCountries].presidentLastName;
            numCountries++;
        }
        numCountries--;
        inFile.close();
        cout << "Данные успешно прочитаны с файла." << endl;
    }
    else {
        cout << "Невозможно открыть файл." << endl;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru");
    int choice;
    string filename;
    string countryName;
    
    do {
        cout << "Меню:\n1. Добавить государство\n2. Дисплей государств\n3. Удалить государство\n4. Поиск государства\n5. Записать в файл\n6. Прочитать с файла\n0. Выход\nВыберите вариант : ";
        cin >> choice;

        switch (choice) {
        case 1:
            addCountry();
            break;
        case 2:
            displayCountries();
            break;
        case 3:
            cout << "Введите название государство, которое хотите удалить: ";
            cin >> countryName;
            deleteCountry(countryName);
            break;
        case 4:
            cout << "Введите название государства, которое хотите найти: ";
            cin >> countryName;
            searchCountry(countryName);
            break;
        case 5:
            cout << "Введите название файла для записи: ";
            cin >> filename;
            writeToFile(filename);
            break;
        case 6:
            cout << "Введите название файла для чтения: ";
            cin >> filename;
            readFromFile(filename);
            break;
        case 0:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Неверный вариант. Попробуйте еще раз." << endl;
        }
    } while (choice != 0);

    return 0;
}