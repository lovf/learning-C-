////String接口简单实现
////string类实现的接口:
//
////容量相关接口: 重点resize, resize
//#include <string>gfdaskj

//#include <iostream>
//using namespace  std;
//
//
//void test1() {
//	string str = "1234";
//	cout << str.size() << endl;
//	cout << str.capacity() << endl;
//	//clear:让size变成0,不改变容量
//	//str.clear(); 
//	//cout << str.size() << endl;
//	//cout << str.capacity() << endl;
//
//	/*str.resize(100);
//	cout << "resize:" << endl;
//	cout << str.size() << endl;
//	cout << str.capacity() << endl;*/
//
//	str.reserve(50);
//	cout << "reserve(50):" << endl;
//	cout << str.size() << endl;
//	cout << str.capacity() << endl;
//
//	str.reserve(6);  //reserve(n):n > size n<=15 ,容量始终都是15
//	cout << "reserve(5)" << endl;
//	cout << str.size() << endl;
//	cout << str.capacity() << endl;
//
//	//str.shrink_to_fit(); //在满足>size的情况下,让容量减小到合适的size,需要的空间和实际相差会改变容量较大时,
//	//cout << str.size() << endl;
//	//cout << str.capacity() << endl;
//}
//int main() {
//	test1();
//	system("color A");
//	system("pause");
//	return 0;
//}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////front back 
//
//#include <string>
//#include <iostream>
//using namespace  std;
//
//
//void test2() {
//
//	//string s1 = "1234";
//	//cout << s1 << endl;
//	////front:获取第一个元素的字符 返回值为引用,都是可读可写的接口
//	//s1.front() = 'a';
//	//cout << s1 << endl;
//
//	////back;获取最后一个元素的字符 返回值为引用,都是可读可写的接口
//	//s1.back() = 'b';
//	//cout << s1 << endl;
//
//	////const front/back  都是可读的接口,不能对值进行修改
//	///*const string s2 = "1234";
//	//s2.front() = 'a';
//	//s2.back() = 'b';
//	//cout << s2 << endl;*/
//
//
//	//at接口:能对有效范围的元素进行修改,假如元素的下标越界,那么会抛异常
//	string s = "1234";
//	cout << s << endl;
//
//	s.at(0) = 'a';
//	s.at(1) = 'b';
//	cout << s << endl;
//
//	//at 位置越界,抛异常
//	/*s.at(5) = 'a';
//	cout << s << endl;*/
//	const string s2 = "1234";
//	cout << s2 << endl;
//	cout << s2.at(2) << endl; //获取小标为2对应的元素
//
//}
//
//int main() {
//
//	test2();
//	system("color A");
//	system("pause");
//	return 0;
//}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////字符串遍历
//
////operator[] 重载 :接口既有const,也有非const接口
////operator []位置越界: 1.deBug版本报assert错误  2.release版本不报错
//
//#include <string>
//#include <iostream>
//using namespace  std;
//
//void test3() {
//	string s = "1234";
//	cout << s << endl;
//	//operator[] 运算符重载
//	//s[]<--->s.operator[] 二者等价 
//
//	s[0] = 'a';
//	s[1] = 'b';
//	s.operator[](2) = 'c';
//	cout << s << endl;
//	//operator[]对字符串进行遍历
//
//	for (int i = 0; i < s.size(); i++) {
//		cout << s[i] << " ";
//		s[i] = 'p';
//	}
//	cout << endl;
//
//	for (int i = 0; i < s.size(); i++) {
//		cout << s[i] << " ";
//
//	}
//	cout << endl;
//}
//
//int main() {
//	test3();
//	system("color A");
//	system("pause");
//	return 0;
//}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#include <string>
//#include <iostream>
//using namespace  std;
//
////字符串的遍历
//
////1.迭代器:一种元素的通用访问机制,是一种设计模式.
////
////begin迭代器:指向容器中的第一个元素下一个位置
////begin和end迭代器的适用范围:左闭右开[begin,end)
////cbegin,cend,begin,end
//
////void PrintString(const string& s) {
////	//iterator begin()    非const接口
////	//const_iterator begin() const
////	//iterator end() 
////	//const_iterator end() const
////
////	cout << "const_iterator:" << endl;
////	string::const_iterator it = s.begin();
////	while (it != s.end()) {
////		cout << *it << " ";
////		++it;
////	}
////	cout << endl;
////}
//
//
//void test4() {
//	//1.operator[]
//	cout << "operator[]:" << endl;
//	string s = "1234";
//	for (int i = 0; i < s.size(); i++) {
//		cout << s[i] << " ";
//	}
//	cout << endl;
//
//	////2.可读可写迭代器
//	//cout << "iterator:" << endl;
//	//string::iterator it = s.begin();
//	//while (it != s.end()) {
//	//	cout << *it << " ";
//	//	*it = 'a';
//	//	++it;
//	//}
//	//cout << endl;
//
//	//cout << "iterator修改后:" << endl;
//	//it = s.begin();
//	//while (it != s.end()) {
//	//	cout << *it << " ";
//
//	//	++it;
//	//}
//	//cout << endl;
//
//	//只读迭代器
//	//cout << "const_iterator:" << endl;
//	//string::const_iterator it = s.cbegin();
//	//while (it != s.cend()) {
//	//	cout << *it << " ";
//	//	//*it = 'a';
//	//	++it;
//	//}
//	//cout << endl;
//	//PrintString(s);
//	//反迭代器: 
//	//rbegin:指向最后一个元素的位置 可读可写
//	//rend:指向第一个元素的前一个位置 可读可写
//
//	//cout << "reverse_iterator:" << endl;
//	//string::reverse_iterator rit = s.rbegin();
//	//while (rit != s.rend()) {
//	//	cout << *rit << " ";
//	//	//移动到前一个位置
//	//	rit++;
//	//}
//	//cout << endl;
//	//	//3.范围for
//	//	//常见的范围for书写: 
//	//	//1.只读的 for(const auto& ch:变量:需要遍历的容器)
//	//	//2.可读可写  for(auto& ch:变量:需要遍历的容器)
//	//
//	//	//范围for底层实现: 通过迭代器实现
//	//	cout << "范围for:" << endl;
//	//	for (char ch:s) { //没有使用引用,其值在后面不能进行修改
//	//		cout << ch << " ";
//	//		ch = 'a';
//	//	}
//	//	cout << endl;
//	//
//	//	cout << "iterator:" << endl;
//	//	string::iterator it = s.begin();
//	//	while (it != s.end()) {
//	//		cout << *it << " ";
//	//		++it;
//	//	}
//	//	cout << endl;
//	//
//	//	cout << "范围for&:" << endl;
//	//	for (char& ch : s) { //使用引用,其值在后面能修改
//	//		//for (char& ch : s) { 可读可写
//	//		//for (const auto& ch : s) 只读操作
//	//		cout << ch << " ";
//	//		ch = 'a';
//	//	}
//	//	cout << endl;
//	//
//	//	cout << "iterator:" << endl;
//	//	it = s.begin();
//	//	while (it != s.end()) {
//	//		cout << *it << " ";
//	//		*it = 'a';
//	//		++it;
//	//	}
//	//	cout << endl;
//	//
//	//}
//
//
//	int main() {
//
//		test4();
//		system("color A");
//		system("pause");
//		return 0;
//	}
//	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//	//增删查改
//	//operator+=时间复杂度O(1) (最常用)
//	//append()时间复杂度O(1)
//	//push_back() 时间复杂度O(1)
//	//assign();  时间复杂度O(1)
//	//insert()  时间复杂度O(n)  非末位置进行插入删除 (尽量不用)
//	//erase();  时间复杂度O(n)  非末位置进行插入删除 (尽量不用)
//	//pop_back() 时间复杂度O(1) (最常用)
//#include <stdio.h>
//#include <stdlib.h>
//#include <iostream>
//	using namespace  std;
//
//
//	void test6() {
//		string s;
//		s.push_back(1);
//		s.push_back(2);
//		s.push_back(3);
//		s.push_back(4);
//		s.push_back(5);
//
//		string s2 = "abc";
//		s.append(s2); //12345abc
//		s.append(s2, 2, 1);//12345abcc
//		s.append("xyz");//12345abcxyz
//		s.append("opq", 2);  // 把"opq"中2个元素插入到s中 //12345abcxyzop
//		s.append(3, '1'); //12345abcxyzop111
//		s.append(s2.begin(), s2.end()); // 12345abcxyzop111abc
//
//		char Arr[] = "6789";
//		s.append(Arr + 1, Arr + 3);//12345abcxyzop111abc78
//		//解引用的字符
//
//	}
//
//	int main() {
//
//
//		test6();
//		system("color A");
//		system("pause");
//		return 0;
//	}
//
//	//operator+=  (根据官网接口实现)运算符重载函数 operator+=--->完成字符串的拼接
//#include <stdio.h>
//#include <stdlib.h>
//#include <iostream>
//	using namespace  std;
//
//	//string+=运算符重载函数：operator+=--->完成字符串的拼接
//	void test7() {
//		string s;
//		s += '1';
//		s += "bc";
//		string s2 = "678";
//		s += s2;
//
//	}
//
//	int main() {
//
//		test7();
//		system("color A");
//		system("pause");
//		return 0;
//	}
//	//insert: (根据官网接口实现)任意位置的插入
//#include <stdio.h>
//#include <stdlib.h>
//#include <iostream>
//	using namespace  std;
//
//	void test8() {
//		string s1;
//		string s2 = "123";
//		s1.insert(0, s2);//123
//		s1.insert(1, s2);//112323
//		string s3 = "abc";
//		s1.insert(2, s2, 1, 2);//11bc2323 从s1中下标为2的位置前面开始，插入s2中从下表1开始的2个元素
//		s1.insert(4, "def");//11bcdef2323
//		s1.insert(5, "ghi", 1); //11bcdgef2323
//		s1.insert(9, 3, 'f');//11bcdgef2fff323
//		s1.insert(s1.begin(), 2, '0');  //0011bcdgef2fff323
//		s1.insert(s1.end(), 3, '4'); //0011bcdgef2fff323444
//		s1.insert(s1.begin() + 1, 'a'); //0a011bcdgef2fff323444
//	}
//
//	int main() {
//		test8();
//		system("color A");
//		system("pause");
//		return 0;
//	}
//
//	//assign:进行赋值的操作，等价于operator
//#include <stdio.h>
//#include <stdlib.h>
//#include <iostream>
//	using namespace  std;
//
//	void test9() {
//		string s1 = "abc";
//		string s2 = "123";
//		s1.assign(s2);
//		s1.assign(s2, 1, 2);  //23  把s2中的下标从1开始的2个元素赋值给s1
//		s1.assign("789");  // 789
//		s1.assign("abcdefg", 5); // abcde
//	}
//	int main() {
//
//
//		test9();
//		system("color A");
//		system("pause");
//		return 0;
//	}
//
//	//erase
//#include <stdio.h>
//#include <stdlib.h>
//#include <iostream>
//	using namespace  std;
//
//	void test10() {
//		string s = "123456789";
//		s.pop_back();//12345678 执行尾删操作
//		s.erase(0, 1);  // 2345678 从下标为0开始删除1个元素
//		s.erase(3, 2);  // 23478   从下标为3开始删除2个元素
//
//
//	}
//	int main() {
//
//
//		test10();
//		system("color A");
//		system("pause");
//		return 0;
//	}
//
//	// replace 替换接口
//#include <string>
//#include <iostream>
//	using namespace  std;
//
//	void test11(){
//		string s1 = "123";
//
//		string s2 = "abc";
//
//		s1.replace(1, 1, s2); //1abc3
//		cout << s1 << endl;
//
//		s1.replace(1, 2, s2); //1abcc3 //从第一元素开始,替换掉s1中的两个字符,用s2来进行交换
//		cout << s1 << endl;
//	}
//
//	int main() {
//
//
//		test11();
//		system("color A");
//		system("pause");
//		return 0;
//	}
//	void test11(){
//		string s1 = "123";
//
//		string s2 = "abc";
//
//		s1.replace(1, 1, s2); //1abc3
//		cout << s1 << endl;
//
//		s1.replace(1, 2, s2); //1abcc3 //从第一元素开始,替换掉s1中的两个字符,用s3来进行交换
//		cout << s1 << endl;
//	}
//
//	//swap()
//#include <string>
//#include <iostream>
//	using namespace  std;
//
//	void test12() {
//
//		string s1 = "123";
//		string s2 = "ab";
//		cout << "交换前:" << endl;
//		cout << s1 << endl;
//		cout << s2 << endl;
//		//成员函数
//		cout << "成员函数中交换后:" << endl;
//
//		s1.swap(s2);
//		cout << s1 << endl;
//		cout << s2 << endl;
//		/* string 成员函数:
//		void Swap(String& str) {
//		swap(_ptr, str._ptr);
//		}
//
//		通用模板:
//		template<class  T>
//		void Swap(T& str1,T& str2) {
//		T tmp = str1;
//		str1 = str2;
//		str2 = tmp;
//		}
//		string 非成员函数 :
//		template<class T>
//		void Swap(basic_string<T>& a, basic_string<T>& b) {
//		a.swap(b);
//		}*/
//
//
//		//非成员函数
//		cout << "非成员函数中交换后:" << endl;
//		swap(s1, s2);
//		cout << s1 << endl;
//		cout << s2 << endl;
//		int a = 1;
//		int b = 2;
//		cout << "交换前:" << endl;
//		cout << a << endl;
//		cout << b << endl;
//
//		cout << "交换后:" << endl;
//		swap(a, b);
//		cout << a << endl;
//		cout << b << endl;
//
//	}
//
//
//	int main() {
//
//		test12();
//		system("color A");
//		system("pause");
//		return 0;
//	}
//	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#include <string>
//#include <iostream>
//	using namespace  std;
//
//	void test13() {
//		string s = "12345";
//		cout << s << endl;
//		cout << s.c_str() << endl;
//		//c_str(): 返回值为const char*,不能通过返回的指针修改内容
//		//const char* ptr = s.c_str();
//
//	}
//	int main() {
//
//		test13();
//		system("color A");
//		system("pause");
//		return 0;
//	}
//	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	//copy 了解  find rfind
//#include <string>
//#include <iostream>
//using namespace  std;
//
//	////substr: 查找一部分字符串进行截取出来
//	void test15() {
//		string s = "https://www.bitedu.vip/login";
//		size_t pos = s.find("://");
//		if (pos != string::npos) {
//			size_t pos2 = s.find("/", pos + 3);
//			if (pos2 != string::npos) {
//				pos += 3;
//				string sub = s.substr(pos, pos2 - pos);
//				cout << sub << endl; //v.bitedu.vip
//			}
//		}
//	}
//
//	int main() {
//
//
//		test15();
//		system("color A");
//		system("pause");
//		return 0;
//	}
//
////compare
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <iostream>using namespace  std;
//
//
//	void test16() {
//		//字符串比较规则: 从前向后,按照每一个字符的ASSCI码值进行比较
//		int ret1 = strcmp("1", "12");
//		int ret2 = strcmp("345", "92");
//		cout << ret1 << endl;//-1
//		cout << ret2 << endl;//-1
//
//		//调用运算符重载函数进行比较
//		string str1 = "1";
//		string str2 = "12";
//		string str3 = "345";
//		string str4 = "92";
//		int rit1 = str1 > str2;  //调用的是运算符重载函数
//		int rit2 = str3 > str4;
//		cout << rit1 << endl; //0 假
//		cout << rit2 << endl; //0 假
//	}
//int main() {
//
//
//	test16();
//	system("color A");
//	system("pause");
//	return 0;
//}
//	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	//operator+(string)
//#include <stdio.h>
//#include <stdlib.h>
//#include <iostream>
//using namespace  std;
//
//void test17() {
//	string str1 = "123";
//	string str2 = "abc";
//	str1 += str2; //123abc 一般使用+=进行计算
//	string rs1 = str1 + str2; //123abcabc
//
//	//string str3 = "123";
//	//string str4 = "abc";
//	//string& rs2 = str3 + str4; //返回值需要拷贝,效率低
//}
//
//int main() {
//
//	test17();
//	system("color A");
//	system("pause");
//	return 0;
//}
//	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <string>
#include <iostream>
using namespace  std;

void test18() {
	//cin: 输入字符串, 遇到空格结束.

	string s;
	cin >> s;
	//operator>>(cin, s);
	cout << s << endl;
	// getline:
	//getline(cin, s); //默认读取一行的内容,中间可以有空格,
	// getline(输入流, string对象, 指定读入结束的分隔符)
	//getline(cin, s, ',');//读取中遇到,结束读取
}

int main() {
	test18();
	system("color A");
	system("pause");
	return 0;
}

//最常用:
//迭代器: begin/end
//capacity:size,resize,capacity,reserve,clear, empty
//operator[]
//增删查该: operator+=/swap

//c_str,find,rfind,substr,

//关系运算符:operator>>, operator<<, getline


////string模拟实现:
//简单string模拟实现包括4个组成部分:
//(析构函数,拷贝构造(有传统写法,现代写法),构造函数,赋值运算符(有传统写法,现代写法))
//#define _CRT_SECURE_NO_WARNINGS
//#include <string>
//#include <iostream>
//using namespace  std;
//
//class String{
//public:
//	
//	//无参构造
//	String(char* ptr = " ")
//		:_ptr(new char[strlen(ptr) +1]) //初始化列表
//	{
//		strcpy(_ptr, ptr);
//	}
//	////////////////////////////////////////////////////////////////////////////////
//	/*String(const String& str)
//		:_ptr(str._ptr)
//	{}*/
//
//	// 传统写法: 显示拷贝构造,完成深拷贝: 拷贝对象+资源
//	//String(const String& str)
//	//	:_ptr(new char[strlen(str._ptr) + 1]) //把空间先开好
//	//{
//	//	strcpy(_ptr, str._ptr); //将对象进行拷贝过去
//	//}
//
//	//拷贝构造现代写法
//	String(const String& str)
//		:_ptr(nullptr)
//	{
//		//创建一个局部变量:调用构造函数--->开空间+内容拷贝
//		String tmp(str._ptr); //复用了构造函数的逻辑
//		swap(_ptr, tmp._ptr);
//	}
//	/////////////////////////////////////////////////////////////////////////////
//	//赋值运算符重载
//	//String& operator=(const String& str) {
//	//	if (this != &str) {
//	//	//1.开空间
//	//		char* tmp = new char[strlen(str._ptr) + 1];
//	//	//2.拷贝资源
//	//		strcpy(tmp, str._ptr);
//	//	//3.释放原有资源
//	//		delete[] _ptr;
//	//	//指向新的空间
//	//		_ptr = tmp;
//	//	}
//	//	return *this;
//	//}
//
//	//复制运算符重载函数 现代写法
//	String& operator=(String str) { //传值过程自动调用构造函数
//		swap(_ptr, str._ptr);
//		return *this;
//	}
//
//	//析构函数             
//	~String() {
//		if (_ptr) {
//			delete[] _ptr;
//			_ptr = nullptr;
//		}
//	}
//	
//	const char* c_str() const {
//	
//		return _ptr;
//	}
//
//private:
//	char* _ptr;
//};
//
//
//void test1() {
//	String s("123");
//	//拷贝构造
//	String s2 = s;
//	//赋值： operator=
//	String s3 = s2;
//}
//
//int main() {
//
//	test1();
//	system("color A");
//	system("pause");
//	return 0;
//}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////String模拟实现:
//#define _CRT_SECURE_NO_WARNINGS
//#include <string>
//#include <assert.h>
//#include <iostream>
//using namespace  std;
//
//class String{
//public:
//	//无参构造
//	String(char* str = " ")	
//	{
//		_size = strlen(str);
//		_capacity = _size;
//		_ptr = new char[_size + 1];
//		strcpy(_ptr, str);
//	}
//
//	//拷贝构造  传统写法
//	/*String(String& str) 
//		:_ptr(new char[strlen(str._ptr)+1])
//		, _capacity(str._capacity)
//		, _size(_size)
//	{
//		strcpy(_ptr, str._ptr);
//	}*/
//	void Swap(String& str) {
//		swap(_ptr, str._ptr);
//		swap(_size, str._size);
//		swap(_capacity, str._capacity);
//	}
//	//拷贝构造 现代写法
//	String(String& str) 
//		:_ptr(nullptr)
//		, _size(0)
//		, _capacity(0)
//	{
//		String tmp(str._ptr);
//		Swap(tmp);
//	}
//	////赋值运算符重载  传统
//	String& operator=(String& str) {
//		if (this != &str) {
//		//开空间
//			char* tmp = new char[strlen(str._ptr) + 1];
//		//赋值拷贝
//			strcpy(tmp, str._ptr);
//		//释放
//			delete[] _ptr;
//			_ptr = tmp;
//			_size = str._size;
//			_capacity = str._capacity;
//		}
//		return *this;
//	}
//	////赋值运算符重载 现代
//	/*String& operator=(String str){
//		Swap(str);
//		return *this;
//		}*/
//	//尾插
//	void push_back(const char& ch) {
//	//判定容量
//		if (_size == _capacity) {
//		//增容
//			size_t newC = _capacity == 0 ? 15 : 2 * _capacity;
//			reserve(newC);
//		}
//		//插入字符
//		_ptr[_size++] = ch;
//	  //尾部添加'\0'
//		_ptr[_size] = '\0';
//	}
//
//	void reserve(size_t n) {
//		if (n >_capacity) {
//		//开新的空间
//			char* tmp = new char[n + 1];
//		//拷贝
//			//strcpy(tmp, _ptr);
//			for (int i = 0; i <= _size;++i) {
//				tmp[i] = _ptr[i];
//			}
//		//释放原有的空间
//			delete[] _ptr;
//			_ptr = tmp;
//			//更新容量
//			_capacity = n;
//		}
//	}
//	//插入字符串
//	void Append(const char* str) {
//	//获取插入字符串的长度
//		int len = strlen(str);
//    //扩容
//		if (len+_size > _capacity) {
//			reserve(len + _size);
//		}
//    //插入字符串
//		strcpy(_ptr+_size,str);
//	//更新_size
//		_size += len;
//	}
//
//	//+= 字符 操作
//	String& operator+=(const char& ch) {
//		push_back(ch);
//		return *this;
//	}
//	////+= 字符串
//	String& operator+=(const char* str) {
//		Append(str);
//		return *this;
//	}
//	//+= String对象
//	String& operator+=(const String& str) {
//		Append(str._ptr);
//		return *this;
//	}
//
//	////插入字符
//	void insert(size_t pos, const char& ch) {
//	//1.判定边界
//		assert(pos <= _size);
//	//2.检查容量
//		if (_size == _capacity) {
//			size_t newC = _capacity == 0 ? 15 : 2 * _capacity;
//			reserve(newC);
//		}
//    //3.移动元素
//		size_t end = _size;
//		while (end>pos) {
//			_ptr[end] = _ptr[end - 1];
//			--end;
//		}
//    //4.在pos位置前插入字符
//		_ptr[pos] = ch;
//	//5.更新_size  之后再复制'\0'
//		_ptr[++_size] = '\0';
//	}
//	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	////插入字符串
//	void insert(size_t pos, const char* str) {
//	//1.不能越界
//		assert(pos <= _size);
//	//2.计算要插入元素的长度
//		int len = strlen(str);
//	//3.检查容量
//		if (_size+len>_capacity) {
//			reserve(_size + len);
//		}
//    //4.在pos位置前面插入字符串
//		size_t end = _size + len;
//		while (end> pos+len-1) {
//			_ptr[end] = _ptr[end - len];
//			--end;
//		}
//	//5.插入字符串
//		memcpy(_ptr + pos, str, len*sizeof(char));
//    //6.更新_size位置
//		_size += len;
//	}
//
//	size_t size() {
//		return _size;
//	}
//	//迭代器: 访问容器元素的一种机制 操作类似于指针  常用操作: 迭代器移动,迭代器解引用,迭代器判断
//	//iterator 迭代器返回值为char* 
//	typedef char* iterator;
//	typedef const char* const_iterator;
//	//begin: 第一个元素的位置
//	iterator begin() {
//		return _ptr;
//	}
//	//end(): 最后一个元素的下一个位置
//	iterator end() {
//		return _ptr + _size;
//	}
//
//	const_iterator begin() const{
//		return _ptr;
//	}
//	const_iterator end() const{
//		return _ptr + _size;
//	}
//	//operator[]
//	char& operator[](size_t pos) {
//		//判断是否越界
//		assert(pos < _size);
//		return _ptr[pos];
//	}
//	const char& operator[](size_t pos) const{
//		//判断是否越界
//		assert(pos < _size);
//		return _ptr[pos];
//	}
//	//resize(n,ch)
//	//1.n<=_size只需要修改_size
//	//2._size<n<=_capacity() :辅助ch-->[_size,_capacity],修改_size
//	//3._capacity<n 增容,赋值修改_size
//	void resize(size_t sz,char ch='\0') {
//		if (sz >_capacity){
//			reserve(sz);
//		}
//		if ( _size<sz) {
//			//赋值
//			memset(_ptr + _size, ch, sz - _size);
//		}
//	
//		_size = sz;
//		
//		_ptr[_size] = '\0';
//	}
//	//删除从pos位置开始,长度为len的字符串
//	void erase(size_t pos,size_t len) {
//		assert(pos<_size);
//		if (pos+len >=_size) {
//			_size = pos;
//			_ptr[_size] = '\0';
//		}
//		else {
//			size_t start = pos + len;
//			while (start < _size) {
//
//				_ptr[pos++] = _ptr[start];
//				++start;
//				/*_ptr[start - len] = _ptr[start];
//				++start;*/
//
//			}
//			_size -= len;
//			_ptr[_size] = '\0';
//		}
//	}
//	//查找字符  
//	size_t find(const char& ch, size_t pos = 0) {
//		for (int i = pos; i < _size; i++) {
//			if (_ptr[i] == ch)
//				return i;
//		}
//		return npos;
//	
//	}
//
//	//查找字符串 
//	size_t find(const char* str, size_t pos = 0) {
//		char* start = strstr(_ptr + pos,str);  //找到str在_ptr + pos
//		if (start) {
//			return start - _ptr;
//		}
//
//		return npos;
//	}
//
//
//
//	//析构
//	~String() {
//		if (_ptr) {
//			delete[] _ptr;
//			_ptr = nullptr;
//			_size = 0;
//			_capacity = 0;
//		}
//	}
//private:
//	char* _ptr;
//	size_t _size;//有效元素的个数
//	size_t _capacity;//容量大小
//	static const size_t npos;//静态成员初始化在类外进行初始化
//};
////类型 + 类名:: 变量
//const size_t String::npos = -1;
//
//void printstring( String& str) {
//	for (int i = 0; i < str.size(); i++) {
//		cout << str[i] << " ";
//	}
//	cout << endl;
//
//}
//
////验证构造函数/拷贝构造/赋值运算符重载/析构函数
//void test1() {
//	String str1 = "123";
//	String str2 = "abcde";
//	String str3(str1);
//	str2 = str1;
//}
//
//void test2() {
//	String str = "abc";
//	//////尾插字符
//	//str.push_back('a');
//	//str.push_back('b');
//	//str.push_back('c');
//	//str.push_back('d');
//	//printstring(str);
//
//	////+=字符
//	////str += '9';
//	//str.operator+=('9');
//	////+= 字符串
//	//str += "5678";
//	//str.operator+=("5678");
//	str.insert(0, "4");
//	printstring(str);
//	str.insert(3, "569");
//	printstring(str);
//
//	////迭代器遍历
//	//String::iterator it = str.begin();
//	//while (it != str.end()) {
//	//	cout << *it << " ";
//	//	it++;
//	//}
//	//cout << endl;
//
//	////operator[]
//	//for (int i = 0; i <str.size();i++) {
//	//	cout << str[i] << " ";
//	//}
//	//cout << endl;
//	////范围for遍历
//	//for (auto& ch:str) {
//	//	cout << ch << " ";
//	//}
//	//cout << endl;
//}
//
//////resize 
////void test3() {
////	String str;//""
////	printstring(str);
////	str.resize(3);//""--->"\0\0\0"
////	printstring(str);
////	str.resize(5, 'a');//"" ---> "\0\0\0aa"
////	printstring(str);
////
////	str.resize(4, 'b');
////	printstring(str);
////}
//
//
//void test4() {
//	String str = "123456";
//	str.erase(5, 2);
//	printstring(str);
//}
//int main () {
//	  //test1();
//	//test2();
//	//test3();
//	test4();
//    system("color A");
//    system ("pause");
//    return 0;
//}


