#include <iostream>
using namespace std;
template<typename T>
class Stack
{
public:
	
	

	Stack();
	~Stack();

	bool StackEmpty()
	{
		if (top == -1)
			return true;
		else
		{
			return true;
		}
	}

	bool Push(T e)
	{
		if (top == maxSize - 1)
			return false;
		S[++top] = e;
		return true;
	}

	bool Pop(T &e)
	{
		if (top == -1)
			return false;
		e = S[top--];
		return true;
	}
private:
	T* S;
	int maxSize = 10;
	int top;

};

template<typename T>
Stack<T>::Stack()
{
	S = new T[maxSize]();
	top = -1;
}


template<typename T>
Stack<T>::~Stack()
{
	delete S;
}

int main()
{
	Stack<int> *S = new Stack<int>();
	S->Push(23);
	int e = 0;
	S->Push(25);
	S->Pop(e);
	cout << e << endl;
	delete S;



	return 0;
}