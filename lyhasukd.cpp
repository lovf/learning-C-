 vector ��ʹ��
һ.(contruct)���캯��˵��  
1.�޲ι��� vector<int> v1;
2.���첢��ʼ��n��val;vector<int>v2(n,val);
3.�������� vector<int>v3(v2);
4.ʹ�õ��������г�ʼ������

#include <string>
#include <iostream>
using namespace std;
#include <vector>

ÿһ�ִ�ӡ�����ķ�ʽ���� for+operator[]
void test1() { 
	1.�޲ι���
	vector<int> v1;
	vector<char> v2;
	vector<string> v3;
	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << " ";
	}
	cout<< endl;
	2.���첢��ʼ��n��val vector<int>v(n,val);
	vector<int>v4(10, 4);
	for (int i = 0; i < v4.size(); i++) {
		cout << v4[i] << " ";
	}
	cout << endl;
	3.��������  ��һ���Ѿ����ڵĶ���ȥ������һ������
	vector<int>v5(v4);
	for (int i = 0; i < v5.size(); i++) {
		cout << v5[i] <<" ";
	}
	cout << endl;
	4.ʹ�õ�������ʼ������
	string s1 = "0123456789";
	vector<char>v6(s1.begin(), s1.end());// [s1.begin(), s1.end())  ����������ǰ�պ󿪵�����
	for (int i = 0; i < v6.size(); i++) {
		cout << v6[i] << " ";
	}
	cout << endl;
}

int main() {
	test1();

	system("pause");
	return 0;
}
***********************************************************************************************************************************************
��.vector �ı���ʹ��
1.����������
2.for + operator[]����
3.��Χfor����
#include <vector>
#include <iostream>
using namespace std;

void PrintVector(vector<int>& v1) {   //vector<int>& ���ñ�ʶ��
	//1.ʹ�õ������������ (�ɶ���д��)
	vector<int>::iterator it = v1.begin();
	while (it != v1.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
	//1.1ʹ�õ������������
	cout << "reverse_iterator" << endl;
	vector<int>::reverse_iterator rit = v1.rbegin();
	while (rit != v1.rend()) {
		cout << *rit << " ";
		++rit;
	}
	cout << endl; 
	//2.for + operator[] (�ɶ���д��)
	for (int i = 0; i < v1.size();i++) {
		//cout << v1.operator[](i) << " ";
		cout << v1[i] << " ";
	}
	cout << endl;
	//3.��Χfor (�ɶ���д��)
	for (auto& ch:v1) {
		cout << ch << " ";
	}
	cout << endl;
}

void test2() {
	vector<int> v1;
	���ʹ��push_back���뼸������
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);
	PrintVector(v1);
}

int main() {
	test2();
	system("pause");
	return 0;
}
************************************************************************************************************************************************
����ʹ����չ

#include <vector>
#include <iostream>
using namespace std;



void test() {
	int a1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; 
	vector<int>v1(a1, a1 + 10); //v(a,a+10)����һ�������������鱾�����һ��������
	for (int i = 0; i < v1.size();i++) {
			cout << v1[i] << " ";
	}
	cout << endl;
	char a2[] = "12345678910";
	vector<char>v2(a2, a2 + 10);
	for (int i = 0; i < v2.size(); i++) {
		cout << v2[i] << " ";
	}
	cout << endl;
	string a3[5] = { "123", "456", "789", "abc", "def" };
	vector<string>v3(a3, a3 + 5);
	for (int i = 0; i < v3.size(); i++) {
		cout << v3[i] << " ";
	}
	cout << endl;
}

int main() {
	test();
	system("pause");
	return 0;
}
*********************************************************************************************************************************************
��.vector �ռ���������
#include <vector>
#include <iostream>
using namespace std;

void PrintVector(vector<int>& v1) {
	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << " ";
	}
	cout << endl;
}

void test() {
	int a1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; 
	vector<int>v1(a1, a1 + 10); //v(a,a+10)����һ�������������鱾�����һ��������
	v1.resize(15,'a');
	cout << "size" << v1.size() << endl;
	PrintVector(v1);
}

int main() {
	test();
	system("pause");
	return 0;
}
resize: 
resize(n,val): �������val,��ʹ��Ĭ��ֵ.(��������-->0),�Զ�������������޲ι���
******************************************************************************************************************************************
�鿴���ݵĹ���
#include <iostream>
#include <vector>
using namespace std;

void test() {

	vector<int>v;
	size_t sz = v.size();
	size_t cap= v.capacity();

	cout << cap << endl;
  cout << "make cap grow: "<<endl;
	for (int i = 0; i < 200;i++) {
		v.push_back(i);
		if (cap != v.capacity()) {
		cap = v.capacity();
		cout << "capacity changed: " <<cap << endl;
		}
	}
}

int main() {
	test();
	system("pause");
	return 0;
}
************************************************************************************************************************************
vector :
����: ����ǿ�,����Ϊ0
vs ��PJ�汾,���ݰ���1.2��,g++��SGI�汾һ����2��;
reserve : ֻ��������,����������

#include <vector>
#include <iostream>
using namespace std;

void test() {
	vector<int>v;
	size_t cap = v.capacity();
	cout << cap << endl;

	v.reserve(100);
	cap = v.capacity();
	cout << cap << endl;

	v.reserve(10);
	cap = v.capacity();
	cout << cap << endl;

}
int main() {
	test();
	system("pause");
	return 0;
}
********************************************************************************************************************************************
��.vector ��ɾ�Ĳ�
1.insert :
#include <iostream>
#include <vector>
using namespace std;



void test() {

	vector<int>v;
	insert �ṩ��3�ֽӿ�
	v.insert(v.begin(), 1);//1  �����ڳ�ʼ��λ�ò���һ��1
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	v.insert(v.begin(),5,0);// 000001 �����ڳ�ʼ��λ�÷���5��0
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;

	int a[] = { 1, 2, 3, 4, 5 };
	v.insert(v.begin(), a + 1, a + 3);// 23000001 ���ڸ�����һ������������ [a+1,a+5)֮�����
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

int main() {

	test();
	system("pause");
	return 0;
}

********************************************************************************************************************************
��.������ʧЧ����:
#include <iostream>
#include <vector>
using namespace std;

void test() {
	vector<int> v;
	insert �ṩ��3�ֽӿ�
	v.insert(v.begin(), 5, 1);//1  �����ڳ�ʼ��λ�ò���һ��1
	vector<int>::iterator it = v.begin();
    cout << *it << endl;
	v.insert(it, 5, 0);
	int a[] = { 1, 2, 3, 4, 5 };
	v.insert(it, a + 1, a + 3); //������ʧЧ
	/*v.reserve(2); 
	cout << *it << endl;*/
	v.push_back(2);
	cout << *it << endl;

}

int main() {

	test();
	system("pause");
	return 0;
}
������ʧЧ:������ָ���λ��,�ռ䱻�ͷŻ��߱��һ�����ɷ��ʵ�λ��.(����Ĺ�����,�ռ䲻����������,Ȼ��֮ǰ�Ŀռ�ͻᱻ�ͷ�)
1.�ռ䷢���˱仯,�ͻᵼ��ԭ���ĵ�����ʧЧ.-->push_back,insert,reserve,resize,assign��Щ�ӿڶ��п��ܵ��¿ռ����������ı�
2.λ�ô�λ-->erase
�ܽ�: ���ǲ���֮��ʹ�ռ�Ĵ�С�����˸ı�,��ô��ʱ��ʹ�õ�����,֮��ͻᷢ��ʧЧ������.(���ݾͻ�)
���:
���»�ȡ������
��ɾ���ӿ�:begin ,end
erase :ֱ�ӻ�ȡ����ֵ,�䷵��ֵΪɾ��Ԫ�صĵ���һ��Ԫ�صĵ�����.
Ǳ������:�������ĵ�����Ϊ���һ��Ԫ�صĵ�����,��÷���ֵΪend������,Ҳ��һ�����ɷ��ʵ�λ��/


#include <vector>
#include <iostream>
using namespace std;


void test() {
	vector<int>v;
	v.insert(v.begin(), 10, 5);
	vector<int>::iterator it = v.begin();
	while (it != v.end()) {
		it = v.erase(it);
		cout << *it << " "; //������������,��Ϊǡ��Ϊ���һ��Ԫ�ص�λ��.
	}


}
int main() {
	test();
	system("pause");
	return 0;
}

*************************************************************************************************************************************************
�����ӿ�:
#include <iostream>
#include <vector>
using namespace std;


void test() {
	vector<int>v1(5,2);
	vector<int>v2(5, 1);
	swap(v1,v2);//�ڲ�����vector�ĳ�Ա����swap���
	v1.swap(v2);
	cout << "v1��ֵΪ: " << endl;
	for (int i = 0; i < v1.size();i++) {
		cout << v1[i] << " ";
	}
	cout << endl;
	cout << "v2��ֵΪ: " << endl;
	for (int i = 0; i < v2.size(); i++) {
		cout << v2[i] << " ";
	}
	cout << endl;
}

int main() {
	test();
	system("pause");
	return 0;
}



















