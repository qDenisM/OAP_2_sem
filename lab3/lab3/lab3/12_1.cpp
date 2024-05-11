#include <iostream>
#include <fstream>

using namespace std;

bool stringContains(const char* line, const char* word) {
    while (*line != '\0') {
        const char* lineStart = line;
        const char* wordStart = word;

        
        while (*line != '\0' && *word != '\0' && *line == *word) {
            line++;
            word++;
        }

        
        if (*word == '\0') {
            return true;
        }

        
        line = lineStart + 1;
        word = wordStart;
    }

    return false;
}

int main() {
    setlocale(LC_ALL, "ru");
    const int maxStringLength = 100;
    char firstWord[maxStringLength] = "";
    const char* inputFile = "FILE1.txt";
    const char* outputFile = "FILE2.txt";

    ifstream inFile(inputFile);
    if (!inFile) {
        cerr << "Не удалось открыть файл " << inputFile << endl;
        return 1;
    }

    
    inFile >> firstWord;

    inFile.clear();
    inFile.seekg(0, ios::beg);

    ofstream outFile(outputFile);
    if (!outFile) {
        cerr << "Не удалось открыть файл " << outputFile << endl;
        return 1;
    }

    char line[maxStringLength];
    while (inFile.getline(line, maxStringLength)) {
        
        if (stringContains(line, firstWord)) {
            outFile << line << endl;
        }
    }

    inFile.close();
    outFile.close();

    ifstream file2(outputFile);
    if (!file2) {
        cerr << "Не удалось открыть файл " << outputFile << endl;
        return 1;
    }

    
    int letterCount = 0;
    char ch;
    while (file2.get(ch)) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            letterCount++;
        }
    }

    file2.close();

    cout << "Скопировано из файла FILE1 в файл FILE2." << endl;
    cout << "Количество букв в FILE2: " << letterCount << endl;

    return 0;
}