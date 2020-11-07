#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <assert.h>
#include <iostream>
using namespace  std;

class String{
public:
	//无参构造
	String(char* str = " ")	
	{
		_size = strlen(str);
		_capacity = _size;
		_ptr = new char[_size + 1];
		strcpy(_ptr, str);
	}

	//拷贝构造  传统写法
	/*String(String& str) 
		:_ptr(new char[strlen(str._ptr)+1])
		, _capacity(str._capacity)
		, _size(_size)
	{
		strcpy(_ptr, str._ptr);
	}*/
	void Swap(String& str) {
		swap(_ptr, str._ptr);
		swap(_size, str._size);
		swap(_capacity, str._capacity);
	}
	//拷贝构造 现代写法
	String(String& str) 
		:_ptr(nullptr)
		, _size(0)
		, _capacity(0)
	{
		String tmp(str._ptr);
		Swap(tmp);
	}
	////赋值运算符重载  传统
	String& operator=(String& str) {
		if (this != &str) {
		//开空间
			char* tmp = new char[strlen(str._ptr) + 1];
		//赋值拷贝
			strcpy(tmp, str._ptr);
		//释放
			delete[] _ptr;
			_ptr = tmp;
			_size = str._size;
			_capacity = str._capacity;
		}
		return *this;
	}
	////赋值运算符重载 现代
	/*String& operator=(String str){
		Swap(str);
		return *this;
		}*/
	//尾插
	void push_back(const char& ch) {
	//判定容量
		if (_size == _capacity) {
		//增容
			size_t newC = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newC);
		}
		//插入字符
		_ptr[_size++] = ch;
	  //尾部添加'\0'
		_ptr[_size] = '\0';
	}

	void reserve(size_t n) {
		if (n >_capacity) {
		//开新的空间
			char* tmp = new char[n + 1];
		//拷贝
			//strcpy(tmp, _ptr);
			for (int i = 0; i <= _size;++i) {
				tmp[i] = _ptr[i];
			}
		//释放原有的空间
			delete[] _ptr;
			_ptr = tmp;
			//更新容量
			_capacity = n;
		}
	}
	//插入字符串
	void Append(const char* str) {
	//获取插入字符串的长度
		int len = strlen(str);
    //扩容
		if (len+_size > _capacity) {
			reserve(len + _size);
		}
    //插入字符串
		strcpy(_ptr+_size,str);
	//更新_size
		_size += len;
	}

	//+= 字符 操作
	String& operator+=(const char& ch) {
		push_back(ch);
		return *this;
	}
	////+= 字符串
	String& operator+=(const char* str) {
		Append(str);
		return *this;
	}
	//+= String对象
	String& operator+=(const String& str) {
		Append(str._ptr);
		return *this;
	}

	////插入字符
	void insert(size_t pos, const char& ch) {
	//1.判定边界
		assert(pos <= _size);
	//2.检查容量
		if (_size == _capacity) {
			size_t newC = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newC);
		}
    //3.移动元素
		size_t end = _size;
		while (end>pos) {
			_ptr[end] = _ptr[end - 1];
			--end;
		}
    //4.在pos位置前插入字符
		_ptr[pos] = ch;
	//5.更新_size  之后再复制'\0'
		_ptr[++_size] = '\0';
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////插入字符串
	void insert(size_t pos, const char* str) {
	//1.不能越界
		assert(pos <= _size);
	//2.计算要插入元素的长度
		int len = strlen(str);
	//3.检查容量
		if (_size+len>_capacity) {
			reserve(_size + len);
		}
    //4.在pos位置前面插入字符串
		size_t end = _size + len;
		while (end> pos+len-1) {
			_ptr[end] = _ptr[end - len];
			--end;
		}
	//5.插入字符串
		memcpy(_ptr + pos, str, len*sizeof(char));
    //6.更新_size位置
		_size += len;
	}

	size_t size() {
		return _size;
	}
	//迭代器: 访问容器元素的一种机制 操作类似于指针  常用操作: 迭代器移动,迭代器解引用,迭代器判断
	//iterator 迭代器返回值为char* 
	typedef char* iterator;
	typedef const char* const_iterator;
	//begin: 第一个元素的位置
	iterator begin() {
		return _ptr;
	}
	//end(): 最后一个元素的下一个位置
	iterator end() {
		return _ptr + _size;
	}

	const_iterator begin() const{
		return _ptr;
	}
	const_iterator end() const{
		return _ptr + _size;
	}
	//operator[]
	char& operator[](size_t pos) {
		//判断是否越界
		assert(pos < _size);
		return _ptr[pos];
	}
	const char& operator[](size_t pos) const{
		//判断是否越界
		assert(pos < _size);
		return _ptr[pos];
	}
	//resize(n,ch)
	//1.n<=_size只需要修改_size
	//2._size<n<=_capacity() :辅助ch-->[_size,_capacity],修改_size
	//3._capacity<n 增容,赋值修改_size
	void resize(size_t sz,char ch='\0') {
		if (sz >_capacity){
			reserve(sz);
		}
		if ( _size<sz) {
			//赋值
			memset(_ptr + _size, ch, sz - _size);
		}
	
		_size = sz;
		
		_ptr[_size] = '\0';
	}
	//删除从pos位置开始,长度为len的字符串
	void erase(size_t pos,size_t len) {
		assert(pos<_size);
		if (pos+len >=_size) {
			_size = pos;
			_ptr[_size] = '\0';
		}
		else {
			size_t start = pos + len;
			while (start < _size) {

				_ptr[pos++] = _ptr[start];
				++start;
				/*_ptr[start - len] = _ptr[start];
				++start;*/

			}
			_size -= len;
			_ptr[_size] = '\0';
		}
	}
	//查找字符  
	size_t find(const char& ch, size_t pos = 0) {
		for (int i = pos; i < _size; i++) {
			if (_ptr[i] == ch)
				return i;
		}
		return npos;
	
	}

	//查找字符串 
	size_t find(const char* str, size_t pos = 0) {
		char* start = strstr(_ptr + pos,str);  //找到str在_ptr + pos
		if (start) {
			return start - _ptr;
		}

		return npos;
	}



	//析构
	~String() {
		if (_ptr) {
			delete[] _ptr;
			_ptr = nullptr;
			_size = 0;
			_capacity = 0;
		}
	}
private:
	char* _ptr;
	size_t _size;//有效元素的个数
	size_t _capacity;//容量大小
	static const size_t npos;//静态成员初始化在类外进行初始化
};
//类型 + 类名:: 变量
const size_t String::npos = -1;

void printstring( String& str) {
	for (int i = 0; i < str.size(); i++) {
		cout << str[i] << " ";
	}
	cout << endl;

}

//验证构造函数/拷贝构造/赋值运算符重载/析构函数
void test1() {
	String str1 = "123";
	String str2 = "abcde";
	String str3(str1);
	str2 = str1;
}

void test2() {
	String str = "abc";
	//////尾插字符
	//str.push_back('a');
	//str.push_back('b');
	//str.push_back('c');
	//str.push_back('d');
	//printstring(str);

	////+=字符
	////str += '9';
	//str.operator+=('9');
	////+= 字符串
	//str += "5678";
	//str.operator+=("5678");
	str.insert(0, "4");
	printstring(str);
	str.insert(3, "569");
	printstring(str);

	////迭代器遍历
	//String::iterator it = str.begin();
	//while (it != str.end()) {
	//	cout << *it << " ";
	//	it++;
	//}
	//cout << endl;

	////operator[]
	//for (int i = 0; i <str.size();i++) {
	//	cout << str[i] << " ";
	//}
	//cout << endl;
	////范围for遍历
	//for (auto& ch:str) {
	//	cout << ch << " ";
	//}
	//cout << endl;
}

////resize 
//void test3() {
//	String str;//""
//	printstring(str);
//	str.resize(3);//""--->"\0\0\0"
//	printstring(str);
//	str.resize(5, 'a');//"" ---> "\0\0\0aa"
//	printstring(str);
//
//	str.resize(4, 'b');
//	printstring(str);
//}


void test4() {
	String str = "123456";
	str.erase(5, 2);
	printstring(str);
}
int main () {
	  //test1();
	//test2();
	//test3();
	test4();
    system("color A");
    system ("pause");
    return 0;
}