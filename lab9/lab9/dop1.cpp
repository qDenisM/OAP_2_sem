#include "stdafx.h"

struct Person
{
	char name[20];
	int age;
	Person* next;
};

void print(void* b)        
{
	Person* a = (Person*)b;
	cout << a->name << "  " << a->age << endl;
}

int menu();

int main()
{
	setlocale(LC_ALL, "Russian");
	bool work = true;
	bool rc;
	Person a1, a2, a3, * aa;
	Object L1;
	Element* e;
	while (work)
	{
		switch ( menu())
		{
		case 1:
			a1 = { "Петров", 20 };
			a2 = { "Сидоров", 25 };
			a3 = { "Гончаров", 47 };
			L1 = Create();   
			L1.Insert(&a1);
			L1.Insert(&a2);
			L1.Insert(&a3);
			break;

		case 2:
			L1.PrintList(print);
			break;

		case 3:
			e = L1.Search(&a3);
			aa = (Person*)e->Data;
			cout << "Найден элемент= " << aa->name << endl;
			break;

		case 4:
			rc = L1.Delete(&a2);
			if (rc == true) cout << "Удален элемент" << endl;
			break;

		case 5:
			cout << "Кол-во элементов = " << L1.CountList(L1.Head) << endl;
			break;

		case 6:
			if (L1.DeleteList(&L1)) cout << "Список удалён!" << endl;
			else cout << "Список не удалён!" << endl;
			break;
		case 7:
			cout << "Выход из программы...";
			exit(0);
			break;
		default:
			break;
		}
	}
}
