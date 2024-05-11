#include<iostream>
#include<fstream>
#include<string>

using namespace std;

#define size21 20

union Utypes
{
	char f[50];
	char i[50];
	char o[50];
	char address[20];
	int phone;
	char work[20];
	char rank[20];
	int day;
	unsigned int mon;
	unsigned int year;

}mun;
struct book {
	string f;
	string i;
	string o;
	string address;
	int phone;
	string work;
	string rank;


	unsigned int day;
	int mon;
	int year;
};
struct book b[20], dost;
int size2 = 0;



void input();
void del();
void out();
void writeF();
void readF();

int main() {
	system("chcp 1251");
	setlocale(LC_ALL, "Russian");
	int choice = 1;

	while (choice != 0)
	{
		cout << " \n1. ����� ������\n2. ������� ������\n3. ������� ������ � �������\n4. ������ � ����\n5. ������ �� �����\n6. ����������\n0. ��������� ������\n���� ";
		cin >> choice;

		switch (choice)
		{
		case(1):
			input();
			break;

		case(2):
			del();
			break;

		case(3):
			out();
			break;

		case(4):
			writeF();
			break;

		case(5):
			readF();
			break;

		default:
			break;
		}
	}


}
void input()
{
	int d;
	int m;
	int y;


	if (size2 < 20)
	{
		cout << " ������� ������(�������,���,��������,�����,����� ���,����� ������, ���������,����,�����,���): \n ������ �" << size2 + 1 << ": ";
		cin >> mun.f;
		b[size2].f = mun.f;
		cin >> mun.i;
		b[size2].i = mun.i;
		cin >> mun.o;
		b[size2].o = mun.o;
		cin >> mun.address;
		b[size2].address = mun.address;
		cin >> mun.phone;
		b[size2].phone = mun.phone;
		cin >> mun.work;
		b[size2].work = mun.work;

		cin >> mun.rank;
		b[size2].rank = mun.rank;
		cin >> mun.day;
		b[size2].day = mun.day;
		cin >> mun.mon;
		b[size2].mon = mun.mon;
		cin >> mun.year;
		b[size2].year = mun.year;

		size2++;
	}
	else
	{
		cout << " ������� ������������ ���-�� �����" << endl;
	}
}

void del() {
	int d;
	cout << "����� ������, �������  ������ �������(1 ��� �������� ����): ";
	cin >> d;
	d--;
	if (d == -2)
	{
		for (int i = 0; i < 20; i++)
		{
			b[i] = dost;
		}
		size2 = 0;
	}
	else
	{
		for (int i = d - 1; i < size2; i++)
		{
			b[i] = b[i + 1];
		}
		size2--;
	}
}

void out()
{
	string name, num;
	cout << " ������� ������� ��� ������ ������(��� ������ ���� ������� ������� 1): ";
	cin >> name;
	if (name == "1")
	{
		for (int i = 0; i < size2; i++)
		{
			cout << " ������ �" << i + 1 << " \n ������� - " << b[i].f << " \n ��� - " << b[i].i << " \n �������� - " << b[i].o << " \n �� - " << b[i].day << "." << b[i].mon << "." << b[i].year << " \n ����� - " << b[i].address << " \n ��� - " << b[i].phone << " \n ����� ������ - " << b[i].work << " \n ��������� - " << b[i].rank << endl << endl;
		}
	}
	else
	{
		for (int i = 0; i < size2; i++)
		{
			if (b[i].f == name)
			{
				cout << " ������ �" << i + 1 << " \n ������� - " << b[i].f << " \n ��� - " << b[i].i << " \n �������� - " << b[i].o << " \n �� - " << b[i].day << "." << b[i].mon << "." << b[i].year << " \n ����� - " << b[i].address << " \n ��� - " << b[i].phone << " \n ����� ������ - " << b[i].work << " \n ��������� - " << b[i].rank << endl << endl;
			}
		}
	}
}
void writeF() {

	ofstream fAout("FILE.txt");
	if (fAout.is_open()) {
		for (int i = 0; i < size2; i++)
		{
			fAout << "������ �";
			fAout << i + 1;
			fAout << " ������ �" << i + 1 << " \n ������� - " << b[i].f << " \n ��� - " << b[i].i << " \n �������� - " << b[i].o << " \n �� - " << b[i].day << "." << b[i].mon << "." << b[i].year << " \n ����� - " << b[i].address << " \n ��� - " << b[i].phone << " \n ����� ������ - " << b[i].work << " \n ��������� - " << b[i].rank << endl << endl;
		}
	}
	else
	{
		cout << " ���������� ������� ����!" << endl;
	}
	fAout.close();
}
void readF() {
	char ch;
	ifstream in;
	in.open("FILE.txt");
	while (in.get(ch))
	{
		cout << ch;
	}
	in.close();
}