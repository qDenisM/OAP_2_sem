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
        cout << "Средняя оценка в каждой группе:\n";
        for (int course = 1; course <= 4; ++course) {
            for (int group = 1; group <= 3; ++group) {
                cout << "Курс " << course << ", Группа " << group << ": ";
                auto total = count_if(students.begin(), students.end(),
                    [course, group](const Student& s) {
                        return s.course == course && s.groupNumber == group;
                    });
                if (total == 0) {
                    cout << "Нет студентов\n";
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

        cout << "Самый взрослый студент: " << oldest->firstName << " " << oldest->lastName << " (" << oldest->birthYear << ")\n";
        cout << "Самый младший студент: " << youngest->firstName << " " << youngest->lastName << " (" << youngest->birthYear << ")\n";
    }

    void findBestStudents() {
        cout << "Лучшие студенты:\n";
        for (int course = 1; course <= 4; ++course) {
            for (int group = 1; group <= 3; ++group) {
                auto best = max_element(students.begin(), students.end(),
                    [course, group](const Student& s1, const Student& s2) {
                        return s1.course == course && s1.groupNumber == group &&
                            s1.averageGrade() < s2.averageGrade();
                    });
                if (best != students.end() && best->course == course && best->groupNumber == group) {
                    cout << "Курс " << course << ", Группа " << group << ": " << best->firstName << " " << best->lastName << " (" << best->averageGrade() << ")\n";
                }
            }
        }
    }

    void displayMenu() {
        int choice;
        do {
            cout << "\nМеню:\n";
            cout << "1. Добавить студента\n";
            cout << "2. Рассортировать студентов\n";
            cout << "3. Найти среднюю оценку группы\n";
            cout << "4. Найти самого старшего и самого младшего студента\n";
            cout << "5. Найти лучших студентов\n";
            cout << "6. Выход\n";
            cout << "Выберите пункт меню: ";
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
                cout << "Выход из программы...\n";
                break;
            default:
                cout << "Неверный выбор. Попробуйте снова.\n";
            }
        } while (choice != 6);
    }

private:
    void addStudentFromInput() {
        Student student;
        cout << "Введите фамилию студента: ";
        cin >> student.lastName;
        cout << "Введите имя студента: ";
        cin >> student.firstName;
        cout << "Введите отчество студента: ";
        cin >> student.patronymic;
        cout << "Введите год рождения стунента: ";
        cin >> student.birthYear;
        cout << "Введите курс студента: ";
        cin >> student.course;
        cout << "Введите группу студента: ";
        cin >> student.groupNumber;
        cout << "Введите оценки для 5 предметов для студентов:\n";
        for (int i = 0; i < 5; ++i) {
            cout << "Предмет " << i + 1 << ": ";
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
