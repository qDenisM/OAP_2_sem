#include <iostream>
#include "12.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    StackLinkedList stack;
    int choice;
    do {
        cout << "\n1. Добавить\n2. Удалить\n3. Вывести стек\n4. Вывести Stack1(чет)\n5. Вывести Stack2(нечет)\n6. Записать в файл\n7. Прочитать с файла\n8. Очистить стек\n0. Выход\n";
        cin >> choice;
        switch (choice) {
        case 1: {
            int value;
            cout << "Введите значение: ";
            cin >> value;
            stack.push(value);
            break;
        }
        case 2: {
            int poppedValue = stack.pop();
            if (poppedValue != -1) {
                cout << "Введите значение: " << poppedValue << endl;
            }
            break;
        }
        case 3: {
            cout << "Стек: ";
            stack.display();
            break;
        }
        case 4: {
            cout << "Stack1(чет): ";
            stack.displayEven();
            break;
        }
        case 5: {
            cout << "Stack2(нечет): ";
            stack.displayOdd();
            break;
        }
        case 6: {
            stack.saveToFile("stack.txt");
            cout << "Стек записан в файл.\n";
            break;
        }
        case 7: {
            stack.readFromFile("stack.txt");
            cout << "Стек прочитан с файла.\n";
            break;
        }
        case 8: {
            stack.clear();
            cout << "Стек очищен\n";
            break;
        }
        case 0: {
            break;
        }
        default: {
            cout << "Неверный выбор. Попробуйте снова.\n";
            break;
        }
        }
    } while (choice != 0);

    return 0;
}
