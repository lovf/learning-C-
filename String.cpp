//String���ʵ��:
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
using namespace std;

class String{

public:
	//1.ȫȱʡ���캯��
	String(char* str = " ")
		:_ptr(new char[strlen(str) + 1])
	{
		strcpy(_ptr, str);
	}
	//2.��������(��ͳд��)
	//String(const String& str)
	//	:_ptr(new char[strlen(str._ptr) + 1]) // ���ռ� + ����
	//{
	//	strcpy(_ptr, str._ptr); //����
	//}
	//2.��������(�ִ�д��)
	String(String& str) {
		String tmp(str._ptr); // ���ù��캯��
		swap(_ptr, tmp._ptr); // �����н���
	}

	//3.��ֵ�����(��ͳд��)
	//String& operator = (const String& str) {
	//	if (this != &str) {
	//		//���ռ�
	//		char* tmp = new char[strlen(str._ptr) + 1];
	//		//��ԭ���ռ�����ݿ������¿ռ�
	//		strcpy(tmp, str._ptr);
	//		//�ͷ��Ǹ�ԭ���ռ�
	//		delete[] _ptr;
	//		_ptr = tmp;
	//	}
	//	return *this;
	//}

	//3.��ֵ�����(�ִ�д��)
	String& operator = (String str) {
		swap(_ptr, str._ptr);
		return *this;
	}


	//4.��������
	~String() {
		if (_ptr) {
			delete[] _ptr;
			_ptr = nullptr;
		}
	}

private:
	char* _ptr;
};

void test1() {



}
int main(){

	test1();
	system("pause");
	return 0;
}

