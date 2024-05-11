#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype>

using namespace std;

// Функция, которая возвращает хеш-таблицу с подсчитанным количеством букв в строке
unordered_map<char, int> countLetters(const string& str) {
    unordered_map<char, int> letterCount;
    for (char c : str) {
        if (isalpha(c)) {
            char letter = tolower(c);  // Преобразуем букву в нижний регистр для учета регистра
            letterCount[letter]++;
        }
    }
    return letterCount;
}

int main() {
    setlocale(LC_ALL, "ru");
    string input;
    cout << "Введите строку: ";
    getline(cin, input);

    unordered_map<char, int> letterCount = countLetters(input);

    cout << "\nХеш-таблица букв и их количества в строке:\n";
    for (const auto& pair : letterCount) {
        cout << pair.first << ": " << pair.second << endl;
    }

    char searchLetter;
    cout << "\nВведите букву для поиска: ";
    cin >> searchLetter;

    if (isalpha(searchLetter)) {
        searchLetter = tolower(searchLetter);
        if (letterCount.find(searchLetter) != letterCount.end()) {
            cout << "Буква '" << searchLetter << "' найдена в строке "
                << letterCount[searchLetter] << " раз(а)" << endl;
        }
        else {
            cout << "Буква '" << searchLetter << "' не найдена в строке" << endl;
        }
    }
    else {
        cout << "Некорректный ввод для поиска" << endl;
    }

    return 0;
}
