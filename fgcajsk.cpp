//********友元********
//1.友元函数
//友元函数可以直接访问类的私有成员,它是定义在类外的普通函数,不属于任何类,但需要在内部声明,声明时添加friend,-

#include <iostream>
using namespace std;

class Date {

	friend ostream& operator<<(ostream& _cout, const Date& d);
	friend istream& operator>>(istream& _cin,  Date& d);

public:
	Date(int year = 1,int month = 1,int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}
private:
	int _year;
	int _month;
	int _day;

};
//输出流
ostream& operator << (ostream& _cout, const Date& d) {
	_cout << d._year<< d._month<< d._day << endl;

	return _cout;
}
//输入流
istream& operator >> (istream& _cin, Date& d) {
   _cin >> d._year >> d._month >> d._day;
	return _cin;
}

int main() {

	Date d;
	cin >> d;
	cout << d << endl;
	system("pause");
	return 0;
}
//友元函数可以直接访问类的私有成员,它是定义在类外的普通函数,不属于任何类,但需要在类中进行声明添加friend 关键字
//1.友元函数可以直接访问类的私有成员,但不是类的成员函数.
//2.友元函数不能用const修饰,
//3.友元函数可以在类的任何地方声明,不受类访问限定符限制.
//4.友元函数的调用与普通函数的调用相同.

#include <iostream>
using namespace std;

class Date {
	friend void  test();
public:
	Date(int year=1,int month=1,int day=1) //构造函数
		: _year(year) //初始化列表 对成员进行初始化
		, _month(month)
		, _day(day)
	{}
private:
	int _year;
	int _month;
	int _day;
};
//友元函数可以直接访问私有成员
void  test() {
	Date d(2020,5,21);
	cout << d._year << " " << d._month << " " << d._day << endl; 
}
int main() {
	test();
	system("pause");
	return 0;
}
//友元类
//友元类的所有成员函数都可以是另一个类的成员函数,都可以访问另一个类的非公有成员.
//友元类的关系是单向的,不具有交换性.
//友元关系不能传递