
��stringģ��ʵ�ְ���4����ɲ���:
(��������,��������(�д�ͳд��,�ִ�д��),���캯��,��ֵ�����(�д�ͳд��,�ִ�д��))
#include <string>
using namespace std;
#include <iostream>


class String
{
public:
	/*
	String()
	:_ptr(new char[1])
	{
	*_ptr = '\0';
	}

	String(char* ptr)
	����
	:_ptr(ptr)
	:_ptr(new char[strlen(ptr) + 1])
	{
	strcpy(_ptr, ptr);
	}
	*/
	����д��
	String(char* ptr = "\0")
	String(char* ptr = "")
		:_ptr(new char[strlen(ptr) + 1])
	{
		strcpy(_ptr, ptr);
	}

	Ĭ�ϵĿ�������
	/*
	String(const String& str)
	:_ptr(str._ptr)
	{
	}
	*/
	��ʽ���忽�����죬��������������������� + �������Դ
	/*
	String(const String& str)
	:_ptr(new char[strlen(str._ptr) + 1])
	{
	strcpy(_ptr, str._ptr);
	}
	*/

	�������죺 �ִ�д��---> ���
	String(const String& str)
		:_ptr(nullptr)
	{
		����һ���ֲ����� ���ù��캯��--> ���ռ� + ���ݿ���
		String tmp(str._ptr);
		swap(_ptr, tmp._ptr);
	}

	���
	/*
	String& operator=(const String& str)
	{
	if (this != &str)
	{
	���ռ�
	char* tmp = new char[strlen(str._ptr) + 1];
	������Դ
	strcpy(tmp, str._ptr);
	�ͷ�ԭ�пռ�
	delete[] _ptr;
	ָ���µĿռ�
	_ptr = tmp;
	}
	return *this;
	}
	*/

	String& operator=(String str)
	{
		swap(_ptr, str._ptr);
		return *this;
	}

	const char* c_str() const
	{
		return _ptr;
	}

	~String()
	{
		if (_ptr)
		{
			delete[] _ptr;
			_ptr = nullptr;
		}
	}

private:
	char* _ptr;
};

void test()
{
	String s("123");
	��������
	String s2 = s;
	��ֵ�� operator=
	s = s2;
}
int main()
{
	test();
	return 0;
}

void test()
{
	String s1;
	String s2("abc");
}
int main()
{
	test();
	return 0;
}

void test()
{
	char str[] = "\0";
}
int main()
{
	test();
	return 0;
}

void test()
{
	std::string s1;
	const char* ptr1 = s1.c_str();
	String s2;
	const char* ptr2 = s2.c_str();
}

int main()
{
	test();
	return 0;
}