//auto�ؼ���
//�����Զ����͵��Ƶ�(���ݱ������������),����������������,����ͨ����ʼ���ʽ�����ͽ����Զ��Ƶ�������
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
//ʹ��auto�������ʱ���������г�ʼ��,�ڱ����ڽ׶θ��ݳ�ʼ���ʽ���Ƶ�auto��ʵ������.���auto����һ��"����"������,����һ����������ʱ��"ռλ��",���������Զ���auto�滻Ϊ������ʵ������.
//ʹ�ù���˵��:
//1.auto��ָ��������ʹ��:auto����ָ������ʱ,auto��auto*û���κ�����,����auto������������ʱ������&

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

//2.ͬһ�ж���������
//ͬһ�ж���������ʱ,��Щ������������ͬ������,����autoֻ�����ͬһ�����ͽ����Ƶ�,������һ�б������и�����Ҳ��������ô�ǲ��ܽ����Ƶ���.




//auto������Ϊ�����Ƶ��ĳ���:
//1.��Ϊ�����Ĳ���
//2.����ֱ��������������

//���ڷ�Χfor��ʹ��
//��Χfor��ð�ŷֳ����������: ��һ����Ϊ�����ı���,�ڶ�����Ϊ�����ķ�Χ
 
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
//ָ���ֵ: nullptr
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
//	func(0); //����0
//	func(NULL); //NULL ����Ϊ������0
//	func((int*)NULL); //��NULl����ǿ��ת��Ϊint*
//	func(nullptr); //nullptr ָ���ֵ
//
//    system("color A");
//    system ("pause");
//    return 0;
//}
//����nullptr����ת��Ϊ����ָ������;

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
//�鿴nullptr����
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

//�������(��)
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
	s.SetStudentInfo("zhangsan", "��", 56);
	s.PrintStudentInfo(); 

    system("color A");
    system ("pause");
    return 0;
}