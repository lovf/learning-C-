//list 接口

#include <iostream>
#include <list>
using namespace std;

template <class T>

void printLst(list<T>& lst) {
	for (auto& ch : lst) {
		cout << ch << " ";
	}
	cout << endl;

}

class A {

public:
	A(int a, int b)
		:_a(a)
	{
	
		cout << "A(int ,int)" << endl;
	}
	bool operator < (const A& a) {
	
		return _a < a._a;
	}
	bool operator > (const A& a) {

		return _a > a._a;
	}

private:
	int _a;

};

//void test1() {
//	list<int>lst1;//无参构造
//	list<char>lst2(5, 'a');//构造n个val //aaaaa
//
//	char str[] = "12345";
//	list<char>lst3(str, str + 5); //在迭代器区间范围内构造list//12345
//	list<char>lst4(lst2.begin(), lst2.end()); //aaaaa
//
//	list<char>lst5(lst3);//12345
//	list<int>lst6(3, 1);
//	//迭代器遍历
//	list<char>::iterator it3 = lst3.begin();
//	while (it3 != lst3.end()){
//		cout << *it3 << " ";
//		//*it3 = '6';
//		++it3;
//	}
//	cout << endl;
//	////将修改的进行打印
//	//cout << " 修改之后的结果: " << endl;
//	//it3 = lst3.begin();
//	//while (it3 != lst3.end()){
//	//	cout << *it3 << " ";
//	//	++it3;
//	//}
//	//cout << endl;
//
//	list<int>::iterator it6 = lst6.begin();
//	while (it6 != lst6.end()){
//		cout << *it6 << " ";
//		*it6 = 5;
//		++it6;
//	}
//	cout << endl;
//	//将修改的进行打印
//	cout << " 修改之后的结果: " << endl;
//	it6 = lst6.begin();
//	while (it6 != lst6.end()){
//		cout << *it6 << " ";
//		++it6;
//	}
//	cout << endl;
//
//	//范围for遍历
//	//假如要使打印的结果进行修改,必须进行再定义的时候取&
//	for (auto ch : lst3) {
//		cout << ch << " ";
//	}
//	cout << endl;
//
//	//for (auto& ch:lst3) {
//	//	cout << ch << " ";
//	//	ch = 'X';
//	//}
//	//cout << endl;
//
//	//for (auto& ch : lst3) {
//	//	cout << ch << " ";
//	//}
//	//cout << endl;
//	//逆向
//	list<char>::reverse_iterator rit = lst3.rbegin();
//	while (rit != lst3.rend()) {
//		cout << *rit << " ";
//		++rit;
//	}
//	cout << endl;
//	//const 迭代器
//	list<char>::const_iterator cit = lst3.cbegin();
//	while (cit != lst3.cend()) {
//		cout << *cit << " ";
//		++cit;
//	}
//	cout << endl;
//
//}

//void test2() {
//
//	//list<int>lst;
//	//lst.push_back(1);
//	//lst.push_front(0);
//	//lst.push_front(-1);
//	//lst.push_front(-2);
//	//for (auto& ch:lst) {
//	//	cout << ch << " ";
//	//}
//	//cout << endl;
//	////尾删
//	//lst.pop_back();
//	//printLst(lst);
//	////头删
//	//lst.pop_front();
//	///*for (auto& ch : lst) {
//	//	cout << ch << " ";
//	//}
//	//cout << endl;*/
//	//printLst(lst);
//
//	list<A>lst;//用参数来创建构造对象
//
//	A a(5, 6);//还得调用拷贝构造
//	lst.emplace_back(10,9);//假如是emplace就不用做拷贝构造,因为内部已经创建好了,因此效率高
//	lst.emplace_front(-1, 0);
//	lst.emplace_front(a);
//}

//切记:lst迭代器在插入之后,不会导致迭代器失效,以下程序进行验证
//void test3() {
//	//插入: 既可以传入迭代器的位置,也可以传入迭代器区间的位置
//	list<int>lst;
//	//list迭代器在插入后不会失效
//	lst.insert(lst.begin(), 1); //在lst头部插入1个1
//	list<int>::iterator it = lst.begin();
//	cout << "*it: " << *it << endl;
//	printLst(lst);//1
//	lst.insert(lst.begin(), 3, 0);//在lst的头部插入3个0
//	cout << "*it: " << *it << endl;
//	printLst(lst);//0001
//	list<int>cop(lst);
//	lst.insert(lst.end(), cop.begin(), cop.end());//迭代器区间插入  避免使用自己的迭代器
//	//lst.insert(lst.end(), lst.begin(), lst.end());// 注意由于使用自己区间的变量名,导致程序进入了一个死循环的过程
//
//	cout << "*it: " << *it << endl;
//	printLst(lst);//0001 0001
//
//	//insert: 即可以传入迭代器的位置,也可以插入迭代器区间的位置
//	////**这块删除之后导致迭代器失效,调用删除接口后,需要重新更新迭代器:1.或许erase的返回值,2.调用迭代器接口
//	cout << "erase" << endl;
//	//lst.erase(it); //删除第一个元素的位置 
//	//cout << "*it" << *it << endl; //删除也会导致迭代器失效，（原因在于删除 之后,导致空间释放,然后再解引用导致使用非法内存空间）
//	//删除之后,然后在打印导致迭代器实效.
//	//解决办法是重新获取迭代器,然后打印结果是下一个元素的位置
//	it = lst.erase(it);
//	cout << "*it: "<<*it << endl; //删除也会导致迭代器失效，（原因在于删除之后然后再解引用导致了目前的结果）
//	printLst(lst); 
//	lst.erase(lst.begin(),lst.end());//删除[begin(),end)区间的位置的值
//	printLst(lst);
//	//resize: 接口
//	cout << "resize" << endl;
//	lst.resize(5);// 默认添加5个0
//	printLst(lst);
//	lst.resize(7,1);//
//	printLst(lst);
//
//	//关于list的特殊接口
//	//应用: 比如给一个链表,让删除其中的元素
//	//remove: 删除指定值,如果有多个,则全部删除,如果没有则不做任何改变
//	cout << "remove" << endl;
//	lst.remove(1);//删除lst中的1
//	printLst(lst); 
//	lst.remove(10);//删除lst中的10  指向元素不存在,那么不做任何的改变,只删除里面的元素而已
//	printLst(lst);
//	lst.remove(0);//删除lst中的0
//	printLst(lst);
//    //remove 删除时,只删除指定的元素,与元素的位置无关
//
//	int a[5] = { 1, 2, 1, 2, 1 };
//	list<int>lst2(a,a+5);
//	printLst(lst2);
//	lst2.remove(2);
//	printLst(lst2);
//
//}
//void test4() {
//	//if接口: 找到特定的值进行修改
//	//remove_if();//满足
//	list<int>lst1;
//	lst1.push_back(1);
//	lst1.push_back(2);
//	lst1.push_back(3);
//	lst1.push_back(4);
//	printLst(lst1);
//
//	list<int>lst2;
//	lst2.push_back(7);
//	lst2.push_back(8);
//	lst2.push_back(9);
//	printLst(lst2);
//	//splice: 拼接时,被拼接的元素直接存入第一个lst1,第二个list中不再保留被拼接的元素
//	lst1.splice(++lst1.begin(), lst2); //从当前位置的前面进行插入  当插入lst2时,,此时变为全部是空了
//	cout << "splice" << endl;
//	printLst(lst1);
//	printLst(lst2);
//	lst2.splice(lst2.begin(),lst1,++lst1.begin(),--lst1.end());
//	printLst(lst1);
//	printLst(lst2);
//
//	lst1.splice(lst1.end(),lst2,--lst2.end());
//	printLst(lst1);
//	printLst(lst2);
//	//unique:(去重排序的有效元素)  使用之前需要lst有序
//	lst2.push_back(7);
//	lst2.push_back(8);
//	lst2.push_back(9);
//	lst2.push_back(2);
//	printLst(lst2);
//	//unique:(去重)  使用之前需要lst有序  利用sort接口进行处理    
//	lst2.unique();
//	cout << "unique" << endl;
//	printLst(lst2);
//
//	lst2.sort();
//	cout << "sort: " << endl;
//	printLst(lst2);
//	lst2.unique();
//	cout <<" sorted unique: "<<endl;
//	printLst(lst2);
//}

//sort接口
void test5() {
	//list<A>lst1;
	//lst1.emplace_back(1,1);
	//lst1.emplace_back(2,2);
	//lst1.emplace_back(3,3);
	//lst1.emplace_back(4,4);
	//lst1.emplace_back(5,5);
	////如果需要给自定义类型进行排序,那么自定义类型需要支持比较运算
	//lst1.sort();
	////printLst(lst1);

	//merge sorted  lists:合并两个有序链表
	//合并之前要保证有序
	list<int>lst2;
	lst2.push_back(4);
	lst2.push_back(10);
	lst2.push_back(6);
	lst2.push_back(1);
	lst2.sort();
	printLst(lst2);
	//list<int>lst3(lst2); //
	//lst2.sort();
	//lst3.sort();
	//lst2.merge(lst3);
	//printLst(lst2);
	//cout << "reverse:" << endl;
	//lst2.reverse();
	//printLst(lst2);
}
int main() {
	// test1();
	//test2();
	//test3();
	//test4();
	test5();
	system("pause");
	return 0;
}
























