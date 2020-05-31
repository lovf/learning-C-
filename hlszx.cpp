//this指针的引出:

#include <iostream>
using namespace  std;


class Date{

public:
	void display() {
		cout << this->_year << "-" << this->_month << "-" << this->_day<<endl;
		//this_year = 2020;
	}

	void SetData(int year,int month,int day) {
		 _year = year;
	     _month = month;
		 _day = day;
	}

private:
	int _year;//年
	int _month;//月
	int _day;//日
};

int main() {
	Date d1, d2;

	d1.SetData(2020, 5, 20);
	d2.SetData(2020, 5, 21);
	d1.display();
	d2.display();

	system("pause");
	return 0;
}

//this:特性
//1.this指针的类型为 *const.
//2.this指针只能在成员函数中使用.
//3.this指针本质上其实是一个成员函数的形参,是对象在调用成员函数时,将对象地址作为实参传递给this形参,
//所以对象中不存储this指针.
//4.this指针是成员函数第一个隐含的指针形参,由编译器自动传递,不需要用户传递.
//面试题常考点
//1.this指针存在哪里？
//
//其实编译器在生成程序时加入了获取对象首地址的相关代码。并把获取的首地址存放在了寄存器ECX中(VC++编译器是放在ECX中，其它编译器有可能不同)。
//也就是成员函数的其它参数正常都是存放在栈中。而this指针参数则是存放在寄存器中。类的静态成员函数因为没有this指针这个参数，所以类的静态成员函数也就无法调用类的非静态成员变量。
//
//2.this指针可以为空吗？
//
//可以为空，当我们在调用函数的时候，如果函数内部并不需要使用到this, 
//也就是不需要通过this指向当前对象并对其进行操作时才可以为空(当我们在其中什么都不放或者在里面随便打印一个字符串)，
//如果调用的函数需要指向当前对象，并进行操作，则会发生错误（空指针引用）就跟C中一样不能进行空指针的引用











