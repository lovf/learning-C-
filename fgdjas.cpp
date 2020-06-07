////string ��������������
//
#include <iostream>
using namespace std;
#include <string>

void test() {
	string str("012345");
	cout << str.size() << endl;
	cout << str.length() << endl;
	cout << str. capacity() << endl;
	cout << str << endl;
//��str�е��ַ�������,ע�����ֻ�ǽ�size��0,���ı�ײ�ռ�Ĵ�С.
	str.clear();
	cout << str.size() << endl;
	cout << str.capacity() << endl;
//��str����Ч�ַ��������ӵ�10��,�����λ����'a'����.
	str.resize(10,'a');
	cout << str.size() << endl;
	cout << str.capacity() << endl;
	cout << str << endl;
//��str����Ч�ַ����ӵ�15��,�����λ��Ӧ'b'���в�
	str.resize(15,'b');
	cout << str.size() << endl;
	cout << str.capacity() << endl;
	cout << str << endl;
}
int main() {
	test();
	system("pause");
	return 0;
}
//*************************************************************************************************************

#include <iostream>
using namespace std;
#include <string>

void test() {
	string str;
	//����reverse�Ƿ��ı�string�е���ЧԪ�ظ���.reserve�ı��ֻ�������ȸı�size������
	str.reserve(100);
	cout << str.size() << endl;
	cout << str.capacity() << endl;
	//����reserve����С��string�ĵײ�ռ��С,�Ƿ�Ὣ�ռ���С
	str.reserve(20);
	cout << str.size() << endl;
	cout << str.capacity() << endl;
}

int main() {
	test();
	system("pause");
	return 0;
}
//********************************************************************************************************
//string�����ķ����Լ���������
#include <iostream>
using namespace std;
#include <string>

void test() {

	string str("0123456789");
	//1.for+operator[]
	for (size_t i = 0; i < str.size(); ++i) {
		cout << str[i] << " ";
		cout << str.operator[](i) << " ";
	}
	cout << endl;
	//2.��Χfor
	for (auto ch : str) {
		cout << ch << " ";
	}
	cout << endl;
	//3.������
	//	���������
	string::iterator it = str.begin();
	while (it != str.end()) {

		cout << *it << " ";
		++it;
	}
	cout << endl;
	//	���������
	string::reverse_iterator rit = str.rbegin();
	while (rit != str.rend()) {
		cout << *rit << " ";
		++rit; //���δӺ�����ǰ�������
	}
	cout << endl;
	//const(����)
	string::const_iterator cit = str.cbegin();
	while (cit != str.cend()) {
		cout << *cit << " ";
		++cit;
	}
	cout << endl;
	//const (����)
	string::const_reverse_iterator crit = str.crbegin();
	while (crit != str.crend()) {
		cout << *crit << " ";
		++crit;
	}
	cout << endl;

	for (size_t i = 0; i < str.size();i++) {
		cout << str.at(i) << " ";
		}
		cout << endl;
}
int main() {
	test();
	system("pause");
	return 0;
}
//������
//��Χ:[begin,end)
//��������ʹ�÷�ʽ:������ָ���ʹ�÷�ʽ,����ͨ�������û�ȡԪ�ص�����,����ͨ��++ ,-- ����λ�õ��ƶ�.





































