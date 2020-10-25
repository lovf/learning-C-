
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////深拷贝: 成员+资源
//string类实现:类似于顺序表实现
#define  _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
using namespace  std;

class String {
	
public: 


	//迭代器:一种访问容器元素的机制,体现封装的特性,不需要关注容器的实现细节,就可以直接访问(可读可写)元素
	//使用方式类似于指针
	//1.解引用--->获取指向位置的内容
	//2.位置移动--->指向其他位置
	//String 迭代器: 通过char*来实现
	//1.可读可写迭代器:char*
	//2.只读迭代器:const char*
	//3.begin:字符串首地址--->_str
	//4.end:最后一个字符的下一个位置--->_str+_size
	//范围for:通过迭代器实现
	//1.编译器执行操作时,把范围for转化成迭代器的遍历方式
	//2.如果遍历过程中,如果要进行写操作,接收类型需要为引用类型

	typedef char* iterator; //可读可写
	typedef const char* const_iterator; //可写
	//如果执行可读可写的操作就执行
	iterator begin() {
		//第一个元素的位置
		return _str;
	}

	iterator end() {
		//最后一个元素的下一个位置
		return _str + _size;
	}
	//如果执行可读的操作就执行,二者一定要区分开
	const_iterator begin() const {
		//第一个元素的位置
		return _str;
	}
	const_iterator end()  const{
		//最后一个元素的下一个位置
		return _str + _size;
	}

	



	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//1.构造函数
	//无参构造: 假如无参就调用该函数
	String()
		: _str(new char[16]) //开16个空间
		, _size(0)
		, _capacity(0)
	
	{
		_str[_size] = '\0';
		_capacity = 15;
	}

	//有参构造: 假如有参数就进行调用  有参时一定不能直接将地址进行拷贝过去
	String(const char* str) //表示以字符串作为参数进行初始化
	/*	:_str(str) 如果直接这样进行赋值之后那么,有可能不会被释放掉,因为常量位于代码段,而delete释放堆上的空间
		, _size(strlen(str))
		, _capacity(strlen(str))
	*/
	{
		_size = strlen(str);
		_str = new char[_size + 1]; //

		strcpy(_str, str);
		_capacity = _size;
	}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//2.拷贝构造
	////拷贝构造函数 传统写法 要进行空间的拷贝
	//String(const String& str)  
	//	:_str(new char[str._capacity+1])
	//	,_size(str._size)
	//	, _capacity(str._capacity)
	//
	//{
	//	//深拷贝: 资源拷贝  成员+资源
	//	strcpy(_str, str._str);
	//	cout << "String(const String& str) " << endl;
	//}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//拷贝构造现代写法 完成拷贝构造并且是一种深拷贝
	//不用开空间,体现代码的复用

	//拷贝构造:现代写法
	//1.复用构造函数
	//2.通过构造函数开空间,拷贝内容,最后通过成员和资源的交换,完成拷贝构造的逻辑
	String(const String& str )
		//要给初始化列表 ,假入不给tmp拷贝完之后要调用析构函数
		:_str(nullptr)  
		, _size(0)
		, _capacity(0)
	
	{
		//创建一个临时变量,调用拷贝构造
		String tmp(str._str);  //拷贝构造调用完之后要调析构
		Swap(tmp);
	}
	void Swap(String& str) {
		//交换三个成员变量的值即可
		swap(_str, str._str);
		swap(_size, str._size);
		swap(_capacity, str._capacity);
	}
	//深拷贝的交换: 效率很低
	//void Swap(String& str) {
	//	//1.拷贝构造
	//	String tmp=str;
	//	//2.赋值运算符
	//	str = *this;
	//	//3.赋值运算符
	//	*this = str;
	//}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//3.赋值运算符
	//// 赋值运算符
	//String& operator=(const String& str) {

	//	if (this != &str) {
	//		//开新的空间
	//		char* tmp = new char[str._capacity + 1];

	//		//把内容放到新的空间里面内容拷贝
	//		strcpy(tmp, str._str);
	//		//释放原有空间 
	//		delete[] _str;

	//		//再把新的空间给他们
	//		_str = tmp;
	//		_size = str._size;
	//		_capacity = str._capacity;

	//	}
	//	return *this;
	//}
	//深拷贝   赋值运算符的现代写法
	//拷贝构造:现代写法
	//1.复用构造函数
	//2.通过构造函数开空间,拷贝内容,最后通过成员和资源的交换,完成拷贝构造的逻辑

	//赋值运算符:现代写法
	//1.复用拷贝构造函数
	//2.传参时,通过值传递,调用拷贝构造构造创建局部变量,完成开空间+内容拷贝,最后通过成员和资源的交换,或许新的资源和内容,
	//最终调用局部对象的析构函数,释放原有空间,完成赋值的逻辑

	String& operator=(String str) {  //拷贝构造: (传参进行拷贝构造)

		Swap(str);//拷贝构造的复用
		return *this;
	}
	//string类的简单写法: 构造函数 拷贝构造(现代写法)  赋值运算符(现代写法)    析构函数 这四个就可以完成一个简单的string类的实现
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	const char* c_str() const {
		return _str;
	}
	//4.析构函数
	~String() {
		if (_str) {
			delete[] _str; //delete是属于释放堆上的空间
			_size = _capacity = 0;
			_str = nullptr;
		}
		cout << "~String()" << endl;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//尾插操作
	void pushBack(const char& ch) {
	////1.检查容量
	//	if (_size == _capacity) {
	//		size_t newC = _capacity == 0 ? 15 : 2 * _capacity;
	//		reserve(newC);
	//	}
	////2.尾插操作
	//	_str[_size] = ch;
	////3.更新size
	//	++_size;
	//	_str[_size] = '\0';
		insert(_size, ch);
	}
	void reserve(size_t n) {
		if (n > _capacity) {
		//1.开空间+1//存放\0
			char* tmp = new char[n + 1];

		//2.拷贝
			strcpy(tmp, _str);
		//3.释放原有空间
			delete[] _str;
			_str = tmp;
			//更新容量
			_capacity = n;
		}
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//第三种遍历方式:operator[]
	char& operator[](size_t pos) {
		if (pos < _size) {
			return _str[pos];
		}
	}
	const char& operator[](size_t pos) const{
		if (pos < _size) {
			return _str[pos];
		}
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	size_t size() const {
		return _size;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//尾插入一个字符串
	void Append(const char* str) {
	//	int len = strlen(str);
	////检查容量
	//	if (_size+len > _capacity) {
	//		reserve(_size + len);
	//	}
	////尾插
	//	strcpy(_str + _size, str);
	////修改size
	//	_size += len;
		insert(_size, str);
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//+=运算符 (应用概率很高)
	String& operator+=(const char& ch) {
		pushBack(ch);
		return *this;
	}

	String& operator+=(const char* str) {
		Append(str);
		return *this;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void insert(size_t pos,const char& ch) {
		if (pos > _size)
			return;
	//检查容量
		if (_size == _capacity) {
			size_t newC = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newC);
		}
		//移动元素[pos._size]:从后向前移动,先移动最右端,防止覆盖
		size_t end = _size+1;
		while (end > pos) {
			//end >= pos  :当pos=0死循环,越界
			_str[end] = _str[end-1]; //先移动的是'\0'
			--end;
		}
	//插入
		_str[pos] = ch;
		++_size;

	}
	void insert(size_t pos, const char* str) {
		if (pos > _size)
			return;
		int len = strlen(str);
		
		if (_size + len > _capacity) {
			reserve(_size + len);
		}
		//移动元素[pos,_size]  //移动的长度是字符串的长度
		size_t end = _size + len;
		while (end>pos+len-1) {
		//第一次: size--->size+len 最后一次: pos--->pos+len
			_str[end] = _str[end - len];
			--end;
		}
		//插入: //每一个元素都要插入
		for (int i = 0; i < len;i++) {
			_str[i + pos] = str[i];
		}
		_size += len;
	}

private:
	char* _str;
	size_t _size;
	size_t _capacity;
};

//ostream& operator<<(ostream& _cout, const String& d) {
//
//_cout<<
//
//}

void test() {
	string s;
	const char* ptr = s.c_str();
	cout << s.c_str() <<"结束"<<endl;

	String Str;
	const char* ptr2 = Str.c_str();
	cout << Str.c_str() << "结束" << endl; //字符串打印 不不是打印的是指针,而是打印字符内容 /Str.c_str() 指针为空


	String str2("123");//常量位于代码段   位于常量区的不能直接使用delete进行释放,必须要将其进行拷贝然后在释放
	ptr2 = str2.c_str();
	cout << ptr2 << endl;


}
void  test2() {
	//因此在这块要进行重新写,拷贝构造
	String s("123");
	//调用拷贝构造
	String copy = s; //字节序拷贝:只拷贝成员变量,不拷贝资源
	String copy2(s);  //字节序拷贝   类似于s被多次释放的问题,

	//赋值运算符  要在上面重新写,假如不重新写那么释放会被释放两次
	String s2("456");
	copy = s2;

}

//字节序拷贝:只拷贝成员变量,不拷贝资源
//问题: 资源会被多次释放,程序崩溃
//必须要进行深拷贝的过程


void PrintString(const String& str) {
	//迭代器遍历
	String::const_iterator it = str.begin();
	while (it != str.end()) {
		cout << *it << " ";
		//写操作
		//*it = '0';
		++it;
	}
	cout << endl;
}
void test3() {
	String s = " ";
	s.pushBack('a');
	s.pushBack('b');
	s.pushBack('c');
	s.pushBack('d');
	s.pushBack('e');
	s.pushBack('f');
	s.pushBack('g');
	cout << s.c_str() << endl;
	//迭代器遍历
	String::iterator it = s.begin();
	while (it != s.end()) {
		cout << *it << " ";
		//写操作
		*it = '0';
		++it;
	}
	cout << endl;

	PrintString(s);
	cout << "范围for" << endl;
	//范围for:用引用接收可以进行修改
	for  (char& ch : s) {
		cout << ch <<" ";
		ch = '1';
	}
	cout << endl;

	for (char& ch : s) {  //这块使用引用可以进行读写操作
		cout << ch << " ";
		ch = '2';
	}
	cout << endl;

	for (char& ch : s) {
		cout << ch << " ";
	}
	cout << endl;

	cout << "范围for没有接收使用应用"<<endl;

	for (char ch : s) { //没有使用引用类型
		cout << ch << " ";
		ch = '3';
	}
	cout << endl;

	for (char ch : s) { //没有使用引用类型
		cout << ch << " ";
		ch = '4';
	}
	cout << endl;

	//operator[]
	cout << "operator[]" << endl;
	for (int i = 0; i < s.size();i++) {
		cout << s[i] << " ";
		//写操作
		s[i] = '7';
	}
	cout << endl;

	cout << "operator[]修改之后" << endl;
	for (int i = 0; i < s.size(); i++) {
		cout << s[i] << " ";
	}
	cout << endl;

}
void test4() {
	String s;
	//s.Append("12345");
	s += "12345";
	PrintString(s); //按照迭代器的方式来打印

	//s.Append("gfdsjhkfflsd");
	s += "6";
	s += "fdgasjhkg";
	PrintString(s);
}
void test5() {
	String s;
	s += "012345";
	s.insert(1, 'a');//0a12345
	s.insert(7, '6'); //0a123456
	s.insert(0, '9'); //90a123456
	PrintString(s);

	s.insert(3,"cdef");
	PrintString(s);
}

int main () {
	//test();
	//test2();
	//test3();
	test4();
	//test5();
    system("color A");
    system ("pause");
    return 0;
}
// insert 常用 插入字符/字符串
//主要讲了迭代器/深浅拷贝/插入

