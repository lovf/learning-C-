//��С���ж�:

//#include <iostream>
//using namespace std;
//
//void test() {
//
//	int a = 1;//0x00000001
//	int* pa = &a;
//	char* pa1 = (char*)pa;//�������ǽ���ַǿת��char ���͵ĵ�ַ��
//	if (*pa1 == 0x01) {
//		cout << "Is Little end "<< endl;
//	} else {
//		cout << "Is Big end " << endl;
//	}
//}
//
//int main() {
//	test();
//	system("pause");
//	return 0;
//}

//��������������ж�
#include <iostream>
using namespace std;

union Un {

	int a;
	char b;
};
typedef union Un un;
void  test() {
	un u;
	u.a = 0x11223344;
	if (u.b == 0x44) {
		cout << "Is Little end " << endl;
	} else {
		cout << "Is Big end " << endl;
	}
}



int main() {
    test();
	system("pause");
	return 0;
}











