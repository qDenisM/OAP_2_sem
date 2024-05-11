#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int SIZE = 5;

void countingSort(int arr[], int size) {

    int max = arr[0], min = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    int range = max - min + 1;

    int* count = new int[range]();

    for (int i = 0; i < size; ++i) {
        count[arr[i] - min]++;
    }

    for (int i = 1; i < range; ++i) {
        count[i] += count[i - 1];
        cout << count[i] << ' ';
    }

    int* result = new int[size];
    for (int i = size - 1; i >= 0; --i) {
        result[--count[arr[i] - min]] = arr[i];
    }

    for (int i = 0; i < size; ++i) {
        arr[i] = result[i];
        
    }

    

    delete[] count;
    delete[] result;
}

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(nullptr));
    int arr[SIZE];

    cout << "Исходный массив: ";
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }

    cout << endl;

    countingSort(arr, SIZE);

    cout << "Отсортированный массив: ";
    for (int i = 0; i < SIZE; ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}
