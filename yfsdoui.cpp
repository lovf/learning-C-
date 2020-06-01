
//************拷贝构造函数******

//用一个对象创键一个新的对象,新对象的内容和当前对象的内容相同.
//1.一种构造函数的重载形式. 2.参数只有一个必须是引用类型.3.编译器默认生成的拷贝构造为字节拷贝,即浅拷贝.如果有资源需要拷贝,需要显示定义,完成深拷贝.
//特征如下:
//1.拷贝构造函数是一种构造函数的重载形式.
//2.拷贝构造函数的参数只有一个且必须使用引用传参,
//3.若未显示定义,系统生成的默认拷贝构造函数.(默认拷贝的对象按照字节序完成拷贝,这种弄拷贝叫做浅拷贝,
//只拷贝对象的模型,不拷贝对象的资源)
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
	d1.play(); //等于实现了将d1的值传给d2;
	Date d2(d1);
	d2.play();

}
int main() {


	test();
	system("pause");
	return 0;
}


