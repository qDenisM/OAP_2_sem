#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

bool isDelimiter(char c) {
    return c == ' ' || c == ',' || c == '.' || c == '!' || c == '?' || c == ';' || c == ':';
}

bool isConsonant(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' &&
            c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U');
    }
    else if ((c >= '�' && c <= '�') || (c >= '�' && c <= '�')) {
        return (c != '�' && c != '�' && c != '�' && c != '�' && c != '�' && c != '�' && c != '�' && c != '�' && c != '�' && c != '�' &&
            c != '�' && c != '�' && c != '�' && c != '�' && c != '�' && c != '�' && c != '�' && c != '�' && c != '�' && c != '�');
    }
    return false;
}


int main() {
    setlocale(LC_ALL, "ru");

    ifstream file1("FILE1.txt");
    if (!file1.is_open()) {
        cerr << "���������� ������� FILE1.txt";
        return 1;
    }

    ofstream file2("FILE2.txt");
    if (!file2.is_open()) {
        cerr << "���������� ������� FILE2.txt";
        return 1;
    }

    string firstLine;
    getline(file1, firstLine);

    istringstream iss(firstLine);
    string firstWord;
    iss >> firstWord;

    string line;
    int consonantCount = 0;
    bool firstLineProcessed = false;
    while (getline(file1, line)) {
        if (line.find(firstWord) != string::npos) {
            continue;
        }

        if (!firstLineProcessed) {
            for (char c : line) {
                if (isConsonant(c)) {
                    consonantCount++;
                }
            }
            firstLineProcessed = true;
        }


        file2 << line << endl;
    }

    file1.close();
    file2.close();

    cout << "����� ��������� � ������ ������ � ����� FILE2: " << consonantCount << endl;

    return 0;
}
