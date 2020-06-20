1.��Сջ
���һ��֧�� push ��pop ��top �����������ڳ���ʱ���ڼ�������СԪ�ص�ջ��
push(x) ���� ��Ԫ�� x ����ջ�С�
pop() ���� ɾ��ջ����Ԫ�ء�
top() ���� ��ȡջ��Ԫ�ء�
getMin() ���� ����ջ�е���СԪ�ء�

ʾ�� :

���룺
["MinStack", "push", "push", "push", "getMin", "pop", "top", "getMin"]
[[], [-2], [0], [-3], [], [], [], []]

�����
[null, null, null, null, -3, null, 0, -2]

���ͣ�
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   -- > ���� - 3.
minStack.pop();
minStack.top();      -- > ���� 0.
minStack.getMin();   -- > ���� - 2.

��������ջ����ķ�������򵥵�
**��������ջ ,���ڴ��ջ�е���Сֵ
////
��Сջ ������ջ����
����˼·��
����һ������ջminSt�����ڴ��ȡstack����Сֵ��
////
�㷨����:
 push ()����: ÿ��push()�½���ֵʱ,������xС�ڵ���minSt�е�ֵʱ,��һ��ִ��push()����  minSt.push(x)  st.push(x)
 pop() ����: �жϽ�pop()��ȥ��Ԫ��ֵ�Ƿ���minStջ��Ԫ��ֵ������Сֵ�����������minStջ��Ԫ��һ��pop()���������Ա�֤minStջ��Ԫ��ʼ����st�е���Сֵ��
getMin()������ ����minStջ��yԪ�ؼ��ɡ�(����st.top() == minSt.top() �źø��������ܱ�֤ ����ͨջ����Сջһ�����pop)

����ջ���÷�����

����ջ�ȼ��ڱ���stack����Ԫ�أ�����������ֶ�ɾ����������һ����ջ�׵�ջ�������ջ��
�൱�ڸ�stack�еĽ���Ԫ�����˱�ǣ�ÿ��pop()��Щ����Ԫ�أ�����ջ�Ὣ��Ӧ��ջ��Ԫ��pop()��ȥ����֤��ջ��Ԫ��ʼ����stack�е���СԪ�ء�




class MinStack {

private:
	stack<int>st;  //����һ����ͨջ
	stack<int>minSt; //����һ�������Сֵ��ջ
public:
	/** initialize your data structure here. */

	void push(int x) {
		//��Сջ����ҲҪ���Ԫ��,ֻ������ЩԪ��Ҫ����һ��������
		if (minSt.empty() || x <= minSt.top())
			minSt.push(x);//����Сջ�� ���Ԫ��

		st.push(x);//��ͨջ����ֱ�Ӵ��Ԫ��
	}
	void pop() {  //��ջ����
		if (st.top() == minSt.top())
			minSt.pop();
		st.pop();
	}

	int top() {
		return st.top();
	}

	int getMin() {  //���ʯ��Сֵ��λ������,�ʹ��ǿ鷵��
		return minSt.top();
	}
};























