//******************************************栈,队列,优先级队列简单接口使用****************************************
//
//***************对于栈要实现成的接口:*******************
//1.stack() 构造栈
//2.push()  入栈操作
//3.pop() 出栈操作
//4.empty() 判空操作
//5.size() 判定栈中有效元素的大小
//6.top() 获取栈顶元素

#include <stack>
#include <iostream>
using namespace  std;

void test1() {
	stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	cout << "栈中有效元素的大小: " << st.size() << endl;
	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
}

int main() {
	test1();
	system("color A");
	system("pause");
	return 0;
}

//最小栈
class MinStack {

private:
	stack<int> st; //构建一个普通栈
	stack<int> Minst; ////构建一个最小普通栈
public:
	/** initialize your data structure here. */
	MinStack() {
	}

	void push(int x) {
		//入栈操作
		//最小栈中一定存放的是最小的元素
		if (Minst.empty() || x <= Minst.top())
			Minst.push(x);

		st.push(x);//普通栈里面直接存放元素
	}

	void pop() {
		if (st.top() == Minst.top())
			Minst.pop();

		st.pop();
	}

	int top() {
		return st.top();
	}

	int getMin() {
		return Minst.top();
	}
};
//栈的弹出压入顺序
class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		//vector<int>& pushed和vector<int>& popped表示入栈序列和出栈序列
		int pushidx = 0;
		int popidx = 0;
		stack<int> st;
		while (pushidx < pushed.size()) {
			st.push(pushed[pushidx++]);//入栈(只要元素没有放完就一直进行入栈操作) 
			//出栈必须满足不是空,同时栈顶的元素是不是等于出栈序列的元素
			while (!st.empty() && st.top() == popped[popidx]) {
				st.pop();
				popidx++;
			}
		}
		return st.empty();
	}
};

//********************对于队列要实现成的接口:****************************
//1.queue() 构造空的队列
//2.push() 入队操作
//3.pop() 出队操作
//4.front() 队头
//5.back() 队尾
//6.size() 有效元素
//7.empty()判空
//
#include <queue>
#include <iostream>
using namespace  std;

void test2() {
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	cout << "队列长度" << q.size() << endl;
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;

}
int main() {
	test2();
	system("color A");
	system("pause");
	return 0;
}
//***************************优先级队列简单接口使用***************
//priority_queue: 底层的实现是通过堆来完成的.
//1. priority_queue() 构造一个空的优先级队列
//2.empty() 检查优先级队列是否为空\
//3.top() 返回队列中的最(小)大元素,即堆顶元素
//4.push() 在优先级队列中插入元素
//5.删除优先级队列中最大(小)元素,即堆顶元素
//
//
////1.prioroty_queue简单接口使用
//
////本身默认优先级队列是建大堆,但是可以通过括号运算符重载的方式进行大小的任意切换重建.
#include<stack>
#include <queue>
#include <vector>
#include <iostream>
using namespace  std;

void test1() {
	priority_queue<int> pq;
	pq.push(10);
	pq.push(1);
	pq.push(15);
	pq.push(20);
	pq.push(2);
	pq.push(4);
	pq.push(19);
	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;

}

int main() {
	test1();
	system("color A");
	system("pause");
	return 0;
}
//本身默认优先级队列是建大堆,但是可以通过括号运算符重载的方式进行大小堆的任意切换重建.
//2.如何实现括号运算符重载实现大小堆的任意重建.
//借用仿函数类模板:  

#include<queue>
#include <stack>
#include <vector>
#include <iostream>
using namespace  std;

class S{
public:
	S(int a = 0, int b = 0, int c = 0)
		:_a(a)
		, _b(b)
		, _c(c)
	{}
	bool operator<(const S& c) const{
		return _a < c._a;
	}
	bool operator>(const S& c) const{
		return _a > c._a;
	}

	int _a;
	int _b;
	int _c;

};

template<class T>
struct Less {

	bool operator()(const T& c1, const T& c2) {
		return c1 < c2; //这块会调用重载函数
	}
};

template<class T>

struct Greater{
	bool operator()(const T& c1, const T& c2) {
		return c1 > c2;
	}
};

ostream& operator<<(ostream& cout, const S& c) {
	cout << c._a << "-" << c._b << "-" << c._c << endl;
	return cout;
}

void test1() {
	priority_queue<S, vector<S>, Greater<S>> pq;  //建小堆
	//priority_queue<S, vector<S>, Less<S>> pq;  //建大堆
	pq.push(S(1, 1, 1));
	pq.push(S(2, 1, 1));
	pq.push(S(3, 1, 1));
	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;

}
int main() {


	test1();
	system("color A");
	system("pause");
	return 0;
}
