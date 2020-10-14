//C++实现排序算法之冒泡排序：

//冒泡排序（Bubble Sort），是一种计算机科学领域的较简单的排序算法。
//
//时间复杂度：O（n²）；
//算法稳定性：稳定排序算法；
//
//它重复地走访过要排序的元素列，依次比较两个相邻的元素，如果顺序（如从大到小、首字母从Z到A）错误就把他们交换过来。走访元素的工作是重复地进行直到没有相邻元素需要交换，也就是说该元素列已经排序完成。
//这个算法的名字由来是因为越小的元素会经由交换慢慢“浮”到数列的顶端（升序或降序排列），就如同碳酸饮料中二氧化碳的气泡最终会上浮到顶端一样，故名“冒泡排序”。
//
//冒泡排序算法的原理如下：
//1、 比较相邻的元素。如果第一个比第二个大，就交换他们两个。
//2、 对每一对相邻元素做同样的工作，从开始第一对到结尾的最后一对。在这一点，最后的元素应该会是最大的数。
//3、 针对所有的元素重复以上的步骤，除了最后一个。
//4、 持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较。
#include <iostream>
using namespace  std;

void PrintArr(int arr[],int size) {
	for (int i = 0; i < size;i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void Swap(int arr[], int left, int right) {
	int tmp = arr[left];
	arr[left] = arr[right];
	arr[right] = tmp;

}

void BubbleSort(int arr[], int size) {
	//趟数
	for (int i = 0; i < size;i++) {
		for (int j = 0; j < size - 1 - i;j++) {
			if (arr[j]>arr[j+1]) {
				Swap(arr, j, j + 1);
			}
		}
	}
}

int main () {
	int arr[10] = { 8, 1, 9, 7, 2, 4, 5, 6, 10, 3 };
	int size = sizeof(arr) / sizeof(arr[0]);
	cout << "未排序序列:";
	PrintArr(arr, size);

	cout << "排序序列:";
	BubbleSort(arr, size);
	PrintArr(arr, size);

    system("color A");
    system ("pause");
    return 0;
}
//C++实现排序算法之直接插入排序：

//
#include <iostream>
using namespace  std;


void PrintArr(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void insertSort(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		int start = i;
		int key = arr[start + 1];
		while (start >= 0 && arr[start]>key) {
			arr[start + 1] = arr[start];
			--start;
		}
		arr[start + 1] = key;
	}
}

int main() {

	int arr[10] = { 8, 1, 9, 7, 2, 4, 5, 6, 10, 3 };
	int size = sizeof(arr) / sizeof(arr[0]);
	cout << "未排序序列:";
	PrintArr(arr, size);

	cout << "排序序列:";
	insertSort(arr, size);
	PrintArr(arr, size);



	system("color A");
	system("pause");
	return 0;
}

//C++实现排序算法之希尔排序：

#include <iostream>
using namespace  std;

void PrintArr(int arr[], int size) {
	for (int i= 0; i < size;i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void shellSort(int arr[], int size) {
	int gap = size;
	while (gap>1) {
		gap = gap / 3 + 1;
		for (int i = 0; i < size-gap; i++) {
			int start = i;
			int key = arr[start+gap];
			while (start >= 0 && arr[start] > key) {
				arr[start + gap] = arr[start];
				start -= gap;
			}
			arr[gap + start] = key;
		}
	}
}
int main() {

	int arr[10] = { 8, 1, 9, 7, 2, 4, 5, 6, 10, 3 };
	int size = sizeof(arr) / sizeof(arr[0]);
	cout << "未排序序列:";
	PrintArr(arr, size);

	cout << "排序序列:";
	shellSort(arr, size);
	PrintArr(arr, size);
	system("color A");
	system("pause");
	return 0;
}

//C++实现排序算法之选择排序：

#include <iostream>
using namespace  std;

void PrintArr(int arr[], int size) {
	for (int i = 0; i < size;i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void Swap(int arr[], int left, int right) {
	int tmp = arr[left];
	arr[left] = arr[right];
	arr[right] = tmp;
}

void selectlSort(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		int start = i;  //每一次start的位置就是开始往后进行比较的位置
		int min = start;
		//这一个循环是进行比较,找到最小值的位置
		for (int j = start+1; j < size; j++) {
			while (arr[j] < arr[min]) 
				min = j;
		}
		Swap(arr, start, min);
	}
}

int main() {

	int arr[10] = { 8, 1, 9, 7, 2, 4, 5, 6, 10, 3 };
	int size = sizeof(arr) / sizeof(arr[0]);
	cout << "未排序序列:";
	PrintArr(arr, size);

	cout << "排序序列:";
	selectlSort(arr, size);
	PrintArr(arr, size);


	system("color A");
	system("pause");
	return 0;
}