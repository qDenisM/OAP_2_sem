#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

void writeToFile(const string& text)
{
    ofstream file("data.txt");
    if (file.is_open())
    {
        file << text;
        file.close();
    }
    else
    {
        cout << "Ошибка открытия файла!" << endl;
    }
}

void readFromFile()
{
    ifstream infile("data.txt");
    if (infile.is_open())
    {
        string word;
        while (infile >> word)
        {
            if (word.find('x') != string::npos)
            {
                cout << word << endl;
            }
        }
        infile.close();
    }
    else
    {
        cout << "Ошибка открытия файла!" << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string text;
    cout << "Введите строку: ";
    getline(cin, text);

    writeToFile(text);

    readFromFile();

    return 0;
}