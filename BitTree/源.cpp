#include<iostream>
#include<queue>
using namespace std;
template<typename T>
struct BitNode {
	T elem;
	bool isNull = true;
	struct BitNode<T>* l_child;
	struct BitNode<T>* r_child;
};

//typedef struct BitNode BitNode;
template<typename T>
class BitTree
{
public:
	BitNode<T>* root;

	BitTree<T>();
	~BitTree<T>();

	void insertRootNode(T t)
	{
		root = new BitNode<T>();
		root->elem = t;
		root->l_child = NULL;
		root->r_child = NULL;
	}

	void insertLeftChild(BitNode<T>* parent,T e)
	{
		BitNode<T>* temp = new BitNode<T>();
		parent->l_child = temp;
		temp->elem = e;
		temp->l_child = NULL;
		temp->l_child = NULL;
	}

	void insertRightChild(BitNode<T>* parent, T e)
	{
		BitNode<T>* temp = new BitNode<T>();
		parent->r_child = temp;
		temp->elem = e;
		temp->l_child = NULL;
		temp->l_child = NULL;
	}

	bool add(T e)
	{
		std::queue<BitNode<T>*> nodes;
		BitNode<T>* bt;
		nodes.push(root);
		while (nodes.empty() != true)
		{
			bt = nodes.front();
			if (bt->isNull == true)
			{
				bt->elem = e;
				bt->isNull = false;
				return true;
			}
			else
			{
				if (bt->l_child == NULL)
				{
					bt->l_child = new BitNode<T>();
				}
				 if (bt->r_child == NULL)
				{
					bt->r_child = new BitNode<T>();
				}
				nodes.push(bt->l_child);
				nodes.push(bt->r_child);
			}
			nodes.pop();
		}
		return false;
	}
	void visit(BitNode<T>* n)
	{
		if (n->isNull == false)
			cout << n->elem << endl;
	}

	void preOrder()
	{
		preOrder(root);
	}
	void inOrder()
	{
		inOrder(root);
	}
	void postOrder()
	{
		postOrder(root);
	}

private:
	void preOrder(BitNode<T>* n)
	{
		if (n != NULL)
		{
			visit(n);
			preOrder(n->l_child);
			preOrder(n->r_child);
		}
	}
	void inOrder(BitNode<T>* n)
	{
		if (n != NULL)
		{
			
			preOrder(n->l_child);
			visit(n);
			preOrder(n->r_child);
		}
	}
	void postOrder(BitNode<T>* n)
	{
		if (n != NULL)
		{
			
			preOrder(n->l_child);
			preOrder(n->r_child);
			visit(n);
		}
	}
};
template<typename T>
BitTree<T>::BitTree()
{
	root = new BitNode<T>();
}
template<typename T>
BitTree<T>::~BitTree()
{
}
int main()
{
	BitTree<int> *bitTree = new BitTree<int>();
	
	for (int i = 1; i <= 9; i++)
	{
		bitTree->add(i);
	}

	bitTree->preOrder();
	cout<< "" << endl;
	bitTree->inOrder();
	cout << "" << endl;
	bitTree->postOrder();
	return 0;
}