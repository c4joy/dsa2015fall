#define  _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
class Stack 
{
private:
	int* data;
	int top;
	int _size;
	int capacity;
public:
	Stack(int cap)
	{
		data = (int *)malloc(cap*sizeof(int));
		top = 0;
		capacity = cap;
	}
	bool empty()
	{
		return !top;
	}
	bool push(int e)
	{
		if (top == capacity) 
		{
			return false;
		}
		data[top++] = e;
		return true;
	}
	int pop()
	{
		if (top == 0)
			return -1;
		return data[--top];
	}
	int getTop()
	{
		return data[top - 1];
	}
};
int main2()
{
	int n = 0, m = 0; //m is the limit
	int *arr;
	int index=0;
	scanf("%d %d", &n, &m);
	arr = (int*)malloc(n*sizeof(int));
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	Stack* S = new Stack(m);
	int a = 1;
	bool no = false;
	for (int i = 0; i < n;i++)
	{
		while (a <= arr[i])
		{
			no=!S->push(a++);
		}
		if (S->getTop() == arr[i])
		{
			if (S->pop() == -1) {
				no = true;
			}
		}
		else
		{
			no = true;
		}
		if (no) {
			printf("No\n");
			break;
		}
	}
	if(!no)
	{
		printf("Yes\n");
	}
//	system("pause");
	return 0;
}