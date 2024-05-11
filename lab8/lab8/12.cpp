#include <iostream>
#include <queue>

using namespace std;

void displayQueue(queue<char> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "ru");
    queue<char> myQueue;
    int maxSize;

    cout << "Введите размер очереди: ";
    cin >> maxSize;

    char choice;
    do {
        cout << "\nМеню очереди:\n";
        cout << "1. Добавить элемент очереди\n";
        cout << "2. Удалить первый элемент из очереди\n";
        cout << "3. Вывести очередь\n";
        cout << "4. Размер очереди\n";
        cout << "5. Выход\n";
        cout << "Выберите: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                char ch;
                cout << "Введите значение: ";
                cin >> ch;
                if (myQueue.size() < maxSize) {
                    myQueue.push(ch);
                    cout << "Элемент добавлен в очередь.\n";
                }
                else {
                    cout << "Очередь полная.\n";
                }
                break;
            }
            case '2': {
                if (!myQueue.empty()) {
                    myQueue.pop();
                    cout << "Элемент удален из очереди.\n";
                }
                else {
                    cout << "Очередь пустая.\n";
                }
                break;
            }
            case '3': {
                if (!myQueue.empty()) {
                    cout << "Очередь: ";
                    displayQueue(myQueue);
                }
                else {
                    cout << "Очередь пустая.\n";
                }
                break;
            }
            case '4': {
                cout << "Размер очереди: " << myQueue.size() << endl;
                break;
            }
            case '5': {
                cout << "Выход из программы...\n";
                break;
            }
            default: {
                cout << "Неверный выбор. Попробуйте снова.\n";
                break;
            }
        }
    } while (choice != '5');

    return 0;
}