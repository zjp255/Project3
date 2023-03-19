#include <iostream>
using namespace std;
template <typename T>
class SqList
{
public:
	const int static initSize = 10;
	T *dataHead;
	int maxSize;
	int length;

	SqList<T>();
	~SqList<T>();

	void IncreaseSize(int size)
	{
		T* p = new T[size];
		
		for (int i = 0; i < size ; i++)
		{
			if (i < maxSize)
				p[i] = dataHead[i];
			else
				p[i] = 0;
		}
		maxSize = size;
		delete(dataHead);
		dataHead = p;
	}

	bool ListInsert(int location,T element)
	{
		if (location < 0 || location > maxSize)
			return false;
		if (length >= maxSize)
			return false;
		
		for (int i = length; i > location - 1; i--)
		{
			/*if (length == 0 && location == 0)
				dataHead[0] = element;
			else
			{*/
				dataHead[i + 1] = dataHead[i];
				if (i == location)
					dataHead[i] = element;
			/*}*/
		}
		length++;
		return true;
	}

	bool ListDelete(int location, T &element)
	{
		if (location < 0 || location > maxSize)
			return false;
		if (length <= 0)
			return false;

		for (int i = location; i < length; i++)
		{
			if (i == location)
				element = dataHead[i];
			dataHead[i] = dataHead[i + 1];
			
		}
		length--;
		return true;
	}

	T GetElem(int location)
	{
		if (location < 0 || location >= length)
			return false;
		return dataHead[location];
	}

	T LocateElem(T elem)
	{
		for (size_t i = 0; i < length; i++)
		{
			if (elem == dataHead[i])
				return i;
		}
		return 0;
	}
private:
	
	void static InitList(SqList *L, int size)
	{
		(*L).length = 0;
		L->maxSize = size;
		L->dataHead = new T[size];
		for (int i = 0; i < size; i++)
		{
			
			(*L).dataHead[i] = 0;
		}

	}
};

template <typename T>
SqList<T>::SqList()
{
	InitList(this,initSize);
}
template <typename T>
SqList<T>::~SqList()
{
}

int main()
{
	SqList<float> L;
	for (int i = 0; i < 10; i++)
	{
		cout << L.dataHead[i]<< endl;
	}
	cout << "\n" << endl;
	L.IncreaseSize(15);
	for (int i = 0; i < 15; i++)
	{
		cout << L.dataHead[i] << endl;
	}
	for (size_t i = 0; i < 10; i++)
	{
		L.ListInsert(i,i);
	}
	L.ListInsert(5,115);
	cout << "\n" << endl;
	for (int i = 0; i < 15; i++)
	{
		cout << L.dataHead[i] << endl;
	}
	float e = 0;
	L.ListDelete(5, e);
	cout << "\n" << endl;
	for (int i = 0; i < 15; i++)
	{
		cout << L.dataHead[i] << endl;
	}
	cout << "\n" << endl;
	cout << e << endl;

	cout << L.GetElem(3) << endl;
	cout << L.LocateElem(3) << endl;
	return 0;
}