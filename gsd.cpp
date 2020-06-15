#include <string>
#include <iostream>
using namespace std;


template <class T>
class Vector {

public:
	Vector()
	: _start(nullptr)
	, _finish(nullptr)
	, _eos(nullptr)//end_of_ storage

	{}

	size_t size() const {
		return _finish - _start;
	}
	size_t capacity() const {
		return _eos - _start;
	}
	//完成尾插的操作***********************************************************************
	void pushBack(const T& val) { //这块使用引用,防止数值过大
	//1.检查容量
	//当_finsh == _eos 时 ,此时空间满了
		if (_finish == _eos) {
			size_t newC = capacity() == 0 ? 1 : 2 * capacity();
			reserve(newC);
		}
	//2.插入 :深拷贝 : 调用T类型的赋值运算符
		*_finish = val;
	//3.更新size
		++_finish;
	}
	void reserve(size_t n) {
		if (n > capacity()) {
			size_t oldsize = size();//必须要将之前的 size() 记录保存一下,后面需要释放_start,导致size()会发生改变
			//1.开空间
			T* temp = new T[n];
			//2.浅拷贝: 内存拷贝 浅拷贝  
			//memcpy(temp, _start, sizeof(T)*size());
			//2.深拷贝(字符类型进行的拷贝)2.深拷贝: 调用T类型的赋值运算符,完成深拷贝
			for (int i = 0; i < size();++i) {
				temp[i] = _start[i];
			}
			//3.释放原有的空间
			delete[] _start;
			//4.更新空间指向,容量
			_start = temp;
			_finish = _start + oldsize;
			_eos = _start + n;
		}
	}
	//operator []: 遍历 可读可写操作
	T& operator[](size_t pos) {
		if (pos<size()) {
			return _start[pos];
		}
	}
	//********************************************************************************************************
	//只读的接口
	const T& operator[](size_t pos) const {
		if (pos < size()) {
			return _start[pos];
		}
	}
	//**********************************************************************************************

	////迭代器
	////可读可写
	typedef T* iterator;
	//只读
	typedef const T* const_iterator;

	iterator begin() {
		//第一个元素的位置
		return _start;
	}

	iterator end() {
		//最后一个元素的下一个位置， 也就是最后一个元素的结束位置
		return _finish;
	}

	const_iterator begin() const {
		return _start;
	}

	const_iterator end() const {
		return _finish;
	}
	//val 默认值:内置类型: 0值,自定义类型:调用无参构造
	void resize(size_t n,const T& val=T()) {
		if (n > capacity())
			reserve(n);
		if (n>size) {
			*_finish++ = val;
		} else {
		  //更新size
			*_finish = _start + n;
		}
	}

	
                                            
private:
	T* _start;
	T* _finish;
	T* _eos;
};
//
template <class T>
void printVector(const Vector<T>& v) {
	cout << "operator[]:  " << endl;
	for (int i = 0; i < v.size();i++) {
		cout << v[i] << " ";
		//调用const接口,只读
		//v[i] = "a";
	}
	cout << endl;
	//*****************************************
	cout << "迭代器: " << endl;
	Vector<T>::const_iterator it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
	//范围for
	cout << "范围for :" << endl;
	for (const T& str : v) {
		cout << str << " ";

	}
	cout << endl;
	
}

//void test1() {
//
//	Vector<int> v1;
//	Vector<char> v2;
//	Vector<string> v3;
//
//	size_t size = v1.size();
//	cout << size << endl; 
//	size = v2.size();
//	cout << size << endl;
//	size = v3.size();
//	cout << size << endl;
//
//	size_t cap = v1.capacity();
//	cout << cap << endl;
//     cap = v2.capacity();
//	 cout << cap << endl;
//	 cap = v3.capacity();
//	 cout << cap << endl;
//}

//对于int类型来说不存在深浅拷贝的问题,有资源的时候才存在深浅拷贝的问题.
//void test2() {
//
//	Vector<int>v1;
//	v1.pushBack(1);
//	v1.pushBack(2);
//	v1.pushBack(3);
//	v1.pushBack(4);
//	v1.pushBack(5);
//	size_t size = v1.size();
//	size_t cap = v1.capacity();
//	cout << size << endl;
//	cout << cap << endl;
//}

//void test3() {
//	Vector<string>v1;
//	v1.pushBack("1");
//	v1.pushBack("2");
//	v1.pushBack("3");//在插入第三个元素的时候出现错误.
//	v1.pushBack("4");
//	size_t size = v1.size();
//	size_t cap = v1.capacity();
//	cout << size << endl;
//	cout << cap << endl;	
//
//}

void test4() {
	Vector<string>v1;
	v1.pushBack("1");
	v1.pushBack("2");
	v1.pushBack("3");//在插入第三个元素的时候出现错误.
	v1.pushBack("4");
	for (int i = 0; i < v1.size();i++) {
		cout << v1[i] << " ";
		//cout << v1.operator[](i) << " ";
		//修改操作:
		v1[i] = "a";
	}
	cout << endl;
	for (int i = 0; i < v1.size(); i++) {
		cout << v1.operator[](i) << " ";
		}
	cout << endl;
	//迭代器
	cout << "迭代器: " << endl;
	Vector<string>::iterator it = v1.begin();
	while (it != v1.end()) {
		cout << *it << " ";
		*it = "b";
		++it;
	}
	cout << endl;
	for (int i = 0; i < v1.size(); i++) {
		cout << v1.operator[](i) << " ";
	}
	cout << endl;
	cout << "范围for :" << endl;
	for (string& str : v1) {
		cout << str << " ";
		str = "c";
	}
	cout << endl;
  printVector(v1);

}
int main() {
	/*test1();
	test2();*/
	//test3();
	test4();
	system("pause");
	return 0;
}


















