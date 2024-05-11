#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Word {
    string keyword;
    string helpMessage;
};

const int TABLE_SIZE = 20;
vector<vector<Word>> hashTable(TABLE_SIZE);

int hashFunction(const string& keyword) {
    int hash = 0;
    for (char c : keyword) {
        hash += c;
    }
    return hash % TABLE_SIZE;
}

void addWord(const string& keyword, const string& helpMessage) {
    int index = hashFunction(keyword);
    hashTable[index].push_back({ keyword, helpMessage });
}
void addOrUpdateWord(const string& keyword, const string& helpMessage) {
    int index = hashFunction(keyword);
    for (auto& word : hashTable[index]) {
        if (word.keyword == keyword) {
            cout << "��������� �����������..." << endl;
            word.helpMessage = helpMessage;
            return;
        }
    }

    // ����� �� �������, �� ��������� ���
    cout << "����������������� ����� �� �������." << endl;
}


void displayHelp(const string& keyword) {
    int index = hashFunction(keyword);
    for (const auto& word : hashTable[index]) {
        if (word.keyword == keyword) {
            cout << "��������� ��� " << keyword << ": " << word.helpMessage << endl;
            return;
        }
    }
    cout << "����������������� �����: " << keyword << endl;
}

void displayTable() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        cout << "������ " << i << ": ";
        for (const auto& word : hashTable[i]) {
            cout << word.keyword << " ";
        }
        cout << endl;
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    addWord("int", "����������������� ����� ��� �������������� ��������.");
    addWord("float", "����������������� ����� ��� ����� � ��������� ������.");
    addWord("for", "����������������� ����� ��� loop iteration");
    addWord("while", "����������������� ����� ��� loop iteration");
    addWord("if", "����������������� ����� ��� conditional statement");
    addWord("else", "����������������� ����� ��� conditional statement");
    addWord("return", "����������������� ����� ��� returning a value from a function");
    addWord("switch", "����������������� ����� ��� switch statement");
    addWord("case", "����������������� ����� ��� case in switch statement");
    addWord("break", "����������������� ����� ��� breaking out of a loop or switch statement");
    addWord("continue", "����������������� ����� ��� continuing to the next iteration of a loop");
    addWord("void", "����������������� ����� ���������� ��� a function does not return a value");
    addWord("const", "����������������� ����� ���������� ��� a variable is constant");
    addWord("static", "����������������� ����� ���������� ��� a variable or function is static");
    addWord("class", "����������������� ����� ��� defining a class");
    addWord("struct", "����������������� ����� ��� defining a struct");
    addWord("enum", "����������������� ����� ��� defining an enumeration");
    addWord("namespace", "����������������� ����� ��� defining a namespace");
    addWord("using", "����������������� ����� ��� using a namespace");
    addWord("public", "����������������� ����� ��� public access in a class or struct");
    addWord("private", "����������������� ����� ��� private access in a class or struct");
    addWord("protected", "����������������� ����� ��� protected access in a class or struct");

    int choice;
    string keyword, helpMessage;

    do {
        cout << "1. �������� ���������" << endl;
        cout << "2. ������� ��������� ��� ������������������ �����" << endl;
        cout << "3. ������� ��� ����������������� �����" << endl;
        cout << "4. �����" << endl;
        cout << "��� �����: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "������� ����������������� �����: ";
            cin >> keyword;
            cout << "������� ���������: ";
            cin.ignore(); // clear buffer
            getline(cin, helpMessage);
            addOrUpdateWord(keyword, helpMessage);
            break;
        case 2:
            cout << "������� ����������������� ����� ��� ����������� ���������: ";
            cin >> keyword;
            displayHelp(keyword);
            break;
        case 3:
            displayTable();
            break;
        case 4:
            cout << "����� �� ���������..." << endl;
            break;
        default:
            cout << "�������� �����. ���������� �����" << endl;
            break;
        }

    } while (choice != 4);

    return 0;
}
