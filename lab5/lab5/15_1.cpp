#include <iostream>
#include <cstring>
#include <windows.h>

using namespace std;

enum Specialization
{
    ComputerScience,
    Math,
    Engineering,
    Business,
};

struct LastYearCompetition
{
    unsigned int computerScience : 8;
    unsigned int math : 8;
    unsigned int engineering : 8;
    unsigned int business : 8;
};

struct Applicant
{
    char universityName[50];
    char address[100];
    Specialization specialty;
    LastYearCompetition lastYearCompetition;
    double tuitionFee;
};

void inputApplicant(Applicant& applicant)
{
    cout << "������� �������� ����: ";
    cin.ignore(); 
    cin.getline(applicant.universityName, sizeof(applicant.universityName));

    cout << "������� ����� ����: ";
    cin.getline(applicant.address, sizeof(applicant.address));

    cout << "�������� ������������� (0 - �����������, 1 - ����������, 2 - ���������� ����, 3 - ������): ";
    int specialization;
    cin >> specialization;
    applicant.specialty = static_cast<Specialization>(specialization);

    cout << "������� ������� �������� ���� ��� ������ ������������� (�� 0 �� 255): ";
    int computerScience, math, engineering, business;
    cin >> computerScience >> math >> engineering >> business;

    applicant.lastYearCompetition.computerScience = static_cast<unsigned int>(computerScience);
    applicant.lastYearCompetition.math = static_cast<unsigned int>(math);
    applicant.lastYearCompetition.engineering = static_cast<unsigned int>(engineering);
    applicant.lastYearCompetition.business = static_cast<unsigned int>(business);

    cout << "������� ������ ������ ��� ���������� ��������: ";
    cin >> applicant.tuitionFee;
}

void displayApplicant(const Applicant& applicant)
{
    cout << "�������� ����: " << applicant.universityName << endl;
    cout << "����� ����: " << applicant.address << endl;
    cout << "�������������: ";
    switch (applicant.specialty)
    {
    case ComputerScience:
        cout << "�����������";
        break;
    case Math:
        cout << "����������";
        break;
    case Engineering:
        cout << "���������� ����";
        break;
    case Business:
        cout << "������";
        break;
    }
    cout << endl;
    cout << "������� �������� ����: "
        << "�����������: " << applicant.lastYearCompetition.computerScience << ", "
        << "����������: " << applicant.lastYearCompetition.math << ", "
        << "���������: " << applicant.lastYearCompetition.engineering << ", "
        << "������: " << applicant.lastYearCompetition.business << endl;
    cout << "������ ������ ��� ���������� ��������: " << applicant.tuitionFee << endl;
}

void deleteApplicant(Applicant& applicant)
{
   
    memset(applicant.universityName, 0, sizeof(applicant.universityName));
    memset(applicant.address, 0, sizeof(applicant.address));
    applicant.specialty = ComputerScience;
    applicant.lastYearCompetition.computerScience = 0;
    applicant.lastYearCompetition.math = 0;
    applicant.lastYearCompetition.engineering = 0;
    applicant.lastYearCompetition.business = 0;
    applicant.tuitionFee = 0.0;
}

Applicant findMinCompetitionApplicant(const Applicant applicants[], int size)
{
    if (size == 0)
    {
        cerr << "������ ������������ ����." << endl;
        Applicant emptyApplicant;
        deleteApplicant(emptyApplicant);
        return emptyApplicant;
    }

    Applicant minCompetitionApplicant = applicants[0];

    for (int i = 1; i < size; ++i)
    {
        if (applicants[i].lastYearCompetition.computerScience < minCompetitionApplicant.lastYearCompetition.computerScience)
        {
            minCompetitionApplicant = applicants[i];
        }
    }

    return minCompetitionApplicant;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int MAX_APPLICANTS = 5;
    Applicant applicants[MAX_APPLICANTS];
    int applicantCount = 0;
    int choice;

    do
    {
        cout << "\n����:" << endl;
        cout << "1. �������� �����������" << endl;
        cout << "2. ������� ������ ������������" << endl;
        cout << "3. ������� �����������" << endl;
        cout << "4. ����� �� ������������ ��������" << endl;
        cout << "0. �����" << endl;
        cout << "�������� ��������: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (applicantCount < MAX_APPLICANTS)
            {
                inputApplicant(applicants[applicantCount]);
                applicantCount++;
            }
            else
            {
                cerr << "���������� ������������ ���������� ������������." << endl;
            }
            break;
        case 2:
            for (int i = 0; i < applicantCount; ++i)
            {
                displayApplicant(applicants[i]);
                cout << "------------------------------" << endl;
            }
            break;
        case 3:
            if (applicantCount > 0)
            {
                int indexToDelete;
                cout << "������� ����� ����������� ��� �������� (�� 1 �� " << applicantCount << "): ";
                cin >> indexToDelete;

                if (indexToDelete >= 1 && indexToDelete <= applicantCount)
                {
                    deleteApplicant(applicants[indexToDelete - 1]);
                    cout << "���������� ������." << endl;
                }
                else
                {
                    cerr << "������������ ����� �����������." << endl;
                }
            }
            else
            {
                cerr << "������ ������������ ����." << endl;
            }
            break;
        case 4:
            displayApplicant(findMinCompetitionApplicant(applicants, applicantCount));
            break;
        case 0:
            cout << "��������� ���������." << endl;
            break;
        default:
            cerr << "������������ �����. ���������� �����." << endl;
        }
    } while (choice != 0);

    return 0;
}
