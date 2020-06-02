//////日期类的实现
//////
#include <iostream>
using namespace std;


class Date {
public:
	Date(int year = 1, int month = 1, int day = 1) {
		if (year > 0 && month > 0 && month < 13 && day > 0 && day <= getMonthday(year, month)) {
			_year = year;
			_month = month;
			_day = day;
		}  else {
			cout << "日期不合法: " << year<<" " << month <<" "<< day << endl;
			cout << "重置默认值: " << "2000-1-1" << endl;
			_year = 2000;
			_month = 1;
			_day = 1;
		}
	}
	
	int	getMonthday(int year, int month) {
		static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = days[month];
		if (month == 2 && (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)))
			++day;
		return day;
	}
	Date& operator += (int day) {
		_day += day;
		while (_day > getMonthday(_year, _month)) {
			//减去当月多余的天数
			_day -= getMonthday(_year, _month);
			++_month;
			if (_month == 13) {
				_month = 1;
				_year++;
			}
		}
		return *this;
	}





	void PrintD() {

		cout << _year << " " << _month << " " << _day << endl;

	}
private:
	int _year;
	int _month;
	int _day;
};

void test1() {
	Date d1(2020, 12, 6);
	d1.PrintD();
	d1 += 60;
	d1.PrintD();

	Date d2(2020, 5, 1);
	d2.PrintD();
	d2 += 20;
	d2.PrintD();

}


int main() {
	test1();

	system("pause");
	return 0;
}








