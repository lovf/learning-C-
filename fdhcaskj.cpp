#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <assert.h>
#include <iostream>
using namespace  std;

class String{
public:
	//�޲ι���
	String(char* str = " ")	
	{
		_size = strlen(str);
		_capacity = _size;
		_ptr = new char[_size + 1];
		strcpy(_ptr, str);
	}

	//��������  ��ͳд��
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
	//�������� �ִ�д��
	String(String& str) 
		:_ptr(nullptr)
		, _size(0)
		, _capacity(0)
	{
		String tmp(str._ptr);
		Swap(tmp);
	}
	////��ֵ���������  ��ͳ
	String& operator=(String& str) {
		if (this != &str) {
		//���ռ�
			char* tmp = new char[strlen(str._ptr) + 1];
		//��ֵ����
			strcpy(tmp, str._ptr);
		//�ͷ�
			delete[] _ptr;
			_ptr = tmp;
			_size = str._size;
			_capacity = str._capacity;
		}
		return *this;
	}
	////��ֵ��������� �ִ�
	/*String& operator=(String str){
		Swap(str);
		return *this;
		}*/
	//β��
	void push_back(const char& ch) {
	//�ж�����
		if (_size == _capacity) {
		//����
			size_t newC = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newC);
		}
		//�����ַ�
		_ptr[_size++] = ch;
	  //β�����'\0'
		_ptr[_size] = '\0';
	}

	void reserve(size_t n) {
		if (n >_capacity) {
		//���µĿռ�
			char* tmp = new char[n + 1];
		//����
			//strcpy(tmp, _ptr);
			for (int i = 0; i <= _size;++i) {
				tmp[i] = _ptr[i];
			}
		//�ͷ�ԭ�еĿռ�
			delete[] _ptr;
			_ptr = tmp;
			//��������
			_capacity = n;
		}
	}
	//�����ַ���
	void Append(const char* str) {
	//��ȡ�����ַ����ĳ���
		int len = strlen(str);
    //����
		if (len+_size > _capacity) {
			reserve(len + _size);
		}
    //�����ַ���
		strcpy(_ptr+_size,str);
	//����_size
		_size += len;
	}

	//+= �ַ� ����
	String& operator+=(const char& ch) {
		push_back(ch);
		return *this;
	}
	////+= �ַ���
	String& operator+=(const char* str) {
		Append(str);
		return *this;
	}
	//+= String����
	String& operator+=(const String& str) {
		Append(str._ptr);
		return *this;
	}

	////�����ַ�
	void insert(size_t pos, const char& ch) {
	//1.�ж��߽�
		assert(pos <= _size);
	//2.�������
		if (_size == _capacity) {
			size_t newC = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newC);
		}
    //3.�ƶ�Ԫ��
		size_t end = _size;
		while (end>pos) {
			_ptr[end] = _ptr[end - 1];
			--end;
		}
    //4.��posλ��ǰ�����ַ�
		_ptr[pos] = ch;
	//5.����_size  ֮���ٸ���'\0'
		_ptr[++_size] = '\0';
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////�����ַ���
	void insert(size_t pos, const char* str) {
	//1.����Խ��
		assert(pos <= _size);
	//2.����Ҫ����Ԫ�صĳ���
		int len = strlen(str);
	//3.�������
		if (_size+len>_capacity) {
			reserve(_size + len);
		}
    //4.��posλ��ǰ������ַ���
		size_t end = _size + len;
		while (end> pos+len-1) {
			_ptr[end] = _ptr[end - len];
			--end;
		}
	//5.�����ַ���
		memcpy(_ptr + pos, str, len*sizeof(char));
    //6.����_sizeλ��
		_size += len;
	}

	size_t size() {
		return _size;
	}
	//������: ��������Ԫ�ص�һ�ֻ��� ����������ָ��  ���ò���: �������ƶ�,������������,�������ж�
	//iterator ����������ֵΪchar* 
	typedef char* iterator;
	typedef const char* const_iterator;
	//begin: ��һ��Ԫ�ص�λ��
	iterator begin() {
		return _ptr;
	}
	//end(): ���һ��Ԫ�ص���һ��λ��
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
		//�ж��Ƿ�Խ��
		assert(pos < _size);
		return _ptr[pos];
	}
	const char& operator[](size_t pos) const{
		//�ж��Ƿ�Խ��
		assert(pos < _size);
		return _ptr[pos];
	}
	//resize(n,ch)
	//1.n<=_sizeֻ��Ҫ�޸�_size
	//2._size<n<=_capacity() :����ch-->[_size,_capacity],�޸�_size
	//3._capacity<n ����,��ֵ�޸�_size
	void resize(size_t sz,char ch='\0') {
		if (sz >_capacity){
			reserve(sz);
		}
		if ( _size<sz) {
			//��ֵ
			memset(_ptr + _size, ch, sz - _size);
		}
	
		_size = sz;
		
		_ptr[_size] = '\0';
	}
	//ɾ����posλ�ÿ�ʼ,����Ϊlen���ַ���
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
	//�����ַ�  
	size_t find(const char& ch, size_t pos = 0) {
		for (int i = pos; i < _size; i++) {
			if (_ptr[i] == ch)
				return i;
		}
		return npos;
	
	}

	//�����ַ��� 
	size_t find(const char* str, size_t pos = 0) {
		char* start = strstr(_ptr + pos,str);  //�ҵ�str��_ptr + pos
		if (start) {
			return start - _ptr;
		}

		return npos;
	}



	//����
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
	size_t _size;//��ЧԪ�صĸ���
	size_t _capacity;//������С
	static const size_t npos;//��̬��Ա��ʼ����������г�ʼ��
};
//���� + ����:: ����
const size_t String::npos = -1;

void printstring( String& str) {
	for (int i = 0; i < str.size(); i++) {
		cout << str[i] << " ";
	}
	cout << endl;

}

//��֤���캯��/��������/��ֵ���������/��������
void test1() {
	String str1 = "123";
	String str2 = "abcde";
	String str3(str1);
	str2 = str1;
}

void test2() {
	String str = "abc";
	//////β���ַ�
	//str.push_back('a');
	//str.push_back('b');
	//str.push_back('c');
	//str.push_back('d');
	//printstring(str);

	////+=�ַ�
	////str += '9';
	//str.operator+=('9');
	////+= �ַ���
	//str += "5678";
	//str.operator+=("5678");
	str.insert(0, "4");
	printstring(str);
	str.insert(3, "569");
	printstring(str);

	////����������
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
	////��Χfor����
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