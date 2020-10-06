//桶排序 从小到大开始排列
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i, j, t;
	int a[11];
	for (i = 0; i <= 10; i++){
		a[i] = 0;
	}
	for (i = 1; i <= 5; i++){
		scanf("%d", &t);
		a[t]++;
	}
	for (i = 0; i <= 10; i++)  {
		for (j = 1; j <= a[i]; j++) {
			printf("%d ", i);
		}
	}
	system("pause");
	return 0;

}