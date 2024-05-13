#include <iostream>
#include <cstring>

using namespace std;

const int MAX_COUNTRIES = 100;

int A[MAX_COUNTRIES][MAX_COUNTRIES];
int groups[MAX_COUNTRIES];

int n;

bool dfs(int country, int group) {
    if (groups[country] != -1) {
        return groups[country] == group;
    }

    groups[country] = group;

    for (int i = 0; i < n; ++i) {
        if (A[country][i]) {
            if (!dfs(i, 1 - group)) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    setlocale(LC_ALL, "ru");
    cout << "Введите количество стран: ";
    cin >> n;
    cout << "Введите границы стран: " << endl;
    memset(groups, -1, sizeof(groups));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        if (groups[i] == -1) {
            if (!dfs(i, 0)) {
                cout << "Невозможно разбить страны на две группы так, чтобы количество пар смежных стран из противоположных групп было минимальным." << endl;
                return 0;
            }
        }
    }

    cout << "Результат раскраски:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Страна " << i + 1 << ": Группа " << groups[i] << endl;
    }

    return 0;
}