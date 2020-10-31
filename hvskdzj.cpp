//string模拟实现:
//简单string模拟实现包括4个组成部分:
//(析构函数,拷贝构造(有传统写法,现代写法),构造函数,赋值运算符(有传统写法,现代写法))
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
using namespace  std;

class String{
public:
	
	//无参构造
	String(char* ptr = " ")
		:_ptr(new char[strlen(ptr) +1]) //初始化列表
	{
		strcpy(_ptr, ptr);
	}
	//默认的拷贝构造
	/*String(const String& str)
		:_ptr(str._ptr)
	
	{}*/
	//  传统写法: 显示拷贝构造,完成深拷贝: 拷贝对象+资源
	//String(const String& str)
	//	:_ptr(new char[strlen(str._ptr) + 1]) //初始化列表
	//{
	//	strcpy(_ptr, str._ptr);
	//}
	//拷贝构造现代写法
	String(const String& str)
		:_ptr(nullptr)
	{
		//创建一个局部变量:调用构造函数--->开空间+内容拷贝
		String tmp(str._ptr);
		swap(_ptr, tmp._ptr);
	}
	//赋值运算符重载 传统写法
	String& operator=(const String& str) {
		if (this != &str) {
		//1.开空间
			char* tmp = new char[strlen(str._ptr) + 1];
		//2.拷贝资源
			strcpy(tmp, str._ptr);
		//3.释放原有资源
			delete[] _ptr;
		//指向新的空间
			_ptr = tmp;
		}
		return *this;
	}
	//赋值运算符重载函数 现代写法
	String& operator=(String str) {
		swap(_ptr, str._ptr);
		return *this;
	}

	//析构函数
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
	//拷贝构造
	String s2 = s;
	//赋值： operator=
	String s3 = s2;
}

int main () {

	test1();
    system("color A");
    system ("pause");
    return 0;
}