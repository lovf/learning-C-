//��̸���캯��:
//1.1 ���캯����ֵ
#include <iostream>
using namespace std;

class Date {

public:
	Date(int year,int month,int day) {+
		//���ڳ�ʼ����ֵ
		_year = year;
		_month = month;
		_day = day;
	}

	void play() {
		cout << _year << " " << _month << " " << _day << endl;
	}
private://��Ա�������������ĵط�
	int _year;
	int _month;
	int _day;
};


int main() {

	Date d(2020,5,21);
	d.play();
	system("pause");
	return 0;
}
//************************************************************************************************************
//1.2��ʼ���б�
//��ʼ���б�: ��һ��ð�ſ�ʼ,�������Զ��Ÿ�������,ÿһ��"��Ա����"����ŵ������еĳ�ʼֵ���߱��ʽ.
//1.��ʼ���б��Ƕ����Ա����ĵط�.2.ÿһ����Ա�����ڳ�ʼ���б���ֻ�ܳ���һ��
//2.���а������³�Ա,����ŵ���ʼ���б��λ�ý��г�ʼ��.(1)���ó�Ա����(2)const��Ա����(3)�Զ������ͳ�Ա����
//3.��Ա���������������Ĵ�����ǳ�ʼ�����б��еĳ�ʼ��˳��.(��ʼ���б��е�˳���������˳�򱣳�һ��)
//��ʼ���б��ʹ��

#include <iostream>
using namespace std;

class Date {

public:
	Date(int year=1,int month=1,int day=1) //���캯��
		: _year(year) //��ʼ���б� �Գ�Ա���г�ʼ��
		, _month(month)
		, _day(day)
	{}
	void print() {
		cout << _year << " " << _month << " " << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

void test() {
	Date d(2020,5,21);
	d.print();
}

int main() {
	test();
	system("pause");
	return 0;
}

//��ʼ���б��е�˳���������˳�򱣳�һ��
#include <iostream>
using namespace std;

class A {

public :
	//���캯��:
	//��ʼ���б�

	A(int a)
		:_a1(a)
		,_a2(_a2)
	{}
	void print() {
		cout << _a1 << " " << _a2 << endl;
	}

private:
	int _a1;
	int _a2;
	static int _cnt;
};

void test() {
	A aa(1);//aa = 1;
	aa.print();

}

int main() {
	test();
	system("pause");
	return 0;
}
//1.3 explicit�ؼ���  ��ֹ�������캯������ʽ����ת��.