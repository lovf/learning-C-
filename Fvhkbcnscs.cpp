//引用:引用不是重新定义一个变量,而是给变量取一个别名,编译器不会为引用变量开辟空间,他和引用变量共用一块内存空间.
//格式: 类型 + & 引用变量名(对象名) = 引用实体


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
	printf("a的值为: %d\n",a);
	printf("b的值为: %d\n",b);
	system("pause");
	return 0;
}
//************************************************************************************************************
#include <iostream>
using namespace std;

void TestRef() {
	int a = 10;
	//引用实体
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
	std::cout << "a的值为: " << a << std::endl;
	std::cout << "b的值为: " << b << std::endl;
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
	cout << "a的值为: " << a << endl;
	cout << "b的值为: " << b << endl;
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
//返回值的生命周期一定要大于函数的生命周期
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









