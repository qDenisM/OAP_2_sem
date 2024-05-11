#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// ������� ��� ����������� �������� �� ������ �������� ��� ������ ����������
bool isDelimiter(char c) {
    return c == ' ' || c == ',' || c == '.' || c == '!' || c == '?' || c == ';' || c == ':';
}

// ������� ��� ����������� �������� �� ������ ��������� ������
bool isConsonant(char c) {
    // ���������� �������
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        // ���������, �������� �� ������ ������ � �� �������
        return (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' &&
            c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U');
    }
    // ������� �������
    else if ((c >= '�' && c <= '�') || (c >= '�' && c <= '�')) {
        // ���������, �������� �� ������ ������ � �� �������
        return (c != '�' && c != '�' && c != '�' && c != '�' && c != '�' && c != '�' && c != '�' && c != '�' && c != '�' && c != '�' &&
            c != '�' && c != '�' && c != '�' && c != '�' && c != '�' && c != '�' && c != '�' && c != '�' && c != '�' && c != '�');
    }
    return false;
}


int main() {
    // ��������� ���� FILE1 ��� ������
    ifstream file1("FILE1.txt");
    if (!file1.is_open()) {
        cerr << "Unable to open FILE1.txt";
        return 1;
    }

    // ��������� ���� FILE2 ��� ������
    ofstream file2("FILE2.txt");
    if (!file2.is_open()) {
        cerr << "Unable to open FILE2.txt";
        return 1;
    }

    // ��������� ������ ������ �� ����� FILE1 (�� ���������� �� � FILE2)
    string firstLine;
    getline(file1, firstLine);

    // ��������� ������ ����� �� ������ ������ ����� FILE1
    istringstream iss(firstLine);
    string firstWord;
    iss >> firstWord;

    // �������� ��������� ������ �� FILE1 � FILE2, �������� �� ���������� � ������ ������
    string line;
    int consonantCount = 0;
    bool firstLineProcessed = false; // ���� ��� ��������� ������ ������ ������ �� FILE2
    while (getline(file1, line)) {
        // ���� ������ �������� ������ �����, ��������� � ��������� ������
        if (line.find(firstWord) != string::npos) {
            continue;
        }

        // ���� ��� ������ ������ �� FILE2, ������������ �� � ������� ���������
        if (!firstLineProcessed) {
            for (char c : line) {
                if (isConsonant(c)) {
                    consonantCount++;
                }
            }
            firstLineProcessed = true; // ��������, ��� ������ ������ ���� ����������
        }

        // �������� ��������� ������ � FILE2
        file2 << line << endl;
    }

    file1.close();
    file2.close();

    // ������� ���������� ��������� ���� � ����� FILE2
    cout << "Number of consonants in FILE2: " << consonantCount << endl;

    return 0;
}
