
简单string模拟实现包括4个组成部分:
(析构函数,拷贝构造(有传统写法,现代写法),构造函数,赋值运算符(有传统写法,现代写法))
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
	错误
	:_ptr(ptr)
	:_ptr(new char[strlen(ptr) + 1])
	{
	strcpy(_ptr, ptr);
	}
	*/
	错误写法
	String(char* ptr = "\0")
	String(char* ptr = "")
		:_ptr(new char[strlen(ptr) + 1])
	{
		strcpy(_ptr, ptr);
	}

	默认的拷贝构造
	/*
	String(const String& str)
	:_ptr(str._ptr)
	{
	}
	*/
	显式定义拷贝构造，完成深拷贝：拷贝对象的内容 + 对象的资源
	/*
	String(const String& str)
	:_ptr(new char[strlen(str._ptr) + 1])
	{
	strcpy(_ptr, str._ptr);
	}
	*/

	拷贝构造： 现代写法---> 深拷贝
	String(const String& str)
		:_ptr(nullptr)
	{
		创建一个局部对象： 调用构造函数--> 开空间 + 内容拷贝
		String tmp(str._ptr);
		swap(_ptr, tmp._ptr);
	}

	深拷贝
	/*
	String& operator=(const String& str)
	{
	if (this != &str)
	{
	开空间
	char* tmp = new char[strlen(str._ptr) + 1];
	拷贝资源
	strcpy(tmp, str._ptr);
	释放原有空间
	delete[] _ptr;
	指向新的空间
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
	拷贝构造
	String s2 = s;
	赋值： operator=
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