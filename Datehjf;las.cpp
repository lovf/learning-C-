
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
	重点4:
	Date& operator+=(int day) {
		a+=-b-->a-=b;
		if (day<0)
			return *this -= -day;

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
	重点3:
	-=赋值运算符重载
	Date& operator-=(int day) {
		if (day < 0)
			return *this += (-day);
		_day -= day;
		判断_day是否为负值或者0,退位
		2020.5.24-30-->2020.5.-6--->月份退位--->+30--->2020.4.24
		while (_day < 0) {
		月份退位
			--_month;
		月份是否为负值或者0
			if (_month == 0) {
				_month = 12;
				年份退位
				--_year;
			}
			_day += getMonthDay(_year, _month);
		}
		return *this;
	}

	前置--
	Date& operator--() {
		return *this -= 1;
	}
	后置--
	Date operator--(int) {
		Date ret(*this); //Date ret = *this; 都是执行拷贝构造
		 *this -= 1;
		 return ret;
	}

	+,-运算符:不能修改操作数的内容
	c=a+b
	Date operator +(int day) {
		Date ret(*this);
		 ret += day;
		 return ret;
	}
	Date operator -(int day) {
		Date ret(*this);
		ret -= day;
		return ret;
	}
	重点1:
	等于
	bool operator==(const Date& date) {

		return _year == date._year &&
			   _month == date._month &&
			   _day == date._day;
	}
	重点2:
	bool operator>(const Date& date) {

		if (_year > date._year)
			return true;
		else if (_year == date._year) {
			if (_month > date._month)
				return true;
			else if (_month == date._month) {
				if (_day > date._day)
					return true;
			}
		}
		return false;
	}


	bool operator>=(const Date& date) {

		return (*this > date) || (*this == date);
	}

	bool operator<(const Date& date) {
		return !(*this >= date);
	}

	bool operator<=(const Date& date) {
		return !(*this > date);
	}


	bool operator!=(const Date& date) {
		return !(*this == date);
	}

	int operator-(Date& date) {

		Date d1(*this);
		Date d2(date);
		int num = 0;
		d1-d2
		if (d1 > d2) {
			while (d1 >d2) {
				--d1;
				++num;
			}
			return num;
		}
		else {
			d1<=d2
			while (d1 < d2) {
				++d1;
				++num;
			}
			return -num;
		}
	}


	/*Date operator-(Date& date) {


	}*/
	//取地址运算符重载
	//一般不需要显示定义
	Date* operator&() {
		return this;
	
	}
	const Date* operator&()  const{
		return this;

	}
	void PrintDate() { // PrintDate(Date* const this)
		cout << _year << " " << _month << " " << _day << endl;
		//可以修改内容
		//this->_year=100;
		//可以调用const成员函数, 读写无权限没被放大
	}

	//const 成员函数中的const修饰的为第一个参数,即this指针
	////const 成员函数内部不能修改成员变量的值
	void PrintDate()  const { // PrintDate(const Date* const this)
		cout << _year << " " << _month << " " << _day << endl;
		//不可以修改内容
		//this->_year=100;
		//++*this 不能调用非const成员函数,读写无权限不能被放大
	}

//private:
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
void test2(){
	Date d(2020, 5, 24);
	d.PrintDate();
	d -= 30;
	d.PrintDate();


	d -= -30;
	d.PrintDate();

	d -= 3650;
	d.PrintDate();
	d += -3650;
	d.PrintDate();
}
void test3() {
	Date d(2020, 5, 24);
	d.PrintDate();
	cout << d.operator +(20);
	cout << d.operator +=(20);
}

void test4() {

	Date d1(2020, 5, 25);
	Date d2(2020, 5, 25);
	Date d3(2020, 5, 26);
	Date d4(2020, 5, 23);
	cout << (d1 > d4) << endl;
	cout << (d1 < d4) << endl;
	cout << (d1 <= d4) << endl;
	cout << (d3 > d1) << endl;
	cout << (d1 >= d1) << endl;
	cout << (d1 == d2) << endl;
	cout << (d1 != d2) << endl;

}

void test5() {
	Date d1(2020, 5, 25);
	Date d2 = d1 + 3650;
	cout << (d1 - d2) << endl;
	cout << (d2 - d1) << endl;

	Date d3 = d2 + 189;
	cout << (d2 - d3) << endl;
	cout << (d3 - d2) << endl;
}

void test6() {
	Date d1(2020, 5, 25);
	const Date d2(d1);
	d1.PrintDate(); //非const对象(即可读可写)  调用非const 成员函数 也可以调用 const 成员函数 原因:读写权限没有被放大
	d2.PrintDate();//const对象(可读) 调用const 成员函数,不能调用非const 成员函数  原因:读写权限不能被放大
}
void test7() {

	Date d1;
	const Date d2;

	Date* pd1=&d1; //等价于 d1.operator&() const;
	const Date* pd2 = &d2;//等价于 d2.operator&();

}

int main () {
    //test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	test7();
    system("color A");
    system ("pause");
    return 0;
}
