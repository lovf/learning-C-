//auto关键字
//属于自动类型的推导(根据变量后面的类型),它不代表具体的类型,而是通过初始表达式的类型进行自动推导出来的
//#include <iostream>
//using namespace  std;
//
//int main () {
//	auto a = 10;
//	auto b = 10.0;
//	auto c = 'z';
//
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//
//    system("color A");
//    system ("pause");
//    return 0;
//}
//使用auto定义变量时必须对其进行初始化,在编译期阶段根据初始表达式来推导auto的实际类型.因此auto不是一种"类型"的声明,而是一个类型声明时的"占位符",编译器会自动将auto替换为变量的实际类型.
//使用规则说明:
//1.auto与指针结合起来使用:auto声明指针类型时,auto和auto*没有任何区别,但是auto声明引用类型时则必须加&

//#include <iostream>
//using namespace  std;
//
//int main () {
//	int x = 10;
//	auto a = &x;
//	auto* b = &x;
//	auto& c = x;
//
//	cout << typeid(x).name() << endl;
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//
//    system("color A");
//    system ("pause");
//    return 0;
//}

//2.同一行定义多个变量
//同一行定义多个变量时,这些变量必须是相同的类型,等于auto只是针对同一种类型进行推导,假如这一行变量既有浮点型也有整形那么是不能进行推导的.




//auto不能作为函数推导的场景:
//1.作为函数的参数
//2.不能直接用来声明数组

//基于范围for的使用
//范围for由冒号分成两部分组成: 第一部分为迭代的变量,第二部分为迭代的范围
 
//#include <iostream>
//using namespace  std;
//
//int main () {
//	int arr[] = { 1, 2, 3, 4, 5, 6 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	//for (int i = 0; i < size;i++) {
//	//	cout << arr[i] << " ";
//	//}
//	//cout << endl;
//
//	for (auto i : arr) {
//		cout << i << " ";
//	}
//	cout << endl;
//
//    system("color A");
//    system ("pause");
//    return 0;
//}
//指针空值: nullptr
//#include <stdio.h>
//#include <stdlib.h>
//#include <iostream>
//using namespace  std;
//
//void func(int a) {
//	cout << "func(int a)" << endl;
//}
//
//void func(int* a) {
//	cout << "func(int* a)" << endl;
//}
//
//int main () {
//	func(0); //整型0
//	func(NULL); //NULL 被认为是整型0
//	func((int*)NULL); //将NULl进行强制转换为int*
//	func(nullptr); //nullptr 指针空值
//
//    system("color A");
//    system ("pause");
//    return 0;
//}
//此外nullptr可以转换为任意指针类型;

//#include <iostream>
//using namespace  std;
//
//int main () {
//	int* a = nullptr;
//
//	float* b = nullptr;
//
//	char* c = nullptr;
//
//	long* d = nullptr;
//
//
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//
//    system("color A");
//    system ("pause");
//    return 0;
//}
//查看nullptr类型
//
//
//#include <iostream>
//using namespace  std;
//
//int main () {
//
//
//	cout << typeid(nullptr).name() << endl;
//
//    system("color A");
//    system ("pause");
//    return 0;
//}

//类与对象(上)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace  std;

class Student {

public:

	void SetStudentInfo(char* name,char* gender,int age) {
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}
	void PrintStudentInfo() {
		cout << _name << " " << _gender << " " << _age << endl;
	}
public:
	char _name[20];
	char _gender[10];
	int _age;

};

int main () {
	Student s;
	s.SetStudentInfo("zhangsan", "男", 56);
	s.PrintStudentInfo(); 

    system("color A");
    system ("pause");
    return 0;
}