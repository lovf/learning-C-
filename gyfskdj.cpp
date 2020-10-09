//如何计算类的大小:(看类创建出来的变量在内存中占多大)
//单独一个类占一个字节,假如有嵌套了一个类并且对这个类没有进行实例化那么不占字节.
//成员函数不占字节,
//遵循结构体内存对齐原则"

#include <iostream>
using namespace  std;

class C
{
	int _c;
	/*class G
	{
	int a = 1;
	float b = 2.0;
	char c = 'a';
	};*/
	void func() {
		int a = 1;
		float b = 2.0;
		char c = 'a';
	}
};
class D
{
	int _c;
	void func() {
		int a = 1;
		float b = 2.0;
		char c = 'a';
	}
};

class E
{
	void func() {
		int a = 1;
		float b = 2.0;
		char c = 'a';
	}
};

class F
{
	
};

void test() {
	cout << sizeof(C) <<" "<< sizeof(D)<< " " << sizeof(E)<<" " << sizeof(F)<< " "<< endl; //4 4 1 1
}
int main () {

	test();
    system("color A");
    system ("pause");
    return 0;
}
//大小端字节序的判定:
//1.借助联合体来判定
//#include <iostream>
//using namespace  std;
//
//union U{
//	int a ;
//	char b;
//};
// 
//void test() {
//	U u;
//	u.a = 0x11223344;
//	if (u.b == 0x44) {
//		cout << "Little end" << endl;
//	}
//	else {
//		cout << "Big end" << endl;
//	}
//}
//
//int main () {
//
//
//	test();
//    system("color A");
//    system ("pause");
//    return 0;
//}
////2.指针强转法
//#include <iostream>
//using namespace  std;
//
//
//void test() {
//	int a = 0x11223344;
//	char* pa = (char*)&a;
//	if (*pa == 0x44) {
//		cout << "Is Little end" << endl;
//	}
//	else {
//		cout << "Is Big end" << endl;
//	}
//}
//
//int main() {
//
//
//	test();
//	system("color A");
//	system("pause");
//	return 0;
//}