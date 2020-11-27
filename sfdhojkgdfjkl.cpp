//栈 、队列、优先级队列、双端队列----------总结----https://blog.csdn.net/qq_45672975/article/details/109364088
//stack的基本操作 :
//
//	关于栈的整理总结
//	1.有关接口的简单使用：
//	1.stack() : 构造空的栈
//	2.empty（)：    检测栈是否为空
//	3.size() : 返回栈中有效元素的个数
//	4.top() : 返回栈顶元素
//	5.push() : 将元素val压入栈中
//	6.pop() : 将栈中stack尾部元素弹出
//#include <stack>
//#include <iostream>
//	using namespace std;
//
//		   void test() {
//			   stack<int> st;
//			   st.push(1);
//			   st.push(2);
//			   st.push(3);
//			   st.push(4);
//			   st.push(5);
//			   while (!st.empty()){
//				   cout << st.top() << " ";
//				   st.pop();
//			   }
//			   cout << endl;
//		   }
//		   int main() {
//
//			   test();
//			   system("pause");
//			   return 0;
//		   }
//		   2.栈的模拟实现:
//		   栈是一种后进先出的数据结构，元素从顶端入栈，然后从顶端出栈。
//			   1.顺序表     入栈----尾插   出栈----尾删   栈顶----最后一个元素
//			   2.链表         入栈----尾插   出栈----尾删   栈顶----最后一个元素
//		   利用顺序表模拟实现栈 :
//#include <vector>
//#include <iostream>
//		   using namespace std;
//
//		   template <class T>
//
//		   class Stack {
//		   public:
//			   Stack() {
//
//			   }
//			   //尾插
//			   void push(const T& val) {
//				   st.push_back(val);
//			   }
//			   //尾删
//			   void pop() {
//				   st.pop_back();
//			   }
//			   //有效元素的个数
//			   size_t size() {
//				   return st.size();
//			   }
//			   //判空
//			   bool empty() {
//				   return st.empty();
//			   }
//			   //栈顶元素: 对于一个顺序表来说指的是最后一个元素
//			   T& top() {
//				   return st.back(); //调用用最后一个元素的接口
//			   }
//		   private:
//			   vector<T> st;
//		   };
//		   void test() {
//			   Stack<int> st;
//			   st.push(1);
//			   st.push(2);
//			   st.push(3);
//			   st.push(4);
//			   st.push(5);
//			   cout << "有效元素的个数为: " << st.size() << endl;
//			   cout << "分别是:";
//			   while (!st.empty()) {
//				   cout << st.top() << " ";
//				   st.pop();
//			   }
//			   cout << endl;
//		   }
//		   int main() {
//			   test();
//			   system("color A");
//			   system("pause");
//			   return 0;
//		   }
//	   栈的相关习题:
//		   1.最小栈---- - https ://leetcode-cn.com/problems/min-stack/submissions/
//
//
//
//			   2.栈的压入弹出------https ://leetcode-cn.com/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof/submissions/
//			   3.逆波兰表达式求值---- - https ://leetcode-cn.com/problems/evaluate-reverse-polish-notation/
//			   4.用两个栈实现队列----https ://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/submissions/
//			   队列的基本操作：
//
//			   1.相关接口基本使用
//			   1.queue()------构造空的队列
//			   2.empty()------判断队列是否为空
//			   3.size()------ - 返回队列中有效元素的个数
//			   4.front()------返回队列头部元素
//			   5.back()------ - 返回队列尾部元素
//			   6.push()------入队操作----尾部插入元素val,
//			   7.pop()------ - 出队操作----头部删除元素
//#include <queue>
//#include <iostream>
//			   using namespace std;
//		   void test() {
//			   queue<int> q;
//			   q.push(1);
//			   q.push(2);
//			   q.push(3);
//			   q.push(4);
//			   while (!q.empty()) {
//				   cout << q.front() << " ";
//				   q.pop();
//			   }
//			   cout << endl;
//		   }
//		   int main() {
//			   test();
//			   system("color A");
//			   system("pause");
//			   return 0;
//		   }
//		   2.队列的模拟实现
//			   队列是一种先进先出的数据结构，元素从后端入队，然后从前端出队
//			   1.顺序表: 出队--头删(效率低O(n))  入队-- - 尾插  对头-- - 第一个元素  队尾-- - 最后一个元素
//			   2.链表; 出队-- - 头删, 入队-- - 尾插  对头-- - 第一个元素    队尾-- - 最后一个元素
//		   队列的模拟实现 : 利用list实现, 因为使用vector来封装效率太低
//#include<list>
//#include <iostream>
//					 using namespace std;
//
//		   template<class T>
//		   class List{
//		   public:
//			   List(){
//			   }
//			   void push(const T& value) {
//				   _lst.push_back(value);
//			   }
//			   void pop() {
//				   _lst.pop_front();
//			   }
//			   size_t size() {
//				   return _lst.size();
//			   }
//			   T& front() {
//				   return _lst.front();
//			   }
//			   T& back() {
//				   _lst.back();
//			   }
//			   bool empty() {
//				   return _lst.empty();
//			   }
//		   private:
//			   list<T> _lst;
//		   };
//
//		   void test() {
//			   List<int> q;
//			   q.push(1);
//			   q.push(2);
//			   q.push(3);
//			   q.push(4);
//			   cout << "队列中有效元素的个数: " << q.size() << endl;
//			   while (!q.empty()) {
//				   cout << q.front() << " ";
//				   q.pop();
//			   }
//			   cout << endl;
//		   }
//		   int main() {
//
//			   test();
//			   system("color A");
//			   system("pause");
//			   return 0;
//		   }
//	   队列相关习题:-- -
//		   1. 用队列实现栈------ - https ://leetcode-cn.com/problems/implement-stack-using-queues/
//		   栈是一种后进先出的数据结构，元素从顶端入栈，然后从顶端出栈。
//		   队列是一种先进先出的数据结构，元素从后端入队，然后从前端出队。
//		   方法一：两个队列
//		   为了满足栈的特性，即最后入栈的元素最先出栈，在使用队列实现栈时，应满足队列前端的元素是最后入栈的元素。
//		   可以使用两个队列实现栈的操作，其中 queue 1  用于存储栈内的元素，queue 2作为入栈操作的辅助队列。
//		   1. 入栈操作------ - 首先将元素入队到queue 2然后将queue 1的全部元素依次出队并入队到 queue 2 ，此时 queue 2的前端的元素即为新入栈的元素，再将queue 1  和queue 2互换，则queue 1 的元素即为栈内的元素，queue 1  的前端和后端分别对应栈顶和栈底。
//		   2.出栈操作--------由于每次入栈操作都确保queue 1的前端元素为栈顶元素，因此出栈操作和获得栈顶元素操作都可以简单实现。出栈操作只需要移 queue 1 的前端元素并返回即可，获得栈顶元素操作只需要获得 queue 1 的前端元素并返回即可（不移除元素）。
//		   3. 判断空操作------ - 由于queue 1 用于存储栈内的元素，判断栈是否为空时，只需要判断queue 1是否为空即可。
//		   优先级队列(priority_queue)
//		   优先级队列例题---- -
//		   数组中第k个大的元素-------- - https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
//			  1.优先级队列接口简单实现
//				  1 > .默认情况 优先级默认情况为建大堆
//#include<queue>
//#include <vector>
//#include <list>
//#include <iostream>
//				  using namespace std;
//
//			  void test() {
//				  //优先级队列默认接口为大堆
//				  priority_queue<int> pq;
//				  pq.push(10);
//				  pq.push(1);
//				  pq.push(3);
//				  pq.push(9);
//				  pq.push(0);
//				  while (!pq.empty()) {
//					  //获取堆顶元素
//					  cout << pq.top() << " ";  //10 9 3 1 0
//					  //删除堆顶元素
//					  pq.pop();
//				  }
//				  cout << endl;
//			  }
//
//			  int main() {
//				  test();
//				  system("color A");
//				  system("pause");
//				  return 0;
//			  }
//			  2 > .将默认的情况改成小堆
//				  1 > .包含头文件#include <functional>（greater算法的头文件）  2 > 定义的时候添加 greater priority_queue<int,vector<int>, greater<int> > pq;
//
//#include <functional>
//#include<queue>
//#include <vector>
//#include <list>
//#include <iostream>
//			  using namespace std;
//
//			  void test() {
//				  //优先级队列默认接口改为小堆
//				  priority_queue<int, vector<int>, greater<int>> pq;
//				  pq.push(10);
//				  pq.push(1);
//				  pq.push(3);
//				  pq.push(9);
//				  pq.push(0);
//				  while (!pq.empty()) {
//					  //获取堆顶元素
//					  cout << pq.top() << " ";  //10 9 3 1 0
//					  //删除堆顶元素
//					  pq.pop();
//				  }
//				  cout << endl;
//			  }
//
//			  int main() {
//				  test();
//				  system("color A");
//				  system("pause");
//				  return 0;
//			  }
//		  对于自定义类型: 如何建大堆，建小堆
//#include <functional>
//#include <list>
//#include<vector>
//#include <queue>
//#include <iostream>
//			  using namespace std;
//
//				   class Date{
//					   friend ostream& operator<<(ostream& _cout, const Date& d);
//				   public:
//					   Date(int year, int month, int day)
//						   :_year(year)
//						   , _month(month)
//						   , _day(day)
//					   {}
//					   //小于运算符重载建大堆 
//					   bool operator<(const Date& d) const {
//						   return (_year < d._year) ||
//							   (_year == d._year && _month < d._month) ||
//							   (_year == d._year && _month == d._month && _day < d._day);
//					   }
//					   //大于运算符重载小堆
//					   bool operator==(const Date& d) const{
//						   return (_year == d._year && _month == d._month && _day == d._day);
//					   }
//					   //大于运算符重载
//					   bool operator>(const Date& d) const{
//						   return !(*this < d || *this == d);
//					   }
//				   private:
//					   int _year;
//					   int _month;
//					   int _day;
//				   };
//				   ostream& operator<<(ostream& _cout, const Date& d) {
//					   _cout << d._year << "-" << d._month << "-" << d._day << endl;
//					   return _cout;
//				   }
//				   void test1() {
//					   //建大堆
//					   //priority_queue<Date> pq;
//					   //建小堆
//					   priority_queue<Date, vector<Date>, greater<Date>> pq;
//					   pq.push(Date(2020, 9, 4));
//					   pq.push(Date(2010, 1, 4));
//					   pq.push(Date(2040, 5, 4));
//					   while (!pq.empty()) {
//						   cout << pq.top();
//						   pq.pop();
//					   }
//				   }
//				   int main() {
//					   test1();
//					   system("color A");
//					   system("pause");
//					   return 0;
//				   }
//			   容器适配器: Container-------- -
//
//				   容器适配器实现栈
//#include<list>
//#include <queue>
//#include <iostream>
//				   using namespace std;
//					  //泛型参数定义的时候，给第二个参数放上Container(适配器)
//					  template<class T, class Container>
//
//					  class Stack{
//					  public:
//						  //尾插
//						  void push(const T& val) {
//							  _lst.push_back(val);
//						  }
//						  //头删
//						  void pop() {
//							  _lst.pop_back();
//						  }
//						  T& top() {
//							  return _lst.back();
//						  }
//						  size_t size() {
//							  return _lst.size();
//						  }
//						  bool empty() {
//							  return _lst.empty();
//						  }
//					  private:
//						  Container _lst;
//					  };
//					  void test() {
//						  Stack<int, list<int>> st1;
//						  Stack<int, vector<int>> st2;
//						  st1.push(1);
//						  st1.push(2);
//						  st1.push(3);
//						  st1.push(4);
//
//						  st2.push(1);
//						  st2.push(2);
//						  st2.push(3);
//						  st2.push(4);
//						  while (!st1.empty()) {
//							  cout << st1.top() << " ";
//							  st1.pop();
//						  }
//						  cout << endl;
//						  while (!st2.empty()) {
//							  cout << st2.top() << " ";
//							  st2.pop();
//						  }
//						  cout << endl;
//					  }
//					  int main() {
//						  test();
//						  system("pause");
//						  return 0;
//					  }
//					  容器适配器实现队列
//						  vector不能作为队列的底层容器，没有提供pop_front接口，因此不能作为队列的底层容器实现
//#include<list>
//#include <queue>
//#include <iostream>
//						  using namespace std;
//
//					  template<class T, class Container>
//
//					  class Queue{
//					  public:
//						  //尾插
//						  void push(const T& val) {
//							  _q.push_back(val);
//						  }
//						  //头删
//						  void pop() {
//							  _q.pop_front();
//						  }
//						  T& front() {
//							  return _q.front();
//						  }
//						  size_t size() {
//							  return _q.size();
//						  }
//						  bool empty() {
//							  return _q.empty();
//						  }
//						  T& back() {
//							  return _q.back();
//						  }
//					  private:
//						  Container _q;
//
//					  };
//					  void test() {
//						  Queue<int, list<int>> q1;
//						  //Queue<int, vector<int>>q2;  vector ，没有pop_front
//						  q1.push(1);
//						  q1.push(2);
//						  q1.push(3);
//						  q1.push(4);
//
//						  while (!q1.empty()) {
//							  cout << q1.front() << " ";
//							  q1.pop();
//						  }
//						  cout << endl;
//					  }
//					  int main() {
//
//						  test();
//						  system("pause");
//						  return 0;
//					  }
//					  容器适配器实现优先级队列
//						  不能用于实现优先级队列, 因为list不支持随机访问
//						  //默认实现的是大堆
//#include <functional>
//#include <vector>
//#include <list>
//#include <queue>
//#include <iostream>
//						  using namespace std;
//
//					  template<class T, class Container = deque<T>> //class Container=vector<T> 容器适配器
//					  class PriorityQueue{
//					  public:
//
//
//
//						  void shiftUp(int child) {
//							  int parent = (child - 1) / 2; //已知父节点位置---孩子节点=2*parent+1
//							  while (child > 0) {  //因为这块是向上调整.因此child需要满足条件>0即可(child始终是递减的)
//								  if (_c[child] > _c[parent]) {//孩子节点与父节点进行比较,因为默认实现大堆,因此当孩子节点大于父节点的时候需要进行交换
//									  // if (_c[child] < _c[parent]) {  //小堆接口
//									  swap(_c[child], _c[parent]);//交换节点(这块不能是下标的位置)
//									  child = parent;//重新更新孩子节点
//									  parent = (child - 1) / 2;//更新父节点
//								  }
//								  else
//									  break;
//							  }
//						  }
//						  void shiftDown(int parent) {
//							  int child = 2 * parent + 1;
//							  while (child < _c.size()) { //child始终是递增的的因此最大的小于size()即可
//								  if (child + 1 < _c.size() && _c[child] < _c[child + 1]) //左右节点的判断
//									  //if (child + 1 < _c.size() && _c[child] > _c[child + 1]) //小堆实现接口
//									  ++child; //右孩子大时要进行下标++
//								  if (_c[child]>_c[parent]) { //默认为大堆,因此必须要满足孩子节点大于父亲节点时才能进行交换
//									  //if (_c[child]>_c[parent]) { //小堆接口
//									  swap(_c[child], _c[parent]); //实现交换操作
//									  parent = child; //清楚更新的顺序-------重新更新父亲节点
//									  child = 2 * parent + 1;//更新孩子节点
//								  }
//								  else
//									  break;
//							  }
//						  }
//						  //尾插操作
//						  void push(const T& val) {
//							  _c.push_back(val);
//							  shiftUp(_c.size() - 1);
//						  }
//
//						  //头删操作
//						  void pop() {
//							  //1.交换2.尾删操作3.向下调整
//							  //将第一个元素和最后一个元素进行交换
//							  swap(_c[0], _c[_c.size() - 1]);
//							  //删除最后一个元素
//							  _c.pop_back();
//							  //向下调整
//							  shiftDown(0);
//						  }
//						  //获取堆顶元素-------堆顶元素始终是第一个元素
//						  T& top() {
//							  return _c[0];
//						  }
//						  //判空操作
//						  bool empty() {
//							  return _c.empty();
//						  }
//						  //求有效元素的的长度
//						  size_t size() const{
//							  return _c.size();
//						  }
//
//					  private:
//						  Container _c;
//					  };
//
//
//					  void test1() {
//						  PriorityQueue<int> pq;
//						  pq.push(10);
//						  pq.push(1);
//
//						  pq.push(5);
//						  pq.push(23);
//						  pq.push(32);
//						  while (!pq.empty()) {
//							  cout << pq.top() << " ";
//							  pq.pop();
//						  }
//						  cout << endl;
//					  }
//					  void test2() {
//						  //PriorityQueue<int,vector<int>> pq;
//						  PriorityQueue<int, deque<int>> pq;
//						  //PriorityQueue<int, list<int>> pq;-------不能用于实现优先级队列,因为list不支持随机访问
//
//						  for (int i = 1; i <= 100; i++) {
//							  pq.push(i);
//						  }
//						  for (int i = 1; i < 100; i++) {
//							  cout << pq.top() << " ";
//							  pq.pop();
//						  }
//					  }
//					  int main() {
//						  //test1();
//						  test2();
//						  system("pause");
//						  return 0;
//					  }
//					  如何实现小堆的过程-- - 1.将大堆中某一些的比较改一下即可 2.借助于库里面引出第三个比较参数(用于比较)
//
//					  方法2:借助了库里引入了第三个参数的比较, conpare类似于函数的形式进行内部比较, 外部不能看出来实现怎样的比较---- - 只需要修改greater / less接口就能判断到底建小堆还是大堆
//#include <vector>
//#include <list>
//#include <queue>
//#include <iostream>
//#include <functional>
//						  using namespace std;
//
//					  template<class T, class Container = vector<T>, class Compare = less<T>> //class Container=vector<T> 容器适配器
//					  class PriorityQueue{
//					  public:
//
//						  void shiftUp(int child) {
//							  int parent = (child - 1) / 2; //已知父节点位置---孩子节点=2*parent+1
//							  while (child > 0) {  //因为这块是向上调整.因此child需要满足条件>0即可(child始终是递减的)
//								  if (_cmp(_c[parent], _c[child])) {//孩子节点与父节点进行比较,因为默认实现大堆,因此当孩子节点大于父节点的时候需要进行交换
//									  swap(_c[parent], _c[child]);//交换节点(这块不能是下标的位置)
//									  child = parent;//重新更新孩子节点
//									  parent = (child - 1) / 2;//更新父节点
//								  }
//								  else
//									  break;
//							  }
//						  }
//						  void shiftDown(int parent) {
//							  int child = 2 * parent + 1;
//							  //1.左右孩子找最大值
//							  while (child < _c.size()) { //child始终是递增的的因此最大的小于size()即可
//								  if (child + 1 < _c.size() && _cmp(_c[child], _c[child + 1])) //左右节点的判断
//									  ++child; //右孩子大时要进行下标++
//								  if (_cmp(_c[parent], _c[child])) { //默认为大堆,因此必须要满足孩子节点大于父亲节点时才能进行交换
//									  swap(_c[parent], _c[child]); //实现交换操作
//									  parent = child; //清楚更新的顺序-------重新更新父亲节点
//									  child = 2 * parent + 1;//更新孩子节点
//								  }
//								  else
//									  break;
//							  }
//						  }
//						  //尾插操作
//						  void push(const T& val) {
//							  _c.push_back(val);
//							  shiftUp(_c.size() - 1);
//						  }
//
//						  //头删操作
//						  void pop() {
//							  //1.交换2.尾删操作3.向下调整
//							  //将第一个元素和最后一个元素进行交换
//							  swap(_c[0], _c[_c.size() - 1]);
//							  //删除最后一个元素
//							  _c.pop_back();
//							  //向下调整
//							  shiftDown(0);
//						  }
//						  //获取堆顶元素-------堆顶元素始终是第一个元素
//						  T& top() {
//							  return _c[0];
//							  //return _c.front();
//						  }
//						  //判空操作
//						  bool empty() {
//							  return _c.empty();
//						  }
//						  //求有效元素的的长度
//						  size_t size() const{
//							  return _c.size();
//						  }
//
//					  private:
//						  Container _c;
//						  Compare _cmp;
//					  };
//
//					  void test1() {
//						  //小堆
//						  PriorityQueue<int, vector<int>, greater<int>> pq; //调用的是库里的内置比较实现建小堆
//						  //大堆
//						  //PriorityQueue<int, vector<int>,less<int>> pq; //调用的是库里的内置比较实现建小堆
//						  //这块也可以自己实现括号运算符重载实现Less ---里面是小于比较即可
//						  for (int i = 1; i <= 100; i++) {                 //到底怎么比较是根据第三个参数进行的(第三个参数类似于仿函数)
//							  pq.push(i);
//						  }
//						  for (int i = 1; i < 100; i++) {
//							  cout << pq.top() << " ";
//							  pq.pop();
//						  }
//
//					  }
//
//					  int main() {
//						  test1();
//						  system("pause");
//						  return 0;
//					  }
//					  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//						  == == == == == == == = 仿函数类--自己实现Less和Greater操作不使用库里面写好的来完成
//						  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ +
//
//#include <vector>
//#include <list>
//#include <queue>
//#include <iostream>
//#include <functional>
//						  using namespace std;
//
//					  template<class T, class Container = vector<T>, class Compare = less<T>> //class Container=vector<T> 容器适配器
//					  class PriorityQueue{
//					  public:
//						  void shiftUp(int child) {
//							  int parent = (child - 1) / 2; //已知父节点位置---孩子节点=2*parent+1
//							  while (child > 0) {  //因为这块是向上调整.因此child需要满足条件>0即可(child始终是递减的)
//								  if (_cmp(_c[parent], _c[child])) {//孩子节点与父节点进行比较,因为默认实现大堆,因此当孩子节点大于父节点的时候需要进行交换
//									  swap(_c[parent], _c[child]);//交换节点(这块不能是下标的位置)
//									  child = parent;//重新更新孩子节点
//									  parent = (child - 1) / 2;//更新父节点
//								  }
//								  else
//									  break;
//							  }
//						  }
//						  void shiftDown(int parent) {
//							  int child = 2 * parent + 1;
//							  //1.左右孩子找最大值
//							  while (child < _c.size()) { //child始终是递增的的因此最大的小于size()即可
//								  if (child + 1 < _c.size() && _cmp(_c[child], _c[child + 1])) //左右节点的判断
//									  ++child; //右孩子大时要进行下标++
//								  if (_cmp(_c[parent], _c[child])) { //默认为大堆,因此必须要满足孩子节点大于父亲节点时才能进行交换
//									  swap(_c[parent], _c[child]); //实现交换操作
//									  parent = child; //清楚更新的顺序-------重新更新父亲节点
//									  child = 2 * parent + 1;//更新孩子节点
//								  }
//								  else
//									  break;
//							  }
//						  }
//						  //尾插操作
//						  void push(const T& val) {
//							  _c.push_back(val);
//							  shiftUp(_c.size() - 1);
//						  }
//
//						  //头删操作
//						  void pop() {
//							  //1.交换2.尾删操作3.向下调整
//							  //将第一个元素和最后一个元素进行交换
//							  swap(_c[0], _c[_c.size() - 1]);
//							  //删除最后一个元素
//							  _c.pop_back();
//							  //向下调整
//							  shiftDown(0);
//						  }
//						  //获取堆顶元素-------堆顶元素始终是第一个元素
//						  T& top() {
//							  return _c[0];
//							  //return _c.front();
//						  }
//						  //判空操作
//						  bool empty() {
//							  return _c.empty();
//						  }
//						  //求有效元素的的长度
//						  size_t size() const{
//							  return _c.size();
//						  }
//
//					  private:
//						  Container _c;
//						  Compare _cmp;
//					  };
//					  ///////自己实现的第三方参数比较-------------------------------利用括号运算符重载====第三个参数也可以使用自己写的第三方函数
//					  ////仿函数类------功能类似于函数
//					  ////必须重载括号（）运算符
//					  //
//					  template<class T>
//
//					  struct Less{
//						  //重载括号()运算符
//						  bool operator()(const T& val1, const T& val2) {
//							  return val1 < val2;
//						  }
//					  };
//
//					  template<class T>
//					  struct Greater{
//						  //重载括号()运算符
//						  bool operator()(const T& val1, const T& val2) {
//							  return val1 > val2;
//						  }
//					  };
//					  void test1() {
//						  //小堆
//						  PriorityQueue<int, vector<int>, Greater<int>> pq;
//						  //大堆
//						  //PriorityQueue<int, vector<int>,Less<int>> pq;  //这块也可以自己实现括号运算符重载实现Less ---里面是小于比较即可
//						  for (int i = 1; i <= 100; i++) {                 //到底怎么比较是根据第三个参数进行的(第三个参数类似于仿函数)
//							  pq.push(i);
//						  }
//						  for (int i = 1; i < 100; i++) {
//							  cout << pq.top() << " ";
//							  pq.pop();
//						  }
//
//					  }
//
//					  int main() {
//						  test1();
//						  system("pause");
//						  return 0;
//					  }
//
//自定义实现
#include <functional>
#include <vector>
#include <list>
#include <queue>
#include <iostream>
using namespace std;


class Date{
	friend ostream& operator<<(ostream& _cout, const Date& d);
public:
	Date(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)

	{}
	bool operator<(const Date& d) const{
		return (_year < d._year) ||
			(_year == d._year && _month < d._month) ||
			(_year == d._year && _month == d._month && _day < d._day);
	}
	
	bool operator==(const Date& d) const{
		return (_year == d._year && _month == d._month && _day == d._day);
	}
	bool operator>(const Date& d) const{
		return !(*this < d || *this == d);
	}


private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& _cout, const Date& d) {
	_cout << d._year << "-" << d._month << "-" << d._day << endl;
	return _cout;
}
void test() {
	priority_queue<Date, vector<Date>, less<Date>> pq; ///自定义类型的第三方参数仿函数是借用库里的
	pq.push(Date(2020, 2, 1));
	pq.push(Date(1990, 2, 1));
	pq.push(Date(2028, 2, 1));
	while (!pq.empty()) {
		cout << pq.top();
		pq.pop();
	}
	//cout << endl;
}

int main() {

	test();
	system("color A");
	system("pause");
	return 0;
}
