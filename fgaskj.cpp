//******************************************ջ,����,���ȼ����м򵥽ӿ�ʹ��****************************************
//
//***************����ջҪʵ�ֳɵĽӿ�:*******************
//1.stack() ����ջ
//2.push()  ��ջ����
//3.pop() ��ջ����
//4.empty() �пղ���
//5.size() �ж�ջ����ЧԪ�صĴ�С
//6.top() ��ȡջ��Ԫ��

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
	cout << "ջ����ЧԪ�صĴ�С: " << st.size() << endl;
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

//��Сջ
class MinStack {

private:
	stack<int> st; //����һ����ͨջ
	stack<int> Minst; ////����һ����С��ͨջ
public:
	/** initialize your data structure here. */
	MinStack() {
	}

	void push(int x) {
		//��ջ����
		//��Сջ��һ����ŵ�����С��Ԫ��
		if (Minst.empty() || x <= Minst.top())
			Minst.push(x);

		st.push(x);//��ͨջ����ֱ�Ӵ��Ԫ��
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
//ջ�ĵ���ѹ��˳��
class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		//vector<int>& pushed��vector<int>& popped��ʾ��ջ���кͳ�ջ����
		int pushidx = 0;
		int popidx = 0;
		stack<int> st;
		while (pushidx < pushed.size()) {
			st.push(pushed[pushidx++]);//��ջ(ֻҪԪ��û�з����һֱ������ջ����) 
			//��ջ�������㲻�ǿ�,ͬʱջ����Ԫ���ǲ��ǵ��ڳ�ջ���е�Ԫ��
			while (!st.empty() && st.top() == popped[popidx]) {
				st.pop();
				popidx++;
			}
		}
		return st.empty();
	}
};

//********************���ڶ���Ҫʵ�ֳɵĽӿ�:****************************
//1.queue() ����յĶ���
//2.push() ��Ӳ���
//3.pop() ���Ӳ���
//4.front() ��ͷ
//5.back() ��β
//6.size() ��ЧԪ��
//7.empty()�п�
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
	cout << "���г���" << q.size() << endl;
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
//***************************���ȼ����м򵥽ӿ�ʹ��***************
//priority_queue: �ײ��ʵ����ͨ��������ɵ�.
//1. priority_queue() ����һ���յ����ȼ�����
//2.empty() ������ȼ������Ƿ�Ϊ��\
//3.top() ���ض����е���(С)��Ԫ��,���Ѷ�Ԫ��
//4.push() �����ȼ������в���Ԫ��
//5.ɾ�����ȼ����������(С)Ԫ��,���Ѷ�Ԫ��
//
//
////1.prioroty_queue�򵥽ӿ�ʹ��
//
////����Ĭ�����ȼ������ǽ����,���ǿ���ͨ��������������صķ�ʽ���д�С�������л��ؽ�.
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
//����Ĭ�����ȼ������ǽ����,���ǿ���ͨ��������������صķ�ʽ���д�С�ѵ������л��ؽ�.
//2.���ʵ���������������ʵ�ִ�С�ѵ������ؽ�.
//���÷º�����ģ��:  

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
		return c1 < c2; //����������غ���
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
	priority_queue<S, vector<S>, Greater<S>> pq;  //��С��
	//priority_queue<S, vector<S>, Less<S>> pq;  //�����
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
