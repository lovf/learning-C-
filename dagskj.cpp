//2.static ��Ա

//������ʱ����ֵ:
//
//#include <iostream>
//using namespace  std;
//
//class A {
//
//public:
//	A() {
//		++_scout;
//	}
//	A(const A& t) {
//		++_scout;
//	}
//	static int  GetScout() {
//		return _scout;
//	
//	}
//
//private:
//	static int _scout;
//};
//int A::_scout = 0;
//void test1() {
//	cout << A::GetScout() << endl;
//	A a1, a2; //���ù��캯��
//	A a3(a1);  //���ÿ������캯��
//	cout << a3.GetScout() << endl;
//	cout << A::GetScout() << endl;
//}
//int main () {
//
//	test1();
//    system("color A");
//    system ("pause");
//    return 0;
//}
//��Ԫ:��Ϊ��Ԫ�����Ԫ����
//cout���������������thisָ������ռ��һ��������λ��,thisָ��ʼ��ռ�õ��ǵ�һ����������λ��Ҳ�������������λ��.
//
////���粻ʹ����Ԫ�����ı仯  d << cout
//#include <iostream>
//using namespace  std;
//
//
//class Date{
//
//public:
//	Date(int year, int month, int day)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{}
//	//���������
//	ostream& operator<<(ostream& _cout) {
//		_cout << _year << " " << _month << " " << _day << endl;
//		return _cout;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//void test1() {
//	Date d(2020, 3, 21);
//	d << cout; //��Ϊthisָ��ʼ���ڲ����ĵ�һ��λ��                                                                    
//}
//int main () {
//	test1();
//    system("color A");
//    system ("pause");
//    return 0;
//}
//��Ԫ����������
////��Ԫ����:���һ����������������ⲿ,������ȻҪ����,��ô�ͱ����������Ԫ��
//#include <iostream>
//using namespace  std;
//
//
//class Date{
//
//	friend ostream& operator<<(ostream& _cout, const Date& d);  //��Ԫ������������������κεط�,���ܷ����޶������޶�
//	friend istream& operator>>(istream& _cin, Date& d);//��Ԫ������������������κεط�,���ܷ����޶������޶�
//
//public:
//	Date(int year=1, int month=1, int day=1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
////����������
//istream& operator>>(istream& _cin, Date& d) {  //��������this�϶�ռ��һ��λ��
//	_cin >> d._year >> d._month >> d._day;
//	return _cin;
//}
//
////ֱ�ӽ���������Ͷ�����������ô���Բ��ܷ������ڵĲ���
//ostream& operator<<(ostream& _cout, const Date& d) {  //��������this�϶�ռ��һ��λ��
//	_cout << d._year << " " << d._month << " " << d._day << endl;
//	return _cout;
//}
//
//void test1() {
//	Date d;
//	cin >> d; //���� ����
//	//Date d(2020, 3, 21);
//	cout << d << endl; // ������� ��Ϊthisָ��ʼ���ڲ����ĵ�һ��λ��                                                                    
//}
//
//int main() {
//	test1();
//	system("color A");
//	system("pause");
//	return 0;
//}
//��Ԫ��:
//1.��Ԫ������г�Ա������������Ϊ��һ�������Ԫ����,�����Է�����һ�����еķǹ��г�Ա.
//2.��Ĺ�ϵ�ǵ����,�����н�����\
//3.��Ԫ��ϵ���ܴ���
//�ڲ���:
//�ڲ�����Ⱦ����Ϊ�ⲿ�����Ԫ����

//6.��ϰ��:
//1.��1+2+3...+nҪ����ʹ�ó˳���,for,while,if,else,switch�ȹؼ����Լ������ж����.

#include <iostream>
using namespace  std;

class A {

public:

	class Sum {
	public:
		//�ڲ���ֱ�ӷ����ⲿ���˽�г�Ա
		Sum() {
			_sum += _num;
			++_num;
			cout << "Sun" << endl;
		}
	};

	int Sum_solution() {
		_sum = 0;
		_num = 1;
		Sum sumarr[10]; //����n��Sum��Ĺ��캯��,����Sum��������
		return _sum;
	}

//private:
	static int _num;
	static int _sum;
};

int A::_num = 1;
int A::_sum = 0;

int main () {
	A s;
	int sum = s.Sum_solution();
	cout << A :: _num << endl;
	cout << sum << endl;

    system("color A");
    system ("pause");
    return 0;
}	

//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//
//
//int sumNums(int n){
//	return (int)(pow(n, 2) + n) >> 1;
//}
//int main () {
//
//    system("color A");
//    system ("pause");
//    return 0;
//}


















