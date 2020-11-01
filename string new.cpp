//string类实现的接口:

//容量相关接口: 重点resize, resize
#include <string>
#include <iostream>
using namespace  std;


void test1() {
	string str = "1234";
	cout << str.size() << endl;
	cout << str.capacity() << endl;
	//clear:让size变成0,不改变容量
	//str.clear(); 
	//cout << str.size() << endl;
	//cout << str.capacity() << endl;

	/*str.resize(100);
	cout << "resize:" << endl;
	cout << str.size() << endl;
	cout << str.capacity() << endl;*/

	str.reserve(50);
	cout << "reserve(50):" << endl;
	cout << str.size() << endl;
	cout << str.capacity() << endl;

	str.reserve(6);  //reserve(n):n > size n<=15 ,容量始终都是15
	cout << "reserve(5)" << endl;
	cout << str.size() << endl;
	cout << str.capacity() << endl;

	//str.shrink_to_fit(); //在满足>size的情况下,让容量减小到合适的size,需要的空间和实际相差会改变容量较大时,
	//cout << str.size() << endl;
	//cout << str.capacity() << endl;
}
int main() {
	test1();
	system("color A");
	system("pause");
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//front back 

#include <string>
#include <iostream>
using namespace  std;


void test2() {

	//string s1 = "1234";
	//cout << s1 << endl;
	////front:获取第一个元素的字符 返回值为引用,都是可读可写的接口
	//s1.front() = 'a';
	//cout << s1 << endl;

	////back;获取最后一个元素的字符 返回值为引用,都是可读可写的接口
	//s1.back() = 'b';
	//cout << s1 << endl;

	////const front/back  都是可读的接口,不能对值进行修改
	///*const string s2 = "1234";
	//s2.front() = 'a';
	//s2.back() = 'b';
	//cout << s2 << endl;*/


	//at接口:能对有效范围的元素进行修改,假如元素的下标越界,那么会抛异常
	string s = "1234";
	cout << s << endl;

	s.at(0) = 'a';
	s.at(1) = 'b';
	cout << s << endl;

	//at 位置越界,抛异常
	/*s.at(5) = 'a';
	cout << s << endl;*/
	const string s2 = "1234";
	cout << s2 << endl;
	cout << s2.at(2) << endl; //获取小标为2对应的元素

}

int main() {

	test2();
	system("color A");
	system("pause");
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//字符串遍历

//operator[] 重载 :接口既有const,也有非const接口
//operator []位置越界: 1.deBug版本报assert错误  2.release版本不报错

#include <string>
#include <iostream>
using namespace  std;

void test3() {
	string s = "1234";
	cout << s << endl;
	//operator[] 运算符重载
	//s[]<--->s.operator[] 二者等价 

	s[0] = 'a';
	s[1] = 'b';
	s.operator[](2) = 'c';
	cout << s << endl;
	//operator[]对字符串进行遍历

	for (int i = 0; i < s.size(); i++) {
		cout << s[i] << " ";
		s[i] = 'p';
	}
	cout << endl;

	for (int i = 0; i < s.size(); i++) {
		cout << s[i] << " ";

	}
	cout << endl;
}

int main() {
	test3();
	system("color A");
	system("pause");
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <string>
#include <iostream>
using namespace  std;

		//字符串的遍历

		//1.迭代器:一种元素的通用访问机制,是一种设计模式.
		//
		//begin迭代器:指向容器中的第一个元素下一个位置
		//begin和end迭代器的适用范围:左闭右开[begin,end)
		//cbegin,cend,begin,end

		//void PrintString(const string& s) {
		//	//iterator begin()    非const接口
		//	//const_iterator begin() const
		//	//iterator end() 
		//	//const_iterator end() const
		//
		//	cout << "const_iterator:" << endl;
		//	string::const_iterator it = s.begin();
		//	while (it != s.end()) {
		//		cout << *it << " ";
		//		++it;
		//	}
		//	cout << endl;
		//}


void test4() {
			//1.operator[]
			cout << "operator[]:" << endl;
			string s = "1234";
			for (int i = 0; i < s.size(); i++) {
				cout << s[i] << " ";
			}
			cout << endl;

			////2.可读可写迭代器
			//cout << "iterator:" << endl;
			//string::iterator it = s.begin();
			//while (it != s.end()) {
			//	cout << *it << " ";
			//	*it = 'a';
			//	++it;
			//}
			//cout << endl;

			//cout << "iterator修改后:" << endl;
			//it = s.begin();
			//while (it != s.end()) {
			//	cout << *it << " ";

			//	++it;
			//}
			//cout << endl;

			//只读迭代器
			//cout << "const_iterator:" << endl;
			//string::const_iterator it = s.cbegin();
			//while (it != s.cend()) {
			//	cout << *it << " ";
			//	//*it = 'a';
			//	++it;
			//}
			//cout << endl;
			//PrintString(s);
			//反迭代器: 
			//rbegin:指向最后一个元素的位置 可读可写
			//rend:指向第一个元素的前一个位置 可读可写

			//cout << "reverse_iterator:" << endl;
			//string::reverse_iterator rit = s.rbegin();
			//while (rit != s.rend()) {
			//	cout << *rit << " ";
			//	//移动到前一个位置
			//	rit++;
			//}
			//cout << endl;
			//	//3.范围for
			//	//常见的范围for书写: 
			//	//1.只读的 for(const auto& ch:变量:需要遍历的容器)
			//	//2.可读可写  for(auto& ch:变量:需要遍历的容器)
			//
			//	//范围for底层实现: 通过迭代器实现
			//	cout << "范围for:" << endl;
			//	for (char ch:s) { //没有使用引用,其值在后面不能进行修改
			//		cout << ch << " ";
			//		ch = 'a';
			//	}
			//	cout << endl;
			//
			//	cout << "iterator:" << endl;
			//	string::iterator it = s.begin();
			//	while (it != s.end()) {
			//		cout << *it << " ";
			//		++it;
			//	}
			//	cout << endl;
			//
			//	cout << "范围for&:" << endl;
			//	for (char& ch : s) { //使用引用,其值在后面能修改
			//		//for (char& ch : s) { 可读可写
			//		//for (const auto& ch : s) 只读操作
			//		cout << ch << " ";
			//		ch = 'a';
			//	}
			//	cout << endl;
			//
			//	cout << "iterator:" << endl;
			//	it = s.begin();
			//	while (it != s.end()) {
			//		cout << *it << " ";
			//		*it = 'a';
			//		++it;
			//	}
			//	cout << endl;
			//
			//}


			int main() {

				test4();
				system("color A");
				system("pause");
				return 0;
			}
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


			//增删查改
			//operator+=时间复杂度O(1) (最常用)
			//append()时间复杂度O(1)
			//push_back() 时间复杂度O(1)
			//assign();  时间复杂度O(1)
			//insert()  时间复杂度O(n)  非末位置进行插入删除 (尽量不用)
			//erase();  时间复杂度O(n)  非末位置进行插入删除 (尽量不用)
			//pop_back() 时间复杂度O(1) (最常用)
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
			using namespace  std;


			void test6() {
				string s;
				s.push_back(1);
				s.push_back(2);
				s.push_back(3);
				s.push_back(4);
				s.push_back(5);

				string s2 = "abc";
				s.append(s2); //12345abc
				s.append(s2, 2, 1);//12345abcc
				s.append("xyz");//12345abcxyz
				s.append("opq", 2);  // 把"opq"中2个元素插入到s中 //12345abcxyzop
				s.append(3, '1'); //12345abcxyzop111
				s.append(s2.begin(), s2.end()); // 12345abcxyzop111abc

				char Arr[] = "6789";
				s.append(Arr + 1, Arr + 3);//12345abcxyzop111abc78
				//解引用的字符

			}

			int main() {


				test6();
				system("color A");
				system("pause");
				return 0;
			}

			//operator+=  (根据官网接口实现)运算符重载函数 operator+=--->完成字符串的拼接
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
			using namespace  std;

			//string+=运算符重载函数：operator+=--->完成字符串的拼接
			void test7() {
				string s;
				s += '1';
				s += "bc";
				string s2 = "678";
				s += s2;

			}

			int main() {

				test7();
				system("color A");
				system("pause");
				return 0;
			}
			//insert: (根据官网接口实现)任意位置的插入
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
			using namespace  std;

			void test8() {
				string s1;
				string s2 = "123";
				s1.insert(0, s2);//123
				s1.insert(1, s2);//112323
				string s3 = "abc";
				s1.insert(2, s2, 1, 2);//11bc2323 从s1中下标为2的位置前面开始，插入s2中从下表1开始的2个元素
				s1.insert(4, "def");//11bcdef2323
				s1.insert(5, "ghi", 1); //11bcdgef2323
				s1.insert(9, 3, 'f');//11bcdgef2fff323
				s1.insert(s1.begin(), 2, '0');  //0011bcdgef2fff323
				s1.insert(s1.end(), 3, '4'); //0011bcdgef2fff323444
				s1.insert(s1.begin() + 1, 'a'); //0a011bcdgef2fff323444
			}

			int main() {
				test8();
				system("color A");
				system("pause");
				return 0;
			}

			//assign:进行赋值的操作，等价于operator
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
			using namespace  std;

			void test9() {
				string s1 = "abc";
				string s2 = "123";
				s1.assign(s2);
				s1.assign(s2, 1, 2);  //23  把s2中的下标从1开始的2个元素赋值给s1
				s1.assign("789");  // 789
				s1.assign("abcdefg", 5); // abcde
			}
			int main() {


				test9();
				system("color A");
				system("pause");
				return 0;
			}

			//erase
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
			using namespace  std;

			void test10() {
				string s = "123456789";
				s.pop_back();//12345678 执行尾删操作
				s.erase(0, 1);  // 2345678 从下标为0开始删除1个元素
				s.erase(3, 2);  // 23478   从下标为3开始删除2个元素


			}
			int main() {


				test10();
				system("color A");
				system("pause");
				return 0;
			}

			// replace 替换接口
#include <string>
#include <iostream>
			using namespace  std;

			void test11(){
				string s1 = "123";

				string s2 = "abc";

				s1.replace(1, 1, s2); //1abc3
				cout << s1 << endl;

				s1.replace(1, 2, s2); //1abcc3 //从第一元素开始,替换掉s1中的两个字符,用s2来进行交换
				cout << s1 << endl;
			}

			int main() {


				test11();
				system("color A");
				system("pause");
				return 0;
			}
			void test11(){
				string s1 = "123";

				string s2 = "abc";

				s1.replace(1, 1, s2); //1abc3
				cout << s1 << endl;

				s1.replace(1, 2, s2); //1abcc3 //从第一元素开始,替换掉s1中的两个字符,用s3来进行交换
				cout << s1 << endl;
			}

			//swap()
#include <string>
#include <iostream>
			using namespace  std;

			void test12() {

				string s1 = "123";
				string s2 = "ab";
				cout << "交换前:" << endl;
				cout << s1 << endl;
				cout << s2 << endl;
				//成员函数
				cout << "成员函数中交换后:" << endl;

				s1.swap(s2);
				cout << s1 << endl;
				cout << s2 << endl;
				/* string 成员函数:
				void Swap(String& str) {
				swap(_ptr, str._ptr);
				}

				通用模板:
				template<class  T>
				void Swap(T& str1,T& str2) {
				T tmp = str1;
				str1 = str2;
				str2 = tmp;
				}
				string 非成员函数 :
				template<class T>
				void Swap(basic_string<T>& a, basic_string<T>& b) {
				a.swap(b);
				}*/


				//非成员函数
				cout << "非成员函数中交换后:" << endl;
				swap(s1, s2);
				cout << s1 << endl;
				cout << s2 << endl;
				int a = 1;
				int b = 2;
				cout << "交换前:" << endl;
				cout << a << endl;
				cout << b << endl;

				cout << "交换后:" << endl;
				swap(a, b);
				cout << a << endl;
				cout << b << endl;

			}


			int main() {

				test12();
				system("color A");
				system("pause");
				return 0;
			}
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <string>
#include <iostream>
			using namespace  std;

			void test13() {
				string s = "12345";
				cout << s << endl;
				cout << s.c_str() << endl;
				//c_str(): 返回值为const char*,不能通过返回的指针修改内容
				//const char* ptr = s.c_str();

			}
			int main() {

				test13();
				system("color A");
				system("pause");
				return 0;
			}
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			//copy 了解  find rfind
#include <string>
#include <iostream>
			using namespace  std;

			////substr: 查找一部分字符串进行截取出来
			void test15() {
				string s = "https://www.bitedu.vip/login";
				size_t pos = s.find("://");
				if (pos != string::npos) {
					size_t pos2 = s.find("/", pos + 3);
					if (pos2 != string::npos) {
						pos += 3;
						string sub = s.substr(pos, pos2 - pos);
						cout << sub << endl; //v.bitedu.vip
					}
				}
			}

			int main() {


				test15();
				system("color A");
				system("pause");
				return 0;
			}

			compare

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
				using namespace  std;


			void test16() {
				//字符串比较规则: 从前向后,按照每一个字符的ASSCI码值进行比较
				int ret1 = strcmp("1", "12");
				int ret2 = strcmp("345", "92");
				cout << ret1 << endl;//-1
				cout << ret2 << endl;//-1

				//调用运算符重载函数进行比较
				string str1 = "1";
				string str2 = "12";
				string str3 = "345";
				string str4 = "92";
				int rit1 = str1 > str2;  //调用的是运算符重载函数
				int rit2 = str3 > str4;
				cout << rit1 << endl; //0 假
				cout << rit2 << endl; //0 假
			}
			int main() {


				test16();
				system("color A");
				system("pause");
				return 0;
			}
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			//operator+(string)
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
			using namespace  std;

			void test17() {
				string str1 = "123";
				string str2 = "abc";
				str1 += str2; //123abc 一般使用+=进行计算
				string rs1 = str1 + str2; //123abcabc

				//string str3 = "123";
				//string str4 = "abc";
				//string& rs2 = str3 + str4; //返回值需要拷贝,效率低
			}

			int main() {

				test17();
				system("color A");
				system("pause");
				return 0;
			}
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <string>
#include <iostream>
			using namespace  std;

			void test18() {
			cin: 输入字符串, 遇到空格结束.

				string s;
				 cin >> s;
				 operator>>(cin, s);
				 cout << s << endl;
			 getline:
				 getline(cin, s); //默认读取一行的内容,中间可以有空格,
				 getline(输入流, string对象, 指定读入结束的分隔符)
					 getline(cin, s, ',');//读取中遇到,结束读取
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



























































