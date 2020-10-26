
//vector:接口简单实现
//1.迭代器:
#include<string>
#include<vector>
#include <iostream>
using namespace  std;


void  test1() {
	vector<int> v1;
	vector<char> v2;
	vector<string> v3;

	vector<int> v4(10, 5); //10个元素都是5

	string s2 = "0123456789";
	vector<char> v5(s2.begin(), s2.end()); //迭代区间 不包括'\0'
	vector<char> v6(v5);//拷贝构造

}

////三种遍历方式:1.operator[] 2.迭代器 3. 范围for
void test2() {
	string s("0123456789");
	vector<char> v(s.begin(), s.end());
	//反向
	cout << "reverse_iterator" << endl;
	vector<char>::reverse_iterator rit = v.rbegin();
	while (rit != v.rend()) {
		cout << *rit << " ";
		rit++;
	}
	cout << endl;

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	vector<char>::iterator it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		*it = 'a';
		it++;
	}
	cout << endl;
	//范围for
	for (char& ch : v) {
		cout << ch << " ";
	}
	cout << endl;
	// operator[]
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;

}
//模板进行打印
template<class T>

void PrintVec(vector<T>& v) {

	cout << "iterator" << endl;
	vector<T>::const_iterator it = v.cbegin();
	while (it != v.cend()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;

	cout << "reverse_iterator" << endl;
	vector<T>::const_reverse_iterator rit = v.crbegin();
	while (rit != v.crend()) {
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
}
void test3() {
	/*template<class T>
	vector(InputIterator  first, InputIterator last);*/
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector<int> v1(a, a + 10);

	char a2[] = "1234567890";
	vector<char> v2(a2, a2 + 10);

	string a3[5] = { "123", "456", "789", "abc", "def" };
	vector<string> v3(a3, a3 + 5);

	PrintVec(v1);
	PrintVec(v2);
	PrintVec(v3);
	cout << "resize" << endl;
	v1.resize(15);
	v1.resize(15);
	v1.resize(15);

	PrintVec(v1);
	PrintVec(v2);
	PrintVec(v3);

}

//reserve只进行增容,不能减小容量
void test4() {
	//vector: 增容:如果是空,容量为0;PJ版本按照大于1.5倍进行,SGI一般是3倍
	//resize(n,val); 如果不给val参数,则使用默认值: 内置类型--->0,自定义类型--->调用无参构造
	vector<int> v;
	size_t sz = v.size();
	size_t cap = v.capacity();
	cout << "增容之前容量的大小: " << cap << " ";

	for (int i = 0; i < 200; i++) {
		v.push_back(i);

		if (cap != v.capacity()) { //判断增容之后,容量大小的进行比较
			cap = v.capacity(); //又再次增容
			cout << cap << " ";
		}
	}
	cout << endl;
}


void test5() {
	//reserve: 只增加容量,不减小容量
	vector<int> v;
	size_t cap = v.capacity();
	v.reserve(100);
	cap = v.capacity();
	cout << cap << endl;
	v.reserve(10); //
	cap = v.capacity();
	cout << cap << endl;

}
void test6() {
	vector<int> v;
	//operator[]越界,调试版本产生断言错误
	int ret1 = v[10];
	//at越界会抛异常
	int ret2 = v.at(0);
	cout << ret1 << endl;
	cout << ret2 << endl;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//插入和删除接口
void test7() {

	vector<int> v;
	v.insert(v.begin(), 1); //1
	v.push_back(2);
	v.push_back(3);
	//迭代器
	vector<int>::iterator it = v.begin();
	cout << *it << endl;
	it = v.insert(it, 0);
	cout << *it << endl;

	//重点:
	//迭代器失效:迭代器指向的位置空间被释放(插入的时候空间就不够了,需要增容,然后要释放原有空间,但是it还是指向原来的位置,导致失效)或者变成一个不可访问的位置,
	//1.空间发生了改变,就会导致原来的迭代器失效--->pushBack(),insert,reserve,resize,assign(这些都有可能导致)
	//2.位置错位--->erase
	//解决方式:重新获取迭代器

	//非删除接口:begin,end;
	//erase: 直接获取返回值,其返回值为指向被删除元素的下一个元素的迭代器
	//潜在问题:如果传入的迭代器为最后一个元素的迭代器,获取的返回值也是一个不能访问的元素,此时需要重新获取迭代器
	//  如果传入的迭代器为最后一个元素的迭代器,获取的返回值为end迭代器,也是一个不能访问的位置
	//在这次插入的时候已经有问题了,(插入导致空间发生了改变 )
	//v.insert(it, 5, 0); //放5个0 000001
	//cout << *it << endl;

	//int a[] = { 1, 2, 3, 4, 5 }; //
	//v.insert(it, a + 1, a + 3);// 迭代器区间[1,3) a+1 是指的2  a+3指的是4 //从索引从1的位置开始到3(不算索引为3的这个位置)结束23000001
	//cout << *it << endl;
	//v.reserve(2);
	//cout << *it << endl;

}

void test8() {

	vector<int> v;
	v.insert(v.begin(), 10, 5);
	vector<int>::iterator it = v.begin();

	while (it != v.end()) {
		it = v.erase(it); //只要获取的元素没有进行解引用,就可以了
	}

}

void test9() {
	vector<int> v1(5, 2);
	vector<int> v2(5, 1);

	swap(v1, v2);//内部调用vector的成员函数swap()进行交换完成
	v1.swap(v2);
}


int main() {
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	//test7();
	//test8();

	test9();
	system("color A");
	system("pause");
	return 0;
}
