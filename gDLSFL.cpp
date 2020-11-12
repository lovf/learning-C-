////vector模拟实现：
////1.8个迭代器接口
////常用的迭代器operayor[]进行遍历 
#include<vector>
#include <assert.h>
#include <iostream>
using namespace std;


template <class T>

class Vector{

public:
	//sizeof(Vector()) :占12个字节
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
	//尾部插入元素：
	void push_back(const T& val) {

		////1.检查容量
		//if(_finish == _endofStorage){
		//	size_t newC = _start == nullptr ? 1 : 2 * capacity();
		//	reserve(newC);
		//}
		////2.尾部插入元素
		//*_finish = val;
		////更新size()
		//++_finish;
		insert(end(),val);
	}

	void pop_back() {
		erase(end()-1); //end()指向最后一个元素的下一位
	}

	void swap(vector<int>& v) {
		swap(_start, v._start);
		swap(_finish, v._finish);
		swap(_endofStorage, v._endofStorage);
	}


	void reserve(size_t n) {
	//只增加容量
		if (n > capacity()) {
			size_t sz = size(); //之前的size先保存下来
			//开空间
			T* tmp = new T[n];
			//内容拷贝
			//memcpy(tmp, _start, size()*sizeof(T); //memcpy属于浅拷贝,要想真正实现拷贝必须进行深拷贝
			//错误	1	error C1075 : 与左侧的 圆括号“(”(位于“e:\c++ 第二遍学习\11月11日线下整理\11月11日线下整理\gdlsfl.cpp(48)”)匹配之前遇到文件结束	
			//e : \c++ 第二遍学习\11月11日线下整理\11月11日线下整理\gdlsfl.cpp	188	1	11月11日线下整理

			//深拷贝： 将每一个元素进行不断拷贝过去
			for (int i = 0; i < size(); i++) {
				tmp[i] = _start[i];
			}
			//释放原有空间 
			delete[] _start;
			//
			_start = tmp;
			_finish = _start + sz;
			_endofStorage = _start + n; //扩容
		}
	}
	//////////////////////////////////////////////////////////////////////////
	//operator[]遍历：
	T& operator[](size_t pos ) {
		assert(pos < size());
		return _start[pos];
	}
	const T& operator[] (size_t pos) const{
		//assert(pos < size());
		return _start[pos];
	}

	//迭代器：
	typedef T* iterator;
	typedef const T* const_iterator;
	iterator begin() {
		//第一个元素的位置
		return _start;
	}
	iterator end() {
		//最后一个元素的下一个位置
		return _finish;
	}
   //const迭代器接口
	const_iterator begin() const{
		return _start;
	}
	const_iterator end() const{
		return _finish;
	}
	//修改有效元素的个数
	void resize(size_t n,const T& val=T()) {
		//1.修改元素的个数小于元素的个数
		if (n<size()) {
			reserve(n);
		}
		//2.修改元素的个数大于元素的个数
		if (n>size()) {
			//从_finish之后的位置开始进行判断
			while (_start + n >= _finish) {
				*_finish++ = val;
			}
		}
		//更新size
		_finish = _start + n;
	}
	//在pos位置的前面插入元素
	void insert(iterator pos, const T& val) {
		//1.判定有效插入位置
		assert(pos >= begin() && pos <= end());  

		//if (pos >= _start && pos<= _finish) {
		//
		//}

		//2.检查容量
		if (_endofStorage == _finish) {
			int len = pos - _start; //标记未扩容之前pos的位置上
			//3.增容处理
			size_t newC = capacity() == 0 ? 1 : 2 * capacity();
			reserve(newC);
			//重新表明pos位置，再扩容的时候会导致pos位置发生改变
			pos = len + _start; //寻找扩容之后元素的位置，假如没有重新标定，pos位置无法找到
		}
		//3.找到pos前面的位置
		iterator end = _finish;
		while (end > pos) { //pos需要重新标定，否则或导致迭代器失效
			*end = *(end - 1);
			--end;
		}
		//4.插入元素
		*pos = val;
		//5.更新—finish
		++_finish;
	}

	//
	iterator erase(iterator pos) {
		//1.判定有效插入位置
		assert(pos >= begin() && pos < end());
		//2.依次从后向前移动
		iterator begin = pos+1;
		while (begin != _finish) {
			*(begin - 1) = *begin;
			++begin;
		}
		--_finish;
		return pos;
	}


private:
	T* _start; //首元素地址的指针
	T* _finish; //最后一个元素的结束位置
	T* _endofStorage;// 空间容量法人结束位置

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


	//vector迭代器失效问题：
	//1.迭代器主要作用就是让算法不关心底层数据结构,其底层就是一个指针,或者对指针进行了封装,vector就是原生态指针T*,实际就是迭代器底层对应
	//随指向指针的空间被销毁了,而使用一块已经被释放的空间,造成的后果就是导致程序崩溃.
	//2.那些情况可能导致迭代器底层失效:
	//1>引起底层空间位置改变,比如resize,reserve,insert,assign,push_back.
	//2>指定位置删除操作-->erase erase删除pos位置元素之后,pos位置元素会往前进行移动,但是假如pos位置恰好就是end的位置,而end位置是没有元素的
	//那么就会导致迭代器失效.
	//解决迭代器失效的方法:在使用前对迭代器进行重新复制即可
	//Vector<int>::iterator it = v1.begin();
	//while (it != v1.end()) {
	//	if (*it % 2 == 0)
	//		v1.erase(it); //删除会导致迭代器失效，解决的办法就是重新迭代器
	//	else
	//		++it; //重新更新迭代器
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

	/*cout << "交换之后" << endl;
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
