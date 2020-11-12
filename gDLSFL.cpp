////vectorģ��ʵ�֣�
////1.8���������ӿ�
////���õĵ�����operayor[]���б��� 
#include<vector>
#include <assert.h>
#include <iostream>
using namespace std;


template <class T>

class Vector{

public:
	//sizeof(Vector()) :ռ12���ֽ�
	Vector()
		:_start(nullptr)
		, _finish(nullptr)
		, _endofStorage(nullptr)
	{}
	size_t size() const{
		return _finish - _start;
	}
	size_t capacity() const{
	
		return _endofStorage - _start;
	}
	//β������Ԫ�أ�
	void push_back(const T& val) {

		////1.�������
		//if(_finish == _endofStorage){
		//	size_t newC = _start == nullptr ? 1 : 2 * capacity();
		//	reserve(newC);
		//}
		////2.β������Ԫ��
		//*_finish = val;
		////����size()
		//++_finish;
		insert(end(),val);
	}

	void pop_back() {
		erase(end()-1); //end()ָ�����һ��Ԫ�ص���һλ
	}

	void swap(vector<int>& v) {
		swap(_start, v._start);
		swap(_finish, v._finish);
		swap(_endofStorage, v._endofStorage);
	}


	void reserve(size_t n) {
	//ֻ��������
		if (n > capacity()) {
			size_t sz = size(); //֮ǰ��size�ȱ�������
			//���ռ�
			T* tmp = new T[n];
			//���ݿ���
			//memcpy(tmp, _start, size()*sizeof(T); //memcpy����ǳ����,Ҫ������ʵ�ֿ�������������
			//����	1	error C1075 : ������ Բ���š�(��(λ�ڡ�e:\c++ �ڶ���ѧϰ\11��11����������\11��11����������\gdlsfl.cpp(48)��)ƥ��֮ǰ�����ļ�����	
			//e : \c++ �ڶ���ѧϰ\11��11����������\11��11����������\gdlsfl.cpp	188	1	11��11����������

			//����� ��ÿһ��Ԫ�ؽ��в��Ͽ�����ȥ
			for (int i = 0; i < size(); i++) {
				tmp[i] = _start[i];
			}
			//�ͷ�ԭ�пռ� 
			delete[] _start;
			//
			_start = tmp;
			_finish = _start + sz;
			_endofStorage = _start + n; //����
		}
	}
	//////////////////////////////////////////////////////////////////////////
	//operator[]������
	T& operator[](size_t pos ) {
		assert(pos < size());
		return _start[pos];
	}
	const T& operator[] (size_t pos) const{
		//assert(pos < size());
		return _start[pos];
	}

	//��������
	typedef T* iterator;
	typedef const T* const_iterator;
	iterator begin() {
		//��һ��Ԫ�ص�λ��
		return _start;
	}
	iterator end() {
		//���һ��Ԫ�ص���һ��λ��
		return _finish;
	}
   //const�������ӿ�
	const_iterator begin() const{
		return _start;
	}
	const_iterator end() const{
		return _finish;
	}
	//�޸���ЧԪ�صĸ���
	void resize(size_t n,const T& val=T()) {
		//1.�޸�Ԫ�صĸ���С��Ԫ�صĸ���
		if (n<size()) {
			reserve(n);
		}
		//2.�޸�Ԫ�صĸ�������Ԫ�صĸ���
		if (n>size()) {
			//��_finish֮���λ�ÿ�ʼ�����ж�
			while (_start + n >= _finish) {
				*_finish++ = val;
			}
		}
		//����size
		_finish = _start + n;
	}
	//��posλ�õ�ǰ�����Ԫ��
	void insert(iterator pos, const T& val) {
		//1.�ж���Ч����λ��
		assert(pos >= begin() && pos <= end());  

		//if (pos >= _start && pos<= _finish) {
		//
		//}

		//2.�������
		if (_endofStorage == _finish) {
			int len = pos - _start; //���δ����֮ǰpos��λ����
			//3.���ݴ���
			size_t newC = capacity() == 0 ? 1 : 2 * capacity();
			reserve(newC);
			//���±���posλ�ã������ݵ�ʱ��ᵼ��posλ�÷����ı�
			pos = len + _start; //Ѱ������֮��Ԫ�ص�λ�ã�����û�����±궨��posλ���޷��ҵ�
		}
		//3.�ҵ�posǰ���λ��
		iterator end = _finish;
		while (end > pos) { //pos��Ҫ���±궨��������µ�����ʧЧ
			*end = *(end - 1);
			--end;
		}
		//4.����Ԫ��
		*pos = val;
		//5.���¡�finish
		++_finish;
	}

	//
	iterator erase(iterator pos) {
		//1.�ж���Ч����λ��
		assert(pos >= begin() && pos < end());
		//2.���δӺ���ǰ�ƶ�
		iterator begin = pos+1;
		while (begin != _finish) {
			*(begin - 1) = *begin;
			++begin;
		}
		--_finish;
		return pos;
	}


private:
	T* _start; //��Ԫ�ص�ַ��ָ��
	T* _finish; //���һ��Ԫ�صĽ���λ��
	T* _endofStorage;// �ռ��������˽���λ��

};

template<class T>

void PrintVec(const Vector<T> v) {

	//Vector<int>::iterator it = v.begin();
	//while (it != v.end()) {
	//	cout << *it << " ";
	//	it++;
	//}
	//cout << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;

}
void test1() {
	Vector<int> v;
	//v.push_back(1);
	//v.push_back(2);
	//v.push_back(3);
	//v.push_back(4);
	//v.push_back(5);
	//PrintVec(v);

	//////v.resize(3, 'a');
	//////PrintVec(v);

	//////v.resize(6,9);
	//////PrintVec(v);
	////v.insert(v.end(), 0);
	////PrintVec(v);//123450

	////v.erase(v.begin()+4);
	////PrintVec(v);
}

void test2() {

	Vector<int> v1;
	v1.insert(v1.end(), 2);
	v1.insert(v1.end(), 3);
	v1.insert(v1.end(), 4);
	v1.insert(v1.end(), 5);
	v1.insert(v1.end(), 6);
	v1.insert(v1.end(), 7);
	PrintVec(v1);

	v1.erase(v1.begin() + 2);
	PrintVec(v1);

	v1.erase(v1.end()-1); //
	PrintVec(v1);
}
void test3() {

	Vector<int> v1;

	v1.insert(v1.end(), 1);
	v1.insert(v1.end(), 2);
	v1.insert(v1.end(), 3);
	v1.insert(v1.end(), 4);
	v1.insert(v1.end(), 5);
	v1.insert(v1.end(), 6);
	v1.insert(v1.end(), 7);
	PrintVec(v1);

	v1.pop_back();
	PrintVec(v1);
	v1.pop_back();
	PrintVec(v1);
	v1.pop_back();
	PrintVec(v1);

	v1.pop_back();
	PrintVec(v1);


	//vector������ʧЧ���⣺
	//1.��������Ҫ���þ������㷨�����ĵײ����ݽṹ,��ײ����һ��ָ��,���߶�ָ������˷�װ,vector����ԭ��ָ̬��T*,ʵ�ʾ��ǵ������ײ��Ӧ
	//��ָ��ָ��Ŀռ䱻������,��ʹ��һ���Ѿ����ͷŵĿռ�,��ɵĺ�����ǵ��³������.
	//2.��Щ������ܵ��µ������ײ�ʧЧ:
	//1>����ײ�ռ�λ�øı�,����resize,reserve,insert,assign,push_back.
	//2>ָ��λ��ɾ������-->erase eraseɾ��posλ��Ԫ��֮��,posλ��Ԫ�ػ���ǰ�����ƶ�,���Ǽ���posλ��ǡ�þ���end��λ��,��endλ����û��Ԫ�ص�
	//��ô�ͻᵼ�µ�����ʧЧ.
	//���������ʧЧ�ķ���:��ʹ��ǰ�Ե������������¸��Ƽ���
	//Vector<int>::iterator it = v1.begin();
	//while (it != v1.end()) {
	//	if (*it % 2 == 0)
	//		v1.erase(it); //ɾ���ᵼ�µ�����ʧЧ������İ취�������µ�����
	//	else
	//		++it; //���¸��µ�����
	//}
	//PrintVec(v1);

}
void test4() {

	Vector<int> v1;
	Vector<int> v2;
	v1.insert(v1.end(), 1);
	v1.insert(v1.end(), 2);
	v1.insert(v1.end(), 3);
	PrintVec(v1);

	v2.insert(v2.end(), 4);
	v2.insert(v2.end(), 5);
	v2.insert(v2.end(), 6);
	PrintVec(v2);

	/*cout << "����֮��" << endl;
	v1.swap(v2);

	PrintVec(v1);
	PrintVec(v2);*/
}
int main() {

	//test1();
	//test2();
	//test3();
	test4();
	system("color A");
	system("pause");
	return 0;
}
