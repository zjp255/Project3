#include<iostream>
using namespace std;
typedef struct BSTNode {
	int key;
	struct BSTNode* lchild, * rchild;
}BSTNode;

class BSTree
{
public:
	BSTNode* root;
	BSTree();
	~BSTree();

	void creatTree(int e[],int n)
	{
		BSTNode* temp = NULL;
		
		for (int i = 0; i < n; i++)
		{
			if (temp == NULL)
			{
				temp = new BSTNode();
				temp->key = e[i];
				root = temp;
			}
			else
			{
				temp = root;
				while (temp != NULL)
				{
					if (temp->key > e[i])
					{
						if (temp->lchild == NULL)
						{
							insertNode(temp->lchild, e[i]);
							break;
						}
						temp = temp->lchild;
					}
					else
					{
						if (temp->rchild == NULL)
						{
							insertNode(temp->rchild, e[i]);
							break;
						}
						temp = temp->rchild;
					}
				}
			
			}
		}
	}

	void InOrder()
	{
		InOrder(root);
	}

	BSTNode* BST_Search(int key)
	{
		BSTNode* temp = root;
		while (temp != NULL && temp->key != key)
		{
			if (key >= temp->key)
				temp = temp->rchild;
			else
			{
				temp = temp->lchild;
			}
		}
		return temp;
	}

	BSTNode* BST_SearchParent(BSTNode* node)
	{
		BSTNode* temp = root;
		bool stop = false;
		while (temp != NULL &&  stop == false)
		{
			if (node->key >= temp->key)
			{
				if (temp->rchild != NULL)
				{
					if (temp->rchild->key == node->key)
						stop = true;
				}
				if (temp->lchild != NULL)
				{
					if (temp->lchild->key == node->key)
						stop = true;
				}
				if(stop == false)
				{
					temp = temp->rchild;
				}
			}
			else
			{
				if (temp->rchild != NULL)
				{
					if (temp->rchild->key == node->key)
						stop = true;
				}
				 if (temp->lchild != NULL)
				{
					if (temp->lchild->key == node->key)
						stop = true;
				}
				if (stop == false)
				{
					temp = temp->lchild;
				}
			}


		}
		return temp;
	}

	void BST_Insert(int e)
	{
		BST_Insert(root, e);
	}

	void BST_Delete(BSTNode* &node)
	{
		if (node->lchild == NULL && node->rchild == NULL)
		{
			BSTNode* temp = node;
			node = NULL;
			delete temp;
		}
		else if (node->lchild == NULL && node->rchild != NULL)
		{
			BSTNode* parent = BST_SearchParent(node);
			if (parent->key > node->key)
			{
				parent->lchild = node->rchild;
			}
			else
			{
				parent->rchild = node->rchild;
			}
			delete node;
		}
		else if (node->lchild != NULL && node->rchild == NULL)
		{
			BSTNode* parent = BST_SearchParent(node);
			if (parent->key > node->key)
			{
				parent->lchild = node->lchild;
			}
			else
			{
				parent->rchild = node->lchild;
			}
			delete node;
		}
		else
		{
			BSTNode* temp = node->rchild;
			while (temp->lchild != NULL)
			{
				temp = temp->lchild;
			}
			node->key = temp->key;
			BST_Delete(temp);
		}
	}
private:
	void insertNode(BSTNode* &targetLocation,int e)
	{
		BSTNode* temp = new BSTNode();
		temp->key = e;
		targetLocation = temp;
	}

	void InOrder(BSTNode* node)
	{
		if (node != NULL)
		{
			InOrder(node->lchild);
			visit(node);
			InOrder(node->rchild);
		}
	}

	void visit(BSTNode* node)
	{
		cout << node->key << endl;
	}

	int BST_Insert(BSTNode* &node, int e)
	{
		if (node == NULL)
		{
			BSTNode* temp = new BSTNode();
			temp->key = e;
			node = temp;
			return 1;
		}
		else if(node->key == e)
		{
			return 0;
		}
		else if(node->key > e)
		{
			return BST_Insert(node->lchild, e);
		}
		else
		{
			return BST_Insert(node->rchild, e);
		}
	}

	
};

BSTree::BSTree()
{
}

BSTree::~BSTree()
{
}

int main()
{
	BSTree *bst = new BSTree();
	int e[10] = {20,30,50,80,10,5,1,60,70,2};
	int n = sizeof(e) / sizeof(e[0]); 
	bst->creatTree(e, n);
	bst->InOrder();
	cout << "" << endl;
	cout << bst->BST_Search(50)->key << endl;
	cout << "" << endl;
	bst->BST_Insert(65);
	bst->InOrder();

	BSTNode* temp = bst->BST_Search(20);
	bst->BST_Delete(temp);
	cout << "" << endl;

	bst->InOrder();



	return 0;
}