//赋值运算符重载
//关键字operator后面接需要重载的运算符符号.
//函数原型: 返回值类型operator操作符(参数列表)
//作为类成员的重载函数时,其形参看起来比操作数数目少1成员函数.
//操作符有一个默认的形参this,限定为第一个形参.
//C++中5个不能重载的运算符:1.作用域操作符:  :: 2.条件操作符: ?: 3.点操作符: . 4.指向成员的指针指针操作符:->*,.*
//5.预处理操作符: # sizeof
//1.运算符重载函数:增强代码的可读性.2.成员函数名特殊定义和使用方式和普通函数一样.3.返回值operator+需要重载的运算符
//4.运算符重载函数如果是成员函数,参数的个数比运算符需要的个数少一个,这里编译器会自动传入this指针.5.this指针始终占用运算符操作数的第一个位置.

//运算符函数位于成员函数中
//#include <iostream>
//using namespace std;
//
//
//class Date {
//
//public:
//	Date(int year = 1, int month = 1, int day = 1) {
//		 _year = year;
//		 _month = month;
//		 _day = month;
//	
//	}
//	bool operator == (const Date& d2) {
//	
//	return _year == d2._year && _month == d2._month && _day == d2._day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//void test() {
//	Date d1;
//	Date d2(2018,9,27);
//	cout << (d1 == d2) << endl;
//}
//int main() {
//	test();
//
//	system("pause");
//	return 0;
//}
//运算符重载函数位于成员函数外部

//#include <iostream>
//using namespace std;
//
//
//class Date {
//
//public:
//	Date(int year = 1, int month = 1, int day = 1) {
//		_year = year;
//		_month = month;
//		_day = month;
//
//	}
//	int _year;
//	int _month;
//	int _day;
//};
//
////参数的个数和运算符需要的个数一样
//bool operator == (const Date& d1, const Date& d2) {
//
//	return d1._year == d2._year && d1._month == d2._month && d1._day == d2._day;
//}
//void test() {
//	Date d1;
//	Date d2(2018, 9, 27);
//	cout << (d1 == d2) << endl;
//}
//int main() {
//	test();
//
//	system("pause");
//	return 0;
//}
//*****************************************************************************************************
//**赋值运算符重载**
//赋值运算符重载函数:用一个对象去修改另一个已经存在的内容,修改之后两个对象的内容一致.
//1.可以通过检查是否给自己赋值,2.如果连续赋值返回值不能为void 3.返回值一般为*this 4.编译器默认的运算符为字节拷贝,及浅拷贝.如果有资源需要拷贝,那么需要进行显示定义,完成深拷贝.
//***区别调用构造函数还是赋值?
//如果左边的对象存在,就调用复制运算符重载.
//如果左边的对象不存在,就调用拷贝构造函数.

#include <iostream>

using namespace std;

class Date {

public:
	Date(int year = 1,int month = 1,int day = 1) {
	
		_year = year;
		_month = month;
		_day = day;

	}

	Date& operator = (const Date& d) {
		if (this != &d) {
			_year = d._year;
	 		_month = d._month;
			_day = d._day;

		}
		return *this;
	}

	Date(const Date& d) {
		_year = d._year;
		_month = d._month;
		_day = d._day;
	
	
	}
	void play() {
	
		cout << _year << " " << _month << " " << _day << endl;
	
	}

private:

	int _year;
	int _month;
	int _day;
	
};


int main() {
	Date d2;
	Date d1(2008, 12, 3);
	d2 = d1;
	d2.play();
	system("pause");
	return 0;
}


































































































