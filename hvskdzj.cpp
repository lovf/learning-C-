//stringģ��ʵ��:
//��stringģ��ʵ�ְ���4����ɲ���:
//(��������,��������(�д�ͳд��,�ִ�д��),���캯��,��ֵ�����(�д�ͳд��,�ִ�д��))
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
using namespace  std;

class String{
public:
	
	//�޲ι���
	String(char* ptr = " ")
		:_ptr(new char[strlen(ptr) +1]) //��ʼ���б�
	{
		strcpy(_ptr, ptr);
	}
	//Ĭ�ϵĿ�������
	/*String(const String& str)
		:_ptr(str._ptr)
	
	{}*/
	//  ��ͳд��: ��ʾ��������,������: ��������+��Դ
	//String(const String& str)
	//	:_ptr(new char[strlen(str._ptr) + 1]) //��ʼ���б�
	//{
	//	strcpy(_ptr, str._ptr);
	//}
	//���������ִ�д��
	String(const String& str)
		:_ptr(nullptr)
	{
		//����һ���ֲ�����:���ù��캯��--->���ռ�+���ݿ���
		String tmp(str._ptr);
		swap(_ptr, tmp._ptr);
	}
	//��ֵ��������� ��ͳд��
	String& operator=(const String& str) {
		if (this != &str) {
		//1.���ռ�
			char* tmp = new char[strlen(str._ptr) + 1];
		//2.������Դ
			strcpy(tmp, str._ptr);
		//3.�ͷ�ԭ����Դ
			delete[] _ptr;
		//ָ���µĿռ�
			_ptr = tmp;
		}
		return *this;
	}
	//��ֵ��������غ��� �ִ�д��
	String& operator=(String str) {
		swap(_ptr, str._ptr);
		return *this;
	}

	//��������
	~String() {
		if (_ptr) {
			delete[] _ptr;
			_ptr = nullptr;
		}
	}
	const char* c_str() const{
	
		return _ptr;
	}

private:
	char* _ptr;
};


void test1() {
	String s("123");
	//��������
	String s2 = s;
	//��ֵ�� operator=
	String s3 = s2;
}

int main () {

	test1();
    system("color A");
    system ("pause");
    return 0;
}