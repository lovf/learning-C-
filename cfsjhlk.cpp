
//start :�ռ���׵�ַ,��һ��Ԫ�ص��׵�ַ
//finish :���һ��Ԫ�صĽ���λ��
//end_of_storage :�ռ�Ľ���λ��
#include <string>
#include <vector>
#include <iostream>
using namespace  std;
template<class T>

class Vector{
public:
	Vector()
		:_start(nullptr)
		, _finish(nullptr)
		, _eos(nullptr)
	{
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//��ЧԪ�ظ���
	size_t size() const {
		return _finish - _start;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//�ռ�������С
	size_t capacity() const {
		return _eos - _start;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//���ݵĽӿ�(�ص�)
	void reserve(size_t n) {
		size_t oldsize = size(); //��δ�޸�֮ǰ��size()�ȱ�������
		//��������
		if (n > capacity()) {
			//1.���ռ�
			T* tmp = new T[n];
			//2.����:�ڴ濽��,ǳ����
			//memcpy(tmp, _start, sizeof(T)*size());
			//2.���
			for (int i = 0; i < size(); i++) {
				tmp[i] = _start[i];
			}
			//3.�ͷ�ԭ�пռ�

			delete[] _start;
			//4.���¿ռ�ָ��,����
			_start = tmp;
			_finish = _start + oldsize; //�¿��ռ�֮����
			_eos = _start + n;
		}
	}
	//����: ���ڵ������:����T���͵ĸ�ֵ�����
	void pushBack(const T& val) {
		//�ռ�����:_eos == _finish(���һ��Ԫ�ص�λ�õ��ڿռ��λ��)
		//1.�������
		if (_eos == _finish) {
			size_t newC = capacity() == 0 ? 1 : 2 * capacity();
			reserve(newC);
		}
		//2.����
		*_finish = val;
		//3.����
		++_finish;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//operator[]:�ɶ���д(�ص�)
	T& operator[](size_t pos) {
		if (pos < size())
			return _start[pos];
	}
	//ֻ���ӿ�
	const T& operator[](size_t pos) const {
		if (pos < size())
			return _start[pos];
	}
	//������:
	typedef T* iterator;
	typedef const T* const_iterator;

	iterator begin() {
		//��һ��Ԫ��λ��
		return _start;
	}

	iterator end() {
		//���һ��Ԫ�ص���һ��λ��
		return _finish;
	}
	const_iterator begin() const {
		//��һ��Ԫ��λ��
		return _start;
	}

	const_iterator end() const {
		//���һ��Ԫ�ص���һ��λ��
		return _finish;
	}
	//valĬ��ֵ:��������:0ֵ,�Զ�������:�����޲ι���
	void resize(size_t n, const T& val = T()) {
		if (n > capacity()) { //����������Ҫ����
			reserve(n);
		}
		if (n > size()) { //����size��Ҫ���
			while (_finish != _start + n) {
				*_finish++ = val;

			}
		}
		//����size
		_finish = _start + n;
	}
	//����(�ص�)
	void insert(iterator pos, const T& val) {
		if (pos >= _start && pos <= _finish) { //��֤��һ����ЧԪ�ص�λ��
			//�������
			if (_finish == _eos) {
				//���ݻᵼ�µ�����ʧЧ,�������������,���µ�����
				//����ԭʼλ��
				int len = pos - _start;  //���ݵ�ƫ����
				size_t newC = capacity() == 0 ? 1 : 2 * capacity();
				reserve(newC);
				//���µ�����
				pos = _start + len;//�����ڴ�ʱpos��λ���Ѿ������˸ı�
			}
			//�ƶ�Ԫ��
			iterator end = _finish;
			while (end > pos) {
				*end = *(end - 1);
				--end;
			}
			//����Ԫ��
			*pos = val;
			//����
			++_finish;
		}
	}

	//���ص�����:ִ�е�ǰ��ɾ��Ԫ�ص���һ��Ԫ�ص�λ��
	iterator erase(iterator pos) {
		if (pos >= _start && pos < _finish) {
			//�ƶ�Ԫ��(��ǰ����ƶ�)
			iterator begin = pos;
			while (begin != _finish) {
				*(begin - 1) = *begin;//  *begin=*(begin + 1); �������һ��Ԫ��ʱ�����Խ����Ϊ
				++begin;
			}
			//����size
			--_finish;
		}
		return pos; //����ʲô����ʲô
	}
private:
	T* _start; //�ռ���׵�ַ,��һ��Ԫ�ص��׵�ַ
	T* _finish;//���һ��Ԫ�صĽ���λ��
	T* _eos;//end_of_storage �ռ�Ľ���λ��

};
template<class T>

void PrintVec(const Vector<T>& v1) {
	cout << "operator[]" << endl;
	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << " ";
		//д����
		//v1[i] = "a";
	}
	cout << endl;


	cout << "��Χfor" << endl;
	for (const T& str : v1) {
		cout << str << " ";

	}
	cout << endl;
}

void test1() {
	Vector<int> v1;
	Vector<char> v2;
	Vector<string> v3;

	size_t size = v1.size();
	size = v2.size();
	size = v3.size();

	size_t capacity = v1.capacity();
	capacity = v2.capacity();
	capacity = v3.capacity();

}

void test2() {

	Vector<int> v1;
	v1.pushBack(1);
	size_t size = v1.size();
	size_t cap = v1.capacity();

	v1.pushBack(1);
	size = v1.size();
	cap = v1.capacity();

	v1.pushBack(2);
	size = v1.size();
	cap = v1.capacity();

	v1.pushBack(3);
	size = v1.size();
	cap = v1.capacity();

	v1.pushBack(4);
	size = v1.size();
	cap = v1.capacity();

}
void test3() {
	Vector<string> v1;
	v1.pushBack("1");
	v1.pushBack("2");
	v1.pushBack("3");
	v1.pushBack("4");

}
void test4() {

	Vector<string> v1;
	v1.pushBack("1");
	v1.pushBack("2");
	v1.pushBack("3");

	PrintVec(v1);
	//������
	Vector<string>::iterator it = v1.begin();
	cout << "iterator" << endl;
	while (it != v1.end()) {
		cout << *it << " ";
		it++;
	}
	cout << endl;

}

void test5() {

	Vector<int> v1;
	Vector<char> v2;
	Vector<string> v3;

	v1.resize(5);
	v2.resize(5);
	v3.resize(5);

}

void test6() {
	Vector<int> v1;

	v1.insert(v1.end(), 1);
	v1.insert(v1.end(), 2);
	v1.insert(v1.end(), 3);
	v1.insert(v1.end(), 4);
	v1.insert(v1.end(), 5);
	v1.insert(v1.end(), 6);
	v1.insert(v1.end(), 7);
	v1.insert(v1.end(), 8);
	PrintVec(v1);
}

void test7() {
	Vector<int> v1;

	v1.insert(v1.end(), 1);
	v1.insert(v1.end(), 2);
	v1.insert(v1.end(), 3);
	v1.insert(v1.end(), 4);
	v1.insert(v1.end(), 5);
	v1.insert(v1.end(), 6);
	v1.insert(v1.end(), 7);
	v1.insert(v1.end(), 8);
	PrintVec(v1);

	v1.erase(v1.begin());
	PrintVec(v1);
	v1.erase(v1.begin());
	PrintVec(v1);
	v1.erase(v1.begin());
	PrintVec(v1);
	v1.erase(v1.begin());
	PrintVec(v1);
	v1.erase(v1.begin());
	PrintVec(v1);
	v1.erase(v1.begin());
	PrintVec(v1);

	v1.erase(v1.end() - 1);//��ɾ��end-1���������
	PrintVec(v1);
}

void test8() {

	Vector<int> v1;

	v1.insert(v1.end(), 1);
	v1.insert(v1.end(), 2);
	v1.insert(v1.end(), 3);
	v1.insert(v1.end(), 4);
	v1.insert(v1.end(), 5);
	v1.insert(v1.end(), 6);
	v1.insert(v1.end(), 7);
	PrintVec(v1);

	Vector<int>::iterator it = v1.begin();
	while (it != v1.end()) {
		if (*it % 2 == 1)
			v1.erase(it);
		else
			++it;
	}
	PrintVec(v1);
}
int main() {

	//test1();
	//test2();
	//test3();
	//test4();
	//test6();
	//test5();
	//test7();
	test8();
	system("color A");
	system("pause");
	return 0;
}


//1.��ǳ����: reserve
//2.������ʧЧ:insert,erase
//3.resize:Ĭ��ֵ:����: 0 �Զ���: Ĭ�Ϲ���
//4.������:T*
//begin: start
//end:finish