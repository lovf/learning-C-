////string 类对象的容量操作
//
#include <iostream>
using namespace std;
#include <string>

void test() {
	string str("012345");
	cout << str.size() << endl;
	cout << str.length() << endl;
	cout << str. capacity() << endl;
	cout << str << endl;
//将str中的字符串清零,注意清空只是将size清0,不改变底层空间的大小.
	str.clear();
	cout << str.size() << endl;
	cout << str.capacity() << endl;
//将str中有效字符个数增加到10个,多出的位置用'a'补上.
	str.resize(10,'a');
	cout << str.size() << endl;
	cout << str.capacity() << endl;
	cout << str << endl;
//将str中有效字符增加到15个,多出的位置应'b'进行补
	str.resize(15,'b');
	cout << str.size() << endl;
	cout << str.capacity() << endl;
	cout << str << endl;
}
int main() {
	test();
	system("pause");
	return 0;
}
//*************************************************************************************************************

#include <iostream>
using namespace std;
#include <string>

void test() {
	string str;
	//测试reverse是否会改变string中的有效元素个数.reserve改变的只是容量比改变size和内容
	str.reserve(100);
	cout << str.size() << endl;
	cout << str.capacity() << endl;
	//测试reserve参数小于string的底层空间大小,是否会将空间缩小
	str.reserve(20);
	cout << str.size() << endl;
	cout << str.capacity() << endl;
}

int main() {
	test();
	system("pause");
	return 0;
}
//********************************************************************************************************
//string类对象的访问以及遍历操作
#include <iostream>
using namespace std;
#include <string>

void test() {

	string str("0123456789");
	//1.for+operator[]
	for (size_t i = 0; i < str.size(); ++i) {
		cout << str[i] << " ";
		cout << str.operator[](i) << " ";
	}
	cout << endl;
	//2.范围for
	for (auto ch : str) {
		cout << ch << " ";
	}
	cout << endl;
	//3.迭代器
	//	正向迭代器
	string::iterator it = str.begin();
	while (it != str.end()) {

		cout << *it << " ";
		++it;
	}
	cout << endl;
	//	反向迭代器
	string::reverse_iterator rit = str.rbegin();
	while (rit != str.rend()) {
		cout << *rit << " ";
		++rit; //依次从后面往前进行相加
	}
	cout << endl;
	//const(正向)
	string::const_iterator cit = str.cbegin();
	while (cit != str.cend()) {
		cout << *cit << " ";
		++cit;
	}
	cout << endl;
	//const (反向)
	string::const_reverse_iterator crit = str.crbegin();
	while (crit != str.crend()) {
		cout << *crit << " ";
		++crit;
	}
	cout << endl;

	for (size_t i = 0; i < str.size();i++) {
		cout << str.at(i) << " ";
		}
		cout << endl;
}
int main() {
	test();
	system("pause");
	return 0;
}
//迭代器
//范围:[begin,end)
//迭代器的使用方式:类似于指针的使用方式,可以通过解引用获取元素的内容,可以通过++ ,-- 进行位置的移动.





































