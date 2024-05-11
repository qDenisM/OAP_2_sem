#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// Функция для определения является ли символ пробелом или знаком пунктуации
bool isDelimiter(char c) {
    return c == ' ' || c == ',' || c == '.' || c == '!' || c == '?' || c == ';' || c == ':';
}

// Функция для определения является ли символ согласной буквой
bool isConsonant(char c) {
    // Английский алфавит
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        // Проверяем, является ли символ буквой и не гласной
        return (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' &&
            c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U');
    }
    // Русский алфавит
    else if ((c >= 'а' && c <= 'я') || (c >= 'А' && c <= 'Я')) {
        // Проверяем, является ли символ буквой и не гласной
        return (c != 'а' && c != 'е' && c != 'ё' && c != 'и' && c != 'о' && c != 'у' && c != 'ы' && c != 'э' && c != 'ю' && c != 'я' &&
            c != 'А' && c != 'Е' && c != 'Ё' && c != 'И' && c != 'О' && c != 'У' && c != 'Ы' && c != 'Э' && c != 'Ю' && c != 'Я');
    }
    return false;
}


int main() {
    // Открываем файл FILE1 для чтения
    ifstream file1("FILE1.txt");
    if (!file1.is_open()) {
        cerr << "Unable to open FILE1.txt";
        return 1;
    }

    // Открываем файл FILE2 для записи
    ofstream file2("FILE2.txt");
    if (!file2.is_open()) {
        cerr << "Unable to open FILE2.txt";
        return 1;
    }

    // Считываем первую строку из файла FILE1 (не записываем ее в FILE2)
    string firstLine;
    getline(file1, firstLine);

    // Считываем первое слово из первой строки файла FILE1
    istringstream iss(firstLine);
    string firstWord;
    iss >> firstWord;

    // Копируем остальные строки из FILE1 в FILE2, проверяя на совпадение с первым словом
    string line;
    int consonantCount = 0;
    bool firstLineProcessed = false; // Флаг для обработки только первой строки из FILE2
    while (getline(file1, line)) {
        // Если строка содержит первое слово, переходим к следующей строке
        if (line.find(firstWord) != string::npos) {
            continue;
        }

        // Если это первая строка из FILE2, обрабатываем ее и считаем согласные
        if (!firstLineProcessed) {
            for (char c : line) {
                if (isConsonant(c)) {
                    consonantCount++;
                }
            }
            firstLineProcessed = true; // Помечаем, что первая строка была обработана
        }

        // Копируем остальные строки в FILE2
        file2 << line << endl;
    }

    file1.close();
    file2.close();

    // Выводим количество согласных букв в файле FILE2
    cout << "Number of consonants in FILE2: " << consonantCount << endl;

    return 0;
}
