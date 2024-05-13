#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <numeric>
#include <array>

using namespace std;

struct Student {
    string lastName;
    string firstName;
    string patronymic;
    int birthYear;
    int course;
    int groupNumber;
    array<int, 5> grades;

    double averageGrade() const {
        return accumulate(grades.begin(), grades.end(), 0.0) / grades.size();
    }
};

bool compareStudents(const Student& s1, const Student& s2) {
    if (s1.course == s2.course) {
        return s1.lastName < s2.lastName;
    }
    return s1.course < s2.course;
}

class StudentList {
private:
    list<Student> students;
public:
    void addStudent(const Student& student) {
        students.push_back(student);
    }

    void sortStudents() {
        students.sort(compareStudents);
    }

    void findAverageGrades() {
        cout << "������� ������ � ������ ������:\n";
        for (int course = 1; course <= 4; ++course) {
            for (int group = 1; group <= 3; ++group) {
                cout << "���� " << course << ", ������ " << group << ": ";
                auto total = count_if(students.begin(), students.end(),
                    [course, group](const Student& s) {
                        return s.course == course && s.groupNumber == group;
                    });
                if (total == 0) {
                    cout << "��� ���������\n";
                    continue;
                }
                auto sum = accumulate(students.begin(), students.end(), 0.0,
                    [course, group](double partialSum, const Student& s) {
                        return partialSum + (s.course == course && s.groupNumber == group ? s.averageGrade() : 0);
                    });
                cout << sum / total << "\n";
            }
        }
    }

    void findOldestAndYoungest() {
        auto oldest = max_element(students.begin(), students.end(),
            [](const Student& s1, const Student& s2) {
                return s1.birthYear < s2.birthYear;
            });
        auto youngest = min_element(students.begin(), students.end(),
            [](const Student& s1, const Student& s2) {
                return s1.birthYear < s2.birthYear;
            });

        cout << "����� �������� �������: " << oldest->firstName << " " << oldest->lastName << " (" << oldest->birthYear << ")\n";
        cout << "����� ������� �������: " << youngest->firstName << " " << youngest->lastName << " (" << youngest->birthYear << ")\n";
    }

    void findBestStudents() {
        cout << "������ ��������:\n";
        for (int course = 1; course <= 4; ++course) {
            for (int group = 1; group <= 3; ++group) {
                auto best = max_element(students.begin(), students.end(),
                    [course, group](const Student& s1, const Student& s2) {
                        return s1.course == course && s1.groupNumber == group &&
                            s1.averageGrade() < s2.averageGrade();
                    });
                if (best != students.end() && best->course == course && best->groupNumber == group) {
                    cout << "���� " << course << ", ������ " << group << ": " << best->firstName << " " << best->lastName << " (" << best->averageGrade() << ")\n";
                }
            }
        }
    }

    void displayMenu() {
        int choice;
        do {
            cout << "\n����:\n";
            cout << "1. �������� ��������\n";
            cout << "2. �������������� ���������\n";
            cout << "3. ����� ������� ������ ������\n";
            cout << "4. ����� ������ �������� � ������ �������� ��������\n";
            cout << "5. ����� ������ ���������\n";
            cout << "6. �����\n";
            cout << "�������� ����� ����: ";
            cin >> choice;

            switch (choice) {
            case 1:
                addStudentFromInput();
                break;
            case 2:
                sortStudents();
                break;
            case 3:
                findAverageGrades();
                break;
            case 4:
                findOldestAndYoungest();
                break;
            case 5:
                findBestStudents();
                break;
            case 6:
                cout << "����� �� ���������...\n";
                break;
            default:
                cout << "�������� �����. ���������� �����.\n";
            }
        } while (choice != 6);
    }

private:
    void addStudentFromInput() {
        Student student;
        cout << "������� ������� ��������: ";
        cin >> student.lastName;
        cout << "������� ��� ��������: ";
        cin >> student.firstName;
        cout << "������� �������� ��������: ";
        cin >> student.patronymic;
        cout << "������� ��� �������� ��������: ";
        cin >> student.birthYear;
        cout << "������� ���� ��������: ";
        cin >> student.course;
        cout << "������� ������ ��������: ";
        cin >> student.groupNumber;
        cout << "������� ������ ��� 5 ��������� ��� ���������:\n";
        for (int i = 0; i < 5; ++i) {
            cout << "������� " << i + 1 << ": ";
            cin >> student.grades[i];
        }
        addStudent(student);
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    StudentList studentList;

    studentList.displayMenu();

    return 0;
}
