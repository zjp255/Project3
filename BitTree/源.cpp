#include<iostream>
#include<queue>
using namespace std;
template<typename T>
struct BitNode {
	T elem;
	bool isNull = true;
	int ltag, rtag;
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
		if (n->elem == e  && isSelect == true)
		{
			selectNode = n;
		}
		else if (n->isNull == false)
		{

			cout << n->elem << endl;
		}
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

	void ThreadTree()
	{
		ThreadTree(root);
		pre = NULL;

	}

	BitNode<T>* SelectNode(T e)
	{
		this->e = e;
		isSelect = true;

		inOrder();
		isSelect = false;
		return selectNode;
	}

	BitNode<T>* preNode(BitNode<T>* n)
	{
		if (n->ltag == 1)
		{
			return n->l_child;
		}
		else
		{
			BitNode<T>* temp;
			temp = n->r_child;
			while (temp->rtag == 0 && temp->r_child != NULL)
			{
				temp = temp->r_child;
			}
			return temp;
		}
	}

	BitNode<T>* nextNode(BitNode<T>* n)
	{
		if (n->rtag == 1)
		{
			return n->r_child;
		}
		else
		{
			BitNode<T>* temp;
			temp = n->l_child;
			while (temp->ltag == 0 && temp->l_child != NULL)
			{
				temp = temp->l_child;
			}
			return temp;
		}
	}
private:
	BitNode<T>* pre;
	BitNode<T>* selectNode;
	T e;
	bool isSelect = false;

	void preOrder(BitNode<T>* n)
	{
		if (n != NULL)
		{
			visit(n);
			if(n->ltag == 0 && n->isNull == false)
			preOrder(n->l_child);
			if (n->rtag == 0 && n->isNull == false)
			preOrder(n->r_child);
		}
	}
	void inOrder(BitNode<T>* n)
	{
		if (n != NULL)
		{
			if (n->ltag == 0 && n->isNull == false)
			inOrder(n->l_child);
			visit(n);
			if (n->rtag == 0 && n->isNull == false)
			inOrder(n->r_child);
		}
	}
	void postOrder(BitNode<T>* n)
	{
		if (n != NULL)
		{
			if (n->ltag == 0 && n->isNull == false)
			postOrder(n->l_child);
			if (n->rtag == 0 && n->isNull == false)
			postOrder(n->r_child);
			visit(n);
		}
	}
	void visitT(BitNode<T>* n)
	{
		if ( n->l_child == NULL ||n->l_child->isNull == true)
		{
			free(n->l_child);
			n->l_child = pre;
			n->ltag = 1;
		}
		
		if (pre != NULL && (pre->r_child == NULL || pre->r_child->isNull == true))
		{
			free(pre->r_child);
			pre->r_child = n;
			pre->rtag = 1;
		}
		pre = n;
	}
	void ThreadTree(BitNode<T>* n)
	{
		if (n != NULL && n->isNull == false)
		{
			ThreadTree(n->l_child);
			visitT(n);
			ThreadTree(n->r_child);
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
	bitTree->ThreadTree();
	cout << "" << endl;
	BitNode<int>* temp = bitTree->SelectNode(5);
	cout << "" << endl;
	cout << bitTree->preNode(temp)->elem << endl;
	cout << bitTree->nextNode(temp)->elem << endl;
	return 0;
}