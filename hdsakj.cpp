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

int main() {
	A s;
	int sum = s.Sum_solution();
	cout << A::_num << endl;
	cout << sum << endl;

	system("color A");
	system("pause");
	return 0;
}