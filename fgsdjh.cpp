//stack��queueʵ��:
//stack:
//1.stack()����յ�ջ
//2.empty() ���ջ�Ƿ�Ϊ��
//3.size() ����ջ��Ԫ�صĸ���
//4.top()  ����ջ��Ԫ�ص�����
//5.push() ��ջ����
//6.pop()��ջ����

//ջҲ��һ�����Ͳ���
//#include <stack>
//#include <iostream>
//using namespace  std;
//
//
//void test1() {
//	stack<int> st;
//	st.push(1);
//	st.push(2);
//	st.push(3);
//	st.push(4);
//	st.push(5);
//	while (! st.empty()) {
//		cout << st.top() << " ";
//		st.pop();
//	}
//	cout << endl;
//}
//int main () {
//
//	test1();
//    system("color A");
//    system ("pause");
//    return 0;
//}
//ʵ��һ����Сջ
//������ջ��ʵ��һ����Сջ
//
//class MinStack {
//
//private:
//	stack<int> st; //����һ����ͨջ
//	stack<int> Minst; ////����һ����С��ͨջ
//public:
//	/** initialize your data structure here. */
//	MinStack() {
//	}
//
//	void push(int x) {
//		//��ջ����
//		//��Сջ��һ����ŵ�����С��Ԫ��
//		if (Minst.empty() || x <= Minst.top())
//			Minst.push(x);
//
//		st.push(x);//��ͨջ����ֱ�Ӵ��Ԫ��
//	}
//
//	void pop() {
//		if (st.top() == Minst.top())
//			Minst.pop();
//
//		st.pop();
//	}
//
//	int top() {
//		return st.top();
//	}
//
//	int getMin() {
//		return Minst.top();
//	}
//};

//ջ��ѹ��,��������:

//����������������,��һ�����б�ʾջ��ѹ��˳��,�жϵڶ���ջ�Ƿ��Ǹ�վ�ĵ���˳��

//class Solution {
//public:
//	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
//		//pushedh�� popped�ֱ��ʾջ��ѹ�뵯������
//		int pushidx = 0;
//		int popidx = 0;
//		stack<int>  st;
//		while (pushidx < pushed.size()) {
//			//����ջ
//			st.push(pushed[pushidx++]);
//			while (!st.empty() && st.top() == popped[popidx]) {
//				st.pop();
//				popidx++;
//			}
//		}
//		return st.empty();
//	}
//};
////�������ĺ������ж�ջ��Ԫ���Ƿ����ջ���е�Ԫ�����

// �沨�����ʽ
//queue:
//1.queue() ����յĶ���
//2.empty()  �������Ƿ�Ϊ��,�Ƿ���true,���򷵻�false
//3.size() ���ض�������ЧԪ��
//4.front() ���ض�ͷԪ�ص�����
//5.back() ���ض�βԪ�ص�����
//6.push() �ڶ�β��Ԫ�����
//7.pop() ����ͷԪ�س�����
//
//#include <queue>
//#include <iostream>
//using namespace  std;
//
//void test1() {
//	queue<int> q;
//	q.push(1);
//	q.push(2);
//	q.push(3);
//	q.push(4);
//
//	while (!q.empty()) {
//		cout << q.front() << " ";
//		q.pop();
//	}
//
//	cout << endl;
//}
//
//int main() {
//	test1();
//	system("color A");
//	system("pause");
//	return 0;
//}

//���ȼ�����: �ײ�ʵ��  ��
//����Ĭ�ϵĻ����ȼ������ǽ����,���ǿ���ͨ�����ǵ��������������("()")���н��д�С�ѵ������ؽ�
#include<list>
#include <stack>
#include <vector>
#include <queue>
#include <iostream>
using namespace  std;
//
//void test1() {
//	//ͨ����ʵ��,Ĭ���Ǵ��,
//	priority_queue<int> pq;
//	pq.push(10);
//	pq.push(1);
//	pq.push(15);
//	pq.push(20);
//	pq.push(2);
//	pq.push(4);
//	pq.push(19);
//	while (!pq.empty()) {
//		cout << pq.top() << " "; //����Ӵ�С�������
//		pq.pop();
//	}
//	cout << endl;
//}

struct C {

	C(int a = 0, int b = 0, int c = 0)
	:_a(a)
	, _b(b)
	, _c(c)
	{}
	bool operator<(const C& c) const{
		return _a < c._a;
	}
	
	bool operator>(const C& c) const{
		return _a > c._a;
	}

	int _a;
	int _b;
	int _c;
};

//�º�����ģ�� : Ŀ����Ϊ�˽�С��
template<class T>

struct Less {
	//�������������
	bool operator() (const T& c1, const T& c2) {
		return c1 < c2;
	}
};


template<class T>

struct Greater {
	//�������������
	bool operator() (const T& c1, const T& c2) {
		return c1 > c2;
	}
};

ostream& operator<<(ostream&  cout, const C& c) {

	cout << c._a << "-" << c._b << "-" << c._c << endl;
	return cout;
}

void test2() {
	//���ȼ����д���Զ�������,�Զ���������Ҫ֧�ִ�С�Ƚ�����
	//�����,��Ҫ�ṩС�ڵıȽ�
	priority_queue<C> pq;
	pq.push(C(1, 1, 1));
	pq.push(C(2, 1, 1));
	pq.push(C(3, 1, 1));
	

	while (!pq.empty()) {
		cout << pq.top();
		pq.pop();
	}
	cout << endl;
}
//
//void test3() {
//	Less<C> 1c;
//	C c1(1, 2, 3);
//	C c2(2, 2, 2);
//	bool ret = 1c.operator()(c1, c2);
//	ret = 1c(c1, c2);//�ȼ���1c.operator()(c1, c2);
//}
void test4() {
	//���ȼ����д���Զ�������,�Զ���������Ҫ֧�ִ�С�Ƚ�����
	//��С��,��Ҫ�ṩ���д��ڱȽϵķº�����

	//priority_queue<C, vector<C>, Less<C>> pq;//�����
	priority_queue<C,vector<C>,Greater<C>> pq; //��С��

	pq.push(C(1, 1, 1));
	pq.push(C(2, 1, 1));
	pq.push(C(3, 1, 1));


	while (!pq.empty()) {
		cout << pq.top();
		pq.pop();
	}
	cout << endl;
}

void test5() {
	stack<int, list<int>> st1;
	st1.push(1);
	stack<int, vector<int>> st2;
	st2.push(2);
	stack<int, deque<int>> st3;
	st3.push(2);


	queue<int, list<int>> q1;
	q1.push(1);
	queue<int,deque<int>> q2;
	q2.push(2);

	//queue����vectorʵ��
	//queue<int, vector<int>> q;
	//q.push(2);

	//priority_queue����listʵ��
	priority_queue<int, vector<int>> pq2;
	pq2.push(1);
	priority_queue<int, deque<int>> pq3;
	pq3.push(1);


}
int main() {
	//test1();
	//test2();
	//test3();

	//test4();
	test5();
	system("color A");
	system("pause");
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//���÷º���ʵ�ֽ�С��:
//�º���:STL���
//ʹ�÷�ʽ�����ں����ĵ���---->����Բ����"()" ��������غ���
//�º�������:
//�ɷº��������Ķ���

//����������: STL���
//stack,queue,priority_queue �ײ㶼�����Ա�(���޵����Ա�) stack: ֻ����β��βɾ���������Ա� queue:ֻ����βɾ��ͷ������Ա� priority_queue :ֻ�ܽ���β���βɾ�����Ա�
//ͨ�������������ģʽ������µ����ݽṹ.
//������: ��һ�ֽӿ�ת��Ϊ��һ�ֽӿڵķ���



//stack: ʵ�� vector,list,deque Ĭ��ʵ��: deque
//stackʵ�ֹ淶:
//1.ֻҪ��������һ�½ӿ�,��������Ϊstack�ĵײ�����.
//push_back()--->push
//pop_back()--->pop
//front--->top
//size--->size
//empty--->empty

//queue: ʵ�� list,deque Ĭ��ʵ��:deque
//queueʵ�ֹ淶:
//ֻҪ��������һ�½ӿ�,��������Ϊqueue�ĵײ�����
//push_back()--->push
//pop_front()--->pop
//front--->front
//size--->size
//empty--->empty
//vector����ʵ��queue,��Ϊ�䲻�ṩpop_front�ӿ�


//priority_queue ʵ��vector,deque    Ĭ��ʵ��:vector

//ֻҪ��������һ�½ӿ�,����������֧����������Ƕ�������Ϊ priority_queue�ĵײ�����

//push_back()--->push
//pop_back()--->pop
//front--->top
//size--->size
//empty--->empty
//list����ʵ��priority_queue,��Ϊ�䲻֧���������







