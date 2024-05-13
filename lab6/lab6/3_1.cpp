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
        << "�������� ��������: " << endl
        << "1 - �������� �������" << endl
        << "2 - ������� �������" << endl
        << "3 - ����� ��������" << endl
        << "4 - ����� ������" << endl
        << "5 - ������ ������ � ����" << endl
        << "6 - ������ ������ �� �����" << endl
        << "7 - ����� ������������� ��������� ������� 5" << endl;
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
            cout << "������� ����� ";
            cin >> value;
            insert(first, value);
            printList(first);
            break;
        case 2:
            if (!IsEmpty(first)) 
            {
                cout << "������� ��������� ����� ";
                cin >> value;
                if (del(first, value))
                {
                    cout << "������� ����� " << value << endl;
                    printList(first);
                }
                else
                    cout << "����� �� �������" << endl;
            }
            else
                cout << "������ ����" << endl;
            break;
        case 3:
            if (!IsEmpty(first)) 
            {
                findElement(first);
            }
            else
                cout << "����� �� �������" << endl;
            break;
        case 4:
            if (!IsEmpty(first)) 
            {
                printList(first);
            }
            else
                cout << "������ ����" << endl;
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
        cout << "�������� ���������� �� ���������" << endl;
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
        cout << "������ ����" << endl;
    else
    {
        cout << "������:" << endl;
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
        cout << "������ ����" << endl;
    else
    {
        while (p != NULL)
        {
            if (p->number > 0 && (p->number % 5 == 0))
                sm += (p->number);
            p = p->next;
        }
        if (sm != 0) cout << "����� = " << sm << endl;
        else cout << "����� ��������� ���" << endl;
    }
    system("pause");
}

void findElement(list* p)
{
    int buff;
    int i = 0;

    cout << "������� ������� ������� ";
    cin >> buff;


    cout << "����� �������� � �������: ";

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
        cout << "\n ������ �������� �����";
        return;
    }
    while (temp)
    {
        buf = *temp;
        frm << buf.number << " "; 
        temp = temp->next;
    }
    frm.close();
    cout << "������ ������� � ���� mList.txt\n";
}

void fromFile(list*& p)
{
    list* first = nullptr;
    int buf;
    ifstream frm("mList.txt");
    if (frm.fail())
    {
        cout << "\n ������ �������� �����";
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
    cout << "\n������ ������ �� ����� mList.txt\n";
}