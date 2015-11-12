//#define  _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#define func(x,y) (a[i][1] * x + a[i][0] * y - a[i][0] * a[i][1])
int main()
{
	int n, m; 
	int a[100000][2];
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &a[i][0], &a[i][1]);
	for (int j = 0; j < m; j++) {
		int x, y;
		scanf("%d %d", &x, &y);
		for (int i = 0; i < n; i++) {
			int result = func(x, y);
			if (result < 0) {
				printf("%d\n", i);
				break;
			}
			else if (result == 0) {
				printf("%d\n", i + 1);
				break;
			}
			else {
				if (i == n - 1) {
					printf("%d\n", i + 1);
					break;
				}
			}
		}
	}
//	system("pause");
	return 0;
}