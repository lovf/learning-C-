//                      C语言的函数声明
 C语言不同于Java语言，在Java语言中，在一个类中，定义函数/方法后，在调用时不需要声明。在C语言中定义函数后，在使用前，需要在main函数前进行声明，否则会报错。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void PrintArr(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void DownAdjust(int* arr, int size, int parent) {
	int child = 2 * parent + 1;
	while (child<size) {
		if (child + 1 < size && arr[child + 1] > arr[child])
			++child;
		if (arr[child] >arr[parent])  {
			Swap(arr, child, parent);
			child = 2 * parent + 1;
		}
		else {
			break;
		}
	}
}
void Swap(int* arr, int left, int right) {
	int tmp = arr[left];
	arr[left] = arr[right];
	arr[right] = tmp;
}
void HeapSort(int* arr, int size) {
	//1.建堆
	for (int i = (size - 2) / 2; i >= 0; i--) {
		DownAdjust(arr, size, i);
	}
	//2.循环尾删
	while (size) {
		Swap(arr, 0, size - 1);
		--size;
		DownAdjust(arr, size, 0);
	}
}

int main() {
	int arr[] = { 6, 1, 2, 7, 9, 3, 4, 5, 10, 8 };
	int size = sizeof(arr) / sizeof(arr[0]);
	HeapSort(arr, size);
	PrintArr(arr, size);
	system("color A");
	system("pause");
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

**错误分析 : **
函数在执行的过程中都是按照顺序进行执行的, 上述代码在还未声明的地方就使用了。由于使用的地方与定义的地方都是在同一个.c文件中，所以会出现Visual Studio编译时报错“函数名：重定义；不同的基类型”.
**解决方法 : **
1 > .把实现放到使用的前面
2 > 在include语句和宏定义后面加上函数声明。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Swap(int*, int, int);

void PrintArr(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void DownAdjust(int* arr, int size, int parent) {
	int child = 2 * parent + 1;
	while (child<size) {
		if (child + 1 < size && arr[child + 1] > arr[child])
			++child;
		if (arr[child] >arr[parent])  {
			Swap(arr, child, parent);
			child = 2 * parent + 1;
		}
		else {
			break;
		}
	}
}
void Swap(int* arr, int left, int right) {
	int tmp = arr[left];
	arr[left] = arr[right];
	arr[right] = tmp;
}
void HeapSort(int* arr, int size) {
	//1.建堆
	for (int i = (size - 2) / 2; i >= 0; i--) {
		DownAdjust(arr, size, i);
	}
	//2.循环尾删
	while (size) {
		Swap(arr, 0, size - 1);
		--size;
		DownAdjust(arr, size, 0);
	}
}

int main() {
	int arr[] = { 6, 1, 2, 7, 9, 3, 4, 5, 10, 8 };
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("排序之前: ");
	PrintArr(arr, size);

	HeapSort(arr, size);
	printf("经过堆排序之后: ");
	PrintArr(arr, size);
	system("color A");
	system("pause");
	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Swap(int* arr, int left, int right) {
	int tmp = arr[left];
	arr[left] = arr[right];
	arr[right] = tmp;
}

void PrintArr(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void DownAdjust(int* arr, int size, int parent) {
	int child = 2 * parent + 1;
	while (child<size) {
		if (child + 1 < size && arr[child + 1] > arr[child])
			++child;
		if (arr[child] >arr[parent])  {
			Swap(arr, child, parent);
			child = 2 * parent + 1;
		}
		else {
			break;
		}
	}
}

void HeapSort(int* arr, int size) {
	//1.建堆
	for (int i = (size - 2) / 2; i >= 0; i--) {
		DownAdjust(arr, size, i);
	}
	//2.循环尾删
	while (size) {
		Swap(arr, 0, size - 1);
		--size;
		DownAdjust(arr, size, 0);
	}
}

int main() {
	int arr[] = { 6, 1, 2, 7, 9, 3, 4, 5, 10, 8 };
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("排序之前: ");
	PrintArr(arr, size);

	HeapSort(arr, size);
	printf("经过堆排序之后: ");
	PrintArr(arr, size);
	system("color A");
	system("pause");
	return 0;
}
