1.�����ռ�:
//1>.��һ��������ʽ �����ռ�+:: ��Ա
#include <iostream>
namespace  N {
	int Add(int left, int right) {
		return left + right;
	}
}

int main () {


	std:: cout << N::Add(10, 20) << std::endl;
	system("color A");
    system ("pause");
    return 0;
}

2>.�ڶ���������ʽ ʹ��using + �����ռ�+:: ��Ա
#include <iostream>
namespace  N {
	int Add(int left, int right) {
		return left + right;
	}
}
using namespace ::N;
int main() {


	std::cout << N::Add(10, 20) << std::endl;
	system("color A");
	system("pause");
	return 0;
}
3>.������������ʽ: 
#include <iostream>
namespace  N {
	int Add(int left, int right) {
		return left + right;
	}
}
using namespace N;
int main() {


	std::cout << N::Add(10, 20) << std::endl;
	system("color A");
	system("pause");
	return 0;
}

//C++���������:
�ַ��������
#include <iostream>
//using namespace std;

int main () {
	int a = 10;
	char* p = "1234"; //�����ַ���
	int* pa = &a;
	std::cout << pa << std::endl;//���ַ���ָ�������ַ
 	std::cout << p << std::endl;//�ַ���ָ���������
	//cout << p << endl;

	system("pause");
    return 0;
}


//ȱʡ����:����������һ��Ĭ��ֵ,ʵ��ʹ��ʱ���û�д���,��Ӧ���βξ�ʹ��Ĭ��ֵ.
#include <iostream>
using namespace  std;

//ȫȱʡ����
void func1(int a=2,int b=2,int c=2) {

	cout << a << b << c << endl;
}
//ȫȱʡ����: ���ֲ�����ȱʡֵ  (���������������������ֵ,�м䲻���м��) void func2(int a=1 , int b = 2, int c)  ����
                                                                // void func2(int a , int b, int c = 2)  ����

//ȱʡֵֻ�ܳ�������������϶����ʱ�����
//����
void func2(int a, int b , int c);
//����
void func2(int a=100, int b = 200, int c = 300) {
	cout << a << b << c << endl;

}

void func2(int a, int b = 2, int c = 3) {
	cout << a << b << c << endl;
}

int main () {


	//�������յ�˳��:��������
	func1(1, 2, 3);  //�����Ǵ������� ,ȱʡֵ�����Ǵ�������
	func1();
	func1(100, 200, 300);


    system("color A");
    system ("pause");
    return 0;
}

//��������:��������ͬ,������ͬ,����ͬһ����������. C++֧��
//������ͬ����: ����,˳��,����.
//�����Ǻ���ֵ�������Ͳ�ͬ���ܹ��ɺ�������



����: 
ʹ�ó���: 1.������
#include <iostream>
using namespace  std;

void Swap(int& left, int& right) {
	int tmp = left;
	left = right;
	right = tmp;
}
//void Swap1(int left, int right) {
//	int tmp = left;
//	left = right;
//	right = tmp;
//}


int main () {
	int a = 10;
	int b = 20;
	cout << "����֮ǰ: " << " ";
	cout << " a = " << a << " ";
	cout << " b = "<< b << endl;

	Swap(a, b);
	cout << "����֮��: " << " ";
	cout << " a = " << a << " ";
	cout << " b = " << b << endl;
    system("color A");
    system ("pause");
    return 0;
}
2.������ֵ����


#include <iostream>
using namespace  std;

int& Add(int a, int b) {
	int c = a + b;
	return c;
}

int main () {
	int& ret = Add(10, 20);
	cout << "Add(10, 20) is: " << ret << endl;
	cout <<"Add(1, 2) is:"<< Add(1, 2) << endl;
	

    system("color A");
    system ("pause");
    return 0;
}
���õ�Ч��Ҫ�ȴ�ֵ��Ч��Ҫ��
