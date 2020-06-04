//再谈构造函数:
//1.1 构造函数赋值
#include <iostream>
using namespace std;

class Date {

public:
	Date(int year,int month,int day) {+
		//属于初始化赋值
		_year = year;
		_month = month;
		_day = day;
	}

	void play() {
		cout << _year << " " << _month << " " << _day << endl;
	}
private://成员变量进行声明的地方
	int _year;
	int _month;
	int _day;
};


int main() {

	Date d(2020,5,21);
	d.play();
	system("pause");
	return 0;
}
//************************************************************************************************************
//1.2初始化列表
//初始化列表: 以一个冒号开始,接着是以逗号隔开数据,每一个"成员变量"后面放到括号中的初始值或者表达式.
//1.初始化列表是对象成员定义的地方.2.每一个成员变量在初始化列表中只能出现一次
//2.类中包含以下成员,必须放到初始化列表的位置进行初始化.(1)引用成员变量(2)const成员变量(3)自定义类型成员变量
//3.成员变量在类中声明的次序就是初始化化列表中的初始化顺序.(初始化列表中的顺序和声明的顺序保持一致)
//初始化列表的使用

#include <iostream>
using namespace std;

class Date {

public:
	Date(int year=1,int month=1,int day=1) //构造函数
		: _year(year) //初始化列表 对成员进行初始化
		, _month(month)
		, _day(day)
	{}
	void print() {
		cout << _year << " " << _month << " " << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

void test() {
	Date d(2020,5,21);
	d.print();
}

int main() {
	test();
	system("pause");
	return 0;
}

//初始化列表中的顺序和声明的顺序保持一致
#include <iostream>
using namespace std;

class A {

public :
	//构造函数:
	//初始化列表

	A(int a)
		:_a1(a)
		,_a2(_a2)
	{}
	void print() {
		cout << _a1 << " " << _a2 << endl;
	}

private:
	int _a1;
	int _a2;
	static int _cnt;
};

void test() {
	A aa(1);//aa = 1;
	aa.print();

}

int main() {
	test();
	system("pause");
	return 0;
}
//1.3 explicit关键字  禁止单调构造函数的隐式类型转换.