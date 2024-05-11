#include <iostream>
#include "6.h"
#include <limits>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    Stack stack;
    int choice;

    do {
        cout << "\nМеню\n";
        cout << "1. Добавить\n";
        cout << "2. Удалить\n";
        cout << "3. Посчитать количество 'соседних' элементов\n";
        cout << "4. Очистить стек\n";
        cout << "5. Записать в файл\n";
        cout << "6. Прочитать из файла\n";
        cout << "0. Выход\n";
        cout << "Выберите пункт: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
        case 1: {
            int data;
            cout << "Введите значение: ";
            cin >> data;
            stack.push(data);
            break;
        }
        case 2: {
            int data = stack.pop();
            if (data != INT_MIN) {
                cout << "Удаленное значение: " << data << endl;
            }
            break;
        }
        case 3: {
            int count = stack.countEqualNeighbors();
            cout << "Количество 'соседних' элементов: " << count << endl;
            break;
        }
        case 4: {
            stack.clear();
            cout << "Стек очищен." << endl;
            break;
        }
        case 5: {
            stack.saveToFile("stack.txt");
            cout << "Стек записан в файл.";
            break;
        }
        case 6: {
            stack.readFromFile("stack.txt");
            cout << "Стек прочтен из файла.";
            break;
        }
        case 0: {
            cout << "Выход из программы..." << endl;
            break;
        }
        default:
            cout << "Неверный выбор. Попробуйте снова." << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}
