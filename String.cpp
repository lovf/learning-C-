//String类简单实现:
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
using namespace std;

class String{

public:
	//1.全缺省构造函数
	String(char* str = " ")
		:_ptr(new char[strlen(str) + 1])
	{
		strcpy(_ptr, str);
	}
	//2.拷贝构造(传统写法)
	//String(const String& str)
	//	:_ptr(new char[strlen(str._ptr) + 1]) // 开空间 + 拷贝
	//{
	//	strcpy(_ptr, str._ptr); //拷贝
	//}
	//2.拷贝构造(现代写法)
	String(String& str) {
		String tmp(str._ptr); // 调用构造函数
		swap(_ptr, tmp._ptr); // 将进行交换
	}

	//3.赋值运算符(传统写法)
	//String& operator = (const String& str) {
	//	if (this != &str) {
	//		//开空间
	//		char* tmp = new char[strlen(str._ptr) + 1];
	//		//将原来空间的内容拷贝到新空间
	//		strcpy(tmp, str._ptr);
	//		//释放那个原来空间
	//		delete[] _ptr;
	//		_ptr = tmp;
	//	}
	//	return *this;
	//}

	//3.赋值运算符(现代写法)
	String& operator = (String str) {
		swap(_ptr, str._ptr);
		return *this;
	}


	//4.析构函数
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

