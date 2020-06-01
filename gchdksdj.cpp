//********************构造函数***********************
//***********************************************************************************************************
//1.构造函数是一个特殊的成员函数,名字和类名字相同,创建类类型对象时,由编译器自动调用,
//保证一个合适的初始值,并且在对象的生命周期内只调用一次

//特性:
//构造函数的主要任务并不是开空间创造对象,而是初始化对象.
//1.函数与类名相同
//2.无返回值
//3.对象实例化时编译器自动调用对应的构造函数.
//4.构造函数可以重载.(如果通过无参构造对象函数时,对象后面不用括号,否则就变成了函数声明)
//5.如果类中没有显示的构造函数,则C++ 编译器会自动生成一个无参的默认构造函数,一旦用户显示定义,则编译器将不在生成.
//6.无参的构造函数和全缺省的构造函数都可默认为构造函数.
// 7.成员命名
//非构造函数的形式
//#include <iostream>
//using namespace std;
//class Date {
//public:
//	void Date1(int year, int month , int day){
//	 _year = year;
//	 _month = month;
//	 _day = day;
//	}
//	void print() {
//		cout << _year << " " << _month << " " << _day << endl;
//	}
//
//private:
//	int _year;
//	int  _month;
//	int _day;
//};
//
//void test() {
//	//Date d(2020, 5, 1);//d 表示类的一个变量
//	//d.print();
//	//Date d2(d); //类似于d2和d1相等；
//	//d2.print();
//	Date d1;
//	d1.Date1(2020, 5, 1);
//	d1.print();
//}
// 
//int main() {
//	test();
//	system("pause");
//	return 0;
//}
//***********************************************************************************************************
//**********************************************************************************************************
//无参构造函数
/*#include <iostream>
using namespace std;
class Date {

public:
Date(){
_year = 2020;
_month = 4;
_day = 6;
}
void print() {
cout << _year << " " << _month << " " << _day << endl;
}
private:
int _year;
int  _month;
int _day;
};

void test() {

Date d;
d.print();
}

int main() {
test();
system("pause");
return 0;
}*/

//**************************************************************************************************************
//***************************************************************************************************************
//全缺省构造函数
#include <iostream>
using namespace std;

class Date {

public:
	Date(int year, int month, int day){
		_year = year;
		_month = month;
		_day = day;
	}
	void print() {
		cout << _year << " " << _month << " " << _day << endl;
	}
private:
	int _year;
	int  _month;
	int _day;
};

void test() {

	Date d(2020, 5, 21);
	d.print();
}

int main() {
	test();
	system("pause");
	return 0;
}
//**********************************************************************************************************