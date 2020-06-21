
两个队列实现一个栈（C++实现）

题目概述：用两个队列实现一个栈，请实现他的两个函数Push 和 Pop，分别完成入栈和出栈功能。
题目分析：我们知道队列结构的特点是“先进先出”，栈结构的特点的“先进后出”；仔细分析这道题，本道题的要求为将两个队列组合起来形成一个“先进后出”结构。
这里我们令第一个队列为queue1，第二个队列为queue2，起始两个队列均为空。

	//首先我们陆续向栈中压入元素a、b、c，这里我们先压入queue1中，此时queue1中的元素为{ a，b，c }（其中a为队首元素，c为队尾元素），queue2为空（如图a所示）；
	//
	//接下来我们考虑从栈中弹出一个元素，依据栈“先进后出”的原则，我们第一次弹出的元素应该是c，但是c是queue1中的队尾元素，我们并不能直接从queue1获取到c元素,
	//我们发现queue2此时为空，于是将queue1中的元素陆续弹出到queue2直至队尾元素留着队列中(如图b所示)；
	//
	//接下来继续从栈中弹出一个元素, 按照入栈顺序，应该出栈的是b，但是b是queue2的队尾元素，不能直接出栈, 发现这个时候queue1是空的，
	//于是将queue2中的元素依次出队到queue1直至队尾元素留在队列中(如图c所示)；
	//
	//考虑继续插入一个元素d(此时考虑是插入queue1还是queue2)如果queue1为空，则插入queue2, 如果queue2为空，则插入queue1，
	//如果两个队列均为空，则回到初始状态, 插入到queue1。此时queue1不为空，queue2为空，所以d插入queue1（如图queue1的元素为{ a，d }，
	//a为队首元素，d为队尾元素，queue2为空）；
	//
	//接着弹出一个元素，依照入栈顺序，此时应该弹出元素d，依据上述方法，可得图e所示结果；
	//
	//当queue1和queue2为空时，栈为空。

题目总结：

解决该题的关键主要在于两个关键：

<1>入栈元素应在放在那个队列中？？？

当两个队列均为空的时候，任意插入一个队列，当再次插入元素时，选择非空的队列进行插入；

<2>出栈时应该注意什么？？？

出栈时，将非空队列中的元素陆续出队并插入到空队列中直至非空队列只有队尾元素时；



#include<iostream>
#include<queue>
using namespace std;

template<typename T>
class CStack
{
public:
	CStack(){}
	~CStack(){}
	void push(const T &val)
	{
		if (queue1.empty() && queue2.empty())  //两个队列为空，则插入queue1
		{
			queue1.push(val);
		}

		if (queue1.empty())         //如果queue1为空，则插入queue2
		{
			queue2.push(val);
		}
		else
		{
			queue1.push(val);      //如果queue2为空，则插入queue1
		}
	}
	T pop()
	{
		if (queue1.empty())        //如果queue1为空
		{
			if (queue2.empty())    //如果queue2为空，则说明栈为空
			{
				throw new exception("stack is empty");
			}
			else
			{
				if (queue2.size() == 1)   //如过queue2只有一个元素，直接退出
				{
					T result = queue2.front();
					queue2.pop();
					return result;
				}
				else
				{
					while (queue2.size() != 1)  //依次退出队中元素，直到队列中只有队尾元素
					{
						queue1.push(queue2.front());
						queue2.pop();
					}
					T result = queue2.front();  //将队尾元素退出
					queue2.pop();
					return result;
				}
			}
		}




		else          //如果queue1不为空
		{
			if (queue1.size() == 1)     //如果queue1中只有队尾元素时，直接退出
			{
				T result = queue1.front();
				queue1.pop();
				return result;
			}
			else
			{
				while (queue1.size() != 1)  //依次退出queue1中的元素到queue2，直到queue1只有队尾元素
				{
					queue2.push(queue1.front());
					queue1.pop();
				}
				T result = queue1.front(); //将队尾元素弹出
				queue1.pop();
				return result;
			}
		}

	}
private:
	queue<T> queue1;
	queue<T> queue2;
};

int main()
{
	CStack<char> stack;

	//测试用例1:
	stack.push('a');           //元素a入栈
	stack.push('b');           //元素b入栈
	stack.push('c');           //元素c入栈
	cout << "第1次出栈元素是：" << stack.pop() << endl;
	cout << "第2次出栈元素是：" << stack.pop() << endl;
	stack.push('d');           //元素d入栈
	cout << "第3次出栈元素是：" << stack.pop() << endl;
	cout << "第4次出栈元素是：" << stack.pop() << endl;
	system("pause");
	return 0;
	
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

template <class T>
class Cstack {

public:

	void push(const T& val) {
		if (queue1.empty() && queue2.empty()) {
			queue1.push(val);
		}
		if (queue2.empty()) {
			queue1.push(val);
		}
		else {
			queue2.push(val);
		}
	}
	T pop() {
		if (queue1.empty()){
			if (queue2.empty()) {
				cout << "stack is empty" << endl;
			}
			else  {
				if (queue2.size() == 1) {
					T result = queue2.front();
					queue2.pop();
					return  result;
				}
				else {
					while (queue2.size() != 1) {
						queue1.push(queue2.front());
						queue2.pop();
					}
					T result = queue2.front();
					queue2.pop();
					return result;
				}
			}
		}
		else          //如果queue1不为空
		{
			if (queue1.size() == 1)     //如果queue1中只有队尾元素时，直接退出
			{
				T result = queue1.front();
				queue1.pop();
				return result;
			}

			else 	{
				while (queue1.size() != 1) {
					queue2.push(queue1.front());
					queue1.pop();
				}
				T result = queue1.front();
				queue1.pop();
				return result;
			}
		}

	}
private:
	queue<T> queue1;
	queue<T> queue2;
};


int main()
{
	Cstack<char> stack;

	//测试用例1:
	stack.push('a');           //元素a入栈
	stack.push('b');           //元素b入栈
	stack.push('c');           //元素c入栈
	stack.push('d');           //元素d入栈
	cout << "第1次出栈元素是：" << stack.pop() << endl;
	cout << "第2次出栈元素是：" << stack.pop() << endl;

	cout << "第3次出栈元素是：" << stack.pop() << endl;
	cout << "第4次出栈元素是：" << stack.pop() << endl;
	system("pause");
	return 0;

}
