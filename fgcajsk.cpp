//********��Ԫ********
//1.��Ԫ����
//��Ԫ��������ֱ�ӷ������˽�г�Ա,���Ƕ������������ͨ����,�������κ���,����Ҫ���ڲ�����,����ʱ���friend,-

#include <iostream>
using namespace std;

class Date {

	friend ostream& operator<<(ostream& _cout, const Date& d);
	friend istream& operator>>(istream& _cin,  Date& d);

public:
	Date(int year = 1,int month = 1,int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}
private:
	int _year;
	int _month;
	int _day;

};
//�����
ostream& operator << (ostream& _cout, const Date& d) {
	_cout << d._year<< d._month<< d._day << endl;

	return _cout;
}
//������
istream& operator >> (istream& _cin, Date& d) {
   _cin >> d._year >> d._month >> d._day;
	return _cin;
}

int main() {

	Date d;
	cin >> d;
	cout << d << endl;
	system("pause");
	return 0;
}
//��Ԫ��������ֱ�ӷ������˽�г�Ա,���Ƕ������������ͨ����,�������κ���,����Ҫ�����н����������friend �ؼ���
//1.��Ԫ��������ֱ�ӷ������˽�г�Ա,��������ĳ�Ա����.
//2.��Ԫ����������const����,
//3.��Ԫ��������������κεط�����,����������޶�������.
//4.��Ԫ�����ĵ�������ͨ�����ĵ�����ͬ.

#include <iostream>
using namespace std;

class Date {
	friend void  test();
public:
	Date(int year=1,int month=1,int day=1) //���캯��
		: _year(year) //��ʼ���б� �Գ�Ա���г�ʼ��
		, _month(month)
		, _day(day)
	{}
private:
	int _year;
	int _month;
	int _day;
};
//��Ԫ��������ֱ�ӷ���˽�г�Ա
void  test() {
	Date d(2020,5,21);
	cout << d._year << " " << d._month << " " << d._day << endl; 
}
int main() {
	test();
	system("pause");
	return 0;
}
//��Ԫ��
//��Ԫ������г�Ա��������������һ����ĳ�Ա����,�����Է�����һ����ķǹ��г�Ա.
//��Ԫ��Ĺ�ϵ�ǵ����,�����н�����.
//��Ԫ��ϵ���ܴ���