1.命名空间:
//1>.第一种命名方式 命名空间+:: 成员
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

2>.第二种命名方式 使用using + 命名空间+:: 成员
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
3>.第三种命名方式: 
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

//C++的输入输出:
字符串的输出
#include <iostream>
//using namespace std;

int main () {
	int a = 10;
	char* p = "1234"; //常量字符串
	int* pa = &a;
	std::cout << pa << std::endl;//非字符串指针输出地址
 	std::cout << p << std::endl;//字符串指针输出内容
	//cout << p << endl;

	system("pause");
    return 0;
}


//缺省参数:给参数定义一个默认值,实际使用时如果没有传参,对应的形参就使用默认值.
#include <iostream>
using namespace  std;

//全缺省参数
void func1(int a=2,int b=2,int c=2) {

	cout << a << b << c << endl;
}
//全缺省参数: 部分参数有缺省值  (必须从右向左依次连续赋值,中间不能有间隔) void func2(int a=1 , int b = 2, int c)  不对
                                                                // void func2(int a , int b, int c = 2)  不对

//缺省值只能出现在声明或组合定义的时候出现
//声明
void func2(int a, int b , int c);
//定义
void func2(int a=100, int b = 200, int c = 300) {
	cout << a << b << c << endl;

}

void func2(int a, int b = 2, int c = 3) {
	cout << a << b << c << endl;
}

int main () {


	//参数接收的顺序:从左向右
	func1(1, 2, 3);  //传参是从左向右 ,缺省值设置是从右向左
	func1();
	func1(100, 200, 300);


    system("color A");
    system ("pause");
    return 0;
}

//函数重载:函数名相同,参数不同,且在同一个作用域内. C++支持
//参数不同包括: 类型,顺序,个数.
//仅仅是函数值返回类型不同不能构成函数重载



引用: 
使用场景: 1.做参数
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
	cout << "交换之前: " << " ";
	cout << " a = " << a << " ";
	cout << " b = "<< b << endl;

	Swap(a, b);
	cout << "交换之后: " << " ";
	cout << " a = " << a << " ";
	cout << " b = " << b << endl;
    system("color A");
    system ("pause");
    return 0;
}
2.做返回值类型


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
引用的效率要比传值的效率要高
