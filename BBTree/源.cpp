#include<iostream>
using namespace std;
typedef struct BSTNode {
	int key;
	int balance;
	struct BSTNode* lchild, * rchild;
}BSTNode;

class BSTree
{
public:
	BSTNode* root;
	BSTree();
	~BSTree();

	void creatTree(int e[], int n)
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
					countBalance();
					balanceTree();
				}

			}
		}
	}

	void countBalance()
	{
		countBalance(root);
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
		while (temp != NULL && stop == false)
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
				if (stop == false)
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

	void BST_Delete(BSTNode*& node)
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

	void balanceTree()
	{
		InOrderBalance(root);
	}
	
private:
	void InOrderBalance(BSTNode* &node)
	{
		if (node != NULL)
		{
			
			InOrderBalance(node->lchild);
			balanceTree(node);
			InOrderBalance(node->rchild);
		}
	}

	void balanceTree(BSTNode* &node)
	{
		BSTNode* right = node->rchild;
		BSTNode* left = node->lchild;
		if (node->balance == -2)
		{
			if (right != NULL && right->balance == 1)
			{
				BSTNode* rlchild =right->lchild;
				if (rlchild->balance == 1)
				{

					llChange(node->rchild);
					rrChange(node);
					countBalance();
				}
			}
			else if (right != NULL && node->rchild->balance == -1)
			{
				rrChange(node);
				countBalance();
			}
		}
		if (node->balance == 2)
		{
			//
			if (left != NULL && left->balance == -1)
			{
				BSTNode* lrchild = left->rchild;
				if (lrchild->balance == -1)
				{
					rrChange(node->lchild);
					llChange(node);
					countBalance();
				}
			}
			
			else if (left != NULL && node->lchild->balance == 1)
			{
				llChange(node);
				countBalance();
			}
		}
	}


	void insertNode(BSTNode*& targetLocation, int e)
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

	int BST_Insert(BSTNode*& node, int e)
	{
		if (node == NULL)
		{
			BSTNode* temp = new BSTNode();
			temp->key = e;
			node = temp;
			return 1;
		}
		else if (node->key == e)
		{
			return 0;
		}
		else if (node->key > e)
		{
			return BST_Insert(node->lchild, e);
		}
		else
		{
			return BST_Insert(node->rchild, e);
		}
	}
	int countBalance(BSTNode*& node)
	{
		
		if (node != NULL)
		{
			if (node->rchild == NULL && node->lchild == NULL)
			{
				node->balance = 0;
				return 1;
			}
			else
			{
				node->balance = countBalance(node->lchild) - countBalance(node->rchild);
				return  (node->balance >= 0 ? node->balance : -node->balance) + 1;
			}
		}
		else
		{
			return 0;
		}
	}

	


	void llChange(BSTNode*& node)
	{
		BSTNode* temp1 = node->lchild;
		BSTNode* temp1_lchild = NULL;
		BSTNode* temp1_rchild = NULL;
		if (temp1 != NULL)
		{
			temp1_lchild = temp1->lchild;
			temp1_rchild = temp1->rchild;
		}
		else
		{
			temp1_lchild = NULL;
			temp1_rchild = NULL;
		}
		node->lchild = temp1_lchild;
		BSTNode* temp2 = node->rchild;
		node->rchild = temp1;
		
		temp1->lchild = temp1_rchild;
		temp1->rchild = temp2;
		int key = node->key;
		node->key = temp1->key;
		temp1->key = key;


	}

	void rrChange(BSTNode*& node)
	{
		BSTNode* temp1 = node->rchild;
		BSTNode* temp1_lchild = NULL;
		BSTNode* temp1_rchild = NULL;
		if (temp1 != NULL)
		{
			temp1_lchild = temp1->lchild;
			temp1_rchild = temp1->rchild;
		}
		else
		{
			temp1_lchild = NULL;
			temp1_rchild = NULL;
		}
		node->rchild = temp1_rchild;
		BSTNode* temp2 = node->lchild;
		node->lchild = temp1;
		temp1->rchild= temp1_lchild;
		temp1->lchild= temp2;
		int key = node->key;
		node->key = temp1->key;
		temp1->key = key;
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
	BSTree* bst = new BSTree();
	int e[10] = { 20,30,50,80,10,5,1,60,70,2 };
	int n = sizeof(e) / sizeof(e[0]);
	bst->creatTree(e, n);
	bst->countBalance();
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
	bst->countBalance();
	bst->balanceTree();

	return 0;
}