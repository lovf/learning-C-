��һ��: ֱ�Ӳ�������

����˼�� : ���Ѿ�����������и��������������һ�����ʵ�λ��; ����֮ǰ�����һ��Ԫ���������
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
		 printf("����֮ǰ: ");
		 PrintArr(arr, size);

		 InsertSort(arr, size);
		 printf("����ֱ�Ӳ�������֮��: ");
		 PrintArr(arr, size);

		 system("color A");
		 system("pause");
		 return 0;
	 }
 �ڶ���: ϣ������

 ����˼�� : ���ж��ֵ�Ԥ����, �����ִ����ͨ�Ĳ�������

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
		  printf("����֮ǰ: ");
		  PrintArr(arr, size);

		  ShellSort(arr, size);
		  printf("����ϣ������֮��: ");
		  PrintArr(arr, size);

		  system("color A");
		  system("pause");
		  return 0;
	  }

	  //3.ѡ������
	  //����˼��: ��δ�����һ��������ѡ���С��,��ǰ������ֽ��н���
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
		  printf("����֮ǰ: ");
		  PrintArr(arr, size);

		  selectSort(arr, size);
		  printf("����ѡ������֮��: ");
		  PrintArr(arr, size);

		  system("color A");
		  system("pause");
		  return 0;
	  }


	  //4.������
  ����˼��: �Ƚ���, Ȼ��ִ��ѭ��βɾ����

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
			for (int i = (size - 2) / 2; i >= 0; i--) { //��ʼ��λ��Ϊ��һ����Ҷ�ӽڵ㿪ʼ��λ��
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

		Visual Studio����ʱ�������������ض��壻��ͬ�Ļ����͡�
			����ԭ��
			�����ڻ�δ�����ĵط���ʹ���ˡ�����ʹ�õĵط��붨��ĵط�������ͬһ��.c�ļ��У�����û�б�δ�����Ĵ���

			���������

			��ʵ�ַŵ�ʹ�õ�ǰ�棬������include���ͺ궨�������Ϻ���������

			//5.ð������
#include <stdio.h>
#include <stdlib.h>

			void Swap(int* arr, int left, int right) {
				int tmp = arr[left];
				arr[left] = arr[right];
				arr[right] = tmp;

			}
		//�������Ǵ�ǰ����������αȽ���ֵ�Ĵ�С
		void BubbleSort(int* arr, int size) {
			////��ѭ��: ��ִ�е�����
			//for (int i = 0; i < size;i++) {
			//	//��ѭ��: ��ʾ�ȽϵĴ���
			//	for (int j = 0; j < size - 1 - i; j++) {
			//		if (arr[j] >= arr[j + 1]) {
			//			Swap(arr, j, j + 1);
			//		}
			//	}
			//}
			//while (size) {
			//	for (int j = 0; j < size-1 ; j++) {  // ��ʲô ��� j < size-1 ,������С��j<size,��Ϊ���С��size�Ļ� �ں���ıȽ���arr[j + 1]��Խ��,
			//		if (arr[j] >= arr[j + 1]) { //������ʼλ���Ǵ�j=1��ʼ,�����Ļ��ͱ����arr[j - 1] �������Խ��
			//			Swap(arr, j, j + 1);
			//		}
			//	}
			//	--size;
			//}
			while (size) {
				for (int j = 1; j < size; j++) {  //��������Ϳ���,����Ҫ������ʼλ�����ж�,����jС�ڶ���
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
			printf("����֮ǰ:  ");
			PrintArr(arr, size);

			BubbleSort(arr, size);
			printf("����ð������֮��:  ");
			PrintArr(arr, size);
			system("color A");
			system("pause");
			return 0;
		}

		6.�������� (�ݹ�)
			//1.hora���ַ�
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
		//��׼ֵ�Ĳ���
		int partion(int* arr, int begin, int end) {

			int start = begin;
			int key = arr[begin];
			//�Ӻ����ҵ�һ��С��key��ֵ,��ǰ���ҵ�һ������key��ֵ
			while (begin < end) {
				//�Ӻ���ǰ�ҵ�һ��С��key��ֵ
				while (begin < end && arr[end] >= key)
					--end;
				//��ǰ����ҵ�һ������key��ֵ
				while (begin < end && arr[begin] <= key)
					++begin;
				Swap(arr, begin, end);
			}
			//���ҵ��Ļ�׼ֵ��λ����������λ�ý��н���
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
		//2.�ڿ� ���ַ�
#include <stdio.h>
#include <stdlib.h>


		void PrintArr(int* arr, int size) {
			for (int i = 0; i < size; i++) {
				printf("%d ", arr[i]);
			}
			printf("\n");
		}
		//��׼ֵ�Ĳ���
		int partion(int* arr, int begin, int end) {

			int key = arr[begin];
			//�Ӻ����ҵ�һ��С��key��ֵ,��ǰ���ҵ�һ������key��ֵ
			while (begin < end) {
				//�Ӻ���ǰ�ҵ�һ��С��key��ֵ
				while (begin < end && arr[end] >= key) {
					--end;
				}
				arr[begin] = arr[end];
				//��ǰ����ҵ�һ������key��ֵ
				while (begin < end && arr[begin] <= key) {
					++begin;
				}
				arr[end] = arr[begin];
			}
			//���ҵ��Ļ�׼ֵ��λ����������λ�ý������
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
		3.ǰ��ָ�� ����

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
			int prev = begin;//���һ��С�ڻ�׼ֵ��λ��
			int cur = prev + 1;//��ʾ��һ��С�ڻ�׼ֵ��λ��
			int key = arr[begin];
			while (cur <= end) {
				//�·��ֵ�С���ݺ�βָ���λ�ò�����,���м京�д��ڻ�׼ֵ������,�ʽ��н���,����������ƶ�,С������ǰ�ƶ�
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
			//���ֵ�ǰ����
			int keypos = partion3(arr, begin, end);
			//����������
			quickSort3(arr, begin, keypos - 1);//�Ȼ������
			quickSort3(arr, keypos + 1, end); //�����ұ�
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
		�ǵݹ�ʵ�ֿ���
			stack.h�ļ�

#pragma once 
#include <stdio.h>
#include <stdlib.h>

			typedef int Type;

		typedef struct Stack{
			Type* _array; //
			size_t _capacity;//������С
			size_t _size; //�����Ԫ�ض���
		}Stack;


		void stackInit(Stack* st, size_t n);
		void stackPush(Stack* st, Type data);
		void stackPop(Stack* st);

		Type stackTop(Stack* st);
		int stackEmpty(Stack* st);
		int stackSize(Stack* st);
		//��������1(ջ��ʵ��)
		void quickSortNoR1(int* arr, int size);

		stack.c�ļ�

#include "stack.h"

			void stackInit(Stack* st, size_t n) {
				st->_array = (Type*)malloc(sizeof(int)*n);
				st->_size = 0;
				st->_capacity = n;
			}

		void stackPush(Stack* st, Type data) {
			//ջ�Ĳ�����̱���Ҫ�ж������Ƿ��㹻
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


		//1.ջʵ��
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
			Swap(arr, start, begin);//��ʼ��λ�ú�������λ�ý��н���
			return begin;
		}

		void quickSortNoR1(int* arr, int size) {
			Stack st;
			stackInit(&st, 10);
			if (size > 1) {
				//��ʼ������ջ,������,������
				stackPush(&st, size - 1);
				stackPush(&st, 0);
			}
			//��������ջ������
			while (stackEmpty(&st) != 1) {
				int begin = stackTop(&st);
				stackPop(&st);
				int end = stackTop(&st);
				stackPop(&st);
				//����
				int keypos = partion(arr, begin, end);
				if (keypos + 1 < end) {
					//��������ջ,������,������
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
		//	printf("ջ�Ĵ�С: %d\n", stackSize(&st));
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
		queue.h�ļ�
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

		queue.c�ļ�
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
		//���: ������β��
		void queuePush(Queue* q, Type data) {
			QNode* node = creatNode(data);
			if (q->_front == NULL) {
				q->_front = q->_rear = node;
			}
			else {
				q->_rear->_next = node;
				q->_rear = node; //β����Ԫ��
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
			Swap(arr, start, begin);//��ʼ��λ�ú�������λ�ý��н���
			return begin;
		}


		void quickSortNoR2(int* arr, int size) {
			Queue q;
			queueInit(&q);
			if (size > 1) {
				//��ʼ������ջ,������,������
				queuePush(&q, 0);
				queuePush(&q, size - 1);
			}
			//��������ջ������
			while (queueEmpty(&q) != 1) {
				int begin = queueFront(&q);
				queuePop(&q);
				int end = queueFront(&q);
				queuePop(&q);
				//����
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

		//7.�鲢����
		//����˼��: �ȶ�������зֽ�,Ȼ����кϲ�����

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
			//ʣ��Ԫ��
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

			//�ϲ��ֺõ�����������
			merge(arr, begin, mid, end, tmp);
		}

		void mergeSort(int* arr, int size) {
			//�ȿ���һ���µ�����,���ź�˳������鷽���¿���������
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
		//8.�ǱȽ�����

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

			for (int i = 1; i < size; i++) {   //��ͳ��Ҫ����ķ�Χ��С max-min+1
				if (arr[i] > max)
					max = arr[i];
				if (arr[i] < min)
					min = arr[i];
			} //ѭ������ʱ�����ҵ����ֵ����Сֵ

			//��һ���ǽ��м��������
			int range = max - min + 1;
			int* countArr = (int*)malloc(sizeof(int)*range);
			//memset: ���ý�ĳһ���ڴ��е�����ȫ������Ϊָ����ֵ,�������ͨ��Ϊ������ڴ�����ʼ����
			//ͷ�ļ�Ϊstring.h 
			memset(countArr, 0, sizeof(int)*range);
			for (int i = 0; i < size; i++) {
				countArr[arr[i] - min]++;
			}
			//�ָ�����
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
			printf("����֮ǰ:  ");
			PrintArr(arr, size);
			countSort(arr, size);
			printf("��������֮��:  ");
			PrintArr(arr, size);
			system("color A");
			system("pause");
			return 0;
		}


