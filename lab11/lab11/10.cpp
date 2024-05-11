#include <iostream>
using namespace std;

struct Tree          
{
	int key;         
	Tree* Left, * Right;
};

Tree* makeTree(Tree* Root);
Tree* list(int i);       
Tree* insertElem(Tree* Root, int key);  
Tree* search(Tree* n, int key);   
Tree* delet(Tree* Root, int key); 
void print(Tree* aBranch);    
void sum(Tree* t, int level);   
void delAll(Tree* t);             

int c = 0;      
Tree* Root = NULL;

Tree* makeTree(Tree* Root)    
{
	int key;
	cout << "����� ����� - ������������� �����\n\n";
	if (Root == NULL)	
	{
		cout << "������� ���� �����: "; cin >> key;

		Root = list(key);	
	}
	while (1)                
	{
		cout << "\n������� ����: ";  cin >> key;
		if (key < 0) 
			break;  
		insertElem(Root, key);
	}
	return Root;
}

Tree* list(int i)     
{
	Tree* t = new Tree[sizeof(Tree)];
	t->key = i;
	t->Left = t->Right = NULL;
	return t;
}

Tree* insertElem(Tree* t, int key)  
{
	Tree* Prev = nullptr;	     
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
		t = list(key);           
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
		puts("\n��� ������ �����");
		return Root;
	}
	if (Del->Right == NULL) 
		R = Del->Left;
	else
		if (Del->Left == NULL)
			R = Del->Right;
		else
		{
			Prev_R = Del; 
			R = Del->Left;
			while (R->Right != NULL)
			{
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
	cout << "\n������ ������� � ������ " << tmp << endl;
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
		cout << "������� " << key << " ����������� � ������.\n";
	}
	else
		cout << "��� ������ ��������\n";
	return rc;
}


int tabs = 0;

void print(Tree* aBranch) 
{
	if (!aBranch) return; 
	tabs++; 
	

	print(aBranch->Left); 

	for (int i = 0; i < tabs; i++) cout << " "; 
	cout << aBranch->key << endl; 


	print(aBranch->Right);

	tabs--; 
	return;
}

int sum2 = 0;
void sum(Tree* t, int level) 
{
	int sum1;
	if (t)
	{
		sum(t->Right, level + 1);	
		sum1 = t->key;
		sum2 += sum1;
		cout << sum2 << endl;
		sum(t->Left, level + 1);	
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

void main()
{
	setlocale(LC_ALL, "ru");
	int key, choice, n;
	Tree* rc;
	for (;;)
	{
		cout << "��������, ��� �������:\n1 - ������� ������;\n2 - �������� �������;\n3 - ����� �� �����;\n4 - ������� �������;"
			"\n5 - ������� ������;\n6 - ����� ����� �������� ���� ������;\n7 - �����.\n";
		cin >> choice;
		cout << "\n";
		switch (choice)
		{
		case 1:  Root = makeTree(Root);	break;
		case 2:  cout << "\n������� ����: "; cin >> key;

			insertElem(Root, key); break;
		case 3:  cout << "\n������� ����: ";  cin >> key;
			rc = search(Root, key); break;

		case 4:  cout << "\n������� ��������� ����: "; cin >> key;
			Root = delet(Root, key);  break;
		case 5:  if (Root->key >= 0)
		{
			cout << "������ ��������� �� 90 �������� �����." << endl;
			print(Root); break;
		}
			  else cout << "������ ������\n"; break;
		case 6:  cout << "����� ���� ������: "; sum(Root, 0);
		case 7:  exit(0);
		}
	}
}
