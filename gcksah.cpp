//auto
//auto不再是一个类型存储型指示符,而是作为一个新的类型指示符来指示编译器
//使用auto必须对他进行初始化,auto的实际类型是是根据初始表达式来确定的
//
//#include <iostream>
//using namespace std;
//
//int main() {
//	int a = 10;
//	auto b = a;
//	auto c = 'a';
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//
//	system("pause");
//	return 0;
//}
//**********************************************************************************************************

//#include <iostream>
////using namespace std;
//
//int main() {
//
//	std::cout << typeid(nullptr).name() << std::endl;
//	system("pause");
//	return 0;
//}
//***********************************************************************************

//9.基于范围的for循环
//1.组成
//for循环后面的括号由冒号分为两部分组成,第一部分是范围进行迭代的变量,第二部分是迭代的变量范围
//#include <iostream>
//using namespace std;
//int main() {
//	int array[] = { 1, 2, 3, 4 };
//	for (auto e : array) {
//		cout << e << " ";
//	}
//	system("pause");
//	return 0;
//}
//*******************************************************************************************************
//2.使用条件
//1.for循环迭代的范围必须是确定的
//对于数组而言就是数组的第一个元素和最后一个元素的范围.

//#include <stdio.h>
//#include <stdlib.h>
//
//int main() {
//	int array[] = { 1, 2, 3, 4 };
//	for (int i = 0; i < 4; i++) {
//		printf("%d ", array[i]);
//	}
//	system("pause");
//	return 0;
//}
//***********************************************************



