//日期类的实现:

#include <iostream>
using namespace  std;


class Date{
public:
	Date(int year,int month,int day) {
		if (year > 0 && month > 0 && month < 13 && day > 0 && day <= getDay(year, month)) {
			_year = year;
			_month = month;
			_day = day;
		}
		else {
			cout << "日期有误" << year << " " << month << " " << day << endl;
			cout << "重新设置" << endl;
			_year = 2020;
			_month = 1;
			_day = 1;
		}
	}
	int getDay(int year, int month) {
		static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = days[month];
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
			day++;
		}
		return day;
 	}

	Date& operator+=(int day) {
		//0.日期假如小于0
		if (day < 0)   
			return *this -= (-day);//加上一个负数等于减去一个整数
		_day += day;
		//1.判定相加之后的天数是否大于本月的天数
		if (_day > getDay(_year, _month)) {
		//2.更新本月的天数
			_day -= getDay(_year, _month);
			//3.月份进位
			++_month;
			if (_month == 13) {
				//年份进位
				++_year;
				_month = 1;
			}
		}
		return *this;
	}
	Date& operator-=(int day) {
		//0.先判定减的日期的征服
		if (day < 0)
			return *this += (-day);//等于复用了上面的+=的运算符重载

		_day -= day;
		//1.检查相减之后的日期是否为负值
		while (_day <= 0) {
		   //2.月份退位
			--_month;
			if (_month == 0) {
				//3.年份退位
				--_year;
				_month = 12;
			}
			//4.更新退位之后的天数
			_day += getDay(_year, _month);
		}
		return *this;
	}

	//关于+= ,-= 赋值运算符重载的总结
	//+= 0.判定相加的天数是否小于0 1.更新当月的天数2.判定当月的天数>本月应该的天数时3.进行月份的进位.4.月份>=13时进行年份的进位
	//-= 0.判定相加的天数是否小于0 1.先进行月份的退位2.判定月份是否退位到0 3.假如退位到0,进行年份的退位4.更新当月的天数
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Date operator+(int day) {
	//ret=a+b
		Date ret(*this);
		ret += day;
		return ret;
	}
	Date operator-(int day) {
		//ret=a-b
		Date ret(*this);
		ret -= day;
		return ret;
	}
	//前置++
	Date& operator++() {
		return *this += 1;
	}
	//后置++
	//返回++之前的值
	Date operator++(int) {
		//把之前的值先进行拷贝
		Date ret(*this);
		 *this += 1;
		 return ret;
	}
	//前置--
	Date& operator--() {
		return *this -= 1;
	}
	//后置--
	//返回--之前的值
	Date operator--(int) {
		//把之前的值先进行拷贝
		Date ret(*this);
		*this -= 1;
		return ret;
	}



	void PrintDate() {
		cout << _year << " " << _month << " " << _day << endl;
	}

//private:
	int _year;
	int _month;
	int _day;

};

ostream& operator<<(ostream& _cout, const Date& d) {

	_cout << d._year << " " << d._month << " " << d._day << endl;
	return _cout;
}
//+= -= 运算符重载 operator+=(int day)  operator-=(int day)
void test1() {
	Date d(2020, 3, 21);
	d.PrintDate();

	//d += 20;
	//d.PrintDate();
	
	d -= 30;
	d.PrintDate();
}

//加减天数运算符重载 operator+(int day)  operator-(int day)
void test2() {
	Date d(2020, 2, 20);
	d.PrintDate();

	cout << d.operator+(20) << endl;

	cout << d.operator-(20) << endl;
}


// 前置++ 后置++
void test3() {
	Date d(2020, 2, 20);
	cout << "执行操作之前的值" << endl;
	d.PrintDate();

	cout << "前置++" << endl;
	cout << (++d) << endl;
	cout << d.operator++() << endl;

	cout << "后置++" << endl;
	cout << (d++) << endl;
	//d.operator++(0);
	//d.PrintDate();
	cout << d.operator++(0) << endl;

}
void test4() {
	Date d(2020, 2, 20);
	cout << "执行操作之前的值" << endl;
	d.PrintDate();

	cout << "前置--" << endl;
	cout << (--d) << endl;
	cout << d.operator--() << endl;

	cout << "后置--" << endl;
	cout << (d--) << endl;
	//d.operator--(0);
	//d.PrintDate();
	cout << d.operator--(0) << endl;

}

int main () {
	//test1();
	//test2();
	//test3();
	test4();
    system("color A");
    system ("pause");
    return 0;
}

//7.const 成员

#include <iostream>
using namespace  std;

//
class Date{
public:
	Date(int year=1, int month=1, int day=1) { 
		_year = year;
		_month = month;
		_day = day;
	}

	//void PrintDate() { //等价于 PrintDate(Date& const this)
	//	cout << _year << " " << _month << " " << _day << endl;
	//}
	void PrintDate() const { // 等价于PrintDate(const Date& const this)
		cout << _year << " " << _month << " " << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main () {
	//1. 非 const对象既能调用非const成员函数,也能调用const成员函数  非const成员函数既能读也能写
    Date d1(2020, 3, 21);
	d1.PrintDate();
	//2.const对象只能调用const成员函数   const成员函数只能读.
	//3.假如用const对象去调用非const成员函数会导致读写权限权限被放大.
	//const Date d2(2020, 3, 1); 
	//d2.PrintDate();
	//4.非成员函数不能使用const修饰,因为非const成员函数没有this指针.
	//5.const修饰成员函数的第一个参数即this指针.
	//6.原则上读写权限是不能被放大的.
    system("color A");
    system ("pause");
    return 0;
}
//8.取地址和const取地址运算符重载

#include <iostream>
using namespace  std;

class Date{

public:
	Date(int year = 1, int month = 1, int day = 1) {
		_year = year;
		_month = month;
		_day = day;
	}
	//非const对象
	Date* operator&() {
	
		return this;
	}
	//const对象
	const Date* operator&()  const {

		return this;
	}

	void PrintDate() const { // 等价于PrintDate(const Date& const this)
		cout << _year << " " << _month << " " << _day << endl;
	}
	//以上两个运算符都不需要重载,使用编译器默认取地址重载即可,只有特殊情况情况下才需要重载,比如想让别人获取对象的指定内容.
private:
	int _year;
	int _month;
	int _day;
};

int main () {
	Date d1(2020, 3, 21);
	d1.PrintDate();
    system("color A");
    system ("pause");
    return 0;
}


类和对象下篇(下)

////1.再谈构造函数
////1.1赋值和初始化

#include <iostream>
using namespace  std;

class Date {
public:
	//这个是对对象的赋值而不是初始化
	//构造函数中的语句只能将其认为是赋初值,而不是作为初始化,镇正的出事啊是在初始化列表中进行的,初始化一次,而构造函数可以进行多次赋值.
	/*Date(int year = 1, int month = 1, int day = 1)  {
		_year = year;
		_month = month;
		_day = day;
		}*/
	//利用初始化列表对
	Date(int year = 1, int month = 1, int day = 1,int ref,int b) 
	//初始化列表
	:_year(year)
	,_month(month)
	,_day(day)
	,_ref(ref)
	, _b(b)
	//赋值操作
	{
		_year = year;
		_month = month;
		_day = day;
	}
	//打印
	void PrintDate() const { // 等价于PrintDate(const Date& const this)
		cout << _year << " " << _month << " " << _day << endl;
	}

	
private:
	//这块属于在声明的时候赋值,程序优先考虑构造函数中的参数
	int _year;
	int _month;
	int _day;
	int& _ref; //引用成员必须在初始化列表进行初始化
	const int _b;//const 成员必须在初始化列表进行初始化
};


int main () {
	Date d(2020, 3, 21, 4, 23);
	d.PrintDate();
	

    system("color A");
    system ("pause");
    return 0;
}

对于初始化列表需要注意:
1.初始化列表中的成员只能初始化一次
2.类中具有以下成员必须放在初始化列表中进行初始化
1>.引用变量
2>const成员变量
3>自定义类型成员
3.对于自定义成员,最好在初始化列表中进行初始化,即使不再初始化列表中进行显示显示初始化,编译器也会在初始化列表中自动调用自定义成员员函数进行初始化
4.成员变量在声明中的次序就是其在初始化列表中的初始化的顺序,与初始化列表中的先后次序无关(最好声明的顺序和初始化的顺序一致)

#include <iostream>
using namespace  std;

class Date{

public:
	Date(int y=1,int m=1,int d=1) 
		:_a(_year) 
		, _year(y)
		, _month(2*_year)
		, _day(3*_year)
		, _b(d)

	{
	}
	void PrintDate() {
		cout << _year << " " << _month << " " << _day << " " << _a << " " << _b << endl;
	
	}
private:
	int _year;
	int _month;
	int _day;
	int _a;
	int _b;
};
int main () {
	Date d(1, 1, 1);
	d.PrintDate();


    system("color A");
    system ("pause");
    return 0;
}


#include <iostream>
using namespace  std;

class  A{

public:
	A(int a)  
	:_a1(a)
	, _a2(_a1)
	{}
	void Printdate() {
		cout << _a2 << " " << _a1 << endl;
	
	}


private:
	声明的顺序是_a2,_a1,因此在定义的地方先完成_a2初始化,在完成_a1的初始化
	注意: 尽量声明的顺序和初始化的顺序保持一致
	int _a2;
	int _a1;
};
int main () {
	A aa(1);
	aa.Printdate();


    system("color A");
    system ("pause");
    return 0;
}
