#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

#define size21 20

enum Position {
    MANAGER,
    ENGINEER,
    ANALYST,
    DIRECTOR,
    CLERK,
    STUDENT,
    PROGRAMMER
};

struct book {
    char f[50];
    char i[50];
    char o[50];
    char address[20];
    long long phone;
    char work[20];
    Position rank;
    struct Date {
        unsigned int day : 5;
        unsigned int mon : 4; 
        unsigned int year : 12;
    } DT;
};

struct book b[20], dost;
int size2 = 0;

void input();
void del();
void out();
void writeF();
void readF();

int main() {
    system("chcp 1251");
    setlocale(LC_ALL, "Russian");
    int choice = 1;

    while (choice != 0) {
        cout << " \n1. Новая запись\n2. Удалить запись\n3. Вывести запись в консоль\n4. Запись в файл\n5. Чтение из файла\n6. Сортировка\n0. Завершить работу\nВвод ";
        cin >> choice;

        switch (choice) {
        case(1):
            input();
            break;
        case(2):
            del();
            break;
        case(3):
            out();
            break;
        case(4):
            writeF();
            break;
        case(5):
            readF();
            break;
        default:
            break;
        }
    }
}

void input() {
    int d, m, y;

    if (size2 < 20) {
        cout << " Введите данные(Фамилия, Имя, Отчество, адрес, номер тлф, место работы, должность, день, месяц, год): \n Запись №" << size2 + 1 << ": ";
        cin >> b[size2].f;
        cin >> b[size2].i;
        cin >> b[size2].o;
        cin >> b[size2].address;
        cin >> b[size2].phone;
        cin >> b[size2].work;
        int rankInput;
        cout << "Введите должность (0 - Менеджер, 1 - Инженер, 2 - Аналитик, 3 - Директор, 4 - Клерк, 5 - Студент, 6 - Программист): ";
        cin >> rankInput;
        b[size2].rank = static_cast<Position>(rankInput);
        cin >> d >> m >> y;
        b[size2].DT.day = d;
        b[size2].DT.mon = m;
        b[size2].DT.year = y;
        size2++;
    }
    else {
        cout << " Введено максимальное кол-во строк" << endl;
    }
}

void del() {
    int d;
    cout << "Номер строки, которую  хотите удалить(1 для удаления всех): ";
    cin >> d;
    d--;
    if (d == -2) {
        for (int i = 0; i < 20; i++) {
            b[i] = dost;
        }
        size2 = 0;
    }
    else {
        for (int i = d - 1; i < size2; i++) {
            b[i] = b[i + 1];
        }
        size2--;
    }
}

void out() {
    string name, num;
    cout << " Введите фамилию для поиска записи(для вывода всех записей введите 1): ";
    cin >> name;
    if (name == "1") {
        for (int i = 0; i < size2; i++) {
            cout << " Запись №" << i + 1 << " \n Фамилия - " << b[i].f << " \n имя - " << b[i].i << " \n отчество - " << b[i].o << " \n ДР - " << b[i].DT.day << "." << b[i].DT.mon << "." << b[i].DT.year << " \n Адрес - " << b[i].address << " \n ТЛФ - " << b[i].phone << " \n Место работы - " << b[i].work << " \n Должность - ";
            switch (b[i].rank) {
            case MANAGER:
                cout << "Менеджер";
                break;
            case ENGINEER:
                cout << "Инженер";
                break;
            case ANALYST:
                cout << "Аналитик";
                break;
            case DIRECTOR:
                cout << "Директор";
                break;
            case CLERK:
                cout << "Клерк";
                break;
            case STUDENT:
                cout << "Студент";
                break;
            case PROGRAMMER:
                cout << "Программист";
                break;
            default:
                cout << "Неизвестно";
                break;
            }
            cout << endl << endl;
        }
    }
    else {
        for (int i = 0; i < size2; i++) {
            if (b[i].f == name) {
                cout << " Запись №" << i + 1 << " \n Фамилия - " << b[i].f << " \n имя - " << b[i].i << " \n отчество - " << b[i].o << " \n ДР - " << b[i].DT.day << "." << b[i].DT.mon << "." << b[i].DT.year << " \n Адрес - " << b[i].address << " \n ТЛФ - " << b[i].phone << " \n Место работы - " << b[i].work << " \n Должность - ";
                switch (b[i].rank) {
                case MANAGER:
                    cout << "Менеджер";
                    break;
                case ENGINEER:
                    cout << "Инженер";
                    break;
                case ANALYST:
                    cout << "Аналитик";
                    break;
                case DIRECTOR:
                    cout << "Директор";
                    break;
                case CLERK:
                    cout << "Клерк";
                    break;
                case STUDENT:
                    cout << "Студент";
                    break;
                case PROGRAMMER:
                    cout << "Программист";
                    break;
                default:
                    cout << "Неизвестно";
                    break;
                }
                cout << endl << endl;
            }
        }
    }
}

void writeF() {
    ofstream fAout("FILE.txt");
    if (fAout.is_open()) {
        for (int i = 0; i < size2; i++) {
            fAout << "Запись №";
            fAout << i + 1;
            fAout << " Запись №" << i + 1 << " \n Фамилия - " << b[i].f << " \n имя - " << b[i].i << " \n отчество - " << b[i].o << " \n ДР - " << b[i].DT.day << "." << b[i].DT.mon << "." << b[i].DT.year << " \n Адрес - " << b[i].address << " \n ТЛФ - " << b[i].phone << " \n Место работы - " << b[i].work << " \n Должность - ";
            switch (b[i].rank) {
            case MANAGER:
                fAout << "Менеджер";
                break;
            case ENGINEER:
                fAout << "Инженер";
                break;
            case ANALYST:
                fAout << "Аналитик";
                break;
            case DIRECTOR:
                fAout << "Директор";
                break;
            case CLERK:
                fAout << "Клерк";
                break;
            case STUDENT:
                fAout << "Студент";
                break;
            case PROGRAMMER:
                fAout << "Программист";
                break;
            default:
                fAout << "Неизвестно";
                break;
            }
            fAout << endl << endl;
        }
    }
    else {
        cout << " Невозможно открыть файл!" << endl;
    }
    fAout.close();
}

void readF() {
    char ch;
    ifstream in;
    in.open("FILE.txt");
    while (in.get(ch)) {
        cout << ch;
    }
    in.close();
}