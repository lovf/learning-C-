//string�������޸Ĳ���
//#include <iostream>
//using namespace std;
//#include <string>
//
//
////void test1() {
////	string s;
////	s.push_back('a'); // push_back ���ַ�����������ַ�
////	s.append(2,'b'); // ��������5���ַ� b
////	s.append("cde"); //append ���������ַ���
////	string s2;
////	s2.append(s); // ���ڸ�s2�������s
////	cout << s2 << endl;
////	string s3;
////	s3.append(s,3,2); //��s�ĵ�3���ַ���ʼ,ȡ2���ַ�
////	cout << s3 << endl;
////}
//
//void test2() {
//	string s = "0123456789";
//	//s.replace(3, 5, "aa");  //012aa89 ��������λ�ÿ�ʼ,
//	//cout << s << endl;
//	//s.replace(s.begin() + 1, s.end() - 1, "0");  //009 ��1��λ�ÿ�ʼ�����һ��Ԫ��֮�任0
//	//cout << s << endl;
//
//	string s2 = "abc";
//	s2.swap(s);   // s2: 009   s: abc
//	//swap(s2, s);  //ȫ��string���͵�swap������ �ڲ�����string�ĳ�Ա����swap��ɽ���
//
//	int a = 1;
//	int b = 2;
//	swap(a,b);
//	cout << a << endl;
//	cout << b << endl;
//}
//
//int main() {
//	//test1();
//	test2();
//	system("pause");
//	return 0;
//}
//������������:
//#include <iostream>
//using namespace std;
//#include <string>
//
//
//void test() {
//	int a = 1;
//	int b = 2;
//	swap(a,b);
//	cout << a << endl;
//	cout << b << endl;
//}
//
//int main() {
//
//	test();
//	system("pause");
//	return 0;
//}
//*****************************************************************************************************************************************
//#include <iostream>
//using namespace std;
//#include <string>
//
//void test1() {
//	string str = "absdfhyg";
//	size_t pos = str.find('b'); //�������,�ҵ���һ��ƥ���λ�þͽ���
//	//size_t  pos2 = str.rfind('d'); // �������,�ҵ���һ��ƥ���λ�þͽ���
//	cout << str.size()-pos-1 << endl;
//}
//
//void test2() {
//	string s1 = "9";
//	string s2 = "123";
//	string s3 = "1234";
//
//	bool ret1 = s1 > s2;
//	bool ret2 = s2 > s3;
//	bool ret3 = s1 > s3;
//
//	cout << ret1 << endl; //1
//	cout << ret2 << endl; //0
//	cout << ret3 << endl; //1
//}
//
//void test5() {
//	string s;
//	
//    getline(cin, s);//����������ո���ַ�
//	cout << s << endl;   
//
//}
//int main() {
//	//test1();
//	//test2();
//	test5();
//	system("pause");
//	return 0;
//}

//����getline �� rfind��ʹ��
#include <iostream>
using namespace std;
#include <string>

void test() {
	string s;
	while (getline(cin, s)) {
		size_t pos = s.rfind(' ');
		cout << s.size() - 1 - pos << endl;
	}
}

int main() {
	test();
	system("pause");
	return 0;
}























