//	stack 
#include <stack>
#include <iostream>
using namespace std;

//栈是后进先出
void test1() {
	stack<int> st;
	st.push(1);//入栈操作
	st.push(2);
	st.push(3);
	while ( !st.empty() ) {
	
		cout << st.top() << " "; //获取栈顶元素    
		st.pop();//获取下一个元素之前,必须先出栈
	}

	cout << endl;
}

int main() {
	test1();
	system("pause");
	return 0;
}






















