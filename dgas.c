//                      C���Եĺ�������
 C���Բ�ͬ��Java���ԣ���Java�����У���һ�����У����庯��/�������ڵ���ʱ����Ҫ��������C�����ж��庯������ʹ��ǰ����Ҫ��main����ǰ��������������ᱨ��

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
	//1.����
	for (int i = (size - 2) / 2; i >= 0; i--) {
		DownAdjust(arr, size, i);
	}
	//2.ѭ��βɾ
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

**������� : **
������ִ�еĹ����ж��ǰ���˳�����ִ�е�, ���������ڻ�δ�����ĵط���ʹ���ˡ�����ʹ�õĵط��붨��ĵط�������ͬһ��.c�ļ��У����Ի����Visual Studio����ʱ�������������ض��壻��ͬ�Ļ����͡�.
**������� : **
1 > .��ʵ�ַŵ�ʹ�õ�ǰ��
2 > ��include���ͺ궨�������Ϻ���������

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
	//1.����
	for (int i = (size - 2) / 2; i >= 0; i--) {
		DownAdjust(arr, size, i);
	}
	//2.ѭ��βɾ
	while (size) {
		Swap(arr, 0, size - 1);
		--size;
		DownAdjust(arr, size, 0);
	}
}

int main() {
	int arr[] = { 6, 1, 2, 7, 9, 3, 4, 5, 10, 8 };
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("����֮ǰ: ");
	PrintArr(arr, size);

	HeapSort(arr, size);
	printf("����������֮��: ");
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
	//1.����
	for (int i = (size - 2) / 2; i >= 0; i--) {
		DownAdjust(arr, size, i);
	}
	//2.ѭ��βɾ
	while (size) {
		Swap(arr, 0, size - 1);
		--size;
		DownAdjust(arr, size, 0);
	}
}

int main() {
	int arr[] = { 6, 1, 2, 7, 9, 3, 4, 5, 10, 8 };
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("����֮ǰ: ");
	PrintArr(arr, size);

	HeapSort(arr, size);
	printf("����������֮��: ");
	PrintArr(arr, size);
	system("color A");
	system("pause");
	return 0;
}
