//����ջʵ��һ�����е�C++����ʵ��/

//���⣺������ջʵ��һ�����У�����ڶ���β������ڵ���ڶ���ͷ��ɾ�����Ĺ��ܡ�
//����ջ���ص����Ƚ������Ҫ��ʵ�ֶ��У����������Ƚ��ȳ���
//���Ƚ��������뵽stack1�У���ʱ���Ƚ�������ٽ�stack1�е������ƶ���stack2�У��൱�ڽ���������ݵ�˳��ߵ�������Ҳ��ʵ���˶��е��ص㣬�Ƚ��ȳ����������˵һ�¶���ΪNULL����Ӻͳ��ӵľ���ʵ�ַ�����
//��1���ж϶����Ƿ�ΪNULL��stack1 == NULL && stack2 == NULL�������Ϊ�գ�
//��2�����ӣ����stack1ΪNULL��stack2��ΪNULL����stack2��ֱ�ӳ�ջ��Ҳ���ǳ����У�
//���stack1��ΪNULL, ��stack1�����ݳ�ջ��stack2�У���stack2��ֱ�ӳ�ջ��Ҳ���ǳ����У�
//��3����ӣ����stack2ΪNULL, ֱ����ջstack1��Ҳ������У�
//���stack2��ΪNULL, ��stack2��ջ��stack1�У�������ջstack1��Ҳ������У�

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
				cout << "�˶���Ϊ��" << endl;
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

//oj ����:
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