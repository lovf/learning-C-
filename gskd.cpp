//两个栈实现一个队列的C++代码实现/

//问题：用两个栈实现一个队列，完成在队列尾部插入节点和在队列头部删除结点的功能。
//由于栈的特点是先进后出，要想实现队列，必须做到先进先出；
//首先将数据输入到stack1中，这时候先进后出，再将stack1中的数据移动到stack2中，相当于将输入的数据的顺序颠倒，这样也就实现了队列的特点，先进先出。下面具体说一下队列为NULL，入队和出队的具体实现方法；
//（1）判断队列是否为NULL：stack1 == NULL && stack2 == NULL，则队列为空；
//（2）出队：如果stack1为NULL，stack2不为NULL，从stack2中直接出栈，也就是出队列；
//如果stack1不为NULL, 将stack1的数据出栈到stack2中，从stack2中直接出栈，也就是出队列；
//（3）入队：如果stack2为NULL, 直接入栈stack1，也即入队列；
//如果stack2不为NULL, 将stack2出栈到stack1中，数据入栈stack1，也即入队列；

#include <iostream>
#include <stack>
#include <stack>
#include <queue>
using namespace std;

template<class T>

class MyQueue {
public:
	void push(T t) {
		s1.push(t);
		cout << t << " ";
	}

	void pop() {
		if (s2.empty()) {
			while (!s1.empty()) {
				s2.push(s1.top());
				s1.pop();
			}
		}

		if (!s2.empty()) {
			s1.push(s2.top());
			s2.pop();
		}
	}

	T front()	{
		if (s2.empty()) {
			if (s1.empty())
				cout << "此队列为空" << endl;
			while (!s1.empty()) {
				s2.push(s1.top());
				s1.pop();
			}
		}

		return s2.top();
	}


private:
	stack<T> s1;
	stack<T> s2;
};


int main() {
	MyQueue<int> mq;
	cout << "inQueue: " << endl;
	mq.push(1);
	mq.push(2);
	mq.push(3);
	mq.push(4);
	mq.push(5);
	mq.push(6);
	mq.push(7);
	cout << endl;
	cout << "outQueue: " << endl;;
	for (int i = 0; i < 7; i++) {

		cout << mq.front() << " ";
		mq.pop();
	}
	cout << endl;
	system("pause");
	return 0;
}

//oj 里面:
//class CQueue {
//public:
//	CQueue() {
//
//	}
//
//	void appendTail(int value) {
//		in.push(value);
//	}
//
//	int deleteHead() {
//		if (out.empty()){
//			while (!in.empty()){
//				out.push(in.top());
//				in.pop();
//			}
//		}
//		if (out.empty()) return -1;
//		else{
//			int del = out.top();
//			out.pop();
//			return del;
//		}
//	}
//private:
//	stack<int> in;
//	stack<int> out;
//
//};