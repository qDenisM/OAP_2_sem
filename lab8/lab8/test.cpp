#include <iostream>
#include <queue>
#include <limits>

using namespace std;

void splitQueue(queue<int>& sourceQueue, queue<int>& queue1, queue<int>& queue2) {
    if (sourceQueue.empty()) {
        cout << "Очередь пуста!" << endl;
        return;
    }

    int queueSize = sourceQueue.size();
    for (int i = 0; i < queueSize / 2; ++i) {
        int minElement = numeric_limits<int>::max();
        int maxElement = numeric_limits<int>::min();
        int minIndex, maxIndex;
        int currentSize = sourceQueue.size();

        // Находим минимальный и максимальный элементы в оставшейся части очереди
        for (int j = 0; j < currentSize; ++j) {
            int currentElement = sourceQueue.front();
            sourceQueue.pop();
            if (currentElement < minElement) {
                minElement = currentElement;
                minIndex = j;
            }
            if (currentElement > maxElement) {
                maxElement = currentElement;
                maxIndex = j;
            }
            sourceQueue.push(currentElement);
        }

        // Перемещаем найденные элементы в соответствующие очереди
        for (int j = 0; j < currentSize; ++j) {
            int currentElement = sourceQueue.front();
            sourceQueue.pop();
            if (j == minIndex) {
                queue1.push(currentElement);
            }
            else if (j == maxIndex) {
                queue2.push(currentElement);
            }
            else {
                sourceQueue.push(currentElement);
            }
        }
    }
}

// Функция для вывода элементов очереди на экран
void displayQueue(queue<int>& q) {
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "ru");
    queue<int> mainQueue;
    queue<int> queue1;
    queue<int> queue2;

    int maxSize;
    cout << "Введите размер очереди: ";
    cin >> maxSize;

    int choice;
    do {
        cout << "\nМеню:\n"
            << "1. Добавить элемент\n"
            << "2. Рассортировать очереди\n"
            << "3. Вывести главную очередь\n"
            << "4. Вывести очередь с минимальными элементами\n"
            << "5. Вывести очередь с максимальными элементами\n"
            << "6. Выход\n"
            << "Выбериту пункт меню: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            if (mainQueue.size() >= maxSize) {
                cout << "Очередь полная!" << endl;
            }
            else {
                int element;
                cout << "Введите значение для добавления: ";
                cin >> element;
                mainQueue.push(element);
            }
            break;
        }
        case 2: {
            splitQueue(mainQueue, queue1, queue2);
            break;
        }
        case 3: {
            cout << "Главная очередь: ";
            displayQueue(mainQueue);
            break;
        }
        case 4: {
            cout << "Очередь с минимальными элементами: ";
            displayQueue(queue1);
            break;
        }
        case 5: {
            cout << "Очередь с максимальными элементами: ";
            displayQueue(queue2);
            break;
        }
        case 6: {
            cout << "Выход из программы..." << endl;
            break;
        }
        default: {
            cout << "Неверный выбор. Попробуйте снова." << endl;
            break;
        }
        }
    } while (choice != 6);

    return 0;
}
