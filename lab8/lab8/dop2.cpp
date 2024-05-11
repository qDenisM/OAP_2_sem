#include <iostream>
#include <queue>

using namespace std;

void fillQueue(queue<double>& q) {
    int n;
    cout << "������� ���������� ��������� � �������: ";
    cin >> n;
    cout << "������� �������� �������:\n";
    for (int i = 0; i < n; ++i) {
        double value;
        cin >> value;
        q.push(value);
    }
}

void cyclicShift(queue<double>& q) {
    double max = q.front();
    size_t size = q.size();
    for (size_t i = 0; i < size; ++i) {
        double front = q.front();
        q.pop();
        q.push(front);
        if (front > max) {
            max = front;
        }
    }
    while (q.front() != max) {
        double front = q.front();
        q.pop();
        q.push(front);
    }
}

void printQueue(queue<double> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "ru");
    queue<double> q;
    int choice;
    do {
        cout << "����:\n";
        cout << "1. ��������� �������\n";
        cout << "2. ��������� ����������� �����\n";
        cout << "3. ������� ������� �� �����\n";
        cout << "4. �����\n";
        cout << "�������� ��������: ";
        cin >> choice;

        switch (choice) {
        case 1:
            fillQueue(q);
            break;
        case 2:
            cyclicShift(q);
            break;
        case 3:
            cout << "�������: ";
            printQueue(q);
            break;
        case 4:
            cout << "����� �� ���������.\n";
            break;
        default:
            cout << "������������ �����.\n";
            break;
        }
    } while (choice != 4);

    return 0;
}
