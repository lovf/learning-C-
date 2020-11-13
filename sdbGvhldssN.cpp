
//��������͸�ֵ�����

//list :��ͷ˫��ѭ������,��֧���������
//list�򵥽ӿ�ʹ��
//////////////////////////////////////////////////////////////////////////
//list�Ĳ���������ᵼ�µ�����ʧЧ,ԭ������list������,�����ʱ��ֻ�ǽڵ����µ�ƴ��,�����ᵼ��ʧЧ
//listɾ�������ᵼ�µ�����ʧЧ,��Ϊ��ɾ��֮��ᵼ�¿ռ��ͷ�
//////////////////////////////////////////////////////////////////////////
//swap����ֻ��һ������Ĳ���,�ı�ͷ��ָ��,��һ��ǳ����������Ҫ��ʵ���������һ������ѭ��ִ������Ĳ�����
//resize:�ı���ЧԪ�صĸ���

//unique:ȥ��֮ǰ�Ƚ�������,�ȵ���һ��sort(),�������������ֱ�ӵ���sort
//merge:�ϲ�������������,ǰ��ϲ�֮ǰ�ȱ�֤�������һ��sort()����,ƴ��֮�󱻺ϲ���Ԫ�����ݱ�ɿյ�
//remove:�Ƴ��������ظ���Ԫ��
//reserve: ���������
//list�ı�����ֻ�ܽ��е������ͷ�Χfor �Ե��������б���������ʹ��operator[]�����Ե��������б���
//list������ʧЧ���⣺ ��Ϊ��˹�صײ�Ϊ˫��ѭ�����������list�н��в���ʱ�ǲ��ᵼ�µ�����ʧЧ�ģ�ֻ��ɾ��ʱ�Ż�ʧЧ������ʧЧ��ֻ��ָ��ɾ���ڵ��
//������������������������Ӱ��
#include <string>
#include <list>
#include <iostream>
using namespace std;

template<class T>
void PrintLst(const list<T>& lst) {
	//����������
	list<T>::const_iterator it = lst.cbegin();
	while (it != lst.cend()) {
	cout << *it << " ";
	++it;
	}
	cout << endl;
	////��Χfor����
	//for (auto& e:lst) {
	//	cout << e << " ";
	//}
	//cout << endl;
	
}

void test1() {
	//list<int> lst1;
	list<int> lst2(3,10);
	list<int> lst3(lst2.begin(),lst2.end());
	/////////////////////////////////list���ṩoperator[]�����Ĳ���,��֧���������//////////
	////////////////////////////////���list�����ķ�ʽֻ������:��Χfor�͵�����
	//list<int> copy(lst3);

	//PrintLst(lst2);
	PrintLst(lst3);
	/*
		list<int> lst4;
		lst4.push_back(1);
		lst4.push_back(2);
		lst4.push_back(3);
		lst4.push_back(4);
		cout << "����" << endl;
		PrintLst(lst4);

		cout << "����" << endl;
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
	lst1.erase(it);//ɾ��itλ�õ�Ԫ��
	PrintLst(lst1);
	//ɾ��һ�������ڵ�Ԫ��(���䷶ΧΪ����ҿ�����)
	lst1.erase(++lst1.begin(), --lst1.end());
	PrintLst(lst1);
	//ɾ���ڵ��ֻ��ָ��ǰ�ڵ�ĵ�����ʧЧ�ˣ���ǰ��ĵ�������Ȼ��Ч����Ϊ�ײ�Ϊ�������ռ䣬ֻ�б�ɾ���Ľڵ�Ż�ʧЧ��
	//cout << *it << endl;
	it = ++lst1.begin();
	cout << *it << endl;
}
void test5() {
	list<int> lst1;
	lst1.resize(2);
	PrintLst(lst1);

	lst1.resize(2, 2); //���������С�ڱ��������,�򱣳�ԭ������ЧԪ��
	PrintLst(lst1);

	lst1.resize(6,2);//������������ڱ��������,����ڵĲ��ָ���Ϊ�������Ԫ��
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
	//ƴ��֮��,ԭ����Ԫ�ػᷢ���ı�
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
//ȥ��Ԫ�ؽӿ�,Ӧ��: ��������ȥ��һ���������ظ���Ԫ��
void test7() {
		list<int> lst;
		lst.push_back(1);
		lst.push_back(10);
		lst.push_back(15);
		lst.push_back(1);
		lst.push_back(1);
		lst.push_back(1);
		PrintLst(lst);
	 //ȥ��֮ǰ����Ԫ������˳���
		lst.sort();
		PrintLst(lst);
		lst.unique();
		PrintLst(lst);
}
//�ϲ��ӿ�
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
////list�ӿ�ʵ��:˫���ͷѭ������
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
//	//�յĴ�ͷѭ������
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

//T*/Node*������ʵ�ֵ�����

//�������������¶�������         ������ȷʹ��
//++ /������/!=/


