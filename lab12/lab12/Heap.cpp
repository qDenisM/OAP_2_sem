#include "Heap.h"
#include <iostream>
#include <iomanip>

using namespace std;

void AAA::print()
{
	cout << x;
}
namespace heap
{
	void UnionHeap(Heap* h1, Heap* h2)
	{
		for (int i = 0; i < h2->size; i++)
		{
			AAA* a = new AAA;
			a->x = ((AAA*)(h2->storage[i]))->x;
			h1->insert(a);
		}
	}
	Heap create(int maxsize, CMP(*f)(void*, void*))
	{
		return *(new Heap(maxsize, f));
	}
	int Heap::left(int ix)
	{
		return (2 * ix + 1 >= size) ? -1 : (2 * ix + 1);
	}
	int Heap::right(int ix)
	{
		return (2 * ix + 2 >= size) ? -1 : (2 * ix + 2);
	}
	int Heap::parent(int ix)
	{
		return (ix + 1) / 2 - 1;
	}
	void Heap::swap(int i, int j)
	{
		void* buf = storage[i];
		storage[i] = storage[j];
		storage[j] = buf;
	}
	void Heap::heapify(int ix)
	{
		int l = left(ix), r = right(ix), irl = ix;
		if (l > 0)
		{
			if (isLess(storage[l], storage[ix])) irl = l;
			if (r > 0 && isLess(storage[r], storage[irl])) irl = r;
			if (irl != ix)
			{
				swap(ix, irl);
				heapify(irl);
			}
		}
	}


	void Heap::insert(void* x)
	{
		int i;
		if (!isFull())
		{
			storage[i = ++size - 1] = x;
			while (i > 0 && isLess(storage[parent(i)], storage[i]))
			{
				swap(parent(i), i);
				i = parent(i);
			}
		}
	}
	void* Heap::extractMax()
	{
		void* rc = nullptr;
		if (!isEmpty())
		{
			
			int maxIndex = 0;
			for (int i = 1; i < size; ++i)
			{
				if (isGreat(storage[i], storage[maxIndex]))
					maxIndex = i;
			}

			
			rc = storage[maxIndex];

			
			storage[maxIndex] = storage[size - 1];
			size--;

			
			int i = maxIndex;
			while (true)
			{
				int l = left(i), r = right(i), newMaxIndex = i;
				if (l != -1 && isLess(storage[l], storage[newMaxIndex]))
					newMaxIndex = l;
				if (r != -1 && isLess(storage[r], storage[newMaxIndex]))
					newMaxIndex = r;
				if (newMaxIndex != i)
				{
					swap(i, newMaxIndex);
					i = newMaxIndex;
				}
				else
				{
					break;
				}
			}
		}
		return rc;
	}
	void Heap::scan(int i) const     
	{
		int probel = 20;
		cout << '\n';
		if (size == 0)
			cout << "Куча пуста";
		for (int u = 0, y = 0; u < size; u++)
		{
			cout << setw(probel + 10) << setfill(' ');
			((AAA*)storage[u])->print();
			if (u == y)
			{
				cout << '\n';
				if (y == 0)
					y = 2;
				else
					y += y * 2;
			}
			probel /= 2;
		}
		cout << '\n';
	}

	void* Heap::extractMin()
	{
		void* rc = nullptr;
		if (!isEmpty())
		{
			
			int minIndex = 0;
			for (int i = 1; i < size; ++i)
			{
				if (isLess(storage[i], storage[minIndex]))
					minIndex = i;
			}

			
			rc = storage[minIndex];

			
			storage[minIndex] = storage[size - 1];
			size--;

			
			int i = minIndex;
			while (true)
			{
				int l = left(i), r = right(i), newMinIndex = i;
				if (l != -1 && isGreat(storage[l], storage[newMinIndex]))
					newMinIndex = l;
				if (r != -1 && isGreat(storage[r], storage[newMinIndex]))
					newMinIndex = r;
				if (newMinIndex != i)
				{
					swap(i, newMinIndex);
					i = newMinIndex;
				}
				else
				{
					break;
				}
			}
		}
		return rc;
	}





	void* Heap::extractI(int i)
	{
		if (!isEmpty())
		{
			if (i <= size && i >= 0) {
				void* rc = storage[i];
				storage[i] = storage[size - 1];
				size--;
				heapify(0);
				printf("I-тый элемент удален\n");
			}
			else printf("Вы ввели неверное число!");
		}
		else printf("Куча пуста!\n");
		return 0;
	}



	

}
