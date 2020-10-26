
//start :空间的首地址,第一个元素的首地址
//finish :最后一个元素的结束位置
//end_of_storage :空间的结束位置
#include <string>
#include <vector>
#include <iostream>
using namespace  std;
template<class T>

class Vector{
public:
	Vector()
		:_start(nullptr)
		, _finish(nullptr)
		, _eos(nullptr)
	{
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//有效元素个数
	size_t size() const {
		return _finish - _start;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//空间容量大小
	size_t capacity() const {
		return _eos - _start;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//增容的接口(重点)
	void reserve(size_t n) {
		size_t oldsize = size(); //把未修改之前的size()先保存下来
		//增加容量
		if (n > capacity()) {
			//1.开空间
			T* tmp = new T[n];
			//2.拷贝:内存拷贝,浅拷贝
			//memcpy(tmp, _start, sizeof(T)*size());
			//2.深拷贝
			for (int i = 0; i < size(); i++) {
				tmp[i] = _start[i];
			}
			//3.释放原有空间

			delete[] _start;
			//4.更新空间指向,容量
			_start = tmp;
			_finish = _start + oldsize; //新开空间之后再
			_eos = _start + n;
		}
	}
	//插入: 存在的是深拷贝:调用T类型的赋值运算符
	void pushBack(const T& val) {
		//空间满了:_eos == _finish(最后一个元素的位置等于空间的位置)
		//1.检查容量
		if (_eos == _finish) {
			size_t newC = capacity() == 0 ? 1 : 2 * capacity();
			reserve(newC);
		}
		//2.插入
		*_finish = val;
		//3.更新
		++_finish;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//operator[]:可读可写(重点)
	T& operator[](size_t pos) {
		if (pos < size())
			return _start[pos];
	}
	//只读接口
	const T& operator[](size_t pos) const {
		if (pos < size())
			return _start[pos];
	}
	//迭代器:
	typedef T* iterator;
	typedef const T* const_iterator;

	iterator begin() {
		//第一个元素位置
		return _start;
	}

	iterator end() {
		//最后一个元素的下一个位置
		return _finish;
	}
	const_iterator begin() const {
		//第一个元素位置
		return _start;
	}

	const_iterator end() const {
		//最后一个元素的下一个位置
		return _finish;
	}
	//val默认值:内置类型:0值,自定义类型:调用无参构造
	void resize(size_t n, const T& val = T()) {
		if (n > capacity()) { //大于容量需要扩容
			reserve(n);
		}
		if (n > size()) { //大于size需要填充
			while (_finish != _start + n) {
				*_finish++ = val;

			}
		}
		//更新size
		_finish = _start + n;
	}
	//插入(重点)
	void insert(iterator pos, const T& val) {
		if (pos >= _start && pos <= _finish) { //保证是一个有效元素的位置
			//检查容量
			if (_finish == _eos) {
				//增容会导致迭代器失效,如果发生了增容,更新迭代器
				//保存原始位置
				int len = pos - _start;  //增容的偏移量
				size_t newC = capacity() == 0 ? 1 : 2 * capacity();
				reserve(newC);
				//更新迭代器
				pos = _start + len;//类似于此时pos的位置已经发生了改变
			}
			//移动元素
			iterator end = _finish;
			while (end > pos) {
				*end = *(end - 1);
				--end;
			}
			//插入元素
			*pos = val;
			//更新
			++_finish;
		}
	}

	//返回迭代器:执行当前被删除元素的下一个元素的位置
	iterator erase(iterator pos) {
		if (pos >= _start && pos < _finish) {
			//移动元素(从前向后移动)
			iterator begin = pos;
			while (begin != _finish) {
				*(begin - 1) = *begin;//  *begin=*(begin + 1); 当是最后一个元素时会出现越界行为
				++begin;
			}
			//更新size
			--_finish;
		}
		return pos; //传的什么返回什么
	}
private:
	T* _start; //空间的首地址,第一个元素的首地址
	T* _finish;//最后一个元素的结束位置
	T* _eos;//end_of_storage 空间的结束位置

};
template<class T>

void PrintVec(const Vector<T>& v1) {
	cout << "operator[]" << endl;
	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << " ";
		//写操作
		//v1[i] = "a";
	}
	cout << endl;


	cout << "范围for" << endl;
	for (const T& str : v1) {
		cout << str << " ";

	}
	cout << endl;
}

void test1() {
	Vector<int> v1;
	Vector<char> v2;
	Vector<string> v3;

	size_t size = v1.size();
	size = v2.size();
	size = v3.size();

	size_t capacity = v1.capacity();
	capacity = v2.capacity();
	capacity = v3.capacity();

}

void test2() {

	Vector<int> v1;
	v1.pushBack(1);
	size_t size = v1.size();
	size_t cap = v1.capacity();

	v1.pushBack(1);
	size = v1.size();
	cap = v1.capacity();

	v1.pushBack(2);
	size = v1.size();
	cap = v1.capacity();

	v1.pushBack(3);
	size = v1.size();
	cap = v1.capacity();

	v1.pushBack(4);
	size = v1.size();
	cap = v1.capacity();

}
void test3() {
	Vector<string> v1;
	v1.pushBack("1");
	v1.pushBack("2");
	v1.pushBack("3");
	v1.pushBack("4");

}
void test4() {

	Vector<string> v1;
	v1.pushBack("1");
	v1.pushBack("2");
	v1.pushBack("3");

	PrintVec(v1);
	//迭代器
	Vector<string>::iterator it = v1.begin();
	cout << "iterator" << endl;
	while (it != v1.end()) {
		cout << *it << " ";
		it++;
	}
	cout << endl;

}

void test5() {

	Vector<int> v1;
	Vector<char> v2;
	Vector<string> v3;

	v1.resize(5);
	v2.resize(5);
	v3.resize(5);

}

void test6() {
	Vector<int> v1;

	v1.insert(v1.end(), 1);
	v1.insert(v1.end(), 2);
	v1.insert(v1.end(), 3);
	v1.insert(v1.end(), 4);
	v1.insert(v1.end(), 5);
	v1.insert(v1.end(), 6);
	v1.insert(v1.end(), 7);
	v1.insert(v1.end(), 8);
	PrintVec(v1);
}

void test7() {
	Vector<int> v1;

	v1.insert(v1.end(), 1);
	v1.insert(v1.end(), 2);
	v1.insert(v1.end(), 3);
	v1.insert(v1.end(), 4);
	v1.insert(v1.end(), 5);
	v1.insert(v1.end(), 6);
	v1.insert(v1.end(), 7);
	v1.insert(v1.end(), 8);
	PrintVec(v1);

	v1.erase(v1.begin());
	PrintVec(v1);
	v1.erase(v1.begin());
	PrintVec(v1);
	v1.erase(v1.begin());
	PrintVec(v1);
	v1.erase(v1.begin());
	PrintVec(v1);
	v1.erase(v1.begin());
	PrintVec(v1);
	v1.erase(v1.begin());
	PrintVec(v1);

	v1.erase(v1.end() - 1);//当删除end-1会出现问题
	PrintVec(v1);
}

void test8() {

	Vector<int> v1;

	v1.insert(v1.end(), 1);
	v1.insert(v1.end(), 2);
	v1.insert(v1.end(), 3);
	v1.insert(v1.end(), 4);
	v1.insert(v1.end(), 5);
	v1.insert(v1.end(), 6);
	v1.insert(v1.end(), 7);
	PrintVec(v1);

	Vector<int>::iterator it = v1.begin();
	while (it != v1.end()) {
		if (*it % 2 == 1)
			v1.erase(it);
		else
			++it;
	}
	PrintVec(v1);
}
int main() {

	//test1();
	//test2();
	//test3();
	//test4();
	//test6();
	//test5();
	//test7();
	test8();
	system("color A");
	system("pause");
	return 0;
}


//1.深浅拷贝: reserve
//2.迭代器失效:insert,erase
//3.resize:默认值:内置: 0 自定义: 默认构造
//4.迭代器:T*
//begin: start
//end:finish