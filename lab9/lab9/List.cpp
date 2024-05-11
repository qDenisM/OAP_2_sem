#include "stdafx.h"

int menu()
{
	int c;
	cout << "\t" << endl;
	cout << "1. Создать список" << endl;
	cout << "2. Вывести список" << endl;
	cout << "3. Найти элемент" << endl;
	cout << "4. Удалить элемент" << endl;
	cout << "5. Подсчитать кол-во элементов " << endl;
	cout << "6. Удалить список" << endl;
	cout << "7. Выход" << endl;
	cin >> c;
	return c;
}

bool Object::Insert(void* data)           
{
	bool rc = 0;
	if (Head == NULL)
	{
		Head = new Element(NULL, data, Head);
		rc = true;
	}
	else
	{
		Head = (Head->Prev = new Element(NULL, data, Head));
		rc = true;
	}
	return rc;
}

Element* Object::Search(void* data)      
{
	Element* rc = Head;
	while ((rc != NULL) && (rc->Data != data))
		rc = rc->Next;
	return rc;
}

void Object::PrintList(void(*f)(void*))     
{
	Element* e = Head;
	while (e != NULL)
	{
		f(e->Data);
		e = e->GetNext();
	};
}

void Object::PrintList(void(*f)(void*), Element* e)
{
	f(e->Data);
}

bool Object::Delete(Element* e)       
{
	bool rc = 0;
	if (rc = (e != NULL))
	{
		if (e->Next != NULL)
			e->Next->Prev = e->Prev;
		if (e->Prev != NULL)
			e->Prev->Next = e->Next;
		else
			Head = e->Next;
		delete e;
	}
	return rc;
}

bool Object::Delete(void* data)         
{
	return Delete(Search(data));
}

Element* Object::GetLast()
{
	Element* e = Head, * rc = e;
	while (e != NULL)
	{
		rc = e;
		e = e->GetNext();
	}
	return rc;
}

Object Create()
{
	return *(new Object());
}

int Object::CountList(Element* head)
{
	int count = 0;
	Element* e = Head;
	while (e != NULL)
	{
		e = e->GetNext();
		count++;
	};
	return count;
}

bool Object::DeleteList(Object* l)
{
	bool rc = 0;
	if (rc = (l != NULL))
	{
		int count = CountList(l->Head);
		for (size_t i = 0; i < count; i++)
		{
			Delete(l->Head);
		}
		l = NULL;
	}
	return rc;
}