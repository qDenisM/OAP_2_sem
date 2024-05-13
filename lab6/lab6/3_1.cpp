#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

int _stateMenu = -1;

struct list
{
    int number;
    list* next;
};

void insert(list*&, int); 
int del(list*&, int); 
int IsEmpty(list*); 
void printList(list*); 
void sum(list*); 
void findElement(list*); 
void toFile(list*& p); 
void fromFile(list*& p); 

void menu() {
    cout
        << "выберете действие: " << endl
        << "1 - добавить элемент" << endl
        << "2 - удалить элемент" << endl
        << "3 - поиск элемента" << endl
        << "4 - вывод списка" << endl
        << "5 - запись списка в файл" << endl
        << "6 - чтение списка из файла" << endl
        << "7 - сумма положительных элементов кратных 5" << endl;
    cin >> _stateMenu;
}

int main() {
    setlocale(0, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    list* first = NULL;
    int value;

    while (_stateMenu != 0) {
        menu();
        switch (_stateMenu) {
        case 1:
            cout << "Введите число ";
            cin >> value;
            insert(first, value);
            printList(first);
            break;
        case 2:
            if (!IsEmpty(first)) 
            {
                cout << "Введите удаляемое число ";
                cin >> value;
                if (del(first, value))
                {
                    cout << "Удалено число " << value << endl;
                    printList(first);
                }
                else
                    cout << "Число не найдено" << endl;
            }
            else
                cout << "Список пуст" << endl;
            break;
        case 3:
            if (!IsEmpty(first)) 
            {
                findElement(first);
            }
            else
                cout << "Число не найдено" << endl;
            break;
        case 4:
            if (!IsEmpty(first)) 
            {
                printList(first);
            }
            else
                cout << "Список пуст" << endl;
            break;
        case 5:
            toFile(first);
            break;
        case 6:
            fromFile(first);
            break;
        case 7:
            sum(first);  
            break;
        default:
            break;
        }
        system("cls");
    }

    return 0;
}

void insert(list*& p, int value) 
{
    list* newP = new list;
    if (newP != NULL)       
    {
        newP->number = value;
        newP->next = p;
        p = newP;
    }
    else
        cout << "Операция добавления не выполнена" << endl;
}

int del(list*& p, int value)  
{
    list* previous, * current, * temp;
    if (value == p->number)
    {
        temp = p;
        p = p->next;    
        delete temp;    
        return value;
    }
    else
    {
        previous = p;
        current = p->next;
        while (current != NULL && current->number != value)
        {
            previous = current;
            current = current->next; 
        }
        if (current != NULL)
        {
            temp = current;
            previous->next = current->next;
            free(temp);
            return value;
        }
    }
    return 0;
}

int IsEmpty(list* p)  
{
    return p == NULL;
}

void printList(list* p)  
{
    if (p == NULL)
        cout << "Список пуст" << endl;
    else
    {
        cout << "Список:" << endl;
        while (p != NULL)
        {
            cout << " > " << p->number;
            p = p->next; 
        }
        cout << "> NULL" << endl;
    }
    system("pause");
}

void sum(list* p)  
{
    int sm = 0;
    if (p == NULL)
        cout << "Список пуст" << endl;
    else
    {
        while (p != NULL)
        {
            if (p->number > 0 && (p->number % 5 == 0))
                sm += (p->number);
            p = p->next;
        }
        if (sm != 0) cout << "Сумма = " << sm << endl;
        else cout << "таких элементов нет" << endl;
    }
    system("pause");
}

void findElement(list* p)
{
    int buff;
    int i = 0;

    cout << "введите искомый элемент ";
    cin >> buff;


    cout << "места элемента в очереди: ";

    while (p != NULL)
    {
        if (p->number == buff)
        {
            cout << i << "; ";
        }
        p = p->next;
        i++;
    }

    cout << endl;
    system("pause");
}

void toFile(list*& p)
{
    list* temp = p;
    list buf;
    ofstream frm("mList.txt");
    if (frm.fail())
    {
        cout << "\n Ошибка открытия файла";
        return;
    }
    while (temp)
    {
        buf = *temp;
        frm << buf.number << " "; 
        temp = temp->next;
    }
    frm.close();
    cout << "Список записан в файл mList.txt\n";
}

void fromFile(list*& p)
{
    list* first = nullptr;
    int buf;
    ifstream frm("mList.txt");
    if (frm.fail())
    {
        cout << "\n Ошибка открытия файла";
        return;
    }
    while (!frm.eof())
    {
        frm >> buf;
        insert(first, buf); 
    }
    cout << "-->NULL" << endl;
    frm.close();
    p = first;
    cout << "\nСписок считан из файла mList.txt\n";
}