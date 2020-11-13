
//拷贝构造和赋值运算符

//list :带头双向循环链表,不支持随机访问
//list简单接口使用
//////////////////////////////////////////////////////////////////////////
//list的插入操作不会导致迭代器失效,原因在于list是链表,插入的时候只是节点重新的拼接,并不会导致失效
//list删除操作会导致迭代器失效,因为被删除之后会导致空间释放
//////////////////////////////////////////////////////////////////////////
//swap操作只是一个很轻的操作,改变头的指向,是一种浅拷贝操作，要想实现深拷贝必须一步步的循环执行深拷贝的操作。
//resize:改变有效元素的个数

//unique:去重之前先进行排序,先调用一下sort(),对链表进行排序直接调用sort
//merge:合并两个有序链表,前提合并之前先保证有序调用一下sort()函数,拼接之后被合并的元素内容变成空的
//remove:移除数组中重复的元素
//reserve: 链表的逆置
//list的遍历：只能进行迭代器和范围for 对迭代器进行遍历，不能使用operator[]操作对迭代器进行遍历
//list迭代器失效问题： 因为李斯特底层为双向循环链表，因此在list中进行插入时是不会导致迭代器失效的，只有删除时才会失效，并且失效的只是指向被删除节点的
//迭代器，其他迭代器不会受影响
#include <string>
#include <list>
#include <iostream>
using namespace std;

template<class T>
void PrintLst(const list<T>& lst) {
	//迭代器遍历
	list<T>::const_iterator it = lst.cbegin();
	while (it != lst.cend()) {
	cout << *it << " ";
	++it;
	}
	cout << endl;
	////范围for遍历
	//for (auto& e:lst) {
	//	cout << e << " ";
	//}
	//cout << endl;
	
}

void test1() {
	//list<int> lst1;
	list<int> lst2(3,10);
	list<int> lst3(lst2.begin(),lst2.end());
	/////////////////////////////////list不提供operator[]遍历的操作,不支持随机访问//////////
	////////////////////////////////因此list遍历的方式只有两种:范围for和迭代器
	//list<int> copy(lst3);

	//PrintLst(lst2);
	PrintLst(lst3);
	/*
		list<int> lst4;
		lst4.push_back(1);
		lst4.push_back(2);
		lst4.push_back(3);
		lst4.push_back(4);
		cout << "正向" << endl;
		PrintLst(lst4);

		cout << "反向" << endl;
		list<int>::reverse_iterator it = lst4.rbegin();
		while (it != lst4.rend()) {
		cout << *it << " ";
		it++;
		}
		cout << endl;
		*/
}

void test2() {
	list<int> lst1;
	list<char> lst2;
	list<string> lst3;

	cout << lst1.max_size() << endl;
	cout << lst2.max_size() << endl;
	cout << lst3.max_size() << endl;
}

void test3() {
	/*list<int> lst1;
	lst1.push_front(0);
	lst1.emplace_front(-1);
	PrintLst(lst1);
	lst1.push_back(0);
	lst1.emplace_back(-7);
	PrintLst(lst1);*/
	list<int> lst2;
	int arr[] = { 1, 2, 3 };
	lst2.assign(arr, arr + 3);
	PrintLst(lst2);
	
	lst2.assign(3, 5);
	PrintLst(lst2);
}

void test4() {
	list<int> lst1;
	lst1.insert(lst1.begin(), 0);
	PrintLst(lst1);
	lst1.insert(lst1.end(), 1);
	PrintLst(lst1);
	lst1.insert(--lst1.end(), 2);
	PrintLst(lst1);
	lst1.insert(--lst1.end(), 3, 5);
	PrintLst(lst1);
	int arr[] = { 7, 8 };
	lst1.insert(lst1.begin(), arr, arr + 2);
	PrintLst(lst1);
	list<int>::iterator it = ++lst1.begin();
	cout << *it << endl;
	lst1.insert(it, 9);
	PrintLst(lst1);
	lst1.erase(it);//删除it位置的元素
	PrintLst(lst1);
	//删除一段区间内的元素(区间范围为左闭右开区间)
	lst1.erase(++lst1.begin(), --lst1.end());
	PrintLst(lst1);
	//删除节点后，只有指向当前节点的迭代器失效了，其前后的迭代器仍然有效，因为底层为不连续空间，只有被删除的节点才会失效，
	//cout << *it << endl;
	it = ++lst1.begin();
	cout << *it << endl;
}
void test5() {
	list<int> lst1;
	lst1.resize(2);
	PrintLst(lst1);

	lst1.resize(2, 2); //扩充的容量小于本身的容量,则保持原来的有效元素
	PrintLst(lst1);

	lst1.resize(6,2);//扩充的容量大于本身的容量,则大于的部分更新为新扩充的元素
	PrintLst(lst1);

	 list<string> lst2;
	 lst2.resize(2);
	 PrintLst(lst2);
	 
}

void test6() {
	list<int> lst;
	list<int> lst2;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	PrintLst(lst);

	lst2.push_back(4);
	lst2.push_back(5);
	PrintLst(lst2);
	//拼接之后,原来的元素会发生改变
	/*lst.splice(lst.begin(), lst2);
	PrintLst(lst);
	PrintLst(lst2);*/
	lst2.splice(lst2.end(), lst,++lst.begin(),--lst.end());
	PrintLst(lst2);

	lst2.remove(4);
	PrintLst(lst2);
	lst2.remove(100);
	PrintLst(lst2);
	 
}
//去重元素接口,应用: 可以用于去掉一个数组中重复的元素
void test7() {
		list<int> lst;
		lst.push_back(1);
		lst.push_back(10);
		lst.push_back(15);
		lst.push_back(1);
		lst.push_back(1);
		lst.push_back(1);
		PrintLst(lst);
	 //去重之前必需元素是有顺序的
		lst.sort();
		PrintLst(lst);
		lst.unique();
		PrintLst(lst);
}
//合并接口
void test8() {
	list<int> lst1;
	list<int> lst2;

	lst1.push_back(1);
	lst1.push_back(2);
	lst1.push_back(3);
	PrintLst(lst1);

	lst2.push_back(4);
	lst2.push_back(1);
	lst2.push_back(13);
	PrintLst(lst2);

	lst1.sort();
	PrintLst(lst1);

	lst2.sort();
	PrintLst(lst2);
	lst1.merge(lst2);

	PrintLst(lst1);
	lst1.clear();
	PrintLst(lst1);
}
int main() {
	//test1();
	//test2();
	//test3();
	//test5();
	//test4();
	//test6();
	//test7();
	test8();
	system("color A");
	system("pause");
	return 0;
}


//emplace_back();
//emplace_front();
//push_front();
//push_back();


//
////list接口实现:双向带头循环链表
//
//#include <iostream>
//using namespace std;
//
//template<class T>
//struct ListNode{
//
//	T* _date;
//	ListNode<T>* _next;
//	ListNode<T>* _prev;
//
//	ListNode(const T& val = T())
//		:_date(val)
//		, _next(nullptr)
//		, _prev(nullptr)
//	{}
//
//};
//template<class T>
//class List{
//public:
//	typedef ListNode<T> Node;
//	List(){
//	//空的带头循环链表
//		_head = new Node;
//		_head->_next = _head->_prev = _head;
//	}
//	
//	void push_back() {
//	
//	
//	
//	
//	}
//private:
//	Node* _head;
//};
//
//
//
//int main () {
//
//
//
//system("pause");
//return 0;
//}

//T*/Node*都不能实现迭代器

//理解迭代器的重新定义类型         才能正确使用
//++ /解引用/!=/


