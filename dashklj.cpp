运算符重载函数:

********************1.判等运算重载函数*****************
1.operator 假如在成员函数的里面参数如何定义
2.operator 假如在成员函数的外面参数如何定义
3.输入运算符重载函数如何使用

#include <iostream>
using namespace  std;


class Date{

public:
	Date(int year,int month,int day) {
		_year = year;
		_month = month;
		_day = day;
	}
	/*bool isEqual(const Date& d) {
		return _year == d._year  &&
		_month == d._month &&
		_day == d._day;
		}*/
	//运算符重载函数: 函数名特殊,定义和使用方式和普通函数一致
	//operator + 需要重载的运算符(参数列表)
	//运算符重载函数如果是成员函数,则参数的个数比运算符的个数少一个,这里编译器会自动传入this指针作为第一个参数
	//this 始终占用运算符操作数的第一个位置
	bool operator == (const Date& d) { //底层接口 bool operator == (const Date* this,const Date& d)
		return _year == d._year  &&
		_month == d._month &&
		_day == d._day;

		}
private:
	int _year;
	int _month;
	int _day;
};

int main () {
	//调用 operator
	Date d1(2020, 5, 21);
	Date d2(2020, 5, 21);
	cout << (d1 == d2) << endl; //等价于d1.operator==(d2)
	cout << d1.operator==(d2) << endl;

	//调用isEmqual 函数进行证明
	//Date d1(2020, 5, 21);
	//Date d2(d1);

	//Date d3(2020, 3, 14);
	//cout << d1.isEqual(d2) << endl;
	//cout << d1.isEqual(d3) << endl;

    system("color A");
    system ("pause");
    return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace  std;


class Date{

public:
	Date(int year, int month, int day) {
		_year = year;
		_month = month;
		_day = day;
	}
	int _year;
	int _month;
	int _day;
};

//将operator定义再外面,是不能少的
bool operator == (const Date& d1, const Date& d) { 
	return d1._year == d._year  &&
		d1._month == d._month &&
		d1._day == d._day;
}
//输出运算符重载函数
ostream& operator<<(ostream& _cout, const Date& date) {

	_cout << date._year << " " << date._month << " " << date._day << endl;
	return _cout;
}

int main() {
	//调用 operator
	Date d1(2020, 5, 21);
	Date d2(2020, 5, 21);
	cout << (d1 == d2) << endl;//判等函数

	cout << d1 << endl;

	system("color A");
	system("pause");
	return 0;
}
***********************2.赋值运算符重载函数****************************

#include <iostream>
using namespace  std;

class Date{

public:
	Date(int year=1, int month=1, int day=1) {
		_year = year;
		_month = month;
		_day = day;
	}
	/*bool isEqual(const Date& d) {
	return _year == d._year  &&
	_month == d._month &&
	_day == d._day;
	}*/
	//运算符重载函数: 函数名特殊,定义和使用方式和普通函数一致
	//operator + 需要重载的运算符(参数列表)
	//运算符重载函数如果是成员函数,则参数的个数比运算符的个数少一个,这里编译器会自动传入this指针作为第一个参数
	//this 始终占用运算符操作数的第一个位置
	bool operator == (const Date& d) { //底层接口 bool operator == (const Date* this,const Date& d)
		return _year == d._year  &&
			_month == d._month &&
			_day == d._day;
	}
	//赋值运算符重载函数:修改已经存在的对象的内容
	//如果连续赋值  Date&  如果不是连续赋值  void 就可以
	//如果不写编译器也会默认生成,默认拷贝也是字节拷贝,即浅拷贝
	//如果当前类中有资源,必须显示定义赋值运算符重载函数,完成深拷贝
	Date& operator=(const Date& d1) {
		//判断是否自己给自己赋值
		if (this != &d1) {
			_year = d1._year;
			_month = d1._month;
			_day = d1._day;
		}
		cout << " operator=(const Date& d1)" << endl;
		//返回当前调用函数本身
		return *this;
	}
	Date(const Date& d) {
		_year = d._year;
		_month = d._month;
		_day = d._day;
		cout << "(const Date& d)" << endl;
		cout << this->_year<<" " << this->_month<<" "<< this->_day<<" " << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
void test1() {
	Date d1(2020, 5, 21);
	Date d2(2021, 5, 21);
	//d2 = d1; //赋值运算符重载函数
	//d2.operator=(d1); //同上等价

	//=调用: 如果对象都存在,调用赋值运算符重载函数,如果左边对象不存在,调用拷贝构造函数

	Date d3(2018, 10, 2);
	d1 = d2 = d3;
	//连续赋值是从右向左
	d1.operator = (d2.operator=(d3));

	Date d4 = d3; //调用拷贝构造:d4不存在,用d3去创造d4,所以调用拷贝构造,而不是赋值.
}

int main() {
	//调用 operator
	//Date d1(2020, 5, 21);
	//Date d2(2020, 5, 21);
	//cout << (d1 == d2) << endl; //等价于d1.operator==(d2)
	//cout << d1.operator==(d2) << endl;

	test1();
	//调用isEmqual 函数进行证明
	//Date d1(2020, 5, 21);
	//Date d2(d1);

	//Date d3(2020, 3, 14);
	//cout << d1.isEqual(d2) << endl;
	//cout << d1.isEqual(d3) << endl;

	system("color A");
	system("pause");
	return 0;
}


*******日期类的实现:

#include <iostream>
using namespace  std;

class Date{

public:
	Date(int year=1,int month=1,int day=1) {
		if (year > 0 && month > 0 && month < 13 && day > 0 && day <= getMonthDay(year, month)) {
			_year = year;
			_month = month;
			_day = day;
		}
		else {
			cout << "日期不合法: " << year << " " << month << " " << day <<endl;
			cout << "重新设置日期" << endl;
			_year = 2020;
			_month = 1;
			_day = 1;
		}
	}

	int  getMonthDay(int year, int month) {
		static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = days[month];
		if (month ==2 && ((year % 4 == 0 && year % 100 != 0) || (year % 100 == 0))) {
			day += 1;
		}
		return day;
	}

	Date& operator+=(int day) {
		_day += day;
		while (_day > getMonthDay(_year, _month)) {
			月份进位
			_day -= getMonthDay(_year, _month);
			_month++;

			if (_month == 13) {
				_month = 1;
				_year++;
			}
		}
		return *this;
	}
	前置++
	Date& operator++() {
		return *this += 1;
	}
	后置++:返回++之前的值
	Date operator++(int) {
		将之前的值进行保存
		Date ret(*this); 
		*this += 1;
		return ret;
	}
	void PrintDate() {
		cout << _year << " " << _month << " " << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& _cout, const Date& date) {

	_cout << date._year << " " << date._month << " " << date._day << endl;
	return _cout;
}

void test1(){
	Date d(2020, 5, 23);
	d.PrintDate();
	d+=20;
	d.PrintDate();
	d++;
	cout << "前置++" << endl;
	cout << (++d) << endl;
	d.operator++();
	d.PrintDate();

	cout << "后置++" << endl;
	cout << (d++) << endl;
	d.operator++(0);
	d.PrintDate();


}

int main () {


	test1();
    system("color A");
    system ("pause");
    return 0;
}












