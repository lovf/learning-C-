//����:���ò������¶���һ������,���Ǹ�����ȡһ������,����������Ϊ���ñ������ٿռ�,�������ñ�������һ���ڴ�ռ�.
//��ʽ: ���� + & ���ñ�����(������) = ����ʵ��


#include <stdio.h>
#include <stdlib.h>

void Swap(int * a,int *b) {

	int temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	int a = 10;
	int b = 20;
	Swap(&a,&b);
	printf("a��ֵΪ: %d\n",a);
	printf("b��ֵΪ: %d\n",b);
	system("pause");
	return 0;
}
//************************************************************************************************************
#include <iostream>
using namespace std;

void TestRef() {
	int a = 10;
	//����ʵ��
	int& ra = a;
	cout << &a << endl;
	cout << &ra << endl;
}

int main() {
	TestRef();
	system("pause");
	return 0;
}

//*******************************************************************************************************
#include <iostream>

//using namespace std;
void Swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int main() {

	int a = 10;
	int b = 20;
	Swap(a,b);
	std::cout << "a��ֵΪ: " << a << std::endl;
	std::cout << "b��ֵΪ: " << b << std::endl;
	system("pause");
	return 0;
}
//**************************************************************************************************************
#include <iostream>

using namespace std;

void Swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int main() {

	int a = 10;
	int b = 20;
	Swap(a,b);
	cout << "a��ֵΪ: " << a << endl;
	cout << "b��ֵΪ: " << b << endl;
	system("pause");
	return 0;
}
//**************************************************************************************************************
#include <iostream>

using namespace std;

int Add(int& ra,int& rb) {
	return ra + rb;
}

int main() {
	int a = 10;
	int b = 20;
	int ret = Add(a,b);
	cout << ret << endl;
	system("pause");
	return 0;
}
//*****************************************************************************************************
//
#include <iostream>

using namespace std;

int Add(int ra, int rb) {
	return ra + rb;
}

int main() {
	int a = 10;
	int b = 20;
	int ret = Add(a, b);
	cout << ret << endl;
	system("pause");
	return 0;
}
//*************************************************************************************************************
#include <iostream>

using namespace std;

int& Add10(int& a) {
	return ++a;
}
//����ֵ����������һ��Ҫ���ں�������������
int& Add20(int a) {
	return ++a;
}

int main() {
	int a = 0;
	int& b = Add10(a);
	int c = Add10(a);
	int d = Add20(a);

	cout << d << endl;
	cout << a << endl;
	cout << d << endl;

	system("pause");
	return 0;
}









