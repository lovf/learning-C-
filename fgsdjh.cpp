//stack和queue实现:
//stack:
//1.stack()构造空的栈
//2.empty() 检查栈是否为空
//3.size() 返回栈中元素的个数
//4.top()  返回栈顶元素的引用
//5.push() 入栈操作
//6.pop()出栈操作

//栈也是一个泛型参数
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
//实现一个最小栈
//用两个栈来实现一个最小栈
//
//class MinStack {
//
//private:
//	stack<int> st; //构建一个普通栈
//	stack<int> Minst; ////构建一个最小普通栈
//public:
//	/** initialize your data structure here. */
//	MinStack() {
//	}
//
//	void push(int x) {
//		//入栈操作
//		//最小栈中一定存放的是最小的元素
//		if (Minst.empty() || x <= Minst.top())
//			Minst.push(x);
//
//		st.push(x);//普通栈里面直接存放元素
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

//栈的压入,弹出序列:

//输入两个整数序列,第一个序列表示栈的压入顺序,判断第二个栈是否是该站的弹出顺序

//class Solution {
//public:
//	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
//		//pushedh和 popped分别表示栈的压入弹出序列
//		int pushidx = 0;
//		int popidx = 0;
//		stack<int>  st;
//		while (pushidx < pushed.size()) {
//			//先入栈
//			st.push(pushed[pushidx++]);
//			while (!st.empty() && st.top() == popped[popidx]) {
//				st.pop();
//				popidx++;
//			}
//		}
//		return st.empty();
//	}
//};
////解决该题的核心是判定栈顶元素是否与出栈序列的元素相等

// 逆波兰表达式
//queue:
//1.queue() 构造空的队列
//2.empty()  检查队列是否为空,是返回true,否则返回false
//3.size() 返回队列中有效元素
//4.front() 返回队头元素的引用
//5.back() 返回队尾元素的引用
//6.push() 在队尾将元素入队
//7.pop() 将队头元素出队列
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

//优先级队列: 底层实现  堆
//本身默认的话优先级队列是建大堆,但是可以通过我们的括号运算符重载("()")进行进行大小堆的任意重建
#include<list>
#include <stack>
#include <vector>
#include <queue>
#include <iostream>
using namespace  std;
//
//void test1() {
//	//通过堆实现,默认是大堆,
//	priority_queue<int> pq;
//	pq.push(10);
//	pq.push(1);
//	pq.push(15);
//	pq.push(20);
//	pq.push(2);
//	pq.push(4);
//	pq.push(19);
//	while (!pq.empty()) {
//		cout << pq.top() << " "; //输出从大到小进行输出
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

//仿函数类模板 : 目的是为了建小堆
template<class T>

struct Less {
	//重载括号运算符
	bool operator() (const T& c1, const T& c2) {
		return c1 < c2;
	}
};


template<class T>

struct Greater {
	//重载括号运算符
	bool operator() (const T& c1, const T& c2) {
		return c1 > c2;
	}
};

ostream& operator<<(ostream&  cout, const C& c) {

	cout << c._a << "-" << c._b << "-" << c._c << endl;
	return cout;
}

void test2() {
	//优先级队列存放自定义类型,自定义类型需要支持大小比较运算
	//建大堆,需要提供小于的比较
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
//	ret = 1c(c1, c2);//等价于1c.operator()(c1, c2);
//}
void test4() {
	//优先级队列存放自定义类型,自定义类型需要支持大小比较运算
	//建小堆,需要提供进行大于比较的仿函数类

	//priority_queue<C, vector<C>, Less<C>> pq;//建大堆
	priority_queue<C,vector<C>,Greater<C>> pq; //建小堆

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

	//queue不能vector实现
	//queue<int, vector<int>> q;
	//q.push(2);

	//priority_queue不能list实现
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

//利用仿函数实现建小堆:
//仿函数:STL组件
//使用方式类似于函数的的类---->重载圆括号"()" 运算符重载函数
//仿函数对象:
//由仿函数创建的对象

//容器适配器: STL组件
//stack,queue,priority_queue 底层都是线性表(受限的线性表) stack: 只允许尾插尾删操作的线性表 queue:只进行尾删和头插的线性表 priority_queue :只能进行尾插和尾删的线性表
//通过适配器的设计模式定义的新的数据结构.
//适配器: 把一种接口转化为另一种接口的方法



//stack: 实现 vector,list,deque 默认实现: deque
//stack实现规范:
//1.只要容器包含一下接口,都可以作为stack的底层容器.
//push_back()--->push
//pop_back()--->pop
//front--->top
//size--->size
//empty--->empty

//queue: 实现 list,deque 默认实现:deque
//queue实现规范:
//只要容器宝含一下接口,都可以作为queue的底层容器
//push_back()--->push
//pop_front()--->pop
//front--->front
//size--->size
//empty--->empty
//vector不能实现queue,因为其不提供pop_front接口


//priority_queue 实现vector,deque    默认实现:vector

//只要容器宝含一下接口,其容器本身支持随机访问们都可以作为 priority_queue的底层容器

//push_back()--->push
//pop_back()--->pop
//front--->top
//size--->size
//empty--->empty
//list不能实现priority_queue,因为其不支持随机访问







