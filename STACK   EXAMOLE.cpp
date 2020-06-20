1.最小栈
设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
push(x) —— 将元素 x 推入栈中。
pop() —— 删除栈顶的元素。
top() —— 获取栈顶元素。
getMin() —— 检索栈中的最小元素。

示例 :

输入：
["MinStack", "push", "push", "push", "getMin", "pop", "top", "getMin"]
[[], [-2], [0], [-3], [], [], [], []]

输出：
[null, null, null, null, -3, null, 0, -2]

解释：
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   -- > 返回 - 3.
minStack.pop();
minStack.top();      -- > 返回 0.
minStack.getMin();   -- > 返回 - 2.

借助辅助栈解体的方法是最简单的
**借助辅助栈 ,用于存放栈中的最小值
////
最小栈 （辅助栈法）
解题思路：
借用一个辅助栈minSt，用于存获取stack中最小值。
////
算法流程:
 push ()方法: 每当push()新进来值时,当满足x小于等于minSt中的值时,则一起执行push()操作  minSt.push(x)  st.push(x)
 pop() 方法: 判断将pop()出去的元素值是否是minSt栈顶元素值（即最小值），如果是则将minSt栈顶元素一起pop()，这样可以保证minSt栈顶元素始终是st中的最小值。
getMin()方法： 返回minSt栈顶y元素即可。(满足st.top() == minSt.top() 嗯好个条件才能保证 将普通栈和最小栈一起进行pop)

辅助栈作用分析：

辅助栈等价于遍历stack所有元素，把升序的数字都删除掉，留下一个从栈底到栈顶降序的栈。
相当于给stack中的降序元素做了标记，每当pop()这些降序元素，辅助栈会将相应的栈顶元素pop()出去，保证其栈顶元素始终是stack中的最小元素。




class MinStack {

private:
	stack<int>st;  //构建一个普通栈
	stack<int>minSt; //构建一个存放最小值的栈
public:
	/** initialize your data structure here. */

	void push(int x) {
		//最小栈里面也要存放元素,只不过这些元素要满足一定的条件
		if (minSt.empty() || x <= minSt.top())
			minSt.push(x);//给最小栈中 存放元素

		st.push(x);//普通栈里面直接存放元素
	}
	void pop() {  //出栈操作
		if (st.top() == minSt.top())
			minSt.pop();
		st.pop();
	}

	int top() {
		return st.top();
	}

	int getMin() {  //这块石最小值的位置在哪,就从那块返回
		return minSt.top();
	}
};























