#include <iostream>
using namespace std;
template <typename T>
struct LNode
{
	T data;
	struct LNode* next;
};

//typedef struct LNode  LNode;

template <typename T>
class LinkList
{
public:
	LNode<T>* L;
	LinkList();
	~LinkList();

	bool ListInsert(int location,T e)
	{
		LNode<T>* p = L;
		if (SelectNode(location, p) == false)
			return false;
		InsertNextNode(p, e);
		return true;
	}
	bool SelectNode(int location,LNode<T>* p)
	{
		if (location < 1)
			return false;
		int j = 0;
		while (p != NULL && j < location - 1)
		{
			p = p->next;
			j++;
		}
		if (p == NULL)
			return false;
		return true;
	}

	bool InsertNextNode(LNode<T> *node,T e)
	{
		if (node == NULL)
			return false;
		LNode<T>* p2 = new LNode<T>();
		if (p2 == NULL)
			return false;
		p2->data = e;
		p2->next = node->next;
		node->next = p2;
		return true;
	}

	bool InsertPriorNode(LNode<T>* node, T e)
	{
		if (node == NULL)
			return false;
		LNode<T>* p2 = new LNode<T>();
		if (p2 == NULL)
			return false;
		p2->data = node->data;
		p2->next = node->next;
		node->next = p2;
		node->data = e;
		return true;
	}

	bool DeleteNode(LNode<T>* node)
	{
		if (node == NULL)
		{
			return false;
		}
		LNode<T>* next = node->next;
		node->data = next->data;
		node->next = next->next;
		delete(next);
		return true;
	}

	bool ListDelete(int location,T &e)
	{
		if (location < 1)
			return false;
		LNode<T>* p = L;
		if (SelectNode(location, p) == false)
			return false;
		e = p->next->data;
		DeleteNode(p->next);
		return true;
	}

	LNode<T>* GetElem(int location)
	{
		if (location < 1)
			return ;
		int j = 0;
		LNode<T>* p = L;
		while (p != NULL && j < location)
		{
			p = p->next;
			j++;
		}
		if (p == NULL)
			return ;
		return p;
	}

	LNode<T>* LocateElem(int e)
	{
		LNode<T>* p = L;
		while (p != NULL )
		{
			p = p->next;
			if (p->data == e)
				return p;
		}
		return p;
	}

	bool IsEmpty()
	{
		if (L->next == NULL)
			return true;
		else
		{
			return false;
		}
	}

private:

};

template <typename T>
LinkList<T>::LinkList()
{
	L = new LNode<T>();
	L->next = NULL;
}

template <typename T>
LinkList<T>::~LinkList()
{
}
int main()
{
	LinkList<int> L;
	L.ListInsert(1, 1);
	L.InsertPriorNode(L.L->next,255);
	L.InsertPriorNode(L.L->next, 200);
	//L.DeleteNode(L.L->next);
	//int e = 0;
	//L.ListDelete(1,e);
	//cout << e << endl;
	auto *p = L.LocateElem(255);
	cout << p->data << endl;


	return 0;
}