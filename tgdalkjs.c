第一种: 直接插入排序

基本思想 : 在已经有序的数组中给待插入的数据找一个合适的位置; 排序之前假设第一个元素是有序的
#include <stdio.h>
#include <stdlib.h>

	   void PrintArr(int* arr, int size) {
		   for (int i = 0; i < size; i++) {
			   printf("%d ", arr[i]);
		   }
		   printf("\n");
	   }

	 void InsertSort(int* arr, int size) {
		 for (int i = 0; i < size - 1; i++) {
			 int start = i;
			 int key = arr[start + 1];
			 while (start >= 0 && key < arr[start]) {
				 arr[start + 1] = arr[start];
				 --start;
			 }
			 arr[start + 1] = key;
		 }
	 }

	 int main() {

		 int arr[] = { 6, 1, 2, 7, 9, 3, 4, 5, 10, 8 };
		 int size = sizeof(arr) / sizeof(arr[0]);
		 printf("排序之前: ");
		 PrintArr(arr, size);

		 InsertSort(arr, size);
		 printf("经过直接插入排序之后: ");
		 PrintArr(arr, size);

		 system("color A");
		 system("pause");
		 return 0;
	 }
 第二种: 希尔排序

 基本思想 : 进行多轮的预排序, 最后在执行普通的插入排序

#include <stdio.h>
#include <stdlib.h>

		void PrintArr(int* arr, int size) {
			for (int i = 0; i < size; i++) {
				printf("%d ", arr[i]);
			}
			printf("\n");
		}

	  void ShellSort(int* arr, int size) {
		  int gap = size;

		  while (gap>1) {
			  gap = gap / 3 + 1;
			  for (int i = 0; i < size - gap; i++) {
				  int end = i;
				  int key = arr[end + gap];
				  while (end >= 0 && key < arr[end]) {
					  arr[end + gap] = arr[end];
					  end -= gap;
				  }
				  arr[end + gap] = key;
			  }
		  }
	  }
	  int main() {

		  int arr[] = { 6, 1, 2, 7, 9, 3, 4, 5, 10, 8 };
		  int size = sizeof(arr) / sizeof(arr[0]);
		  printf("排序之前: ");
		  PrintArr(arr, size);

		  ShellSort(arr, size);
		  printf("经过希尔排序之后: ");
		  PrintArr(arr, size);

		  system("color A");
		  system("pause");
		  return 0;
	  }

	  //3.选择排序
	  //基本思想: 从未排序的一组数字中选择较小的,和前面的数字进行交换
#include <stdio.h>
#include <stdlib.h>

	  void Swap(int* arr, int left, int right) {
		  int tmp = arr[left];
		  arr[left] = arr[right];
		  arr[right] = tmp;
	  }

	  void selectSort(int* arr, int size) {
		  for (int i = 0; i < size; i++) {
			  int start = i;
			  int min = start;
			  for (int i = start + 1; i < size; i++) {
				  if (arr[i] < arr[min])
					  min = i;
			  }
			  Swap(arr, start, min);
		  }

	  }

	  void PrintArr(int* arr, int size) {
		  for (int i = 0; i < size; i++) {
			  printf("%d ", arr[i]);
		  }
		  printf("\n");
	  }

	  int main() {

		  int arr[] = { 6, 1, 2, 7, 9, 3, 4, 5, 10, 8 };
		  int size = sizeof(arr) / sizeof(arr[0]);
		  printf("排序之前: ");
		  PrintArr(arr, size);

		  selectSort(arr, size);
		  printf("经过选择排序之后: ");
		  PrintArr(arr, size);

		  system("color A");
		  system("pause");
		  return 0;
	  }


	  //4.堆排序
  基本思想: 先建堆, 然后执行循环尾删操作

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
			for (int i = (size - 2) / 2; i >= 0; i--) { //开始的位置为第一个非叶子节点开始的位置
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

		Visual Studio编译时报错“函数名：重定义；不同的基类型”
			错误原因：
			方法在还未声明的地方就使用了。由于使用的地方与定义的地方都是在同一个.c文件中，所以没有报未声明的错误。

			解决方法：

			把实现放到使用的前面，或者在include语句和宏定义后面加上函数声明。

			//5.冒泡排序
#include <stdio.h>
#include <stdlib.h>

			void Swap(int* arr, int left, int right) {
				int tmp = arr[left];
				arr[left] = arr[right];
				arr[right] = tmp;

			}
		//升序并且是从前往后进行依次比较数值的大小
		void BubbleSort(int* arr, int size) {
			////外循环: 表执行的趟数
			//for (int i = 0; i < size;i++) {
			//	//内循环: 表示比较的次数
			//	for (int j = 0; j < size - 1 - i; j++) {
			//		if (arr[j] >= arr[j + 1]) {
			//			Swap(arr, j, j + 1);
			//		}
			//	}
			//}
			//while (size) {
			//	for (int j = 0; j < size-1 ; j++) {  // 问什么 这块 j < size-1 ,而不是小于j<size,因为如果小于size的话 在后面的比较中arr[j + 1]会越界,
			//		if (arr[j] >= arr[j + 1]) { //除非起始位置是从j=1开始,那样的话就变成了arr[j - 1] 不会存在越界
			//			Swap(arr, j, j + 1);
			//		}
			//	}
			//	--size;
			//}
			while (size) {
				for (int j = 1; j < size; j++) {  //这种情况就可以,必须要根据起始位置来判定,到底j小于多少
					if (arr[j] <= arr[j - 1]) {
						Swap(arr, j, j - 1);
					}
				}
				--size;
			}
		}

		void PrintArr(int* arr, int size) {
			for (int i = 0; i < size; i++) {
				printf("%d ", arr[i]);
			}
			printf("\n");
		}

		int main() {
			int arr[] = { 6, 1, 2, 7, 9, 3, 4, 5, 10, 8 };
			int size = sizeof(arr) / sizeof(arr[0]);
			printf("排序之前:  ");
			PrintArr(arr, size);

			BubbleSort(arr, size);
			printf("经过冒泡排序之后:  ");
			PrintArr(arr, size);
			system("color A");
			system("pause");
			return 0;
		}

		6.快速排序 (递归)
			//1.hora划分法
#include <stdio.h>
#include <stdlib.h>


			void PrintArr(int* arr, int size) {
				for (int i = 0; i < size; i++) {
					printf("%d ", arr[i]);
				}
				printf("\n");
			}
		void Swap(int* arr, int left, int right) {
			int tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
		}
		//基准值的查找
		int partion(int* arr, int begin, int end) {

			int start = begin;
			int key = arr[begin];
			//从后面找第一个小于key的值,从前面找第一个大于key的值
			while (begin < end) {
				//从后向前找第一个小于key的值
				while (begin < end && arr[end] >= key)
					--end;
				//从前向后找第一个大于key的值
				while (begin < end && arr[begin] <= key)
					++begin;
				Swap(arr, begin, end);
			}
			//将找到的基准值的位置与相遇的位置进行交换
			Swap(arr, start, begin);
			return begin;
		}

		void quickSort(int* arr, int begin, int end) {
			if (begin >= end)
				return;
			int keypos = partion(arr, begin, end);
			quickSort(arr, begin, keypos);
			quickSort(arr, keypos + 1, end);
		}

		int main() {
			int arr[] = { 6, 1, 2, 7, 9, 3, 4, 5, 10, 8 };
			int size = sizeof(arr) / sizeof(arr[0]);
			quickSort(arr, 0, size - 1);
			PrintArr(arr, size);
			system("color A");
			system("pause");
			return 0;
		}
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//2.挖坑 划分法
#include <stdio.h>
#include <stdlib.h>


		void PrintArr(int* arr, int size) {
			for (int i = 0; i < size; i++) {
				printf("%d ", arr[i]);
			}
			printf("\n");
		}
		//基准值的查找
		int partion(int* arr, int begin, int end) {

			int key = arr[begin];
			//从后面找第一个小于key的值,从前面找第一个大于key的值
			while (begin < end) {
				//从后向前找第一个小于key的值
				while (begin < end && arr[end] >= key) {
					--end;
				}
				arr[begin] = arr[end];
				//从前向后找第一个大于key的值
				while (begin < end && arr[begin] <= key) {
					++begin;
				}
				arr[end] = arr[begin];
			}
			//将找到的基准值的位置与相遇的位置进行填充
			arr[begin] = key;
			return begin;
		}

		void quickSort(int* arr, int begin, int end) {
			if (begin >= end)
				return;
			int keypos = partion(arr, begin, end);
			quickSort(arr, begin, keypos);
			quickSort(arr, keypos + 1, end);
		}

		int main() {
			int arr[] = { 6, 1, 2, 7, 9, 3, 4, 5, 10, 8 };
			int size = sizeof(arr) / sizeof(arr[0]);
			quickSort(arr, 0, size - 1);
			PrintArr(arr, size);
			system("color A");
			system("pause");
			return 0;
		}
		3.前后指针 划分

#include <stdio.h>
#include <stdlib.h>


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

		int partion3(int* arr, int begin, int end) {
			int prev = begin;//最后一个小于基准值的位置
			int cur = prev + 1;//表示下一个小于基准值的位置
			int key = arr[begin];
			while (cur <= end) {
				//新发现的小数据和尾指针的位置不连续,则中间含有大于基准值的数据,故进行交换,大数据向后移动,小数据向前移动
				if (arr[cur] < key && ++prev != cur)
					Swap(arr, prev, cur);
				++cur;
			}
			Swap(arr, begin, prev);
			return prev;
		}

		void quickSort3(int* arr, int begin, int end) {
			if (begin >= end)
				return;
			//划分当前区间
			int keypos = partion3(arr, begin, end);
			//划分子区间
			quickSort3(arr, begin, keypos - 1);//先划分左边
			quickSort3(arr, keypos + 1, end); //划分右边
		}

		int main() {
			int arr[] = { 6, 1, 2, 7, 9, 3, 4, 5, 10, 8 };
			int size = sizeof(arr) / sizeof(arr[0]);
			quickSort3(arr, 0, size - 1);
			PrintArr(arr, size);
			system("color A");
			system("pause");
			return 0;
		}
		非递归实现快排
			stack.h文件

#pragma once 
#include <stdio.h>
#include <stdlib.h>

			typedef int Type;

		typedef struct Stack{
			Type* _array; //
			size_t _capacity;//容量大小
			size_t _size; //存入的元素多少
		}Stack;


		void stackInit(Stack* st, size_t n);
		void stackPush(Stack* st, Type data);
		void stackPop(Stack* st);

		Type stackTop(Stack* st);
		int stackEmpty(Stack* st);
		int stackSize(Stack* st);
		//快速排序1(栈来实现)
		void quickSortNoR1(int* arr, int size);

		stack.c文件

#include "stack.h"

			void stackInit(Stack* st, size_t n) {
				st->_array = (Type*)malloc(sizeof(int)*n);
				st->_size = 0;
				st->_capacity = n;
			}

		void stackPush(Stack* st, Type data) {
			//栈的插入过程必须要判定容量是否足够
			if (st->_capacity == st->_size) {
				st->_capacity *= 2;
				st->_array = (Type*)realloc(st->_array, st->_capacity*(sizeof(Type)));
			}
			st->_array[st->_size++] = data;
		}

		void stackPop(Stack* st) {
			if (st->_size > 0)
				--st->_size;
		}

		Type stackTop(Stack* st) {
			return st->_array[st->_size - 1];
		}
		int stackSize(Stack* st) {
			return st->_size;

		}

		int stackEmpty(Stack* st) {
			if (st->_size == 0)
				return 1;
			else {
				return 0;
			}
		}


		//1.栈实现
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

		void  Swap(int*arr, int left, int right) {
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

		int partion(int* arr, int begin, int end) {
			int start = begin;
			int key = arr[begin];
			while (begin < end) {
				while (begin < end && arr[end] >= key)
					--end;

				while (begin < end && arr[end] <= key)
					++begin;
				Swap(arr, begin, end);
			}
			Swap(arr, start, begin);//开始的位置和相遇的位置进行交换
			return begin;
		}

		void quickSortNoR1(int* arr, int size) {
			Stack st;
			stackInit(&st, 10);
			if (size > 1) {
				//起始区间入栈,先入右,再入左
				stackPush(&st, size - 1);
				stackPush(&st, 0);
			}
			//遍历划分栈中区间
			while (stackEmpty(&st) != 1) {
				int begin = stackTop(&st);
				stackPop(&st);
				int end = stackTop(&st);
				stackPop(&st);
				//划分
				int keypos = partion(arr, begin, end);
				if (keypos + 1 < end) {
					//子区间入栈,先入右,在入左
					stackPush(&st, end);
					stackPush(&st, keypos + 1);
				}
				if (begin < keypos) {
					stackPush(&st, keypos);
					stackPush(&st, begin);
				}
			}
		}
		//
		//void test1() {
		//	Stack st;
		//	stackInit(&st, 10);
		//	stackPush(&st, 1);
		//	stackPush(&st, 2);
		//	stackPush(&st, 3);
		//	stackPush(&st, 4);
		//	stackPush(&st, 5);
		//	stackPush(&st, 6);
		//
		//	printf("栈的大小: %d\n", stackSize(&st));
		//	while (stackEmpty(&st) != 1) {
		//		printf("%d ", stackTop(&st));
		//		stackPop(&st);
		//	}
		//}
		int main() {
			//test1();

			int arr[] = { 6, 1, 2, 7, 9, 3, 4, 5, 10, 8 };
			int size = sizeof(arr) / sizeof(arr[0]);
			quickSortNoR1(arr, size);
			PrintArr(arr, size);
			system("color A");
			system("pause");
			return 0;
		}
		queue.h文件
#pragma once 
#include <stdio.h>
#include <stdlib.h>

			typedef int Type;
		typedef struct QNode {
			struct QNode* _next;
			Type _data;
		}QNode;

		typedef struct Queue {
			QNode* _front;
			QNode* _rear;
			int _size;
		}Queue;


		void queueInit(Queue* q);
		QNode* creatNode(Type data);

		void queuePush(Queue* q, Type data);
		void queuePop(Queue* q);

		Type queueFront(Queue* q);
		int queueEmpty(Queue* q);

		//void PrintQueue(Queue* q);

		queue.c文件
#include "queue.h"


			void queueInit(Queue* q) {
				q->_front = q->_rear = 0;
				q->_size = 0;
			}

		QNode* creatNode(Type data) {
			QNode* node = (QNode*)malloc(sizeof(QNode));
			node->_data = data;
			node->_next = NULL;
			return node;
		}
		//入队: 类似于尾插
		void queuePush(Queue* q, Type data) {
			QNode* node = creatNode(data);
			if (q->_front == NULL) {
				q->_front = q->_rear = node;
			}
			else {
				q->_rear->_next = node;
				q->_rear = node; //尾部的元素
			}
			++q->_size;
		}

		void queuePop(Queue* q) {
			if (q->_front) {
				QNode* next = q->_front->_next;
				free(q->_front);
				q->_front = next;
				if (q->_front == NULL)
					q->_rear = NULL;
				--q->_size;
			}
		}

		Type queueFront(Queue* q) {
			return q->_front->_data;
		}
		int queueEmpty(Queue* q) {
			if (q->_front == NULL) {
				return 1;
			}
			return 0;
		}

		//void PrintQueue(Queue* q) {
		//	QNode* cur = q->_front;
		//	while (cur) {
		//		QNode* next = cur->_next;
		//		free(next);
		//		cur = cur->_next;
		//	}
		//	q->_front = q->_rear = NULL;
		//	q->_size = 0;
		//}




#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
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

		int partion2(int* arr, int begin, int end) {
			int start = begin;
			int key = arr[begin];
			while (begin < end) {
				while (begin < end && arr[end] >= key)
					--end;
				while (begin < end && arr[end] <= key)
					++begin;
				Swap(arr, begin, end);
			}
			Swap(arr, start, begin);//开始的位置和相遇的位置进行交换
			return begin;
		}


		void quickSortNoR2(int* arr, int size) {
			Queue q;
			queueInit(&q);
			if (size > 1) {
				//起始区间入栈,先入右,再入左
				queuePush(&q, 0);
				queuePush(&q, size - 1);
			}
			//遍历划分栈中区间
			while (queueEmpty(&q) != 1) {
				int begin = queueFront(&q);
				queuePop(&q);
				int end = queueFront(&q);
				queuePop(&q);
				//划分
				int keypos = partion2(arr, begin, end);
				if (begin < keypos) {
					queuePush(&q, begin);
					queuePush(&q, keypos);
				}
				if (keypos + 1 < end) {
					queuePush(&q, keypos + 1);
					queuePush(&q, end);
				}
			}
		}

		void test() {
			Queue q;
			queueInit(&q);
			queuePush(&q, 1);
			queuePush(&q, 2);
			queuePush(&q, 3);
			queuePush(&q, 4);
			queuePush(&q, 5);
			queuePush(&q, 6);
			queuePush(&q, 7);
			queuePush(&q, 8);
			while (queueEmpty(&q) != 1) {
				printf("%d ", queueFront(&q));
				queuePop(&q);
			}
			printf("\n");
		}
		int main() {

			int arr[] = { 6, 1, 2, 7, 9, 3, 4, 5, 10, 8 };
			int size = sizeof(arr) / sizeof(arr[0]);
			quickSortNoR2(arr, size);
			PrintArr(arr, size);
			system("color A");
			system("pause");
			return 0;
		}

		//7.归并排序
		//基本思想: 先对数组进行分解,然后进行合并排序

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

		void PrintArr(int* arr, int size) {
			for (int i = 0; i < size; i++) {
				printf("%d ", arr[i]);
			}
			printf("\n");
		}

		void merge(int* arr, int begin, int mid, int end, int* tmp) {
			int begin1 = begin;
			int end1 = mid;
			int begin2 = mid + 1;
			int end2 = end;
			int idx = begin;
			while (begin1 <= end1 && begin2 <= end2) {
				if (arr[begin1] <= arr[begin2])
					tmp[idx++] = arr[begin1++];
				else
					tmp[idx++] = arr[begin2++];
			}
			//剩余元素
			if (begin1 <= end1)
				memcpy(tmp + idx, arr + begin1, sizeof(int)*(end1 - begin1 + 1));
			if (begin2 <= end2)
				memcpy(tmp + idx, arr + begin2, sizeof(int)*(end2 - begin2 + 1));
			memcpy(arr + begin, tmp + begin, sizeof(int)*(end - begin + 1));
		}

		void mergeSortR(int* arr, int begin, int end, int*tmp) {
			if (begin >= end)
				return;
			int mid = begin + (end - begin) / 2;
			mergeSortR(arr, begin, mid, tmp);
			mergeSortR(arr, mid + 1, end, tmp);

			//合并分好的有序子序列
			merge(arr, begin, mid, end, tmp);
		}

		void mergeSort(int* arr, int size) {
			//先开辟一个新的数组,将排好顺序的数组方进新开的数组中
			int* tmp = (int*)malloc(sizeof(int)*size);
			mergeSortR(arr, 0, size - 1, tmp);
			free(tmp);
		}

		int main() {
			int arr[] = { 10, 6, 7, 1, 3, 9, 4, 2 };
			int size = sizeof(arr) / sizeof(arr[0]);


			PrintArr(arr, size);
			system("color A");
			system("pause");
			return 0;
		}
		//8.非比较排序

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

		void PrintArr(int* arr, int size) {
			for (int i = 0; i < size; i++) {
				printf("%d ", arr[i]);
			}
			printf("\n");
		}

		void countSort(int* arr, int size) {
			int max = arr[0];
			int min = arr[0];

			for (int i = 1; i < size; i++) {   //先统计要申请的范围大小 max-min+1
				if (arr[i] > max)
					max = arr[i];
				if (arr[i] < min)
					min = arr[i];
			} //循环结束时就能找到最大值和最小值

			//这一步是进行计数处理的
			int range = max - min + 1;
			int* countArr = (int*)malloc(sizeof(int)*range);
			//memset: 作用将某一块内存中的内容全部设置为指定的值,这个函数通常为申请的内存做初始工作
			//头文件为string.h 
			memset(countArr, 0, sizeof(int)*range);
			for (int i = 0; i < size; i++) {
				countArr[arr[i] - min]++;
			}
			//恢复数据
			int idx = 0;
			for (int i = 0; i < range; i++) {
				while (countArr[i]--){
					arr[idx++] = i + min;
				}
			}
			free(countArr);
		}

		int main() {

			int arr[] = { 10, 6, 7, 1, 3, 9, 4, 2 };
			int size = sizeof(arr) / sizeof(arr[0]);
			printf("排序之前:  ");
			PrintArr(arr, size);
			countSort(arr, size);
			printf("计数排序之后:  ");
			PrintArr(arr, size);
			system("color A");
			system("pause");
			return 0;
		}


