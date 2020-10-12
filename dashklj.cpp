��������غ���:

********************1.�е��������غ���*****************
1.operator �����ڳ�Ա���������������ζ���
2.operator �����ڳ�Ա���������������ζ���
3.������������غ������ʹ��

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
	//��������غ���: ����������,�����ʹ�÷�ʽ����ͨ����һ��
	//operator + ��Ҫ���ص������(�����б�)
	//��������غ�������ǳ�Ա����,������ĸ�����������ĸ�����һ��,������������Զ�����thisָ����Ϊ��һ������
	//this ʼ��ռ��������������ĵ�һ��λ��
	bool operator == (const Date& d) { //�ײ�ӿ� bool operator == (const Date* this,const Date& d)
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
	//���� operator
	Date d1(2020, 5, 21);
	Date d2(2020, 5, 21);
	cout << (d1 == d2) << endl; //�ȼ���d1.operator==(d2)
	cout << d1.operator==(d2) << endl;

	//����isEmqual ��������֤��
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

//��operator����������,�ǲ����ٵ�
bool operator == (const Date& d1, const Date& d) { 
	return d1._year == d._year  &&
		d1._month == d._month &&
		d1._day == d._day;
}
//�����������غ���
ostream& operator<<(ostream& _cout, const Date& date) {

	_cout << date._year << " " << date._month << " " << date._day << endl;
	return _cout;
}

int main() {
	//���� operator
	Date d1(2020, 5, 21);
	Date d2(2020, 5, 21);
	cout << (d1 == d2) << endl;//�еȺ���

	cout << d1 << endl;

	system("color A");
	system("pause");
	return 0;
}
***********************2.��ֵ��������غ���****************************

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
	//��������غ���: ����������,�����ʹ�÷�ʽ����ͨ����һ��
	//operator + ��Ҫ���ص������(�����б�)
	//��������غ�������ǳ�Ա����,������ĸ�����������ĸ�����һ��,������������Զ�����thisָ����Ϊ��һ������
	//this ʼ��ռ��������������ĵ�һ��λ��
	bool operator == (const Date& d) { //�ײ�ӿ� bool operator == (const Date* this,const Date& d)
		return _year == d._year  &&
			_month == d._month &&
			_day == d._day;
	}
	//��ֵ��������غ���:�޸��Ѿ����ڵĶ��������
	//���������ֵ  Date&  �������������ֵ  void �Ϳ���
	//�����д������Ҳ��Ĭ������,Ĭ�Ͽ���Ҳ���ֽڿ���,��ǳ����
	//�����ǰ��������Դ,������ʾ���帳ֵ��������غ���,������
	Date& operator=(const Date& d1) {
		//�ж��Ƿ��Լ����Լ���ֵ
		if (this != &d1) {
			_year = d1._year;
			_month = d1._month;
			_day = d1._day;
		}
		cout << " operator=(const Date& d1)" << endl;
		//���ص�ǰ���ú�������
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
	//d2 = d1; //��ֵ��������غ���
	//d2.operator=(d1); //ͬ�ϵȼ�

	//=����: ������󶼴���,���ø�ֵ��������غ���,�����߶��󲻴���,���ÿ������캯��

	Date d3(2018, 10, 2);
	d1 = d2 = d3;
	//������ֵ�Ǵ�������
	d1.operator = (d2.operator=(d3));

	Date d4 = d3; //���ÿ�������:d4������,��d3ȥ����d4,���Ե��ÿ�������,�����Ǹ�ֵ.
}

int main() {
	//���� operator
	//Date d1(2020, 5, 21);
	//Date d2(2020, 5, 21);
	//cout << (d1 == d2) << endl; //�ȼ���d1.operator==(d2)
	//cout << d1.operator==(d2) << endl;

	test1();
	//����isEmqual ��������֤��
	//Date d1(2020, 5, 21);
	//Date d2(d1);

	//Date d3(2020, 3, 14);
	//cout << d1.isEqual(d2) << endl;
	//cout << d1.isEqual(d3) << endl;

	system("color A");
	system("pause");
	return 0;
}


*******�������ʵ��:

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

	Date& operator+=(int day) {
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
	cout << "ǰ��++" << endl;
	cout << (++d) << endl;
	d.operator++();
	d.PrintDate();

	cout << "����++" << endl;
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












