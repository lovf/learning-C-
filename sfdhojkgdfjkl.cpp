//ջ �����С����ȼ����С�˫�˶���----------�ܽ�----https://blog.csdn.net/qq_45672975/article/details/109364088
//stack�Ļ������� :
//
//	����ջ�������ܽ�
//	1.�йؽӿڵļ�ʹ�ã�
//	1.stack() : ����յ�ջ
//	2.empty��)��    ���ջ�Ƿ�Ϊ��
//	3.size() : ����ջ����ЧԪ�صĸ���
//	4.top() : ����ջ��Ԫ��
//	5.push() : ��Ԫ��valѹ��ջ��
//	6.pop() : ��ջ��stackβ��Ԫ�ص���
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
//		   2.ջ��ģ��ʵ��:
//		   ջ��һ�ֺ���ȳ������ݽṹ��Ԫ�شӶ�����ջ��Ȼ��Ӷ��˳�ջ��
//			   1.˳���     ��ջ----β��   ��ջ----βɾ   ջ��----���һ��Ԫ��
//			   2.����         ��ջ----β��   ��ջ----βɾ   ջ��----���һ��Ԫ��
//		   ����˳���ģ��ʵ��ջ :
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
//			   //β��
//			   void push(const T& val) {
//				   st.push_back(val);
//			   }
//			   //βɾ
//			   void pop() {
//				   st.pop_back();
//			   }
//			   //��ЧԪ�صĸ���
//			   size_t size() {
//				   return st.size();
//			   }
//			   //�п�
//			   bool empty() {
//				   return st.empty();
//			   }
//			   //ջ��Ԫ��: ����һ��˳�����˵ָ�������һ��Ԫ��
//			   T& top() {
//				   return st.back(); //���������һ��Ԫ�صĽӿ�
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
//			   cout << "��ЧԪ�صĸ���Ϊ: " << st.size() << endl;
//			   cout << "�ֱ���:";
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
//	   ջ�����ϰ��:
//		   1.��Сջ---- - https ://leetcode-cn.com/problems/min-stack/submissions/
//
//
//
//			   2.ջ��ѹ�뵯��------https ://leetcode-cn.com/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof/submissions/
//			   3.�沨�����ʽ��ֵ---- - https ://leetcode-cn.com/problems/evaluate-reverse-polish-notation/
//			   4.������ջʵ�ֶ���----https ://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/submissions/
//			   ���еĻ���������
//
//			   1.��ؽӿڻ���ʹ��
//			   1.queue()------����յĶ���
//			   2.empty()------�ж϶����Ƿ�Ϊ��
//			   3.size()------ - ���ض�������ЧԪ�صĸ���
//			   4.front()------���ض���ͷ��Ԫ��
//			   5.back()------ - ���ض���β��Ԫ��
//			   6.push()------��Ӳ���----β������Ԫ��val,
//			   7.pop()------ - ���Ӳ���----ͷ��ɾ��Ԫ��
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
//		   2.���е�ģ��ʵ��
//			   ������һ���Ƚ��ȳ������ݽṹ��Ԫ�شӺ����ӣ�Ȼ���ǰ�˳���
//			   1.˳���: ����--ͷɾ(Ч�ʵ�O(n))  ���-- - β��  ��ͷ-- - ��һ��Ԫ��  ��β-- - ���һ��Ԫ��
//			   2.����; ����-- - ͷɾ, ���-- - β��  ��ͷ-- - ��һ��Ԫ��    ��β-- - ���һ��Ԫ��
//		   ���е�ģ��ʵ�� : ����listʵ��, ��Ϊʹ��vector����װЧ��̫��
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
//			   cout << "��������ЧԪ�صĸ���: " << q.size() << endl;
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
//	   �������ϰ��:-- -
//		   1. �ö���ʵ��ջ------ - https ://leetcode-cn.com/problems/implement-stack-using-queues/
//		   ջ��һ�ֺ���ȳ������ݽṹ��Ԫ�شӶ�����ջ��Ȼ��Ӷ��˳�ջ��
//		   ������һ���Ƚ��ȳ������ݽṹ��Ԫ�شӺ����ӣ�Ȼ���ǰ�˳��ӡ�
//		   ����һ����������
//		   Ϊ������ջ�����ԣ��������ջ��Ԫ�����ȳ�ջ����ʹ�ö���ʵ��ջʱ��Ӧ�������ǰ�˵�Ԫ���������ջ��Ԫ�ء�
//		   ����ʹ����������ʵ��ջ�Ĳ��������� queue 1  ���ڴ洢ջ�ڵ�Ԫ�أ�queue 2��Ϊ��ջ�����ĸ������С�
//		   1. ��ջ����------ - ���Ƚ�Ԫ����ӵ�queue 2Ȼ��queue 1��ȫ��Ԫ�����γ��Ӳ���ӵ� queue 2 ����ʱ queue 2��ǰ�˵�Ԫ�ؼ�Ϊ����ջ��Ԫ�أ��ٽ�queue 1  ��queue 2��������queue 1 ��Ԫ�ؼ�Ϊջ�ڵ�Ԫ�أ�queue 1  ��ǰ�˺ͺ�˷ֱ��Ӧջ����ջ�ס�
//		   2.��ջ����--------����ÿ����ջ������ȷ��queue 1��ǰ��Ԫ��Ϊջ��Ԫ�أ���˳�ջ�����ͻ��ջ��Ԫ�ز��������Լ�ʵ�֡���ջ����ֻ��Ҫ�� queue 1 ��ǰ��Ԫ�ز����ؼ��ɣ����ջ��Ԫ�ز���ֻ��Ҫ��� queue 1 ��ǰ��Ԫ�ز����ؼ��ɣ����Ƴ�Ԫ�أ���
//		   3. �жϿղ���------ - ����queue 1 ���ڴ洢ջ�ڵ�Ԫ�أ��ж�ջ�Ƿ�Ϊ��ʱ��ֻ��Ҫ�ж�queue 1�Ƿ�Ϊ�ռ��ɡ�
//		   ���ȼ�����(priority_queue)
//		   ���ȼ���������---- -
//		   �����е�k�����Ԫ��-------- - https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
//			  1.���ȼ����нӿڼ�ʵ��
//				  1 > .Ĭ����� ���ȼ�Ĭ�����Ϊ�����
//#include<queue>
//#include <vector>
//#include <list>
//#include <iostream>
//				  using namespace std;
//
//			  void test() {
//				  //���ȼ�����Ĭ�Ͻӿ�Ϊ���
//				  priority_queue<int> pq;
//				  pq.push(10);
//				  pq.push(1);
//				  pq.push(3);
//				  pq.push(9);
//				  pq.push(0);
//				  while (!pq.empty()) {
//					  //��ȡ�Ѷ�Ԫ��
//					  cout << pq.top() << " ";  //10 9 3 1 0
//					  //ɾ���Ѷ�Ԫ��
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
//			  2 > .��Ĭ�ϵ�����ĳ�С��
//				  1 > .����ͷ�ļ�#include <functional>��greater�㷨��ͷ�ļ���  2 > �����ʱ����� greater priority_queue<int,vector<int>, greater<int> > pq;
//
//#include <functional>
//#include<queue>
//#include <vector>
//#include <list>
//#include <iostream>
//			  using namespace std;
//
//			  void test() {
//				  //���ȼ�����Ĭ�Ͻӿڸ�ΪС��
//				  priority_queue<int, vector<int>, greater<int>> pq;
//				  pq.push(10);
//				  pq.push(1);
//				  pq.push(3);
//				  pq.push(9);
//				  pq.push(0);
//				  while (!pq.empty()) {
//					  //��ȡ�Ѷ�Ԫ��
//					  cout << pq.top() << " ";  //10 9 3 1 0
//					  //ɾ���Ѷ�Ԫ��
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
//		  �����Զ�������: ��ν���ѣ���С��
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
//					   //С����������ؽ���� 
//					   bool operator<(const Date& d) const {
//						   return (_year < d._year) ||
//							   (_year == d._year && _month < d._month) ||
//							   (_year == d._year && _month == d._month && _day < d._day);
//					   }
//					   //�������������С��
//					   bool operator==(const Date& d) const{
//						   return (_year == d._year && _month == d._month && _day == d._day);
//					   }
//					   //�������������
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
//					   //�����
//					   //priority_queue<Date> pq;
//					   //��С��
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
//			   ����������: Container-------- -
//
//				   ����������ʵ��ջ
//#include<list>
//#include <queue>
//#include <iostream>
//				   using namespace std;
//					  //���Ͳ��������ʱ�򣬸��ڶ�����������Container(������)
//					  template<class T, class Container>
//
//					  class Stack{
//					  public:
//						  //β��
//						  void push(const T& val) {
//							  _lst.push_back(val);
//						  }
//						  //ͷɾ
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
//					  ����������ʵ�ֶ���
//						  vector������Ϊ���еĵײ�������û���ṩpop_front�ӿڣ���˲�����Ϊ���еĵײ�����ʵ��
//#include<list>
//#include <queue>
//#include <iostream>
//						  using namespace std;
//
//					  template<class T, class Container>
//
//					  class Queue{
//					  public:
//						  //β��
//						  void push(const T& val) {
//							  _q.push_back(val);
//						  }
//						  //ͷɾ
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
//						  //Queue<int, vector<int>>q2;  vector ��û��pop_front
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
//					  ����������ʵ�����ȼ�����
//						  ��������ʵ�����ȼ�����, ��Ϊlist��֧���������
//						  //Ĭ��ʵ�ֵ��Ǵ��
//#include <functional>
//#include <vector>
//#include <list>
//#include <queue>
//#include <iostream>
//						  using namespace std;
//
//					  template<class T, class Container = deque<T>> //class Container=vector<T> ����������
//					  class PriorityQueue{
//					  public:
//
//
//
//						  void shiftUp(int child) {
//							  int parent = (child - 1) / 2; //��֪���ڵ�λ��---���ӽڵ�=2*parent+1
//							  while (child > 0) {  //��Ϊ��������ϵ���.���child��Ҫ��������>0����(childʼ���ǵݼ���)
//								  if (_c[child] > _c[parent]) {//���ӽڵ��븸�ڵ���бȽ�,��ΪĬ��ʵ�ִ��,��˵����ӽڵ���ڸ��ڵ��ʱ����Ҫ���н���
//									  // if (_c[child] < _c[parent]) {  //С�ѽӿ�
//									  swap(_c[child], _c[parent]);//�����ڵ�(��鲻�����±��λ��)
//									  child = parent;//���¸��º��ӽڵ�
//									  parent = (child - 1) / 2;//���¸��ڵ�
//								  }
//								  else
//									  break;
//							  }
//						  }
//						  void shiftDown(int parent) {
//							  int child = 2 * parent + 1;
//							  while (child < _c.size()) { //childʼ���ǵ����ĵ��������С��size()����
//								  if (child + 1 < _c.size() && _c[child] < _c[child + 1]) //���ҽڵ���ж�
//									  //if (child + 1 < _c.size() && _c[child] > _c[child + 1]) //С��ʵ�ֽӿ�
//									  ++child; //�Һ��Ӵ�ʱҪ�����±�++
//								  if (_c[child]>_c[parent]) { //Ĭ��Ϊ���,��˱���Ҫ���㺢�ӽڵ���ڸ��׽ڵ�ʱ���ܽ��н���
//									  //if (_c[child]>_c[parent]) { //С�ѽӿ�
//									  swap(_c[child], _c[parent]); //ʵ�ֽ�������
//									  parent = child; //������µ�˳��-------���¸��¸��׽ڵ�
//									  child = 2 * parent + 1;//���º��ӽڵ�
//								  }
//								  else
//									  break;
//							  }
//						  }
//						  //β�����
//						  void push(const T& val) {
//							  _c.push_back(val);
//							  shiftUp(_c.size() - 1);
//						  }
//
//						  //ͷɾ����
//						  void pop() {
//							  //1.����2.βɾ����3.���µ���
//							  //����һ��Ԫ�غ����һ��Ԫ�ؽ��н���
//							  swap(_c[0], _c[_c.size() - 1]);
//							  //ɾ�����һ��Ԫ��
//							  _c.pop_back();
//							  //���µ���
//							  shiftDown(0);
//						  }
//						  //��ȡ�Ѷ�Ԫ��-------�Ѷ�Ԫ��ʼ���ǵ�һ��Ԫ��
//						  T& top() {
//							  return _c[0];
//						  }
//						  //�пղ���
//						  bool empty() {
//							  return _c.empty();
//						  }
//						  //����ЧԪ�صĵĳ���
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
//						  //PriorityQueue<int, list<int>> pq;-------��������ʵ�����ȼ�����,��Ϊlist��֧���������
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
//					  ���ʵ��С�ѵĹ���-- - 1.�������ĳһЩ�ıȽϸ�һ�¼��� 2.�����ڿ����������������Ƚϲ���(���ڱȽ�)
//
//					  ����2:�����˿��������˵����������ıȽ�, conpare�����ں�������ʽ�����ڲ��Ƚ�, �ⲿ���ܿ�����ʵ�������ıȽ�---- - ֻ��Ҫ�޸�greater / less�ӿھ����жϵ��׽�С�ѻ��Ǵ��
//#include <vector>
//#include <list>
//#include <queue>
//#include <iostream>
//#include <functional>
//						  using namespace std;
//
//					  template<class T, class Container = vector<T>, class Compare = less<T>> //class Container=vector<T> ����������
//					  class PriorityQueue{
//					  public:
//
//						  void shiftUp(int child) {
//							  int parent = (child - 1) / 2; //��֪���ڵ�λ��---���ӽڵ�=2*parent+1
//							  while (child > 0) {  //��Ϊ��������ϵ���.���child��Ҫ��������>0����(childʼ���ǵݼ���)
//								  if (_cmp(_c[parent], _c[child])) {//���ӽڵ��븸�ڵ���бȽ�,��ΪĬ��ʵ�ִ��,��˵����ӽڵ���ڸ��ڵ��ʱ����Ҫ���н���
//									  swap(_c[parent], _c[child]);//�����ڵ�(��鲻�����±��λ��)
//									  child = parent;//���¸��º��ӽڵ�
//									  parent = (child - 1) / 2;//���¸��ڵ�
//								  }
//								  else
//									  break;
//							  }
//						  }
//						  void shiftDown(int parent) {
//							  int child = 2 * parent + 1;
//							  //1.���Һ��������ֵ
//							  while (child < _c.size()) { //childʼ���ǵ����ĵ��������С��size()����
//								  if (child + 1 < _c.size() && _cmp(_c[child], _c[child + 1])) //���ҽڵ���ж�
//									  ++child; //�Һ��Ӵ�ʱҪ�����±�++
//								  if (_cmp(_c[parent], _c[child])) { //Ĭ��Ϊ���,��˱���Ҫ���㺢�ӽڵ���ڸ��׽ڵ�ʱ���ܽ��н���
//									  swap(_c[parent], _c[child]); //ʵ�ֽ�������
//									  parent = child; //������µ�˳��-------���¸��¸��׽ڵ�
//									  child = 2 * parent + 1;//���º��ӽڵ�
//								  }
//								  else
//									  break;
//							  }
//						  }
//						  //β�����
//						  void push(const T& val) {
//							  _c.push_back(val);
//							  shiftUp(_c.size() - 1);
//						  }
//
//						  //ͷɾ����
//						  void pop() {
//							  //1.����2.βɾ����3.���µ���
//							  //����һ��Ԫ�غ����һ��Ԫ�ؽ��н���
//							  swap(_c[0], _c[_c.size() - 1]);
//							  //ɾ�����һ��Ԫ��
//							  _c.pop_back();
//							  //���µ���
//							  shiftDown(0);
//						  }
//						  //��ȡ�Ѷ�Ԫ��-------�Ѷ�Ԫ��ʼ���ǵ�һ��Ԫ��
//						  T& top() {
//							  return _c[0];
//							  //return _c.front();
//						  }
//						  //�пղ���
//						  bool empty() {
//							  return _c.empty();
//						  }
//						  //����ЧԪ�صĵĳ���
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
//						  //С��
//						  PriorityQueue<int, vector<int>, greater<int>> pq; //���õ��ǿ�������ñȽ�ʵ�ֽ�С��
//						  //���
//						  //PriorityQueue<int, vector<int>,less<int>> pq; //���õ��ǿ�������ñȽ�ʵ�ֽ�С��
//						  //���Ҳ�����Լ�ʵ���������������ʵ��Less ---������С�ڱȽϼ���
//						  for (int i = 1; i <= 100; i++) {                 //������ô�Ƚ��Ǹ��ݵ������������е�(���������������ڷº���)
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
//						  == == == == == == == = �º�����--�Լ�ʵ��Less��Greater������ʹ�ÿ�����д�õ������
//						  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ +
//
//#include <vector>
//#include <list>
//#include <queue>
//#include <iostream>
//#include <functional>
//						  using namespace std;
//
//					  template<class T, class Container = vector<T>, class Compare = less<T>> //class Container=vector<T> ����������
//					  class PriorityQueue{
//					  public:
//						  void shiftUp(int child) {
//							  int parent = (child - 1) / 2; //��֪���ڵ�λ��---���ӽڵ�=2*parent+1
//							  while (child > 0) {  //��Ϊ��������ϵ���.���child��Ҫ��������>0����(childʼ���ǵݼ���)
//								  if (_cmp(_c[parent], _c[child])) {//���ӽڵ��븸�ڵ���бȽ�,��ΪĬ��ʵ�ִ��,��˵����ӽڵ���ڸ��ڵ��ʱ����Ҫ���н���
//									  swap(_c[parent], _c[child]);//�����ڵ�(��鲻�����±��λ��)
//									  child = parent;//���¸��º��ӽڵ�
//									  parent = (child - 1) / 2;//���¸��ڵ�
//								  }
//								  else
//									  break;
//							  }
//						  }
//						  void shiftDown(int parent) {
//							  int child = 2 * parent + 1;
//							  //1.���Һ��������ֵ
//							  while (child < _c.size()) { //childʼ���ǵ����ĵ��������С��size()����
//								  if (child + 1 < _c.size() && _cmp(_c[child], _c[child + 1])) //���ҽڵ���ж�
//									  ++child; //�Һ��Ӵ�ʱҪ�����±�++
//								  if (_cmp(_c[parent], _c[child])) { //Ĭ��Ϊ���,��˱���Ҫ���㺢�ӽڵ���ڸ��׽ڵ�ʱ���ܽ��н���
//									  swap(_c[parent], _c[child]); //ʵ�ֽ�������
//									  parent = child; //������µ�˳��-------���¸��¸��׽ڵ�
//									  child = 2 * parent + 1;//���º��ӽڵ�
//								  }
//								  else
//									  break;
//							  }
//						  }
//						  //β�����
//						  void push(const T& val) {
//							  _c.push_back(val);
//							  shiftUp(_c.size() - 1);
//						  }
//
//						  //ͷɾ����
//						  void pop() {
//							  //1.����2.βɾ����3.���µ���
//							  //����һ��Ԫ�غ����һ��Ԫ�ؽ��н���
//							  swap(_c[0], _c[_c.size() - 1]);
//							  //ɾ�����һ��Ԫ��
//							  _c.pop_back();
//							  //���µ���
//							  shiftDown(0);
//						  }
//						  //��ȡ�Ѷ�Ԫ��-------�Ѷ�Ԫ��ʼ���ǵ�һ��Ԫ��
//						  T& top() {
//							  return _c[0];
//							  //return _c.front();
//						  }
//						  //�пղ���
//						  bool empty() {
//							  return _c.empty();
//						  }
//						  //����ЧԪ�صĵĳ���
//						  size_t size() const{
//							  return _c.size();
//						  }
//
//					  private:
//						  Container _c;
//						  Compare _cmp;
//					  };
//					  ///////�Լ�ʵ�ֵĵ����������Ƚ�-------------------------------�����������������====����������Ҳ����ʹ���Լ�д�ĵ���������
//					  ////�º�����------���������ں���
//					  ////�����������ţ��������
//					  //
//					  template<class T>
//
//					  struct Less{
//						  //��������()�����
//						  bool operator()(const T& val1, const T& val2) {
//							  return val1 < val2;
//						  }
//					  };
//
//					  template<class T>
//					  struct Greater{
//						  //��������()�����
//						  bool operator()(const T& val1, const T& val2) {
//							  return val1 > val2;
//						  }
//					  };
//					  void test1() {
//						  //С��
//						  PriorityQueue<int, vector<int>, Greater<int>> pq;
//						  //���
//						  //PriorityQueue<int, vector<int>,Less<int>> pq;  //���Ҳ�����Լ�ʵ���������������ʵ��Less ---������С�ڱȽϼ���
//						  for (int i = 1; i <= 100; i++) {                 //������ô�Ƚ��Ǹ��ݵ������������е�(���������������ڷº���)
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
//�Զ���ʵ��
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
	priority_queue<Date, vector<Date>, less<Date>> pq; ///�Զ������͵ĵ����������º����ǽ��ÿ����
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
