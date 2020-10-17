//�������ʵ��:

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
			cout << "��������" << year << " " << month << " " << day << endl;
			cout << "��������" << endl;
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
		//0.���ڼ���С��0
		if (day < 0)   
			return *this -= (-day);//����һ���������ڼ�ȥһ������
		_day += day;
		//1.�ж����֮��������Ƿ���ڱ��µ�����
		if (_day > getDay(_year, _month)) {
		//2.���±��µ�����
			_day -= getDay(_year, _month);
			//3.�·ݽ�λ
			++_month;
			if (_month == 13) {
				//��ݽ�λ
				++_year;
				_month = 1;
			}
		}
		return *this;
	}
	Date& operator-=(int day) {
		//0.���ж��������ڵ�����
		if (day < 0)
			return *this += (-day);//���ڸ����������+=�����������

		_day -= day;
		//1.������֮��������Ƿ�Ϊ��ֵ
		while (_day <= 0) {
		   //2.�·���λ
			--_month;
			if (_month == 0) {
				//3.�����λ
				--_year;
				_month = 12;
			}
			//4.������λ֮�������
			_day += getDay(_year, _month);
		}
		return *this;
	}

	//����+= ,-= ��ֵ��������ص��ܽ�
	//+= 0.�ж���ӵ������Ƿ�С��0 1.���µ��µ�����2.�ж����µ�����>����Ӧ�õ�����ʱ3.�����·ݵĽ�λ.4.�·�>=13ʱ������ݵĽ�λ
	//-= 0.�ж���ӵ������Ƿ�С��0 1.�Ƚ����·ݵ���λ2.�ж��·��Ƿ���λ��0 3.������λ��0,������ݵ���λ4.���µ��µ�����
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
	//ǰ��++
	Date& operator++() {
		return *this += 1;
	}
	//����++
	//����++֮ǰ��ֵ
	Date operator++(int) {
		//��֮ǰ��ֵ�Ƚ��п���
		Date ret(*this);
		 *this += 1;
		 return ret;
	}
	//ǰ��--
	Date& operator--() {
		return *this -= 1;
	}
	//����--
	//����--֮ǰ��ֵ
	Date operator--(int) {
		//��֮ǰ��ֵ�Ƚ��п���
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
//+= -= ��������� operator+=(int day)  operator-=(int day)
void test1() {
	Date d(2020, 3, 21);
	d.PrintDate();

	//d += 20;
	//d.PrintDate();
	
	d -= 30;
	d.PrintDate();
}

//�Ӽ�������������� operator+(int day)  operator-(int day)
void test2() {
	Date d(2020, 2, 20);
	d.PrintDate();

	cout << d.operator+(20) << endl;

	cout << d.operator-(20) << endl;
}


// ǰ��++ ����++
void test3() {
	Date d(2020, 2, 20);
	cout << "ִ�в���֮ǰ��ֵ" << endl;
	d.PrintDate();

	cout << "ǰ��++" << endl;
	cout << (++d) << endl;
	cout << d.operator++() << endl;

	cout << "����++" << endl;
	cout << (d++) << endl;
	//d.operator++(0);
	//d.PrintDate();
	cout << d.operator++(0) << endl;

}
void test4() {
	Date d(2020, 2, 20);
	cout << "ִ�в���֮ǰ��ֵ" << endl;
	d.PrintDate();

	cout << "ǰ��--" << endl;
	cout << (--d) << endl;
	cout << d.operator--() << endl;

	cout << "����--" << endl;
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

//7.const ��Ա

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

	//void PrintDate() { //�ȼ��� PrintDate(Date& const this)
	//	cout << _year << " " << _month << " " << _day << endl;
	//}
	void PrintDate() const { // �ȼ���PrintDate(const Date& const this)
		cout << _year << " " << _month << " " << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main () {
	//1. �� const������ܵ��÷�const��Ա����,Ҳ�ܵ���const��Ա����  ��const��Ա�������ܶ�Ҳ��д
    Date d1(2020, 3, 21);
	d1.PrintDate();
	//2.const����ֻ�ܵ���const��Ա����   const��Ա����ֻ�ܶ�.
	//3.������const����ȥ���÷�const��Ա�����ᵼ�¶�дȨ��Ȩ�ޱ��Ŵ�.
	//const Date d2(2020, 3, 1); 
	//d2.PrintDate();
	//4.�ǳ�Ա��������ʹ��const����,��Ϊ��const��Ա����û��thisָ��.
	//5.const���γ�Ա�����ĵ�һ��������thisָ��.
	//6.ԭ���϶�дȨ���ǲ��ܱ��Ŵ��.
    system("color A");
    system ("pause");
    return 0;
}
//8.ȡ��ַ��constȡ��ַ���������

#include <iostream>
using namespace  std;

class Date{

public:
	Date(int year = 1, int month = 1, int day = 1) {
		_year = year;
		_month = month;
		_day = day;
	}
	//��const����
	Date* operator&() {
	
		return this;
	}
	//const����
	const Date* operator&()  const {

		return this;
	}

	void PrintDate() const { // �ȼ���PrintDate(const Date& const this)
		cout << _year << " " << _month << " " << _day << endl;
	}
	//�������������������Ҫ����,ʹ�ñ�����Ĭ��ȡ��ַ���ؼ���,ֻ�������������²���Ҫ����,�������ñ��˻�ȡ�����ָ������.
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


��Ͷ�����ƪ(��)

////1.��̸���캯��
////1.1��ֵ�ͳ�ʼ��

#include <iostream>
using namespace  std;

class Date {
public:
	//����ǶԶ���ĸ�ֵ�����ǳ�ʼ��
	//���캯���е����ֻ�ܽ�����Ϊ�Ǹ���ֵ,��������Ϊ��ʼ��,�����ĳ��°����ڳ�ʼ���б��н��е�,��ʼ��һ��,�����캯�����Խ��ж�θ�ֵ.
	/*Date(int year = 1, int month = 1, int day = 1)  {
		_year = year;
		_month = month;
		_day = day;
		}*/
	//���ó�ʼ���б��
	Date(int year = 1, int month = 1, int day = 1,int ref,int b) 
	//��ʼ���б�
	:_year(year)
	,_month(month)
	,_day(day)
	,_ref(ref)
	, _b(b)
	//��ֵ����
	{
		_year = year;
		_month = month;
		_day = day;
	}
	//��ӡ
	void PrintDate() const { // �ȼ���PrintDate(const Date& const this)
		cout << _year << " " << _month << " " << _day << endl;
	}

	
private:
	//���������������ʱ��ֵ,�������ȿ��ǹ��캯���еĲ���
	int _year;
	int _month;
	int _day;
	int& _ref; //���ó�Ա�����ڳ�ʼ���б���г�ʼ��
	const int _b;//const ��Ա�����ڳ�ʼ���б���г�ʼ��
};


int main () {
	Date d(2020, 3, 21, 4, 23);
	d.PrintDate();
	

    system("color A");
    system ("pause");
    return 0;
}

���ڳ�ʼ���б���Ҫע��:
1.��ʼ���б��еĳ�Աֻ�ܳ�ʼ��һ��
2.���о������³�Ա������ڳ�ʼ���б��н��г�ʼ��
1>.���ñ���
2>const��Ա����
3>�Զ������ͳ�Ա
3.�����Զ����Ա,����ڳ�ʼ���б��н��г�ʼ��,��ʹ���ٳ�ʼ���б��н�����ʾ��ʾ��ʼ��,������Ҳ���ڳ�ʼ���б����Զ������Զ����ԱԱ�������г�ʼ��
4.��Ա�����������еĴ���������ڳ�ʼ���б��еĳ�ʼ����˳��,���ʼ���б��е��Ⱥ�����޹�(���������˳��ͳ�ʼ����˳��һ��)

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
	������˳����_a2,_a1,����ڶ���ĵط������_a2��ʼ��,�����_a1�ĳ�ʼ��
	ע��: ����������˳��ͳ�ʼ����˳�򱣳�һ��
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
