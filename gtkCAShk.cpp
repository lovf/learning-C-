//string类对象的修改操作
//#include <iostream>
//using namespace std;
//#include <string>
//
//
////void test1() {
////	string s;
////	s.push_back('a'); // push_back 向字符串后面插入字符
////	s.append(2,'b'); // 向后面插入5个字符 b
////	s.append("cde"); //append 向后面插入字符串
////	string s2;
////	s2.append(s); // 等于给s2后面插入s
////	cout << s2 << endl;
////	string s3;
////	s3.append(s,3,2); //从s的第3个字符开始,取2个字符
////	cout << s3 << endl;
////}
//
//void test2() {
//	string s = "0123456789";
//	//s.replace(3, 5, "aa");  //012aa89 从索引的位置开始,
//	//cout << s << endl;
//	//s.replace(s.begin() + 1, s.end() - 1, "0");  //009 从1的位置开始到最后一个元素之间换0
//	//cout << s << endl;
//
//	string s2 = "abc";
//	s2.swap(s);   // s2: 009   s: abc
//	//swap(s2, s);  //全局string类型的swap函数： 内部调用string的成员函数swap完成交换
//
//	int a = 1;
//	int b = 2;
//	swap(a,b);
//	cout << a << endl;
//	cout << b << endl;
//}
//
//int main() {
//	//test1();
//	test2();
//	system("pause");
//	return 0;
//}
//交换两个数字:
//#include <iostream>
//using namespace std;
//#include <string>
//
//
//void test() {
//	int a = 1;
//	int b = 2;
//	swap(a,b);
//	cout << a << endl;
//	cout << b << endl;
//}
//
//int main() {
//
//	test();
//	system("pause");
//	return 0;
//}
//*****************************************************************************************************************************************
//#include <iostream>
//using namespace std;
//#include <string>
//
//void test1() {
//	string str = "absdfhyg";
//	size_t pos = str.find('b'); //正向查找,找到第一个匹配的位置就结束
//	//size_t  pos2 = str.rfind('d'); // 反向查找,找到第一个匹配的位置就结束
//	cout << str.size()-pos-1 << endl;
//}
//
//void test2() {
//	string s1 = "9";
//	string s2 = "123";
//	string s3 = "1234";
//
//	bool ret1 = s1 > s2;
//	bool ret2 = s2 > s3;
//	bool ret3 = s1 > s3;
//
//	cout << ret1 << endl; //1
//	cout << ret2 << endl; //0
//	cout << ret3 << endl; //1
//}
//
//void test5() {
//	string s;
//	
//    getline(cin, s);//可以输入带空格的字符
//	cout << s << endl;   
//
//}
//int main() {
//	//test1();
//	//test2();
//	test5();
//	system("pause");
//	return 0;
//}

//关于getline 和 rfind的使用
#include <iostream>
using namespace std;
#include <string>

void test() {
	string s;
	while (getline(cin, s)) {
		size_t pos = s.rfind(' ');
		cout << s.size() - 1 - pos << endl;
	}
}

int main() {
	test();
	system("pause");
	return 0;
}























