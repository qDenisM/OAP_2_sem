#include <iostream>
#include <windows.h>
using namespace std;
struct Tree          
{
    int key;         
    char text[5];    
    Tree* Left, * Right;
};

Tree* makeTree(Tree* Root);       
Tree* list(int i, char* s);       
Tree* insertElem(Tree* Root, int key, char* s);  
Tree* search(Tree* n, int key);   
Tree* delet(Tree* Root, int key); 
void view(Tree* t, int level);    
int count(Tree* t, char letter);  
void delAll(Tree* t);             

int c = 0;         
Tree* Root = NULL; 

void main()
{
    setlocale(0, "Russian");
    int key, choice, n;
    Tree* rc; char s[5], letter;
    for (;;)
    {
        cout << "1 -  создание дерева\n";
        cout << "2 -  добавление элемента\n";
        cout << "3 -  поиск по ключу\n";
        cout << "4 -  удаление элемента\n";
        cout << "5 -  вывод дерева\n";
        cout << "6 -  подсчет количества слов\n";
        cout << "7 -  очистка дерева\n";
        cout << "8 -  выход\n";
        cout << "ваш выбор?\n";
        cin >> choice;
        cout << "\n";
        switch (choice)
        {
        case 1:  Root = makeTree(Root);  break;
        case 2:  cout << "\nВведите ключ: "; cin >> key;
            cout << "Введите слово: "; cin >> s;
            insertElem(Root, key, s); break;
        case 3:  cout << "\nВведите ключ: ";  cin >> key;
            rc = search(Root, key);
            cout << "Найденное слово= ";
            puts(rc->text); break;
        case 4:  cout << "\nВведите удаляемый ключ: "; cin >> key;
            Root = delet(Root, key);  break;
        case 5:  if (Root->key >= 0)
        {
            cout << "Дерево повернуто на 90 град. влево" << endl;
            view(Root, 0);
        }
              else cout << "Дерево пустое\n"; break;
        case 6:  cout << "\nВведите букву: "; cin >> letter;
            n = count(Root, letter);
            cout << "Количество слов, начинающихся с буквы " << letter;
            cout << " равно " << n << endl; break;
        case 7:  delAll(Root); break;
        case 8:  exit(0);
        }
    }
}

Tree* makeTree(Tree* Root)    
{
    int key; char s[5];
    cout << "Конец ввода - отрицательное число\n\n";
    if (Root == NULL)  
    {
        cout << "Введите ключ корня: "; cin >> key;
        cout << "Введите слово корня: "; cin >> s;
        Root = list(key, s);  
    }
    while (1)                
    {
        cout << "\nВведите ключ: ";  cin >> key;
        if (key < 0) break;          
        cout << "Введите слово: ";  cin >> s;
        insertElem(Root, key, s);
    }
    return Root;
}

Tree* list(int i, char* s)     
{
    Tree* t = new Tree[sizeof(Tree)];
    t->key = i;
    for (i = 0; i < 5; i++)
        *((t->text) + i) = *(s + i);
    t->Left = t->Right = NULL;
    return t;
}

Tree* insertElem(Tree* t, int key, char* s)  
{
    Tree* Prev = NULL;       
    int find = 0;        
    while (t && !find)
    {
        Prev = t;
        if (key == t->key)
            find = 1;     
        else
            if (key < t->key) t = t->Left;
            else t = t->Right;
    }
    if (!find)              
    {
        t = list(key, s);           
        if (key < Prev->key)  
            Prev->Left = t;    
        else
            Prev->Right = t;   
    }
    return t;
}

Tree* delet(Tree* Root, int key)  
{   
    Tree* Del, * Prev_Del, * R, * Prev_R;
    Del = Root;
    Prev_Del = NULL;
    while (Del != NULL && Del->key != key)
    {
        Prev_Del = Del;
        if (Del->key > key)
            Del = Del->Left;
        else
            Del = Del->Right;
    }
    if (Del == NULL)              
    {
        puts("\nНет такого ключа");
        return Root;
    }
    if (Del->Right == NULL) 
        R = Del->Left;
    else
        if (Del->Left == NULL)
            R = Del->Right;
        else {
            Prev_R = Del; 
            R = Del->Left;
            while (R->Right != NULL) {
                Prev_R = R;
                R = R->Right;
            }
            if (Prev_R == Del) 
                R->Right = Del->Right;
            else
            {
                R->Right = Del->Right;
                Prev_R->Right = R->Left;
                R->Left = Prev_R;
            }
        }
    if (Del == Root) Root = R;  
    else
        if (Del->key < Prev_Del->key)
            Prev_Del->Left = R; 
        else
            Prev_Del->Right = R;  
    int tmp = Del->key;
    cout << "\nУдален элемент с ключом " << tmp << endl;
    delete Del;
    return Root;
}

Tree* search(Tree* n, int key)  
{
    Tree* rc = n;
    if (rc != NULL)
    {
        if (key < (key, n->key))
            rc = search(n->Left, key);
        else
            if (key > (key, n->key))
                rc = search(n->Right, key);
    }
    else
        cout << "Нет такого элемента\n";
    return rc;
}

int count(Tree* t, char letter) 
{
    if (t)
    {
        count(t->Right, letter);
        if (*(t->text) == letter)
            c++;
        count(t->Left, letter);
    }
    return c;
}

void view(Tree* t, int level) 
{
    if (t)
    {
        view(t->Right, level + 1);  
        for (int i = 0; i < level; i++)
            cout << "   ";
        int tm = t->key;
        cout << tm << ' ';
        puts(t->text);
        view(t->Left, level + 1);  
    }
}

void delAll(Tree* t) 
{
    if (t != NULL)
    {
        delAll(t->Left);
        delAll(t->Right);
        delete t;
    }
}
