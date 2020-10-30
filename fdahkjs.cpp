//*******************************string类接口简单使用
#include <string> 
#include <iostream>
using namespace  std;


void test1() {
	//字符串的相关构造
	///*string s1;
	//string s2("123");
	//string s3(s2);
	//string s4 = "123456";*/
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///*size: 返回有效字符的个数---和\0有区别
	//length:返回有效字符的个数*/
	///*string s1("123");
	//const string s2 = "123456";
	//int ret1 = s1.size();
	//int ret2 = s2.size();
	//cout << "ret1: " << ret1 << endl;
	//cout << "ret2: " << ret2 << endl;

	//char s3[] = { '1', '2', '\0', '\0' };
	//int ret3 = strlen(s3);
	//string s4(s3);
	//int ret4 = s4.size();
	//cout << "ret3: " << ret3 << endl;
	//cout << "ret4: " << ret4 << endl;
	//}
	//int main() {
	//test1();
	//system("color A");
	//system("pause");
	//return 0;
	//}*/
	//	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//	//扩大resize
	//	string s5("12345");
	//	//resize: 修改有效字符的个数
	//	s5.resize(10); //扩容的个数大于本身有效元素的个数 大于有效元素的部分用\0代替
	//	const char* str = s5.c_str();
	//	int ret5 = s5.size();
	//	int ret6 = strlen(str); //遇到\0就结束
	//	cout << "ret5: " << ret5 << endl;
	//	cout << "ret6: " << ret6 << endl;
	//
	//	cout << s5 << "end" << endl; //\0\0\0\0\0 s5本身有效字符的个数是5,经过resize之后扩容(扩容的个数大于本身有效元素的个数)
	//	cout << str << "end" << endl;
	//}
	//int main() {
	//	test1();
	//	system("color A");
	//	system("pause");
	//	return 0;
	//}
	//	string s5("12345");
	//	//resize: 修改有效字符的个数
	//	s5.resize(10,'a'); //扩容的个数大于本身有效元素的个数  大于有效元素的部分用a代替 
	//	const char* str = s5.c_str();
	//	int ret5 = s5.size();
	//	int ret6 = strlen(str);
	//	cout << "ret5: " << ret5 << endl;
	//	cout << "ret6: " << ret6 << endl;
	//
	//	cout << s5 << "end" << endl; //aaaaa s5本身有效字符的个数是5,经过resize之后扩容(扩容的个数大于本身有效元素的个数)
	//	cout << str << "end" << endl;
	//
	//}
	//int main() {
	//	test1();
	//	system("color A");
	//	system("pause");
	//	return 0;
	//}
	//	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//	//缩小resize:  不会改变原有位置的内容
	//	string s5("12345");
	//	s5.resize(2); //扩容的个数小于本身有效元素的个数
	//	const char* str = s5.c_str();
	//	int ret5 = s5.size();
	//	int ret6 = strlen(str);
	//	cout << "ret5: " << ret5 << endl;
	//	cout << "ret6: " << ret6 << endl;
	//
	//	//s5本身有效字符的个数是5,
	//	//经过resize之后扩容(扩容的个数大于本身有效元素的个数)
	//	cout << s5 << "end" << endl;
	//	cout << str << "end" << endl;
	//}
	//
	//int main() {
	//	test1();
	//	system("color A");
	//	system("pause");
	//	return 0;
	////}
	//	string s6("123");
	//	int ret1 = s6.size();
	//	int cap1 = s6.capacity();
	//	cout << "扩容之前的size: " << ret1 << endl;
	//	cout << "扩容之前的capacity: " << cap1 << endl;
	//	//resize:只改变有效元素的个数,不会改变capacity
	//	s6.resize(10,'a');
	//	int ret2 = s6.size();
	//	//capacity:表示string对象能存放有效元素的最大个数
	//	int cap2 = s6.capacity();
	//	cout << s6 << endl;
	//	cout << "扩容之后的size: " << ret2 << endl;
	//	cout << "扩容之后的capacity: " << cap2 << endl;
	////resize:总结
	////1.resize(n):让size变成n,且新增的位置用\0补充
	////2.resize(n,'c'):让size变成n,且新增的位置用'c'补充
	////3.resize: 只会增加新填充的内容,不会修改已有位置的内容
	////4.resize:可以变大变小size
	////5.resize之后的size比string原始的容量大,则string之后会进行增容
	//}

	//int main() {
	//	test1();
	//	system("color A");
	//	system("pause");
	//	return 0;
	//}
	//	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//	//reserve: 只改变容量(既能增大也能减小),不改变实际元素的个数(size)
	//	string s1;
	//	s1.resize(10);
	//	cout << "size: " << s1.size() << endl;
	//	cout << "capacity: " << s1.capacity() << endl;
	//	s1.reserve(60);
	//	cout << "size: " << s1.size() << endl;
	//	cout << "capacity: " << s1.capacity() << endl;
	//
	//	s1.reserve(10);
	//	cout << "size: " << s1.size() << endl;
	//	cout << "capacity: " << s1.capacity() << endl;
	//		}
	//
	//int main() {
	//	test1();
	//	system("color A");
	//	system("pause");
	//	return 0;
	//}
	//reserve: 改变容量大小,size大小不发生能改变
	//如果需要减小容量,实际的容量大小会根据string对象的内容进行适当优化处理(直到容量必须满足元素需要的空间即可)
/*string s2("12345");
cout << "扩容之前" << endl;
cout << "size: " << s2.size() << endl;
cout << "capacity: " << s2.capacity() << endl;

cout << "扩容之后" << endl;
s2.reserve(4);
cout << "size: " << s2.size() << endl;
cout << "capacity: " << s2.capacity() << endl;
}

int main() {
test1();
system("color A");
system("pause");
return 0;
}
*/
  //增容: 第一次2倍,后续大概1.5倍,这样的方式进行增容会使得开销很大,每一次进行增容都要经过,//1.开空间2.复制拷贝3.释放空间
// // 假如提前开好空间那么会大大减小开销
//string s1;
//int cap = s1.capacity();
//cout << "capacity:" << cap << endl;
//for (int i = 0; i < 100; i++) {
//	s1.push_back(i);
//	if (cap != s1.capacity()) {
//		cap = s1.capacity();
//		cout << "capacity:" << cap << endl;
//	}
//}
//		}
//
//		int main() {
//			test1();
//			system("color A");
//			system("pause");
//			return 0;
//		}

    //提前开好空间: 
	string s1;
	int cap = s1.capacity();
	cout << "capacity:" << cap << endl;

	s1.reserve(100); //减小了增容的开销
	cout << "capacity:" << s1.capacity() << endl;

	for (int i = 0; i < 100; i++) {
		s1.push_back(i);
		if (cap != s1.capacity()) {
			cap = s1.capacity();
			cout << "capacity:" << cap << endl;
		}
	}

}

int main () {
	test1();
    system("color A");
    system ("pause");
    return 0;
}