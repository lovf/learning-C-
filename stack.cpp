//	stack 
#include <stack>
#include <iostream>
using namespace std;

//ջ�Ǻ���ȳ�
void test1() {
	stack<int> st;
	st.push(1);//��ջ����
	st.push(2);
	st.push(3);
	while ( !st.empty() ) {
	
		cout << st.top() << " "; //��ȡջ��Ԫ��    
		st.pop();//��ȡ��һ��Ԫ��֮ǰ,�����ȳ�ջ
	}

	cout << endl;
}

int main() {
	test1();
	system("pause");
	return 0;
}






















