//******************************************统计1出现的个数**************************
//*****************fangfa 1.
#include<stdio.h>
#include <stdlib.h>

int main() {
	int n = 7;
	int cout = 0;
	while (n != 0) {
		n = (n - 1) & n;
		cout += 1;
	}
	printf("%d\n",cout);

	system("pause");
	return 0;
}

//************************************************************************************************************************************
//fangfa 2
#include <stdio.h>
#include <stdlib.h>

int main() {
	int n = 7;
	int cout = 0;
	while (n != 0) {
		if (n % 2 == 1) {
			cout++;
			n /= 2;
		}
		//printf("%d\n", cout);
	}
	printf("%d\n",cout);
	system("pause");
	return 0;
}