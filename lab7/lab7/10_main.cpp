#include <iostream>
#include "10.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    Stack stack;
    int choice, value, low, high;

    while (true) {
        cout << "\nМеню:\n";
        cout << "1. Добавить\n";
        cout << "2. Удалить\n";
        cout << "3. Вывести стек\n";
        cout << "4. Записать в файл\n";
        cout << "5. Прочитать из файла\n";
        cout << "6. Проверить есть ли число в заданном диапазоне\n";
        cout << "7. Очистить\n";
        cout << "8. Выход\n";
        cout << "Выберите пункт: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введите значение: ";
            cin >> value;
            stack.push(value);
            break;
        case 2:
            cout << "Удаленное значение: " << stack.pop() << "\n";
            break;
        case 3:
            stack.printStack();
            break;
        case 4:
            stack.saveToFile("stack.txt");
            cout << "Стек записан в файл.\n";
            break;
        case 5:
            stack.readFromFile("stack.txt");
            cout << "Стек прочитан из файла.\n";
            break;
        case 6:
            cout << "Введите начало диапазона: ";
            cin >> low;
            cout << "Введите конец диапазона: ";
            cin >> high;
            if (stack.isInRange(low, high)) {
                cout << "Как минимум один элемент находится в заданном диапазоне.\n";
            }
            else {
                cout << "Ни один элемент не находится в заданном диапазоне.\n";
            }
            break;
        case 7:
            stack.clear();
            cout << "Стек очищен.\n";
            break;
        case 8:
            cout << "Выход из программы...\n";
            return 0;
        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
        }
    }

    return 0;
}
