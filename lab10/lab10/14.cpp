#include <iostream>

using namespace std;

double factorial(int n) {
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}

double f(double x, int n) {
    if (n == 0)
        return 1;
    else if (n == 1)
        return x;
    else
        return x * x / n / (n - 1) * f(x, n - 2);
}

int main() {
    double x;
    int n;
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter n: ";
    cin >> n;

    if (n < 0) {
        cout << "n should be a non-negative integer." << endl;
        return 1;
    }

    double result = f(x, n) / factorial(n);
    cout << "Result: " << result << endl;

    return 0;
}
