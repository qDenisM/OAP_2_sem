#include <iostream>
#include <cmath>

using namespace std;

double sumCos(int n, double x) {
    if (n == 0) {
        return cos(n * x);
    }
    else {
        return cos(n * x) + sumCos(n - 1, x);
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    int n;
    double x;

    cout << "Введите значение n: ";
    cin >> n;

    cout << "Введите значение x: ";
    cin >> x;

    double result = sumCos(n, x);
    cout << "Результат: " << result << endl;

    return 0;
}
