#include <iostream>
#include <queue>
#include <limits>

using namespace std;

void splitQueue(queue<int>& sourceQueue, queue<int>& queue1, queue<int>& queue2) {
    if (sourceQueue.empty()) {
        cout << "������� �����!" << endl;
        return;
    }

    int queueSize = sourceQueue.size();
    for (int i = 0; i < queueSize / 2; ++i) {
        int minElement = numeric_limits<int>::max();
        int maxElement = numeric_limits<int>::min();
        int minIndex, maxIndex;
        int currentSize = sourceQueue.size();

        // ������� ����������� � ������������ �������� � ���������� ����� �������
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

        // ���������� ��������� �������� � ��������������� �������
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

// ������� ��� ������ ��������� ������� �� �����
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
    cout << "������� ������ �������: ";
    cin >> maxSize;

    int choice;
    do {
        cout << "\n����:\n"
            << "1. �������� �������\n"
            << "2. �������������� �������\n"
            << "3. ������� ������� �������\n"
            << "4. ������� ������� � ������������ ����������\n"
            << "5. ������� ������� � ������������� ����������\n"
            << "6. �����\n"
            << "�������� ����� ����: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            if (mainQueue.size() >= maxSize) {
                cout << "������� ������!" << endl;
            }
            else {
                int element;
                cout << "������� �������� ��� ����������: ";
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
            cout << "������� �������: ";
            displayQueue(mainQueue);
            break;
        }
        case 4: {
            cout << "������� � ������������ ����������: ";
            displayQueue(queue1);
            break;
        }
        case 5: {
            cout << "������� � ������������� ����������: ";
            displayQueue(queue2);
            break;
        }
        case 6: {
            cout << "����� �� ���������..." << endl;
            break;
        }
        default: {
            cout << "�������� �����. ���������� �����." << endl;
            break;
        }
        }
    } while (choice != 6);

    return 0;
}
