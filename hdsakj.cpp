//1.求1+2+3...+n要求不能使用乘除法,for,while,if,else,switch等关键字以及条件判定语句.

#include <iostream>
using namespace  std;

class A {

public:

	class Sum {
	public:
		//内部类直接访问外部类的私有成员
		Sum() {
			_sum += _num;
			++_num;
			cout << "Sun" << endl;
		}
	};

	int Sum_solution() {
		_sum = 0;
		_num = 1;
		Sum sumarr[10]; //调用n次Sum类的构造函数,创建Sum对象数组
		return _sum;
	}

	//private:
	static int _num;
	static int _sum;
};

int A::_num = 1;
int A::_sum = 0;

int main() {
	A s;
	int sum = s.Sum_solution();
	cout << A::_num << endl;
	cout << sum << endl;

	system("color A");
	system("pause");
	return 0;
}