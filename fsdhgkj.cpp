
//vector:�ӿڼ�ʵ��
//1.������:
#include<string>
#include<vector>
#include <iostream>
using namespace  std;


void  test1() {
	vector<int> v1;
	vector<char> v2;
	vector<string> v3;

	vector<int> v4(10, 5); //10��Ԫ�ض���5

	string s2 = "0123456789";
	vector<char> v5(s2.begin(), s2.end()); //�������� ������'\0'
	vector<char> v6(v5);//��������

}

////���ֱ�����ʽ:1.operator[] 2.������ 3. ��Χfor
void test2() {
	string s("0123456789");
	vector<char> v(s.begin(), s.end());
	//����
	cout << "reverse_iterator" << endl;
	vector<char>::reverse_iterator rit = v.rbegin();
	while (rit != v.rend()) {
		cout << *rit << " ";
		rit++;
	}
	cout << endl;

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	vector<char>::iterator it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		*it = 'a';
		it++;
	}
	cout << endl;
	//��Χfor
	for (char& ch : v) {
		cout << ch << " ";
	}
	cout << endl;
	// operator[]
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;

}
//ģ����д�ӡ
template<class T>

void PrintVec(vector<T>& v) {

	cout << "iterator" << endl;
	vector<T>::const_iterator it = v.cbegin();
	while (it != v.cend()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;

	cout << "reverse_iterator" << endl;
	vector<T>::const_reverse_iterator rit = v.crbegin();
	while (rit != v.crend()) {
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
}
void test3() {
	/*template<class T>
	vector(InputIterator  first, InputIterator last);*/
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector<int> v1(a, a + 10);

	char a2[] = "1234567890";
	vector<char> v2(a2, a2 + 10);

	string a3[5] = { "123", "456", "789", "abc", "def" };
	vector<string> v3(a3, a3 + 5);

	PrintVec(v1);
	PrintVec(v2);
	PrintVec(v3);
	cout << "resize" << endl;
	v1.resize(15);
	v1.resize(15);
	v1.resize(15);

	PrintVec(v1);
	PrintVec(v2);
	PrintVec(v3);

}

//reserveֻ��������,���ܼ�С����
void test4() {
	//vector: ����:����ǿ�,����Ϊ0;PJ�汾���մ���1.5������,SGIһ����3��
	//resize(n,val); �������val����,��ʹ��Ĭ��ֵ: ��������--->0,�Զ�������--->�����޲ι���
	vector<int> v;
	size_t sz = v.size();
	size_t cap = v.capacity();
	cout << "����֮ǰ�����Ĵ�С: " << cap << " ";

	for (int i = 0; i < 200; i++) {
		v.push_back(i);

		if (cap != v.capacity()) { //�ж�����֮��,������С�Ľ��бȽ�
			cap = v.capacity(); //���ٴ�����
			cout << cap << " ";
		}
	}
	cout << endl;
}


void test5() {
	//reserve: ֻ��������,����С����
	vector<int> v;
	size_t cap = v.capacity();
	v.reserve(100);
	cap = v.capacity();
	cout << cap << endl;
	v.reserve(10); //
	cap = v.capacity();
	cout << cap << endl;

}
void test6() {
	vector<int> v;
	//operator[]Խ��,���԰汾�������Դ���
	int ret1 = v[10];
	//atԽ������쳣
	int ret2 = v.at(0);
	cout << ret1 << endl;
	cout << ret2 << endl;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//�����ɾ���ӿ�
void test7() {

	vector<int> v;
	v.insert(v.begin(), 1); //1
	v.push_back(2);
	v.push_back(3);
	//������
	vector<int>::iterator it = v.begin();
	cout << *it << endl;
	it = v.insert(it, 0);
	cout << *it << endl;

	//�ص�:
	//������ʧЧ:������ָ���λ�ÿռ䱻�ͷ�(�����ʱ��ռ�Ͳ�����,��Ҫ����,Ȼ��Ҫ�ͷ�ԭ�пռ�,����it����ָ��ԭ����λ��,����ʧЧ)���߱��һ�����ɷ��ʵ�λ��,
	//1.�ռ䷢���˸ı�,�ͻᵼ��ԭ���ĵ�����ʧЧ--->pushBack(),insert,reserve,resize,assign(��Щ���п��ܵ���)
	//2.λ�ô�λ--->erase
	//�����ʽ:���»�ȡ������

	//��ɾ���ӿ�:begin,end;
	//erase: ֱ�ӻ�ȡ����ֵ,�䷵��ֵΪָ��ɾ��Ԫ�ص���һ��Ԫ�صĵ�����
	//Ǳ������:�������ĵ�����Ϊ���һ��Ԫ�صĵ�����,��ȡ�ķ���ֵҲ��һ�����ܷ��ʵ�Ԫ��,��ʱ��Ҫ���»�ȡ������
	//  �������ĵ�����Ϊ���һ��Ԫ�صĵ�����,��ȡ�ķ���ֵΪend������,Ҳ��һ�����ܷ��ʵ�λ��
	//����β����ʱ���Ѿ���������,(���뵼�¿ռ䷢���˸ı� )
	//v.insert(it, 5, 0); //��5��0 000001
	//cout << *it << endl;

	//int a[] = { 1, 2, 3, 4, 5 }; //
	//v.insert(it, a + 1, a + 3);// ����������[1,3) a+1 ��ָ��2  a+3ָ����4 //��������1��λ�ÿ�ʼ��3(��������Ϊ3�����λ��)����23000001
	//cout << *it << endl;
	//v.reserve(2);
	//cout << *it << endl;

}

void test8() {

	vector<int> v;
	v.insert(v.begin(), 10, 5);
	vector<int>::iterator it = v.begin();

	while (it != v.end()) {
		it = v.erase(it); //ֻҪ��ȡ��Ԫ��û�н��н�����,�Ϳ�����
	}

}

void test9() {
	vector<int> v1(5, 2);
	vector<int> v2(5, 1);

	swap(v1, v2);//�ڲ�����vector�ĳ�Ա����swap()���н������
	v1.swap(v2);
}


int main() {
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	//test7();
	//test8();

	test9();
	system("color A");
	system("pause");
	return 0;
}
