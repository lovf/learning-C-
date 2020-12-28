///1. 关联式容器
//关联式容器也是用来存储数据的，与序列式容器不同的是，其里面存储的是<key, value>结构的键值对，在
//数据检索时比序列式容器效率更高.key表示查找数据的索引(这块的索引可以为任何值),value表示索引对应的数据
//pair中有两个类型:----first(key)----second(value)-----

//first======>key    second=====>value
//强调:======key表示查找数据的索引(这块的索引可以为任何值,整数,字符串都可以,没有局限 )
//2. 键值对
//用来表示具有一一对应关系的一种结构，该结构中一般只包含两个成员变量key和value，key代表键值，
//value表示与key对应的信息。比如：现在要建立一个英汉互译的字典，那该字典中必然有英文单词与其对应
//的中文含义，而且，英文单词与其中文含义是一一对应的关系，即通过该应该单词，在词典中就可以找到与
//其对应的中文含义。

//3. 树形结构的关联式容器
//根据应用场景的不桶，STL总共实现了两种不同结构的管理式容器：树型结构与哈希结构。树型结构的关联式
//容器主要有四种：map、set、multimap、multiset。这四种容器的共同点是：使用平衡搜索树(即红黑树)
//作为其底层结果，容器中的元素是一个有序的序列。下面一依次介绍每一个容器。
//map、set、multimap、multiset  都是不能修改key的

//3.1 set----中存放的元素都是不重复的---可以用于去重操作
//3.1.1 set的介绍
//==key和value是一样的,数据不能重复
//==有序遍历
//==不能修改

//翻译：
//1. set是按照一定次序存储元素的容器
//2. 在set中，元素的value也标识它(value就是key，类型为T)，并且每个value必须是唯一的。set中的元素
//不能在容器中修改(元素总是const)，但是可以从容器中插入或删除它们。
//3. 在内部，set中的元素总是按照其内部比较对象(类型比较)所指示的特定严格弱排序准则进行排序。
//4. set容器通过key访问单个元素的速度通常比unordered_set容器慢，但它们允许根据顺序对子集进行直接迭代。
//5. set在底层是用二叉搜索树(红黑树)实现的。

//注意：
//1. 与map / multimap不同，map / multimap中存储的是真正的键值对<key, value>，set中只放value，但
//在底层实际存放的是由<value, value>构成的键值对。
//2. set中插入元素时，只需要插入value即可，不需要构造键值对。
//3. set中的元素不可以重复(因此可以使用set进行去重)。
//4. 使用set的迭代器遍历set中的元素，可以得到有序序列
//5. set中的元素默认按照小于来比较========得到元素为升序排列
//6. set中查找某个元素, 时间复杂度为:log(2^n)
//7.set中的元素不允许修改(为什么)
//8. set中的底层使用二叉搜索树(红黑树)来实现

//#include<functional>
//#include <map>
//#include <set>
//#include <iostream>
//using namespace std;
//
//template<class T> 
//
//void PrintSet(const set<T>& set) {
//	for (const auto& e:set) {
//		cout << e << " ";
//	}
//	cout << endl;
//
//}
////set进行数据遍历========
//void testSet1() {
//	//三个set类型的创建
//	set<int> s1;
//	int arr[] = { 10, 2, 13, 4, 35 };
//	set<int> s2(arr, arr + sizeof(arr) / sizeof(arr[0]));
//	set<int> copy(s2);
//	//搜索树的中序遍历
//	//set容器本身遍历有序====默认是小于的比较,因此得到的有序的升序列
//	set<int>::iterator sit1 = s2.begin();
//	while (sit1 != s2.end()) {
//		cout << *sit1 << " ";
//		++sit1;
//	}
//	cout << endl;
//
//	//按照大于比较:  遍历有序---递减
//	set<int, greater<int>> s3(arr, arr + sizeof(arr) / sizeof(arr[0]), greater<int>());
//	set<int, greater<int>>::iterator sit2 = s3.begin();
//	while (sit2 != s3.end()) {
//		cout << *sit2 << " ";
//
//		//set迭代器不能进行修改
//		//*sit2 = 10; 这块的key是不能进行修改的
//		++sit2;
//	}
//	cout << endl;
//
//	////====================此外里面存放的元素不能进行修改
//
//	//反向迭代器
//	//遍历有序====默认是小于的比较,因此得到的有序的升序列
//	set<int>::reverse_iterator rit1 = s2.rbegin();
//	while (rit1 != s2.rend()) {
//		cout << *rit1 << " ";
//		++rit1;
//	}
//	cout << endl;
//
//	set<int>::reverse_iterator rit2 = s3.rbegin();
//	while (rit2 != s3.rend()) {
//		cout << *rit2 << " ";
//		++rit2;
//	}
//	cout << endl;
//}
//
//
////验证set不能存放重复的数据====这块打印完之后得到只重复的那一个数字
//void testSet2() {
//	int arr[] = { 10, 10, 10 };
//	set<int> s2(arr, arr + sizeof(arr) / sizeof(arr[0]));
//
//	//遍历有序====默认是小于的比较,因此得到的有序的升序列
//	set<int>::iterator sit = s2.begin();
//	while (sit != s2.end()) {
//		cout << *sit << " ";
//		++sit;
//	}
//	cout << endl;
//}
////关于插入最常用的接口: 1.insert接口 2.insert(s.begin(),s.end()) 含迭代器接口
////删除:
//void testSet3() {
//	set<int> s;
//
//	//元素插入: 失败--->返回值: bool:true    iterator: 新插入元素的位置    
//	pair<set<int>::iterator, bool> kvRet = s.insert(1); //pair<set<int>::iterator, bool>===K  V键值对判定是否插入元素
//	bool ret = kvRet.second;
//
//	cout << ret << endl;
//	set<int>::iterator it = kvRet.first;
//	cout << *it << endl;
//
//	//重复元素插入:失败--->返回值: bool:false    iterator:已经存在元素的位置   
//	kvRet = s.insert(1);
//	ret = kvRet.second;
//	cout << ret << endl;
//	it = kvRet.first;
//	cout << *it << endl; //1 已经存在的元素
//
//	s.insert(2);
//	s.insert(3);
//	s.insert(4);
//	s.insert(5);
//	s.insert(6);
//	s.insert(7);
//	it = s.begin();
//
//	//insert(iterator,value): iterator只是一个参考位置
//	it = s.insert(it, 12); //表示在第一个元素的位置前面放一个12,但是实际不一定放过去=====
//	//底层还是按照搜索树进行插入的
//
//	cout << *it << endl; //打印新插入元素的位置
//	++it;
//	//cout << *it << endl;
//
//	//表示不会插入新的元素,因为要插入的所有元素已经存在
//	//s.insert(s.begin(), s.end());
//	//会插入新的元素,s2中元素没有s中的元素
//	set<int> s2;
//	s2.insert(s.begin(), s.end());
//
//	PrintSet(s);
//	//erase 1.删除一个位置(s.begin())2.删除一个value(value) 3.删除一个迭代器区间(s.begin(),s.end())
//	//PrintSet(s);
//	cout << "erase:" << endl;
//	s.erase(3);//删除元素3 
//	PrintSet(s);
//
//	s.erase(s.begin());//删除第一个位置的元素
//	PrintSet(s);
//
//	s.erase(s.begin(),s.end());//删除一段区间的元素
//	PrintSet(s);
//
//	PrintSet(s2);
//	s2.clear();//表示清空元素
//	PrintSet(s2);
//}
//
////查找接口: 找到了:返回找到返回元素的迭代器  没找到:返回end元素的迭代器等价于  返回值等于end表示元素不存在
////用的比较多
////count====表示value出现的次数
////find======
//
//void testSet4() {
//	set<int> s;
//	s.insert(2);
//	s.insert(3);
//	s.insert(4);
//	s.insert(5);
//	s.insert(6);
//	s.insert(7);
//
//	auto it = s.find(5);
//	cout << (it == s.end()) << endl; //找到不等于end
//
//	it = s.find(10);
//	cout << (it == s.end()) << endl; //没有找到等于end 
//
//	cout << s.count(5) << endl;
//	cout << s.count(10) << endl;
//
//	//这块作用不大
//	pair<set<int>::iterator, set<int>::iterator> p = s.equal_range(5);
//	cout << *(p.first) << endl;
//	cout << *(p.second) << endl;
//
//}
//int main() {
//
//	//testSet1();
//	//testSet2();
//	//testSet3();
//	testSet4();
//	system("pause");
//	return 0;
//}

//set接口总结:
//重点:1.set的构造 2.迭代器遍历 3.插入和删除  3.find和count接口(查找效率高)=====因为key和value是一样的,因此导致value是不能重复的

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

//3.2 map
//3.2.1 map的介绍
//翻译：
//1. map是关联容器，它按照特定的次序(按照key来比较)存储由键值key和值value组合而成的元素。
//2. 在map中，键值key通常用于排序和惟一地标识元素，而值value中存储与此键值key关联的内容。键值
//key和值value的类型可能不同，并且在map的内部，key与value通过成员类型value_type绑定在一起，
//为其取别名称为pair :
//typedef pair<const key,T> value_type;
//3. 在内部，map中的元素总是按照键值key进行比较排序的。
//4. map中通过键值访问单个元素的速度通常比unordered_map容器慢，但map允许根据顺序对元素进行
//直接迭代(即对map中的元素进行迭代时，可以得到一个有序的序列)。
//5. map支持下标访问符，即在[]中放入key，就可以找到与key对应的value
//6. map通常被实现为二叉搜索树(更准确的说：平衡二叉搜索树(红黑数)


//key: 键值对中key的类型
//	 T： 键值对中value的类型
// Compare : 比较器的类型，map中的元素是按照key来比较的，缺省情况下按照小于来比较，一般情况
//		   下(内置类型元素)该参数不需要传递，如果无法比较时(自定义类型)，需要用户自己显式传递比较规则
//		   (一般情况下按照函数指针或者仿函数来传递)
//		   Alloc：通过空间配置器来申请底层空间，不需要用户传递，除非用户不想使用标准库提供的空间配置器
//		   注意：在使用map时，需要包含头文件。

//默认按照key从小到大的关系进行比较============================================
//map本身支持operator[]进行访问
//map所有的接口都是基于key进行查找的

//#include <string>
//#include<functional>
//#include <map>
//#include <set>
//#include <iostream>
//using namespace std;
//
//
//template<class K,class V> 
//
//
//void PrintMap(const map<K, V,less<K>>& mp) {
//	for (const auto& p:mp) {
//		cout << p.first << "--->" << p.second << endl;
//	}
//}
//
//
//template<class K, class V>
//void PrintMap(const map<K, V, greater<K>>& mp) {
//	for (const auto& p : mp) {
//		cout << p.first << "--->" << p.second << endl;
//	}
//}
//
//
//void testMap() {
//	map<int, int> mp1;
//	map<string, int> mp2; //表示key是一个字符串,value是一个整数  应用: 统计单词出现的次数
//
//
//	//数据单元: pair类型
//	pair<int, int> arr[] = { { 1, 2 }, { 3, 4 } };
//	map<int, int> mp3(arr, arr + 2);
//
//	pair<string, int> arr2[] = { { "a", 10 }, { "bcd" , 5 } };
//	map<string, int> mp4(arr2, arr2 + 2);
//
//	//默认打印的值(小于比较)是按照递增的顺序进行打印的
//	////遍历有序: 遍历按照key的大小关系进行有序遍历: 搜索树的中序遍历
//	//map<int, int>::iterator it = mp3.begin();
//	//while (it != mp3.end()) {
//	//	//错误的写法	:解引用之后的类型是pair,pair不支持cout(输出)
//	//	//cout<<*it<<endl;
//	//	//pair有多个成员,可以通过迭代器的->访问每一个成员
//	//	cout << it->first << "--->" << it->second << endl;
//	//	++it;
//	//}
//
//	//map<string, int>::iterator it2 = mp4.begin();
//	//while (it2 != mp4.end()) {
//	//	cout << it2->first << "--->" << it2->second << endl;
//	//	++it2;
//	//}
//	//以上默认打印的值(小于比较)是按照递增的顺序进行打印的
//	
//	/////======将默认的小于比较改成大于的比较=====将key从小到大进行比较
//	////遍历有序: 遍历按照key的大小关系进行有序遍历: 搜索树的中序遍历
//	map<int, int,greater<int>>::iterator it = mp3.begin();
//	while (it != mp3.end()) {
//		//错误的写法	:解引用之后的类型是pair,pair不支持cout(输出)
//		//cout<<*it<<endl;
//		//pair有多个成员,可以通过迭代器的->访问每一个成员
//		cout << it->first << "--->" << it->second << endl;
//		++it;
//	}
//
//	map<string, int, greater<int>>::iterator it2 = mp4.begin();
//	while (it2 != mp4.end()) {
//		cout << it2->first << "--->" << it2->second << endl;
//		++it2;
//	}
//	//////////////////////////////////////////////////////////////////
//
//	////只能修改value,不能修改value;修改完之后所有的值等于修改之后的值
//	//cout << "value修改" << endl;
//	//it = mp3.begin();
//	//while (it != mp3.end()) {
//	//	//错误的写法	:解引用之后的类型是pair,pair不支持cout
//	//	//cout<<*it<<endl;
//	//	//通过迭代器修改
//	//	//it->first = 10;
//	//	it->second = 100;
//	//	//pair有多个成员,可以通过迭代器的->访问每一个成员
//	//	cout << it->first << "--->" << it->second << endl;
//	//	++it;
//	//}
//
//
//	//operator[] (key)可以通过key找到所对应的value,返回value的引用
//	cout << "修改之前对应的值: " << endl;
//	cout << mp4["a"] << endl; // mp4["a"]====找到mp4中字符a所对应的value,此时key是"a"
//	mp4["a"] = 1000;//修改value对应的值
//	cout << "修改之后对应的值: " << endl;
//	cout << mp4["a"] << endl;
//
//	cout << "[]修改之后全部的值: " << endl;
//	PrintMap(mp4);
//
//
//	//insert==也可以完成插入的操作
//	//operator[]操作:   如果key不存在,直接插入
//	//1.插入:K,V
//	//2.插入成功:返回k对应的pair数据的迭代器,获取pair数据对应的second(value对应的默认值)
//	//  插入失败:返回已经存在的K对应数据的迭代器,获取pair数据对应的second(已经存在的value值)
//
//	mp4["f"] = 10;
//	cout << "[]插入之后全部的值:" << endl;
//	PrintMap(mp4);
//	
//	cout << "insert: " << endl;
//	//错误写法
//	//mp4.insert("fffff", 5);  //这块的操作是错误的,因为要插入K,V键值对因此插入pair数据=====K,V数据是根据pair产生的
//
//	//要插入pair类型的数据
//	//1.调用构造
//	mp4.insert(pair<string, int>("fffff", 5));
//	PrintMap(mp4);
//
//	//2.调用make_pair函数
//	mp4.insert(make_pair("aa", 5));
//	PrintMap(mp4);
//
//
//	//at操作: 如果key不存在,抛异常
//	//mp4.at("q");//因为key不存在,无法通过key找到对应的键值对
//
//	//erase:
//	//删除某一个位置的元素
//	//删除key所对应的键值对的数据
//	//删除迭代器区间的元素
//	
//	//find基于key进行查找的
//	//找不到返回end迭代
//	//count统计键值为key的元素有多少个,key不能重复==一般结果是等于1,或者等于0
//}
//
//int main() {
//
//	testMap();
//	system("pause");
//	return 0;
//}

//【总结】
//1. map中的的元素是键值对
//2. map中的key是唯一的，并且不能修改
//3. 默认按照小于的方式对key进行比较;得到的数据是递增的数据
//4. map中的元素如果用迭代器去遍历，可以得到一个有序的序列
//5. map的底层为平衡搜索树(红黑树)，查找效率比较高
//6. 支持[]操作符，operator[]中实际进行插入查找。

//3.3 multiset
//3.3.1 multiset的介绍
//multiset文档介绍
//[翻译]：
//1. multiset是按照特定顺序存储元素的容器，其中元素是可以重复的。
//2. 在multiset中，元素的value也会识别它(因为multiset中本身存储的就是<value, value>组成的键值对，
//因此value本身就是key，key就是value，类型为T).multiset元素的值不能在容器中进行修改(因为元素总是const的)，但可以从容器中插入或删除。
//3. 在内部，multiset中的元素总是按照其内部比较规则(类型比较)所指示的特定严格弱排序准则进行排序。
//4. multiset容器通过key访问单个元素的速度通常比unordered_multiset容器慢，但当使用迭代器遍历时会得到一个有序序列。
//5. multiset底层结构为二叉搜索树(红黑树)。
//注意：
//1. multiset中再底层中存储的是<value, value>的键值对
//2. mtltiset的插入接口中只需要插入即可
//3. 与set的区别是，multiset中的元素可以重复，set是中value是唯一的
//4. 使用迭代器对multiset中的元素进行遍历，可以得到有序的序列
//5. multiset中的元素不能修改
//6. 在multiset中找某个元素，时间复杂度为
//7. multiset的作用：可以对元素进行排序


//#include<functional>
//#include <map>
//#include <set>
//#include <iostream>
//using namespace std;
//
//
//void test() {
//	//multiset====可以用于存放重复的数据
//	//遍历有序: 从小到达进行遍历
//	multiset<int> s;
//	s.insert(1);
//	s.insert(15);
//	s.insert(1);
//	s.insert(3);
//	s.insert(1);
//	s.insert(10);
//	
//
//	for (const auto& e: s) {
//		cout << e << " ";
//	}
//	cout << endl;
//	//pair<multiset<int>::iterator, multiset<int>::iterator> it = s.equal_range(1);//找到所有值相同(起始到结束)的区间
//	// pair<multiset<int>::iterator, multiset<int>::iterator>//第一个为位置代表起始位置迭代器   第二个位置代表结束位置迭代器
//	    
//	auto it = s.equal_range(1);
//	//multiset<int>::iterator start = it.first;//代表起始位置的迭代器
//	auto start = it.first;
//	while (start != it.second) {
//		cout << *start << " ";
//		++start;
//	}
//	cout << endl;
//	//find:返回第一个元素的位置
//	start = s.find(1);
//	cout << *start << endl;
//	//count: 找到元素出现的次数
//
//	cout << s.count(1) << endl;  // s.count(1)表示找到key元素出现的个数
//}
//
//int main() {
//	test();
//	system("pause");
//	return 0;
//}

//3.4 multimap
//3.4.1 multimap的介绍
//multimap文档介绍
//翻译：
//1. Multimaps是关联式容器，它按照特定的顺序，存储由key和value映射成的键值对<key, value>，其中多个键值对之间的key是可以重复的，但是不支持[]操作
//2. 在multimap中，通常按照key排序和惟一地标识元素，而映射的value存储与key关联的内容。key和value的类型可能不同，通过multimap内部的成员类型value_type组合在一起，value_type是组合key
//和value的键值对 :
//typedef pair<const Key, T> value_type;
//3. 在内部，multimap中的元素总是通过其内部比较对象，按照指定的特定严格弱排序标准对key进行排序的。
//4. multimap通过key访问单个元素的速度通常比unordered_multimap容器慢，但是使用迭代器直接遍历
//multimap中的元素可以得到关于key有序的序列。
//5. multimap在底层用二叉搜索树(红黑树)来实现。
//
//注意：multimap和map的唯一不同就是：map中的key是唯一的，而multimap中key是可以重复的。
//
//3.4.2 multimap的使用

#include<functional>
#include <map>
#include <set>
#include <iostream>
using namespace std;

void test() {

	//map中key值是不能重复的,但是对于multimap而言key是可以重复的,但是不能进行修改
	multimap<int, int> mp;
	//map<int, int> mp;

	mp.insert(make_pair(1, 2));
	mp.insert(make_pair(1, 3));
	mp.insert(make_pair(1, 4));
	mp.insert(make_pair(1, 5));
	mp.insert(make_pair(1, 6));
	mp.insert(make_pair(1, 7));

	auto it = mp.begin();
	while (it != mp.end()) {
		cout << it->first << "--->" << it->second << endl;
		++it;
	}

}
int main() {
	test();
	system("pause");
	return 0;
}