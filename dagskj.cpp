//2.static 成员

//声明此时给的值:
//
//#include <iostream>
//using namespace  std;
//
//class A {
//
//public:
//	A() {
//		++_scout;
//	}
//	A(const A& t) {
//		++_scout;
//	}
//	static int  GetScout() {
//		return _scout;
//	
//	}
//
//private:
//	static int _scout;
//};
//int A::_scout = 0;
//void test1() {
//	cout << A::GetScout() << endl;
//	A a1, a2; //调用构造函数
//	A a3(a1);  //调用拷贝构造函数
//	cout << a3.GetScout() << endl;
//	cout << A::GetScout() << endl;
//}
//int main () {
//
//	test1();
//    system("color A");
//    system ("pause");
//    return 0;
//}
//友元:分为友元类和友元函数
//cout的输出流和隐含的this指针在抢占第一个参数的位置,this指针始终占用的是第一个操作数的位置也就是左操作数的位置.
//
////假如不使用友元函数的变化  d << cout
//#include <iostream>
//using namespace  std;
//
//
//class Date{
//
//public:
//	Date(int year, int month, int day)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{}
//	//输出流类型
//	ostream& operator<<(ostream& _cout) {
//		_cout << _year << " " << _month << " " << _day << endl;
//		return _cout;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//void test1() {
//	Date d(2020, 3, 21);
//	d << cout; //因为this指针始终在参数的第一个位置                                                                    
//}
//int main () {
//	test1();
//    system("color A");
//    system ("pause");
//    return 0;
//}
//友元函数的引出
////友元函数:如果一个函数定义在类的外部,但是仍然要访问,那么就变成了它的友元类
//#include <iostream>
//using namespace  std;
//
//
//class Date{
//
//	friend ostream& operator<<(ostream& _cout, const Date& d);  //友元函数可以声明在类的任何地方,不受访问限定符的限定
//	friend istream& operator>>(istream& _cin, Date& d);//友元函数可以声明在类的任何地方,不受访问限定符的限定
//
//public:
//	Date(int year=1, int month=1, int day=1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
////输入流类型
//istream& operator>>(istream& _cin, Date& d) {  //两个参数this肯定占第一个位置
//	_cin >> d._year >> d._month >> d._day;
//	return _cin;
//}
//
////直接将输出流类型定义在类外那么明显不能访问类内的参数
//ostream& operator<<(ostream& _cout, const Date& d) {  //两个参数this肯定占第一个位置
//	_cout << d._year << " " << d._month << " " << d._day << endl;
//	return _cout;
//}
//
//void test1() {
//	Date d;
//	cin >> d; //输入 参数
//	//Date d(2020, 3, 21);
//	cout << d << endl; // 参数输出 因为this指针始终在参数的第一个位置                                                                    
//}
//
//int main() {
//	test1();
//	system("color A");
//	system("pause");
//	return 0;
//}
//友元类:
//1.友元类的所有成员函数都可以作为另一个类的友元函数,都可以访问另一个类中的非公有成员.
//2.类的关系是单向的,不具有交换性\
//3.友元关系不能传递
//内部类:
//内部类天染得作为外部类的友元函数

//6.练习题:
//1.求1+2+3...+n要求不能使用乘除法,for,while,if,else,switch等关键字以及条件判定语句.

#include <iostream>
using namespace  std;

class A {

public:

	class Sum {
	public:
		//内部类直接访问外部类的私有成员
		Sum() {
			_sum += _num;
			++_num;
			cout << "Sun" << endl;
		}
	};

	int Sum_solution() {
		_sum = 0;
		_num = 1;
		Sum sumarr[10]; //调用n次Sum类的构造函数,创建Sum对象数组
		return _sum;
	}

//private:
	static int _num;
	static int _sum;
};

int A::_num = 1;
int A::_sum = 0;

int main () {
	A s;
	int sum = s.Sum_solution();
	cout << A :: _num << endl;
	cout << sum << endl;

    system("color A");
    system ("pause");
    return 0;
}	

//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//
//
//int sumNums(int n){
//	return (int)(pow(n, 2) + n) >> 1;
//}
//int main () {
//
//    system("color A");
//    system ("pause");
//    return 0;
//}


















