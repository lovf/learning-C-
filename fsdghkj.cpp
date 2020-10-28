//## list接口简单使用
//list实现 : 泛型实现
//	构造函数; 无参构造
//	```c
#include<string>
#include <list>
#include <iostream>
using namespace  std;

template<class T>
void Printlst(const list<T>& lst) {

	for (const T& e : lst) {
		cout << e << " ";
	}
	cout << endl;

}

void test1() {
	list<int> lst1;
	list<char> lst2(5, 'a');//aaaaa

	char str[] = "123456";
	list<char> lst3(str, str + 5); //12345

	list<char> lst4(lst2.begin(), lst2.end()); //aaaaa

	list<char> copy(lst3);//拷贝构造 12345

	//字符类型迭代器
	list<char> ::iterator it1 = lst3.begin();
	while (it1 != lst3.end()) {
		cout << *it1 << " ";
	}
	cout << endl;

	//整型迭代器
	list<int> lst5(3, 1);
	list<int>::iterator it2 = lst5.begin();
	while (it2 != lst5.end()) {
		cout << *it2 << " ";
		++it2;
	}
	cout << endl;

	//范围for
	for (char ch : lst3) {
		cout << ch << " ";
	}
	cout << endl;

	for (char& ch : lst3) {
		cout << ch << " ";
		ch = 'x';
	}
	cout << endl;

	for (char& ch : lst3) {
		cout << ch << " ";
		ch = 'x';
	}
	cout << endl;
	//反向迭代器
	cout << "反向迭代器" << endl;
	list<char> ::reverse_iterator rit1 = lst3.rbegin();
	while (rit1 != lst3.rend()) {
		cout << *rit1 << " ";
		rit1++;
	}
	cout << endl;

}
 class A {

 public:
	 A(int a, int b)
		 :_a(a)

	 {
		 cout << "A(int ,int )" << endl;
	 }

	 bool operator < (const A& a) {
		 return _a < a._a;
	 }
	 bool operator>(const A& a) {
		 return _a > a._a;
	 }
 private:
	 int _a;
 };


 void test2() {
	 list<int> lst;
	 lst.push_back(1);
	 lst.push_front(0);
	 lst.push_front(-1);
	 lst.push_front(-2);
	 Printlst(lst);

	 lst.pop_back();
	 Printlst(lst);

	 lst.pop_front();
	 Printlst(lst);

	 list<A> lst1;

	 lst1.emplace_back(10, 9);
	 lst1.emplace_front(-1, 0);

 }


 void test3() {
	 list<int> lst;
	 //list迭代器在插入之后不会失效
	 lst.insert(lst.begin(), 1);
	 list<int>::iterator it = lst.begin();
	 cout << "*it:" << *it << endl;

	 Printlst(lst);
	 lst.insert(lst.begin(), 3, 0);
	 list<int>::iterator it1 = lst.begin();
	 cout << "*it1:" << *it1 << endl;
	 Printlst(lst);

	 list<int> copy(lst);
	 lst.insert(lst.end(), copy.begin(), copy.end()); //插入要拿其他的进行确定范围
	 Printlst(lst);

	 //被删除之后迭代器不能使用,假如要使用必须进行重新获取迭代器
	 //调用删除之后,需要重新更新迭代器:1.获取erase返回值2.调用迭代器接口
	 cout << "erase" << endl;
	 it = lst.erase(it);
	 cout << "*it1:" << *it1 << endl;


	 Printlst(lst);
	 lst.erase(lst.begin(), lst.end());
	 Printlst(lst);

	 cout << "resize()" << endl;
	 lst.resize(5);
	 Printlst(lst);

	 lst.resize(7, 1);
	 Printlst(lst);
	 //remove:只删除指定元素的值,如果有多个全部删除,如果没有,则不删除
	 cout << "rempve" << endl;
	 lst.remove(1);
	 Printlst(lst);
	 lst.remove(10);
	 Printlst(lst);
	 lst.remove(0);
	 Printlst(lst);

	 int a[5] = { 1, 2, 1, 2, 1 };
	 list<int> lst2(a, a + 5);
	 Printlst(lst2);
	 lst2.remove(2);
	 Printlst(lst2);

 }

 void test4() {
	 //	splice: 拼接操作
	 list<int> lst1;
	 lst1.push_back(1);
	 lst1.push_back(2);
	 lst1.push_back(3);
	 lst1.push_back(4);

	 list<int> lst2;
	 lst2.push_back(7);
	 lst2.push_back(8);
	 lst2.push_back(9);
	 lst2.push_back(10);

	 //splice: 拼接的元素直接存入第一个list1中,第二个list2不在保留被拼接的元素
	 lst1.splice(++lst1.begin(), lst2);
	 cout << "splice" << endl;
	 Printlst(lst1);
	 Printlst(lst2);

	 lst2.splice(lst2.begin(), lst1, ++lst1.begin(), --lst1.end());
	 Printlst(lst1);
	 Printlst(lst2);

	 lst1.splice(lst1.end(), lst2, --lst2.end());
	 Printlst(lst1);
	 Printlst(lst2);


	 lst2.push_back(7);
	 lst2.push_back(8);
	 lst2.push_back(9);
	 lst2.push_back(2);
	 Printlst(lst2);
	 //unique: 使用之前lst元素必须有序(必须要在去重之前对元素进行排好顺序,然后再进行去重处理)
	 cout << "unique" << endl;
	 lst2.unique();
	 Printlst(lst2);

	 cout << "sort" << endl;
	 lst2.sort();
	 Printlst(lst2);
	 lst2.unique();
	 Printlst(lst2);

 }

 void test5() {
	 //sort:排序
	 //如果是自定义类型的话,自定义类型必须提供能比较大小的关系
	 list<A> lst;
	 lst.emplace_back(2, 2);
	 lst.emplace_back(3, 3);
	 lst.emplace_back(4, 5);
	 lst.emplace_back(5, 5);
	 lst.sort();
	 //Printlst(lst);

	 //merge:
	 list<int> lst2;
	 lst2.push_back(4);
	 lst2.push_back(10);
	 lst2.push_back(6);
	 lst2.push_back(1);

	 list<int> lst3(lst2);
	 lst3.sort();
	 lst2.sort();
	 cout << "merge" << endl;
	 lst2.merge(lst3);
	 Printlst(lst2);

	 cout << "reversr" << endl;
	 lst2.reverse();
	 Printlst(lst2);
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

//## list模拟实现:双向带头循环链表
			
#include <list>
#include <iostream>
using namespace  std;

 template<class T>

 struct ListNode{
	 T _value;
	 ListNode<T>* _next;
	 ListNode<T>* _prev;
	 //对各个节点进行初始化列表
	 ListNode(const T& val = T())
		 :_value(val)
		 , _next(nullptr)
		 , _prev(nullptr)
	 {}
 };
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// list实现迭代器的过程:
 template<class T>
 struct ListIterator{

	 typedef ListNode<T> Node;
	 typedef ListIterator<T> Self;

	 ListIterator(Node* node)
		 :_node(node)
	 {}
	 // 解引用:*iterator--->获取节点value
	 T& operator*() {
		 return _node->_value;
	 }
	 // 指针->成员
	 T* operator->() {
		 return &_node->_value;

	 }

	 // ++:移动到下一个元素的位置
	 Self& operator++() {

		 _node = _node->_next;
		 return *this;
	 }
	 // 前置--
	 Self& operator--() {

		 _node = _node->_prev;
		 return *this;
	 }

	 bool operator != (const Self& it) {
		 return _node != it._node;
	 }

	 Node* _node;
 };

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 template<class T>

 class List {
 public:
	 typedef ListNode<T> Node;
	 typedef ListIterator<T> iterator;

	 typedef const ListIterator<T> const_iterator;


	 iterator begin() {
		 // 第一个元素的位置
		 return iterator(_header->_next);
	 }

	 iterator end() {
		 // 最后一个元素的下一个位置
		 return iterator(_header);
	 }

	 List()
		 :_header(new Node)
	 {
		 // 构建循环结构
		 _header->_next = _header->_prev = _header;
	 }

	 void pushBack(const T& val) {
		 Node* cur = new Node(val);
		 // 链接
		 Node* prev = _header->_prev;
		 prev->_next = cur;
		 cur->_prev = prev;

		 cur->_next = _header;
		 _header->_prev = cur;
	 }

 private:
	 Node* _header;
 };

 class B {
 public:
	 B(int a, int b)
		 :_a(a)
		 , _b(b)
	 {
	 }
	 int _a;
	 int _b;
 };

 void test1() {
	 List<int> lst;
	 lst.pushBack(1);
	 lst.pushBack(2);
	 lst.pushBack(3);
	 lst.pushBack(4);
	 lst.pushBack(5);

 }


 void test2() {
	 List<int> lst;
	 lst.pushBack(1);
	 lst.pushBack(2);
	 lst.pushBack(3);
	 lst.pushBack(4);
	 lst.pushBack(5);
	 List<int> ::iterator it = lst.begin();
	 while (it != lst.end()) {
		 cout << it.operator*() << " ";
		 *it = 10;
		 it.operator++();
	 }
	 cout << endl;


	 it = lst.begin();
	 while (it != lst.end()) {
		 cout << it.operator*() << " ";

		 it.operator++();
	 }
	 cout << endl;
 }
 void test3() {

	 List<B> lst;
	 lst.pushBack(1, 2);
	 lst.pushBack(3, 4);
	 lst.pushBack(5, 6);

	 B* pb = new B(7, 8);
	 cout << pb->_a << endl;
	 cout << pb->_b << endl;
	 cout << *pb << endl;


	 List<B>::iterator it = lst.begin();
	 while (it != lst.end()) {
		 cout << *it << endl;
		 cout << it->_a << "-" << it->_b << endl;
		 cout << it.operator->()->_a << "-" << it.operator->()->_b << endl;
		 it++;
	 }
 }

 int main() {

	 test1();
	 test2();
	 test3();
	 system("color A");
	 system("pause");
	 return 0;
 }
	
		 //list迭代器:
		 //1.不是原生指针实现的
			// 2.通过封装节点, 定义一个自定义类型, 通过运算符重载函数完成迭代器规定的操作
			// 3.迭代器不是一个指针, 而是一个对象
			// 4.解引用 : *iterator : operator*()-- > _node->val
			// 5.++, --, --opereator, ++operator: operator++--->_node = _node->_next, operator---- > _node = _node->_prev;
		 //6.箭头iterator->:operator->()-- > &_node->val
			// 7. != iterator != iterator2: operator!=()-- > _node != iterator2._node
