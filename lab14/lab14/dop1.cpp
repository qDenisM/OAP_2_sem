#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype>

using namespace std;

// �������, ������� ���������� ���-������� � ������������ ����������� ���� � ������
unordered_map<char, int> countLetters(const string& str) {
    unordered_map<char, int> letterCount;
    for (char c : str) {
        if (isalpha(c)) {
            char letter = tolower(c);  // ����������� ����� � ������ ������� ��� ����� ��������
            letterCount[letter]++;
        }
    }
    return letterCount;
}

int main() {
    setlocale(LC_ALL, "ru");
    string input;
    cout << "������� ������: ";
    getline(cin, input);

    unordered_map<char, int> letterCount = countLetters(input);

    cout << "\n���-������� ���� � �� ���������� � ������:\n";
    for (const auto& pair : letterCount) {
        cout << pair.first << ": " << pair.second << endl;
    }

    char searchLetter;
    cout << "\n������� ����� ��� ������: ";
    cin >> searchLetter;

    if (isalpha(searchLetter)) {
        searchLetter = tolower(searchLetter);
        if (letterCount.find(searchLetter) != letterCount.end()) {
            cout << "����� '" << searchLetter << "' ������� � ������ "
                << letterCount[searchLetter] << " ���(�)" << endl;
        }
        else {
            cout << "����� '" << searchLetter << "' �� ������� � ������" << endl;
        }
    }
    else {
        cout << "������������ ���� ��� ������" << endl;
    }

    return 0;
}
