#include<iostream>
using namespace std;
typedef struct HFNode
{
	int key;
	bool isyezi = false;
	struct HFNode* lchild, * rchild;
}HFNode;

class HFTree
{
public:
	HFNode* root;
	HFTree();
	~HFTree();

	void creat_HF(int e[], int n)
	{
		root = new HFNode();
		HFNode* temp = root;
		for (int i = n - 1; i >= 1; i--)
		{
			HFNode* right = new HFNode();
			HFNode* left = new HFNode();
			left->key = e[i];
			left->isyezi = true;
			temp->rchild = right;
			temp->lchild = left;
			temp = right;
			if (i == 1)
			{
				temp->isyezi = true;
				temp->key = e[0];
			}
			
		}
	}

private:

};

HFTree::HFTree()
{
	root = NULL;
}

HFTree::~HFTree()
{
}

void popSort(int* e,int n)
{
	for (int i = 0; i < n; i++)
	{
		int temp = e[i];
		for (int j = i; j < n; j++)
		{
			if (e[j] < temp)
			{
				temp = e[j];
				e[j] = e[i];
				e[i] = temp;
			}
		}
	}
}

int main()
{
	int e[] = { 5,12,25,10,60,40,35,23 };
	int n = sizeof(e) / sizeof(e[1]);
	popSort(e, n);
	HFTree* tree = new HFTree();
	tree->creat_HF(e, n);

	return 0;
}