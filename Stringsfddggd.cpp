//String类简单模拟实现练习
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace  std;

class String{
public:

	////无参构造
	//String(char* str=" ") 
	//	:_ptr(new char[strlen(str)+1])
	//
	//{
	//	strcpy(_ptr, str);
	//}
	//带参拷贝构造拷贝
	String(char* str)
		:_ptr(new char[strlen(str) + 1])

	{
		strcpy(_ptr, str);
	}

	////拷贝构造 传统
	//String(String& str) 
	//	:_ptr(new char[strlen(str._ptr)+1])
	//{
	//	strcpy(_ptr, str._ptr);
	//}
	//拷贝构造 现代写法
	String(String& str) 
		:_ptr(nullptr)
	{
		String tmp(str._ptr);
		swap(_ptr, tmp._ptr);
	}

	//////赋值运算符重载  传统
	//String& operator=(String& str){
	//	if (this != &str) {
	//	//1.开空间
	//		char* tmp = new char[strlen(str._ptr) + 1];
	//	//2.拷贝
	//		strcpy(tmp, str._ptr);
	//	//3.释放原有空间
	//		delete[] _ptr;
	//	//更新
	//		_ptr = tmp;
	//	
	//	}
	//	return *this;
	//}
	//赋值运算符重载  现代
	String& operator=(String& str) {
		swap(_ptr, str._ptr);
		return *this;
	}

	//析构函数
	~String(){
		if (_ptr) {
			delete[] _ptr;
			_ptr = nullptr;
		}
	
	}

private:
	char* _ptr;
};

void test1() {
	String s1 = "1234";
	String s2 = "6789";

	String s3(s1);
	cout << "拷贝构造" << endl;
	s1 = s2;
	cout << "赋值运算符重载" << endl;

}

int main () {


	test1();
    system("color A");
    system ("pause");
    return 0;
}

