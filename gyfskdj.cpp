//��μ�����Ĵ�С:(���ഴ�������ı������ڴ���ռ���)
//����һ����ռһ���ֽ�,������Ƕ����һ���ಢ�Ҷ������û�н���ʵ������ô��ռ�ֽ�.
//��Ա������ռ�ֽ�,
//��ѭ�ṹ���ڴ����ԭ��"

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
//��С���ֽ�����ж�:
//1.�������������ж�
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
////2.ָ��ǿת��
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