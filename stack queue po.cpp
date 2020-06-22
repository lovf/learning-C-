
////栈  队列  优先级队列
////1. 栈 
////接口 push pop front size empty
////
#include <queue>
#include <vector>
#include <list>
#include <iostream>
using namespace std;


template <class T,class Container = queue<T>> //后面这块是栈里面的一个容器

class Stack{

public:

	void push(const T& val) {
		_c.push_back(val);
	}
	void pop() {
		_c.pop_back();
	}
	const T& top() { //一般不修改栈顶元素,因此返回值为const
		return _c.back();
	}
	size_t size() const {
		return _c.size();
	}
	bool empty() const {
		return _c.empty();
	}


private:
	Container _c;

};
void  test1() {
	//Stack<int> st;
	//Stack<int,list<int>> st;
   //Stack<int ,vector<int>> st;
	Stack<int,deque<int>> st;

	cout << "入栈元素: ";
	st.push(1);
	cout << st.top() << " ";
	st.push(2);
	cout << st.top() << " ";
	st.push(3);
	cout << st.top() << " ";
	st.push(4);
	cout << st.top() << " ";
	cout << endl;
	cout << "出栈元素: ";
	while ( !st.empty()) {
		cout << st.top() << " ";
		st.pop();//删除栈顶元素
	}
	cout << endl;
}
int main() {
	test1();
	system("pause");
	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//2.队列 
//接口 push pop front size empty
//vector 不支持实现队列,因为vector不支持头删
#include <queue>
#include <vector>
#include <list>
#include <iostream>
using namespace std;


template <class T, class Container = deque<T>> //后面这块是队列里面的一个容器
class Queue{

public:

	void push(const T& val) {
		_c.push_back(val);
	}
	void pop() {
		_c.pop_front();
	}
	const T& front() { //一般不修改栈顶元素,因此返回值为const
		return _c.front();
	}

	const T& back() { //一般不修改栈顶元素,因此返回值为const
		return _c.back();
	}
	size_t size() const {
		return _c.size();
	}
	bool empty() const {
		return _c.empty();
	}
private:
	Container _c;

};
void  test2() {
	//Queue<int> q;
	Queue<int,list<int>> q;
	//vector 不能实现 
	cout << "入队: ";
	q.push(1);
	cout << q.front() << " ";
	q.pop();
	q.push(2);
	cout << q.front() << " ";
	q.pop();
	q.push(3);
	cout << q.front() << " ";
	q.pop();
	q.push(4);
	cout << q.front() << " ";
	q.pop();
	cout << endl;

	cout << "出队: ";
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}
int main() {
	test2();
	system("pause");
	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//priority_queue  的简单实现

//通过堆实现,默认为大堆
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void test1() {
	priority_queue<int>pq;

	pq.push(1);
	pq.push(2);
	pq.push(3);
	pq.push(4);
	pq.push(5);
	pq.push(6);
	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}

int main() {
	test1();
	system( "pause");
	return 0;
}

//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;


template <class T, class Container = vector<T>>
class Priority_Queue {
public:
	void push(const T& val) {
		_c.push_back(val);
		shiftUp(_c.size() - 1);
	}

	void pop() {
		swap(_c[0], _c[_c.size() - 1]);
		_c.pop_back();
		shiftDown(0);
	}

	T& top() {
		return _c.front();
	}

	size_t size() const {
		return _c.size();
	}

	bool empty() const {
		return _c.empty();
	}

private:
	void shiftDown(int parent) {
		int child = 2 * parent + 1;
		while (child < _c.size()) {
			if (child + 1 < _c.size() && _c[child] > _c[child + 1])
				++child;
			if (_c[parent] > _c[child]) {
			
				swap(_c[parent], _c[child]);
				parent = child;
				child = 2 * parent + 1;
			}
			else
				break;
		}
	}

	void shiftUp(int child) {
		int parent = (child - 1) / 2;
		while (child > 0) {
			if (_c[parent] > _c[child]){
			
				swap(_c[parent], _c[child]);
				child = parent;
				parent = (child - 1) / 2;
			}
			else
				break;
		}
	}
private:
	Container _c;
	
};

void test2() {

	Priority_Queue<int, vector<int>> pq;
	int n = 200;
	for (int i = 0; i < n; i++) {
		pq.push(i);
	}

	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}                                                                   

int main() {
	test2();
	system("pause");
	return 0;
}
///////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////自定义类型输出大堆还是小堆
////利用模板参数进行确定
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

template <class T>
//圆括号运算符重载
struct Greater {
	bool operator()(const T& val1, const T& val2) {
		return val1 > val2;
	}
};
template <class T>
struct Less {
	bool operator()(const T& val1, const T& val2)
	{
		return val1 < val2;
	}
};

class Date {
public:
	Date(int y, int m, int d)
		:_y(y)
		,
		_m(m)
		,
		_d(d)
	{}

	bool operator > (const Date& d) const {

		if (_y > d._y)
			return true;
		else if (_y == d._y) {
			if (_m > d._m)
				return true;
			else if (_m == d._m) {
				if (_d > d._d)
					return true;
			}
		}
		return false;

	}
	bool operator < (const Date& d) const {

		if (_y < d._y)
			return true;
		else if (_y == d._y) {
			if (_m < d._m)
				return true;
			else if (_y == d._y && _m == d._m) { 
				if (_d < d._d)
					return true;
			}
		}
		return false;
	}


public:
	int _y;
	int _m;
	int _d;

};

ostream& operator<<(ostream& cout, const Date& d){

	cout << d._y << "-" << d._m << "-" << d._d << endl;
	return cout;

}

template <class T, class Container = vector<T>, class Compare = Greater<T>>

class Priority_Queue {
public:
	void push(const T& val) {
		_c.push_back(val);
		shiftUp(_c.size() - 1);
	}
	void pop() {
		swap(_c[0], _c[_c.size() - 1]);
		_c.pop_back();
		shiftDown(0);
	}

	T& top() {
		return _c.front();
	}

	size_t size() const {
		return _c.size();
	}

	bool empty() const {
		return _c.empty();
	}
private:
	void shiftDown(int parent) {
		int child = 2 * parent + 1;
		while (child < _c.size()) {
			if (child + 1 < _c.size() && _c[child] > _c[child + 1])
				++child;
			if (_c[parent] > _c[child]) {

				swap(_c[parent], _c[child]);
				parent = child;
				child = 2 * parent + 1;
			}
			else
				break;
		}
	}

	void shiftUp(int child) {
		int parent = (child - 1) / 2;
		while (child > 0) {
			if (_c[parent] > _c[child]){

				swap(_c[parent], _c[child]);
				child = parent;
				parent = (child - 1) / 2;
			}
			else
				break;
		}
	}
private:
	Container _c;
	Compare _cmp;
};

void test() {
	Priority_Queue<Date, deque<Date>, Greater<Date>> pq;
	pq.push(Date(2020, 5, 31));
	pq.push(Date(2022, 5, 31));
	pq.push(Date(2008, 5, 31));
	pq.push(Date(2025, 5, 31));
	pq.push(Date(2020, 12, 31));
	pq.push(Date(2020, 5, 3));

	while (!pq.empty()) {
		cout << pq.top();
		pq.pop();
	}

}
int main() {
	
	test();
	system("pause");
	return 0;
}






















