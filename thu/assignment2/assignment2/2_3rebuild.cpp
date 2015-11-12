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
		//���ø��ڵ�
		*rootAddress = new BinNode(pre[0]);
		BinNode *r = *rootAddress;
		//������г���С��2����Ϊ��������ֻ�и��ڵ�
		if (n < 2) {
			if (pre[0] != inorder[0]) {
				over = true;
				root = new BinNode(-1);
			}
			return;
		}
		lSize++;
		int i=0;
		//����������������ҵ����ڵ㣬��¼��λ��Ϊi
		for (i = 0; i < n; i++)
		{
			if (r->data == inorder[i])
			{
				break;
			}
		}
		//�ݹ���ã�����������ǰ����������н��й���������
		if(i>0)
			build(pre + 1, inorder, i , &(r->lChild));
		//�ݹ���ã�����������ǰ����������н��й���������
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