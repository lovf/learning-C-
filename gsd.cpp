#include <string>
#include <iostream>
using namespace std;


template <class T>
class Vector {

public:
	Vector()
	: _start(nullptr)
	, _finish(nullptr)
	, _eos(nullptr)//end_of_ storage

	{}

	size_t size() const {
		return _finish - _start;
	}
	size_t capacity() const {
		return _eos - _start;
	}
	//���β��Ĳ���***********************************************************************
	void pushBack(const T& val) { //���ʹ������,��ֹ��ֵ����
	//1.�������
	//��_finsh == _eos ʱ ,��ʱ�ռ�����
		if (_finish == _eos) {
			size_t newC = capacity() == 0 ? 1 : 2 * capacity();
			reserve(newC);
		}
	//2.���� :��� : ����T���͵ĸ�ֵ�����
		*_finish = val;
	//3.����size
		++_finish;
	}
	void reserve(size_t n) {
		if (n > capacity()) {
			size_t oldsize = size();//����Ҫ��֮ǰ�� size() ��¼����һ��,������Ҫ�ͷ�_start,����size()�ᷢ���ı�
			//1.���ռ�
			T* temp = new T[n];
			//2.ǳ����: �ڴ濽�� ǳ����  
			//memcpy(temp, _start, sizeof(T)*size());
			//2.���(�ַ����ͽ��еĿ���)2.���: ����T���͵ĸ�ֵ�����,������
			for (int i = 0; i < size();++i) {
				temp[i] = _start[i];
			}
			//3.�ͷ�ԭ�еĿռ�
			delete[] _start;
			//4.���¿ռ�ָ��,����
			_start = temp;
			_finish = _start + oldsize;
			_eos = _start + n;
		}
	}
	//operator []: ���� �ɶ���д����
	T& operator[](size_t pos) {
		if (pos<size()) {
			return _start[pos];
		}
	}
	//********************************************************************************************************
	//ֻ���Ľӿ�
	const T& operator[](size_t pos) const {
		if (pos < size()) {
			return _start[pos];
		}
	}
	//**********************************************************************************************

	////������
	////�ɶ���д
	typedef T* iterator;
	//ֻ��
	typedef const T* const_iterator;

	iterator begin() {
		//��һ��Ԫ�ص�λ��
		return _start;
	}

	iterator end() {
		//���һ��Ԫ�ص���һ��λ�ã� Ҳ�������һ��Ԫ�صĽ���λ��
		return _finish;
	}

	const_iterator begin() const {
		return _start;
	}

	const_iterator end() const {
		return _finish;
	}
	//val Ĭ��ֵ:��������: 0ֵ,�Զ�������:�����޲ι���
	void resize(size_t n,const T& val=T()) {
		if (n > capacity())
			reserve(n);
		if (n>size) {
			*_finish++ = val;
		} else {
		  //����size
			*_finish = _start + n;
		}
	}

	
                                            
private:
	T* _start;
	T* _finish;
	T* _eos;
};
//
template <class T>
void printVector(const Vector<T>& v) {
	cout << "operator[]:  " << endl;
	for (int i = 0; i < v.size();i++) {
		cout << v[i] << " ";
		//����const�ӿ�,ֻ��
		//v[i] = "a";
	}
	cout << endl;
	//*****************************************
	cout << "������: " << endl;
	Vector<T>::const_iterator it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
	//��Χfor
	cout << "��Χfor :" << endl;
	for (const T& str : v) {
		cout << str << " ";

	}
	cout << endl;
	
}

//void test1() {
//
//	Vector<int> v1;
//	Vector<char> v2;
//	Vector<string> v3;
//
//	size_t size = v1.size();
//	cout << size << endl; 
//	size = v2.size();
//	cout << size << endl;
//	size = v3.size();
//	cout << size << endl;
//
//	size_t cap = v1.capacity();
//	cout << cap << endl;
//     cap = v2.capacity();
//	 cout << cap << endl;
//	 cap = v3.capacity();
//	 cout << cap << endl;
//}

//����int������˵��������ǳ����������,����Դ��ʱ��Ŵ�����ǳ����������.
//void test2() {
//
//	Vector<int>v1;
//	v1.pushBack(1);
//	v1.pushBack(2);
//	v1.pushBack(3);
//	v1.pushBack(4);
//	v1.pushBack(5);
//	size_t size = v1.size();
//	size_t cap = v1.capacity();
//	cout << size << endl;
//	cout << cap << endl;
//}

//void test3() {
//	Vector<string>v1;
//	v1.pushBack("1");
//	v1.pushBack("2");
//	v1.pushBack("3");//�ڲ��������Ԫ�ص�ʱ����ִ���.
//	v1.pushBack("4");
//	size_t size = v1.size();
//	size_t cap = v1.capacity();
//	cout << size << endl;
//	cout << cap << endl;	
//
//}

void test4() {
	Vector<string>v1;
	v1.pushBack("1");
	v1.pushBack("2");
	v1.pushBack("3");//�ڲ��������Ԫ�ص�ʱ����ִ���.
	v1.pushBack("4");
	for (int i = 0; i < v1.size();i++) {
		cout << v1[i] << " ";
		//cout << v1.operator[](i) << " ";
		//�޸Ĳ���:
		v1[i] = "a";
	}
	cout << endl;
	for (int i = 0; i < v1.size(); i++) {
		cout << v1.operator[](i) << " ";
		}
	cout << endl;
	//������
	cout << "������: " << endl;
	Vector<string>::iterator it = v1.begin();
	while (it != v1.end()) {
		cout << *it << " ";
		*it = "b";
		++it;
	}
	cout << endl;
	for (int i = 0; i < v1.size(); i++) {
		cout << v1.operator[](i) << " ";
	}
	cout << endl;
	cout << "��Χfor :" << endl;
	for (string& str : v1) {
		cout << str << " ";
		str = "c";
	}
	cout << endl;
  printVector(v1);

}
int main() {
	/*test1();
	test2();*/
	//test3();
	test4();
	system("pause");
	return 0;
}


















