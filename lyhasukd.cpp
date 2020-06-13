 vector 的使用
一.(contruct)构造函数说明  
1.无参构造 vector<int> v1;
2.构造并初始化n个val;vector<int>v2(n,val);
3.拷贝构造 vector<int>v3(v2);
4.使用迭代器进行初始化构造

#include <string>
#include <iostream>
using namespace std;
#include <vector>

每一种打印遍历的方式都是 for+operator[]
void test1() { 
	1.无参构造
	vector<int> v1;
	vector<char> v2;
	vector<string> v3;
	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << " ";
	}
	cout<< endl;
	2.构造并初始化n个val vector<int>v(n,val);
	vector<int>v4(10, 4);
	for (int i = 0; i < v4.size(); i++) {
		cout << v4[i] << " ";
	}
	cout << endl;
	3.拷贝构造  用一个已经存在的对象去拷贝另一个对象
	vector<int>v5(v4);
	for (int i = 0; i < v5.size(); i++) {
		cout << v5[i] <<" ";
	}
	cout << endl;
	4.使用迭代器初始化构造
	string s1 = "0123456789";
	vector<char>v6(s1.begin(), s1.end());// [s1.begin(), s1.end())  这块迭代器是前闭后开的区间
	for (int i = 0; i < v6.size(); i++) {
		cout << v6[i] << " ";
	}
	cout << endl;
}

int main() {
	test1();

	system("pause");
	return 0;
}
***********************************************************************************************************************************************
二.vector 的遍历使用
1.迭代器遍历
2.for + operator[]遍历
3.范围for遍历
#include <vector>
#include <iostream>
using namespace std;

void PrintVector(vector<int>& v1) {   //vector<int>& 引用标识符
	//1.使用迭代器正向遍历 (可读可写的)
	vector<int>::iterator it = v1.begin();
	while (it != v1.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
	//1.1使用迭代器反向遍历
	cout << "reverse_iterator" << endl;
	vector<int>::reverse_iterator rit = v1.rbegin();
	while (rit != v1.rend()) {
		cout << *rit << " ";
		++rit;
	}
	cout << endl; 
	//2.for + operator[] (可读可写的)
	for (int i = 0; i < v1.size();i++) {
		//cout << v1.operator[](i) << " ";
		cout << v1[i] << " ";
	}
	cout << endl;
	//3.范围for (可读可写的)
	for (auto& ch:v1) {
		cout << ch << " ";
	}
	cout << endl;
}

void test2() {
	vector<int> v1;
	这块使用push_back插入几个数据
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);
	PrintVector(v1);
}

int main() {
	test2();
	system("pause");
	return 0;
}
************************************************************************************************************************************************
遍历使用拓展

#include <vector>
#include <iostream>
using namespace std;



void test() {
	int a1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; 
	vector<int>v1(a1, a1 + 10); //v(a,a+10)类似一个迭代器，数组本身就是一个迭代器
	for (int i = 0; i < v1.size();i++) {
			cout << v1[i] << " ";
	}
	cout << endl;
	char a2[] = "12345678910";
	vector<char>v2(a2, a2 + 10);
	for (int i = 0; i < v2.size(); i++) {
		cout << v2[i] << " ";
	}
	cout << endl;
	string a3[5] = { "123", "456", "789", "abc", "def" };
	vector<string>v3(a3, a3 + 5);
	for (int i = 0; i < v3.size(); i++) {
		cout << v3[i] << " ";
	}
	cout << endl;
}

int main() {
	test();
	system("pause");
	return 0;
}
*********************************************************************************************************************************************
三.vector 空间增容问题
#include <vector>
#include <iostream>
using namespace std;

void PrintVector(vector<int>& v1) {
	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << " ";
	}
	cout << endl;
}

void test() {
	int a1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; 
	vector<int>v1(a1, a1 + 10); //v(a,a+10)类似一个迭代器，数组本身就是一个迭代器
	v1.resize(15,'a');
	cout << "size" << v1.size() << endl;
	PrintVector(v1);
}

int main() {
	test();
	system("pause");
	return 0;
}
resize: 
resize(n,val): 如果不给val,则使用默认值.(内置类型-->0),自定义类型则调用无参构造
******************************************************************************************************************************************
查看增容的过程
#include <iostream>
#include <vector>
using namespace std;

void test() {

	vector<int>v;
	size_t sz = v.size();
	size_t cap= v.capacity();

	cout << cap << endl;
  cout << "make cap grow: "<<endl;
	for (int i = 0; i < 200;i++) {
		v.push_back(i);
		if (cap != v.capacity()) {
		cap = v.capacity();
		cout << "capacity changed: " <<cap << endl;
		}
	}
}

int main() {
	test();
	system("pause");
	return 0;
}
************************************************************************************************************************************
vector :
增容: 如果是空,容量为0
vs 是PJ版本,增容按照1.2倍,g++是SGI版本一般是2倍;
reserve : 只增加容量,不减少容量

#include <vector>
#include <iostream>
using namespace std;

void test() {
	vector<int>v;
	size_t cap = v.capacity();
	cout << cap << endl;

	v.reserve(100);
	cap = v.capacity();
	cout << cap << endl;

	v.reserve(10);
	cap = v.capacity();
	cout << cap << endl;

}
int main() {
	test();
	system("pause");
	return 0;
}
********************************************************************************************************************************************
四.vector 增删改查
1.insert :
#include <iostream>
#include <vector>
using namespace std;



void test() {

	vector<int>v;
	insert 提供的3种接口
	v.insert(v.begin(), 1);//1  等于在初始的位置插入一个1
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	v.insert(v.begin(),5,0);// 000001 等于在初始的位置放入5个0
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;

	int a[] = { 1, 2, 3, 4, 5 };
	v.insert(v.begin(), a + 1, a + 3);// 23000001 等于给的是一个迭代器区间 [a+1,a+5)之间插入
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

int main() {

	test();
	system("pause");
	return 0;
}

********************************************************************************************************************************
五.迭代器失效问题:
#include <iostream>
#include <vector>
using namespace std;

void test() {
	vector<int> v;
	insert 提供的3种接口
	v.insert(v.begin(), 5, 1);//1  等于在初始的位置插入一个1
	vector<int>::iterator it = v.begin();
    cout << *it << endl;
	v.insert(it, 5, 0);
	int a[] = { 1, 2, 3, 4, 5 };
	v.insert(it, a + 1, a + 3); //迭代器失效
	/*v.reserve(2); 
	cout << *it << endl;*/
	v.push_back(2);
	cout << *it << endl;

}

int main() {

	test();
	system("pause");
	return 0;
}
迭代器失效:迭代器指向的位置,空间被释放或者变成一个不可访问的位置.(插入的过程中,空间不够导致增容,然后之前的空间就会被释放)
1.空间发生了变化,就会导致原来的迭代器失效.-->push_back,insert,reserve,resize,assign这些接口都有可能导致空间容量发生改变
2.位置错位-->erase
总结: 就是操作之后使空间的大小发生了改变,那么这时在使用迭代器,之后就会发生失效的问题.(增容就会)
解决:
重新获取迭代器
非删除接口:begin ,end
erase :直接获取返回值,其返回值为删除元素的的下一个元素的迭代器.
潜在问题:如果传入的迭代器为最后一个元素的迭代器,获得返回值为end迭代器,也是一个不可访问的位置/


#include <vector>
#include <iostream>
using namespace std;


void test() {
	vector<int>v;
	v.insert(v.begin(), 10, 5);
	vector<int>::iterator it = v.begin();
	while (it != v.end()) {
		it = v.erase(it);
		cout << *it << " "; //不能做解引用,因为恰好为最后一个元素的位置.
	}


}
int main() {
	test();
	system("pause");
	return 0;
}

*************************************************************************************************************************************************
交换接口:
#include <iostream>
#include <vector>
using namespace std;


void test() {
	vector<int>v1(5,2);
	vector<int>v2(5, 1);
	swap(v1,v2);//内部调用vector的成员函数swap完成
	v1.swap(v2);
	cout << "v1的值为: " << endl;
	for (int i = 0; i < v1.size();i++) {
		cout << v1[i] << " ";
	}
	cout << endl;
	cout << "v2得值为: " << endl;
	for (int i = 0; i < v2.size(); i++) {
		cout << v2[i] << " ";
	}
	cout << endl;
}

int main() {
	test();
	system("pause");
	return 0;
}



















