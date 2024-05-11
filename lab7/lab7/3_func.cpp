#include <iostream>;
#include <fstream>
#include <string>
#include <malloc.h>
#include "3.h"

using namespace std;

string A = "stack.txt";
char str[100];
int numOfnumber;

void push(comp** top, int D)
{
    comp* q = new comp(); 
    q->Data = D;  
    if (top == NULL)
    {
        *top = q;
    }
    else
    {
        q->next = *top; 
        *top = q;
    }
}

bool pop(comp** top)
{
    comp* q = *top;
    if (q != NULL)
    {
        *top = q->next;
        free(q);
    }
    else return 0;

    return 1;
}

void find(comp* top, int N) 
{
    comp* q = top;
    comp* prev = NULL;
    cout << "Переменных со значением: " << N << endl;
    while (q != NULL)
    {
        if (q->Data == N) cout << q->Data << endl;
        prev = q;
        q = q->next;
    }
}

void print(comp* top) 
{
    comp* q = top;
    while (q)
    {
        cout << q->Data << ' ';
        q = q->next;
    }
}



void toFile(comp* top)
{
    numOfnumber = 0;
    ofstream fAout(A);
    if (fAout.is_open())
    {
        if (top == NULL)
        {
            fAout << "Стек пуст" << endl;
        }
        else
        {
            while (top != NULL)
            {
                fAout << top->Data << endl;
                numOfnumber++;
                top = top->next;
            }
        }
    }
    else
    {
        cout << " Невозможно открыть файл!" << endl;
    }
    fAout.close();
}

void fromFile(comp** top)
{
    int* arr = new int[numOfnumber], n;
    ifstream fAin(A);
    if (fAin.is_open())
    {
        clear(top);
        for (int i = 0; i < numOfnumber; i++)
        {
            fAin.getline(str, sizeof(str));
            arr[i] = atoi(str);
        }
        for (int i = numOfnumber - 1; i >= 0; i--)
        {
            push(top, arr[i]);
        }
    }
    else
    {
        cout << " Невозможно открыть файл!" << endl;
    }
    fAin.close();
    delete[] arr;
}

void printFirstPositiveElement(comp** top)
{
    comp* q = *top;
    comp* prev = NULL;
    while (q != NULL)
    {
        if (q->Data > 0)
        {
            if (q == *top)
            {

                *top = q->next;
                free(q);
                q->Data = NULL;
                q->next = NULL;
            }
            else
            {
                prev->next = q->next;
                free(q);
                q->Data = NULL;
                q->next = NULL;
            }
        }
        prev = q;
        q = q->next;
    }
}

void clear(comp** top) 
{
    while (pop(top));
}
