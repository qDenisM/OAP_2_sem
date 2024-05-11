#include <iostream>

using namespace std;

void printPermutations(int numbers[], bool used[], int permutation[], int n, int pos) {
    if (pos == n) {
        for (int i = 0; i < n; ++i) {
            cout << permutation[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            permutation[pos] = numbers[i];
            used[i] = true;
            printPermutations(numbers, used, permutation, n, pos + 1);
            used[i] = false;
        }
    }
}

int main() {
    const int n = 5;
    int numbers[] = { 1, 2, 3, 4, 5 };
    bool used[n] = { false };
    int permutation[n];

    printPermutations(numbers, used, permutation, n, 0);

    return 0;
}
