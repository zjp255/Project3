#include <iostream>
using namespace std;
template<typename T>
class Queue
{
public:
	Queue();
	~Queue();
	bool QueueEmpty()
	{
		if (front == rear)
		{
			return true;
		}
		else
		{
			return true;
		}
	}

	bool EnQueue(T e)
	{
		if ((rear + 1) % maxSize == front)
			return false;
		Q[rear++] = e;
		rear = rear % maxSize;
		return true;
	}

	bool DeQueue(T &e)
	{
		if (rear == front)
			return false;
		e = Q[front++];
		front = front % maxSize;
		return true;
	}

	bool GetHead(T& e)
	{
		if (rear == front)
			return false;
		e = Q[front];
		return true;
	}
private:
	T* Q;
	int front, rear;
	int maxSize = 10;

};
template<typename T>
Queue<T>::Queue()
{
	Q = new T[maxSize];
	front = 0;
	rear = 0;
}
template<typename T>
Queue<T>::~Queue()
{
	delete Q;
}

int main()
{
	Queue<int> Q;
	Q.EnQueue(1);
	Q.EnQueue(2);
	Q.EnQueue(3);
	Q.EnQueue(4);
	Q.EnQueue(5);

	int e = 0;
	for (size_t i = 0; i < 5; i++)
	{
		
		Q.GetHead(e);
		cout << e << endl;
		Q.DeQueue(e);
	}

	return 0;
}