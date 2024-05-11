#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

struct ExamResult {
    string fullName;
    int numExams;
    int* grades; 
};

bool passedWithHighMarks(const ExamResult& result) {
    
    for (int i = 0; i < result.numExams; ++i) {
        if (result.grades[i] < 4) {
            return false;
        }
    }
    return true;
}

float calculateSuccessRate(const ExamResult* results, int numStudents) {
    int passedHighMarksCount = 0;
    for (int i = 0; i < numStudents; ++i) {
        if (passedWithHighMarks(results[i])) {
            passedHighMarksCount++;
        }
    }
    
    return (static_cast<float>(passedHighMarksCount) / numStudents) * 100;
}

int main() {
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int numStudents;
    cout << "������� ���������� ���������: ";
    cin >> numStudents;

    ExamResult* results = new ExamResult[numStudents];

    for (int i = 0; i < numStudents; ++i) {
        cout << "������� ��� �������� " << i + 1 << ": ";
        cin.ignore(); 
        getline(cin, results[i].fullName);

        cout << "������� ���������� ��������� ��� �������� " << i + 1 << ": ";
        cin >> results[i].numExams;

        results[i].grades = new int[results[i].numExams];
        for (int j = 0; j < results[i].numExams; ++j) {
            cout << "������� ������ �� ������� " << j + 1 << " ��� �������� " << i + 1 << ": ";
            cin >> results[i].grades[j];
        }
    }

    float successRate = calculateSuccessRate(results, numStudents);
    cout << "������������ ���������: " << successRate << "%" << endl;

    
    for (int i = 0; i < numStudents; ++i) {
        delete[] results[i].grades;
    }
    delete[] results;

    return 0;
}