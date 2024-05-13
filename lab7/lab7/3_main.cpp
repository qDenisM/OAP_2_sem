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
    cout << " 1. Добавление числа" << endl;
    cout << " 2. Удаление числа" << endl;
    cout << " 3. Поиск числа" << endl;
    cout << " 4. Вывод стека" << endl;
    cout << " 5. Запись стека в файл" << endl;
    cout << " 6. Считывание стека из файла" << endl;
    cout << " 7. Очистка стека" << endl;
    cout << " 8. Удаление первого положительного элемента: " << endl;
    cout << " 0. Выход" << endl;
    cout << "Введите выбор: ";
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
            cout << "Введите число: ";
            cin >> n;
            push(&top, n);
            break;
        case 2:
            pop(&top);
            break;
        case 3:
            cout << "Введите число, которое нужно найти: ";
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
