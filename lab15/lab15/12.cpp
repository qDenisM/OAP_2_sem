#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void fillArrayRandomly(int* arr, int size) {
    srand(time(nullptr));
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 50; 
    }
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void copyEvenIndexes(int* A, int* B, int sizeA, int& sizeB) {
    sizeB = 0;
    for (int i = 0; i < sizeA; i += 2) {
        B[sizeB++] = A[i];
    }
}

void bubbleSort(int* arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void merge(int* arr, int l, int m, int r) {
    const int n1 = m - l + 1;
    const int n2 = r - m;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; ++i) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; ++j) {
        R[j] = arr[m + 1 + j];
    }

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        }
        else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(int* arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    const int sizeA = 10;
    int* A = new int[sizeA];
    fillArrayRandomly(A, sizeA);

    const int sizeB = sizeA / 2;
    int* B = new int[sizeB];

    int actualSizeB;
    copyEvenIndexes(A, B, sizeA, actualSizeB);

    cout << "Исходный массив A: ";
    printArray(A, sizeA);

    cout << "Массив B (элементы с четными индексами из A): ";
    printArray(B, actualSizeB);

    int choice;
    do
    {
        cout << "Выберите метод сортировки для массива B:\n";
        cout << "1. Сортировка пузырьком\n";
        cout << "2. Сортировка слиянием\n";
        cout << "3. Выход\n";
        cin >> choice;
        switch (choice) {
            case 1:
                bubbleSort(B, actualSizeB);
                cout << "Отсортированный массив B: ";
                printArray(B, actualSizeB);
                break;
            case 2:
                mergeSort(B, 0, actualSizeB - 1);
                cout << "Отсортированный массив B: ";
                printArray(B, actualSizeB);
                break;
            case 3:
                cout << "Выход из программы..." << endl;
                exit(0);
                break;
            default:
                cout << "Неверный выбор\n";
                return 1;
        }
    } while (choice != 3);

    delete[] A;
    delete[] B;

    return 0;
}
