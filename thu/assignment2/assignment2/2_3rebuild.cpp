//#define  _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
typedef struct BinNode
{
	int data;
	BinNode *lChild;
	BinNode *rChild;
	BinNode(int e) :data(e), lChild(NULL), rChild(NULL) {};
}BinNode;
class BinaryTree
{
private:
	BinNode* root;
	int lSize;
	bool over;
	void build(int *pre, int *inorder, int n, BinNode **rootAddress)
	{
		if (over)
			return;
		//设置根节点
		*rootAddress = new BinNode(pre[0]);
		BinNode *r = *rootAddress;
		//如果序列长度小于2，则为空树或者只有根节点
		if (n < 2) {
			if (pre[0] != inorder[0]) {
				over = true;
				root = new BinNode(-1);
			}
			return;
		}
		lSize++;
		int i=0;
		//在中序遍历序列中找到根节点，记录其位置为i
		for (i = 0; i < n; i++)
		{
			if (r->data == inorder[i])
			{
				break;
			}
		}
		//递归调用，对左子树的前序和中序序列进行构建二叉树
		if(i>0)
			build(pre + 1, inorder, i , &(r->lChild));
		//递归调用，对右子树的前序和中序序列进行构建二叉树
		if(n-i-1>0)
			build(pre + 1+i, inorder + i + 1, n-i-1, &(r->rChild));
	}
	void postOrder(BinNode *r)
	{
		if (!r)
			return;
		postOrder(r->lChild);
		postOrder(r->rChild);
		printf("%d ", r->data);
	}

public:
	BinaryTree()
	{
		root = new BinNode(-1);
		lSize = 1;
		over = false;
	}
	void preInorderBuild(int *pre,int *inorder,int n)
	{
		build(pre, inorder, n, &root);
	}
	void traverse()
	{
//		printf("%d\n", lSize);
//		InOrder2(root);
		postOrder(root);
	}
	
};
int main()
{
	int n = 0;
	int *pre;
	int *inorder;
	scanf("%d", &n);
	pre = (int *)malloc(n*sizeof(int));
	inorder = (int *)malloc(n*sizeof(int));
	for (int i = 0; i < n; i++)
		scanf("%d", &pre[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &inorder[i]);
	BinaryTree* bt = new BinaryTree();
	bt->preInorderBuild(pre, inorder, n);
	bt->traverse();
//	system("pause");
	return 0;
}