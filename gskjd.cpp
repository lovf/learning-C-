//c++函数模板和类模板
一.函数模板
1.函数模板:建立一个虚拟的通用函数, 函数的参数和类型不具体确定, 用一个虚拟类型来代表通用函数的参数和类型, 在使用的过程中,
只要函数类型和该通用类型匹配, 就不用了多定义函数(只定义一次通用函数), 直接可以调用通用函数, 在调用过程中, 根据实参的类型
来控制虚拟类型的类型, 从而实现不同函数的调用.
功能 : 减少了程序猿代表的输入量, 让机器自动进行识别.(实际的代码量是完全没有少得只是让机器进行识别调用)

	 2.函数模板的格式
	 template<typename / class T1, typename / class T2, typename / class T3, typename / class T4, typename / class T5, ....>
返回值类型 函数名(参数列表){}
//***********************************************************************************************
**具体样板:
template<typename T>
void Swap(T& left, T&right){  // 通用函数模板
	T temp = left;
	left = right;
	right = temp;

}

template 的含义是“模板”，尖括号中 typename（或class）是关键字，T是一个类型参数（虚拟的类型名）。
typename和class的作用相同，都是表示“类型名”，二者可以互换。
//*******************************************************************************************************
3.函数模板的实例化
用不同类型的参数使用函数模板时, 成为函数模板的实例化.
(1)隐式实例化 让编译器根据实参进行推演实际的类型

#include <iostream>
using namespace std;

template <class T>

T Swap(const T left, const T right) {
	return left + right;
}

int main() {
	int a = 1, b = 3, ret1;
	double c = 2.1, d = 3.2, ret2;

	ret1 = Swap(a, b); //调用函数模板,此时T被int代替
	ret2 = Swap(c, d);//调用函数模板,此时T被double代替
	cout << ret1 << endl; //4
	cout << ret2 << endl; //5.3

	system("pause");
	return 0;
}
//***********************************************************************************************
(2)显示实例化:在函数的后面添加<类型>指定参数的实际类型
#include <iostream>
using namespace std;

template <class T>

T Swap(const T left, const T right) {
	return left + right;
}

int main() {
	int a = 1;
	double c = 2.1, ret;

	ret = Swap<double>(a, c);//显示实例化 调用函数模板,此时T被double代替
	cout << ret << endl;
	system("pause");
	return 0;
}
//*******************************************************************************************************
当编译器对类型识别有混淆的时候, 此时应该进行显示实例化.
2.函数模板的匹配原则
(1).普通函数和模板函数共存时, 如果普通函数的参数类型可以完全匹配时, 则优先执行普通函数模板, 不进行模板函数的实例化.
(2).当普通函数参数不匹配时, 但是实例化之后完全匹配参数类型, 则就使用模板函数.
(3).假如已经指明了实例化(Add()<int >(a, c)), 那么一定执行的是模板函数.

二.类模板
1.格式:
template <class T1, class T2, class T3, class T4, ..>
class 类模板名字
{

	//类内成员定义
};

template <class T> //声明类模板，虚拟类型名为numtype
class Compare { //类模板名为Compare

private:
	T x, y;
public:
	Compare(T a, T b) { //定义构造函数
		x = a;
		y = b;
	}
}

类模板不进行隐式实例化(意思就是直接进行显示的转化)
Date d;
类模板
类型和类名不同
类型：类名<模板实际参数类型>

举例说明:(再类内定义模板成员函数)
	 //************************************************************************************************
#include <iostream>
using namespace std;

template <class T1, class T2, class T3>
class Date {
public:
	Date(T1 year, T2 month, T3 day)
		:_year(year)
		, _month(month)
		, _day(day)
	{}

	void Display() {
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	T1 _year;
	T2 _month;
	T3 _day;
};

void test2() {
	Date<int, int, int> d(2020, 5, 31);
	d.Display();
}
int main() {
	test2();
	system("pause");
	return 0;
}
//************************************************************************************************************
//在类外定义模板成员函数
//在类外定义模板的成员函数,必须加上泛型的声明
//******************************************************************************************************
#include <iostream>
using namespace std;

template <class T1, class T2, class T3>
class Date {
public:
	Date(T1 year, T2 month, T3 day)
	:_year(year)
	, _month(month)
	, _day(day)
	{}
	void Display(); //必须先声明
private:
	T1 _year;
	T2 _month;
	T3 _day;
};

如果在类外定义类模板的成员函数，需要加上泛型的声明
作用域为 "类名<泛型参数>"

template <class T1, class T2, class T3>
void Date<T1, T2, T3>::Display() {
	cout << _year << "-" << _month << "-" << _day << endl;
}

void test2() {
	Date<int, int, int> d(2020, 5, 31); //直接进行显示的实例化
	d.Display() ;
}
int main() {
	test2();
	system("pause");
	return 0;
}
////******************************************************************************************************
//注意:类型和类名不同
//普通类的定义:类型等与类名Date d(2020,5,21);
//类模板的定义:;类型=类名<模板实际参数类型> Date<int ,int ,int>
//
//

