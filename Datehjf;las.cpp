
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
			cout << "���ڲ��Ϸ�: " << year << " " << month << " " << day <<endl;
			cout << "������������" << endl;
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
	�ص�4:
	Date& operator+=(int day) {
		a+=-b-->a-=b;
		if (day<0)
			return *this -= -day;

		_day += day;
		while (_day > getMonthDay(_year, _month)) {
			�·ݽ�λ
			_day -= getMonthDay(_year, _month);
			_month++;

			if (_month == 13) {
				_month = 1;
				_year++;
			}
		}
		return *this;
	}
	ǰ��++
	Date& operator++() {
		return *this += 1;
	}
	����++:����++֮ǰ��ֵ
	Date operator++(int) {
		��֮ǰ��ֵ���б���
		Date ret(*this);
		*this += 1;
		return ret;
	}
	�ص�3:
	-=��ֵ���������
	Date& operator-=(int day) {
		if (day < 0)
			return *this += (-day);
		_day -= day;
		�ж�_day�Ƿ�Ϊ��ֵ����0,��λ
		2020.5.24-30-->2020.5.-6--->�·���λ--->+30--->2020.4.24
		while (_day < 0) {
		�·���λ
			--_month;
		�·��Ƿ�Ϊ��ֵ����0
			if (_month == 0) {
				_month = 12;
				�����λ
				--_year;
			}
			_day += getMonthDay(_year, _month);
		}
		return *this;
	}

	ǰ��--
	Date& operator--() {
		return *this -= 1;
	}
	����--
	Date operator--(int) {
		Date ret(*this); //Date ret = *this; ����ִ�п�������
		 *this -= 1;
		 return ret;
	}

	+,-�����:�����޸Ĳ�����������
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
	�ص�1:
	����
	bool operator==(const Date& date) {

		return _year == date._year &&
			   _month == date._month &&
			   _day == date._day;
	}
	�ص�2:
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
	//ȡ��ַ���������
	//һ�㲻��Ҫ��ʾ����
	Date* operator&() {
		return this;
	
	}
	const Date* operator&()  const{
		return this;

	}
	void PrintDate() { // PrintDate(Date* const this)
		cout << _year << " " << _month << " " << _day << endl;
		//�����޸�����
		//this->_year=100;
		//���Ե���const��Ա����, ��д��Ȩ��û���Ŵ�
	}

	//const ��Ա�����е�const���ε�Ϊ��һ������,��thisָ��
	////const ��Ա�����ڲ������޸ĳ�Ա������ֵ
	void PrintDate()  const { // PrintDate(const Date* const this)
		cout << _year << " " << _month << " " << _day << endl;
		//�������޸�����
		//this->_year=100;
		//++*this ���ܵ��÷�const��Ա����,��д��Ȩ�޲��ܱ��Ŵ�
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
	cout << "ǰ��++" << endl;
	cout << (++d) << endl;
	d.operator++();
	d.PrintDate();

	cout << "����++" << endl;
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
	d1.PrintDate(); //��const����(���ɶ���д)  ���÷�const ��Ա���� Ҳ���Ե��� const ��Ա���� ԭ��:��дȨ��û�б��Ŵ�
	d2.PrintDate();//const����(�ɶ�) ����const ��Ա����,���ܵ��÷�const ��Ա����  ԭ��:��дȨ�޲��ܱ��Ŵ�
}
void test7() {

	Date d1;
	const Date d2;

	Date* pd1=&d1; //�ȼ��� d1.operator&() const;
	const Date* pd2 = &d2;//�ȼ��� d2.operator&();

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
