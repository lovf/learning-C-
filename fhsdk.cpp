
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////���: ��Ա+��Դ
//string��ʵ��:������˳���ʵ��
#define  _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
using namespace  std;

class String {
	
public: 


	//������:һ�ַ�������Ԫ�صĻ���,���ַ�װ������,����Ҫ��ע������ʵ��ϸ��,�Ϳ���ֱ�ӷ���(�ɶ���д)Ԫ��
	//ʹ�÷�ʽ������ָ��
	//1.������--->��ȡָ��λ�õ�����
	//2.λ���ƶ�--->ָ������λ��
	//String ������: ͨ��char*��ʵ��
	//1.�ɶ���д������:char*
	//2.ֻ��������:const char*
	//3.begin:�ַ����׵�ַ--->_str
	//4.end:���һ���ַ�����һ��λ��--->_str+_size
	//��Χfor:ͨ��������ʵ��
	//1.������ִ�в���ʱ,�ѷ�Χforת���ɵ������ı�����ʽ
	//2.�������������,���Ҫ����д����,����������ҪΪ��������

	typedef char* iterator; //�ɶ���д
	typedef const char* const_iterator; //��д
	//���ִ�пɶ���д�Ĳ�����ִ��
	iterator begin() {
		//��һ��Ԫ�ص�λ��
		return _str;
	}

	iterator end() {
		//���һ��Ԫ�ص���һ��λ��
		return _str + _size;
	}
	//���ִ�пɶ��Ĳ�����ִ��,����һ��Ҫ���ֿ�
	const_iterator begin() const {
		//��һ��Ԫ�ص�λ��
		return _str;
	}
	const_iterator end()  const{
		//���һ��Ԫ�ص���һ��λ��
		return _str + _size;
	}

	



	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//1.���캯��
	//�޲ι���: �����޲ξ͵��øú���
	String()
		: _str(new char[16]) //��16���ռ�
		, _size(0)
		, _capacity(0)
	
	{
		_str[_size] = '\0';
		_capacity = 15;
	}

	//�вι���: �����в����ͽ��е���  �в�ʱһ������ֱ�ӽ���ַ���п�����ȥ
	String(const char* str) //��ʾ���ַ�����Ϊ�������г�ʼ��
	/*	:_str(str) ���ֱ���������и�ֵ֮����ô,�п��ܲ��ᱻ�ͷŵ�,��Ϊ����λ�ڴ����,��delete�ͷŶ��ϵĿռ�
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
	//2.��������
	////�������캯�� ��ͳд�� Ҫ���пռ�Ŀ���
	//String(const String& str)  
	//	:_str(new char[str._capacity+1])
	//	,_size(str._size)
	//	, _capacity(str._capacity)
	//
	//{
	//	//���: ��Դ����  ��Ա+��Դ
	//	strcpy(_str, str._str);
	//	cout << "String(const String& str) " << endl;
	//}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//���������ִ�д�� ��ɿ������첢����һ�����
	//���ÿ��ռ�,���ִ���ĸ���

	//��������:�ִ�д��
	//1.���ù��캯��
	//2.ͨ�����캯�����ռ�,��������,���ͨ����Ա����Դ�Ľ���,��ɿ���������߼�
	String(const String& str )
		//Ҫ����ʼ���б� ,���벻��tmp������֮��Ҫ������������
		:_str(nullptr)  
		, _size(0)
		, _capacity(0)
	
	{
		//����һ����ʱ����,���ÿ�������
		String tmp(str._str);  //�������������֮��Ҫ������
		Swap(tmp);
	}
	void Swap(String& str) {
		//����������Ա������ֵ����
		swap(_str, str._str);
		swap(_size, str._size);
		swap(_capacity, str._capacity);
	}
	//����Ľ���: Ч�ʺܵ�
	//void Swap(String& str) {
	//	//1.��������
	//	String tmp=str;
	//	//2.��ֵ�����
	//	str = *this;
	//	//3.��ֵ�����
	//	*this = str;
	//}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//3.��ֵ�����
	//// ��ֵ�����
	//String& operator=(const String& str) {

	//	if (this != &str) {
	//		//���µĿռ�
	//		char* tmp = new char[str._capacity + 1];

	//		//�����ݷŵ��µĿռ��������ݿ���
	//		strcpy(tmp, str._str);
	//		//�ͷ�ԭ�пռ� 
	//		delete[] _str;

	//		//�ٰ��µĿռ������
	//		_str = tmp;
	//		_size = str._size;
	//		_capacity = str._capacity;

	//	}
	//	return *this;
	//}
	//���   ��ֵ��������ִ�д��
	//��������:�ִ�д��
	//1.���ù��캯��
	//2.ͨ�����캯�����ռ�,��������,���ͨ����Ա����Դ�Ľ���,��ɿ���������߼�

	//��ֵ�����:�ִ�д��
	//1.���ÿ������캯��
	//2.����ʱ,ͨ��ֵ����,���ÿ������칹�촴���ֲ�����,��ɿ��ռ�+���ݿ���,���ͨ����Ա����Դ�Ľ���,�����µ���Դ������,
	//���յ��þֲ��������������,�ͷ�ԭ�пռ�,��ɸ�ֵ���߼�

	String& operator=(String str) {  //��������: (���ν��п�������)

		Swap(str);//��������ĸ���
		return *this;
	}
	//string��ļ�д��: ���캯�� ��������(�ִ�д��)  ��ֵ�����(�ִ�д��)    �������� ���ĸ��Ϳ������һ���򵥵�string���ʵ��
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	const char* c_str() const {
		return _str;
	}
	//4.��������
	~String() {
		if (_str) {
			delete[] _str; //delete�������ͷŶ��ϵĿռ�
			_size = _capacity = 0;
			_str = nullptr;
		}
		cout << "~String()" << endl;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//β�����
	void pushBack(const char& ch) {
	////1.�������
	//	if (_size == _capacity) {
	//		size_t newC = _capacity == 0 ? 15 : 2 * _capacity;
	//		reserve(newC);
	//	}
	////2.β�����
	//	_str[_size] = ch;
	////3.����size
	//	++_size;
	//	_str[_size] = '\0';
		insert(_size, ch);
	}
	void reserve(size_t n) {
		if (n > _capacity) {
		//1.���ռ�+1//���\0
			char* tmp = new char[n + 1];

		//2.����
			strcpy(tmp, _str);
		//3.�ͷ�ԭ�пռ�
			delete[] _str;
			_str = tmp;
			//��������
			_capacity = n;
		}
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//�����ֱ�����ʽ:operator[]
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
	//β����һ���ַ���
	void Append(const char* str) {
	//	int len = strlen(str);
	////�������
	//	if (_size+len > _capacity) {
	//		reserve(_size + len);
	//	}
	////β��
	//	strcpy(_str + _size, str);
	////�޸�size
	//	_size += len;
		insert(_size, str);
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//+=����� (Ӧ�ø��ʺܸ�)
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
	//�������
		if (_size == _capacity) {
			size_t newC = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newC);
		}
		//�ƶ�Ԫ��[pos._size]:�Ӻ���ǰ�ƶ�,���ƶ����Ҷ�,��ֹ����
		size_t end = _size+1;
		while (end > pos) {
			//end >= pos  :��pos=0��ѭ��,Խ��
			_str[end] = _str[end-1]; //���ƶ�����'\0'
			--end;
		}
	//����
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
		//�ƶ�Ԫ��[pos,_size]  //�ƶ��ĳ������ַ����ĳ���
		size_t end = _size + len;
		while (end>pos+len-1) {
		//��һ��: size--->size+len ���һ��: pos--->pos+len
			_str[end] = _str[end - len];
			--end;
		}
		//����: //ÿһ��Ԫ�ض�Ҫ����
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
	cout << s.c_str() <<"����"<<endl;

	String Str;
	const char* ptr2 = Str.c_str();
	cout << Str.c_str() << "����" << endl; //�ַ�����ӡ �����Ǵ�ӡ����ָ��,���Ǵ�ӡ�ַ����� /Str.c_str() ָ��Ϊ��


	String str2("123");//����λ�ڴ����   λ�ڳ������Ĳ���ֱ��ʹ��delete�����ͷ�,����Ҫ������п���Ȼ�����ͷ�
	ptr2 = str2.c_str();
	cout << ptr2 << endl;


}
void  test2() {
	//��������Ҫ��������д,��������
	String s("123");
	//���ÿ�������
	String copy = s; //�ֽ��򿽱�:ֻ������Ա����,��������Դ
	String copy2(s);  //�ֽ��򿽱�   ������s������ͷŵ�����,

	//��ֵ�����  Ҫ����������д,���粻����д��ô�ͷŻᱻ�ͷ�����
	String s2("456");
	copy = s2;

}

//�ֽ��򿽱�:ֻ������Ա����,��������Դ
//����: ��Դ�ᱻ����ͷ�,�������
//����Ҫ��������Ĺ���


void PrintString(const String& str) {
	//����������
	String::const_iterator it = str.begin();
	while (it != str.end()) {
		cout << *it << " ";
		//д����
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
	//����������
	String::iterator it = s.begin();
	while (it != s.end()) {
		cout << *it << " ";
		//д����
		*it = '0';
		++it;
	}
	cout << endl;

	PrintString(s);
	cout << "��Χfor" << endl;
	//��Χfor:�����ý��տ��Խ����޸�
	for  (char& ch : s) {
		cout << ch <<" ";
		ch = '1';
	}
	cout << endl;

	for (char& ch : s) {  //���ʹ�����ÿ��Խ��ж�д����
		cout << ch << " ";
		ch = '2';
	}
	cout << endl;

	for (char& ch : s) {
		cout << ch << " ";
	}
	cout << endl;

	cout << "��Χforû�н���ʹ��Ӧ��"<<endl;

	for (char ch : s) { //û��ʹ����������
		cout << ch << " ";
		ch = '3';
	}
	cout << endl;

	for (char ch : s) { //û��ʹ����������
		cout << ch << " ";
		ch = '4';
	}
	cout << endl;

	//operator[]
	cout << "operator[]" << endl;
	for (int i = 0; i < s.size();i++) {
		cout << s[i] << " ";
		//д����
		s[i] = '7';
	}
	cout << endl;

	cout << "operator[]�޸�֮��" << endl;
	for (int i = 0; i < s.size(); i++) {
		cout << s[i] << " ";
	}
	cout << endl;

}
void test4() {
	String s;
	//s.Append("12345");
	s += "12345";
	PrintString(s); //���յ������ķ�ʽ����ӡ

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
// insert ���� �����ַ�/�ַ���
//��Ҫ���˵�����/��ǳ����/����

