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
    cout << "Введите число A: ";
    cin >> A;

    if (A < 1 || A > MAX_DIGITS) {
        cout << "Некорректный ввод для числа A." << endl;
        return 1;
    }

    ofstream outputFile("numbers.txt");
    if (!outputFile.is_open()) {
        cout << "Не удалось открыть файл для записи." << endl;
        return 1;
    }

    int currentNumber[MAX_DIGITS];
    writeNumbersToFile(A, 0, currentNumber, outputFile);

    outputFile.close();
    cout << "Числа записаны в файл numbers.txt." << endl;

    return 0;
}
