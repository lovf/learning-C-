//��ֵ���������
//�ؼ���operator�������Ҫ���ص����������.
//����ԭ��: ����ֵ����operator������(�����б�)
//��Ϊ���Ա�����غ���ʱ,���βο������Ȳ�������Ŀ��1��Ա����.
//��������һ��Ĭ�ϵ��β�this,�޶�Ϊ��һ���β�.
//C++��5���������ص������:1.�����������:  :: 2.����������: ?: 3.�������: . 4.ָ���Ա��ָ��ָ�������:->*,.*
//5.Ԥ���������: # sizeof
//1.��������غ���:��ǿ����Ŀɶ���.2.��Ա���������ⶨ���ʹ�÷�ʽ����ͨ����һ��.3.����ֵoperator+��Ҫ���ص������
//4.��������غ�������ǳ�Ա����,�����ĸ������������Ҫ�ĸ�����һ��,������������Զ�����thisָ��.5.thisָ��ʼ��ռ��������������ĵ�һ��λ��.

//���������λ�ڳ�Ա������
//#include <iostream>
//using namespace std;
//
//
//class Date {
//
//public:
//	Date(int year = 1, int month = 1, int day = 1) {
//		 _year = year;
//		 _month = month;
//		 _day = month;
//	
//	}
//	bool operator == (const Date& d2) {
//	
//	return _year == d2._year && _month == d2._month && _day == d2._day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//void test() {
//	Date d1;
//	Date d2(2018,9,27);
//	cout << (d1 == d2) << endl;
//}
//int main() {
//	test();
//
//	system("pause");
//	return 0;
//}
//��������غ���λ�ڳ�Ա�����ⲿ

//#include <iostream>
//using namespace std;
//
//
//class Date {
//
//public:
//	Date(int year = 1, int month = 1, int day = 1) {
//		_year = year;
//		_month = month;
//		_day = month;
//
//	}
//	int _year;
//	int _month;
//	int _day;
//};
//
////�����ĸ������������Ҫ�ĸ���һ��
//bool operator == (const Date& d1, const Date& d2) {
//
//	return d1._year == d2._year && d1._month == d2._month && d1._day == d2._day;
//}
//void test() {
//	Date d1;
//	Date d2(2018, 9, 27);
//	cout << (d1 == d2) << endl;
//}
//int main() {
//	test();
//
//	system("pause");
//	return 0;
//}
//*****************************************************************************************************
//**��ֵ���������**
//��ֵ��������غ���:��һ������ȥ�޸���һ���Ѿ����ڵ�����,�޸�֮���������������һ��.
//1.����ͨ������Ƿ���Լ���ֵ,2.���������ֵ����ֵ����Ϊvoid 3.����ֵһ��Ϊ*this 4.������Ĭ�ϵ������Ϊ�ֽڿ���,��ǳ����.�������Դ��Ҫ����,��ô��Ҫ������ʾ����,������.
//***������ù��캯�����Ǹ�ֵ?
//�����ߵĶ������,�͵��ø������������.
//�����ߵĶ��󲻴���,�͵��ÿ������캯��.

#include <iostream>

using namespace std;

class Date {

public:
	Date(int year = 1,int month = 1,int day = 1) {
	
		_year = year;
		_month = month;
		_day = day;

	}

	Date& operator = (const Date& d) {
		if (this != &d) {
			_year = d._year;
	 		_month = d._month;
			_day = d._day;

		}
		return *this;
	}

	Date(const Date& d) {
		_year = d._year;
		_month = d._month;
		_day = d._day;
	
	
	}
	void play() {
	
		cout << _year << " " << _month << " " << _day << endl;
	
	}

private:

	int _year;
	int _month;
	int _day;
	
};


int main() {
	Date d2;
	Date d1(2008, 12, 3);
	d2 = d1;
	d2.play();
	system("pause");
	return 0;
}


































































































