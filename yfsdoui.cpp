
//************�������캯��******

//��һ�����󴴼�һ���µĶ���,�¶�������ݺ͵�ǰ�����������ͬ.
//1.һ�ֹ��캯����������ʽ. 2.����ֻ��һ����������������.3.������Ĭ�����ɵĿ�������Ϊ�ֽڿ���,��ǳ����.�������Դ��Ҫ����,��Ҫ��ʾ����,������.
//��������:
//1.�������캯����һ�ֹ��캯����������ʽ.
//2.�������캯���Ĳ���ֻ��һ���ұ���ʹ�����ô���,
//3.��δ��ʾ����,ϵͳ���ɵ�Ĭ�Ͽ������캯��.(Ĭ�Ͽ����Ķ������ֽ�����ɿ���,����Ū��������ǳ����,
//ֻ���������ģ��,�������������Դ)
#include <iostream>
using namespace std;

class Date {
public:
	Date(int year, int month, int day) {
		_year = year;
		_month = month;
		_day = day;
	}
	void play() {

		cout << _year << " " << _month << " " << _day << endl;

	}
	/*Date(const Date& d) {
	_year = d._year;
	_month = d._month;
	_day = d._day;
	}*/
private:
	int _year;
	int _month;
	int _day;
};

void test() {
	Date d1(2020, 5, 21);
	d1.play(); //����ʵ���˽�d1��ֵ����d2;
	Date d2(d1);
	d2.play();

}
int main() {


	test();
	system("pause");
	return 0;
}


