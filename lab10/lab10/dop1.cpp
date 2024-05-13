#include <iostream>
#include <fstream>

using namespace std;

const int MAX_DIGITS = 10;

void writeNumbersToFile(int A, int currentLength, int currentNumber[], ofstream& outputFile) {
    if (currentLength == A) {
        if (currentNumber[0] != 0) {
            for (int i = 0; i < A; ++i) {
                outputFile << currentNumber[i];
            }
            outputFile << endl;
        }
        return;
    }

    for (int i = 0; i <= A; ++i) {
        currentNumber[currentLength] = i;
        writeNumbersToFile(A, currentLength + 1, currentNumber, outputFile);
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    int A;
    cout << "������� ����� A: ";
    cin >> A;

    if (A < 1 || A > MAX_DIGITS) {
        cout << "������������ ���� ��� ����� A." << endl;
        return 1;
    }

    ofstream outputFile("numbers.txt");
    if (!outputFile.is_open()) {
        cout << "�� ������� ������� ���� ��� ������." << endl;
        return 1;
    }

    int currentNumber[MAX_DIGITS];
    writeNumbersToFile(A, 0, currentNumber, outputFile);

    outputFile.close();
    cout << "����� �������� � ���� numbers.txt." << endl;

    return 0;
}
