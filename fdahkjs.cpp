//*******************************string��ӿڼ�ʹ��
#include <string> 
#include <iostream>
using namespace  std;


void test1() {
	//�ַ�������ع���
	///*string s1;
	//string s2("123");
	//string s3(s2);
	//string s4 = "123456";*/
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///*size: ������Ч�ַ��ĸ���---��\0������
	//length:������Ч�ַ��ĸ���*/
	///*string s1("123");
	//const string s2 = "123456";
	//int ret1 = s1.size();
	//int ret2 = s2.size();
	//cout << "ret1: " << ret1 << endl;
	//cout << "ret2: " << ret2 << endl;

	//char s3[] = { '1', '2', '\0', '\0' };
	//int ret3 = strlen(s3);
	//string s4(s3);
	//int ret4 = s4.size();
	//cout << "ret3: " << ret3 << endl;
	//cout << "ret4: " << ret4 << endl;
	//}
	//int main() {
	//test1();
	//system("color A");
	//system("pause");
	//return 0;
	//}*/
	//	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//	//����resize
	//	string s5("12345");
	//	//resize: �޸���Ч�ַ��ĸ���
	//	s5.resize(10); //���ݵĸ������ڱ�����ЧԪ�صĸ��� ������ЧԪ�صĲ�����\0����
	//	const char* str = s5.c_str();
	//	int ret5 = s5.size();
	//	int ret6 = strlen(str); //����\0�ͽ���
	//	cout << "ret5: " << ret5 << endl;
	//	cout << "ret6: " << ret6 << endl;
	//
	//	cout << s5 << "end" << endl; //\0\0\0\0\0 s5������Ч�ַ��ĸ�����5,����resize֮������(���ݵĸ������ڱ�����ЧԪ�صĸ���)
	//	cout << str << "end" << endl;
	//}
	//int main() {
	//	test1();
	//	system("color A");
	//	system("pause");
	//	return 0;
	//}
	//	string s5("12345");
	//	//resize: �޸���Ч�ַ��ĸ���
	//	s5.resize(10,'a'); //���ݵĸ������ڱ�����ЧԪ�صĸ���  ������ЧԪ�صĲ�����a���� 
	//	const char* str = s5.c_str();
	//	int ret5 = s5.size();
	//	int ret6 = strlen(str);
	//	cout << "ret5: " << ret5 << endl;
	//	cout << "ret6: " << ret6 << endl;
	//
	//	cout << s5 << "end" << endl; //aaaaa s5������Ч�ַ��ĸ�����5,����resize֮������(���ݵĸ������ڱ�����ЧԪ�صĸ���)
	//	cout << str << "end" << endl;
	//
	//}
	//int main() {
	//	test1();
	//	system("color A");
	//	system("pause");
	//	return 0;
	//}
	//	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//	//��Сresize:  ����ı�ԭ��λ�õ�����
	//	string s5("12345");
	//	s5.resize(2); //���ݵĸ���С�ڱ�����ЧԪ�صĸ���
	//	const char* str = s5.c_str();
	//	int ret5 = s5.size();
	//	int ret6 = strlen(str);
	//	cout << "ret5: " << ret5 << endl;
	//	cout << "ret6: " << ret6 << endl;
	//
	//	//s5������Ч�ַ��ĸ�����5,
	//	//����resize֮������(���ݵĸ������ڱ�����ЧԪ�صĸ���)
	//	cout << s5 << "end" << endl;
	//	cout << str << "end" << endl;
	//}
	//
	//int main() {
	//	test1();
	//	system("color A");
	//	system("pause");
	//	return 0;
	////}
	//	string s6("123");
	//	int ret1 = s6.size();
	//	int cap1 = s6.capacity();
	//	cout << "����֮ǰ��size: " << ret1 << endl;
	//	cout << "����֮ǰ��capacity: " << cap1 << endl;
	//	//resize:ֻ�ı���ЧԪ�صĸ���,����ı�capacity
	//	s6.resize(10,'a');
	//	int ret2 = s6.size();
	//	//capacity:��ʾstring�����ܴ����ЧԪ�ص�������
	//	int cap2 = s6.capacity();
	//	cout << s6 << endl;
	//	cout << "����֮���size: " << ret2 << endl;
	//	cout << "����֮���capacity: " << cap2 << endl;
	////resize:�ܽ�
	////1.resize(n):��size���n,��������λ����\0����
	////2.resize(n,'c'):��size���n,��������λ����'c'����
	////3.resize: ֻ����������������,�����޸�����λ�õ�����
	////4.resize:���Ա���Сsize
	////5.resize֮���size��stringԭʼ��������,��string֮����������
	//}

	//int main() {
	//	test1();
	//	system("color A");
	//	system("pause");
	//	return 0;
	//}
	//	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//	//reserve: ֻ�ı�����(��������Ҳ�ܼ�С),���ı�ʵ��Ԫ�صĸ���(size)
	//	string s1;
	//	s1.resize(10);
	//	cout << "size: " << s1.size() << endl;
	//	cout << "capacity: " << s1.capacity() << endl;
	//	s1.reserve(60);
	//	cout << "size: " << s1.size() << endl;
	//	cout << "capacity: " << s1.capacity() << endl;
	//
	//	s1.reserve(10);
	//	cout << "size: " << s1.size() << endl;
	//	cout << "capacity: " << s1.capacity() << endl;
	//		}
	//
	//int main() {
	//	test1();
	//	system("color A");
	//	system("pause");
	//	return 0;
	//}
	//reserve: �ı�������С,size��С�������ܸı�
	//�����Ҫ��С����,ʵ�ʵ�������С�����string��������ݽ����ʵ��Ż�����(ֱ��������������Ԫ����Ҫ�Ŀռ伴��)
/*string s2("12345");
cout << "����֮ǰ" << endl;
cout << "size: " << s2.size() << endl;
cout << "capacity: " << s2.capacity() << endl;

cout << "����֮��" << endl;
s2.reserve(4);
cout << "size: " << s2.size() << endl;
cout << "capacity: " << s2.capacity() << endl;
}

int main() {
test1();
system("color A");
system("pause");
return 0;
}
*/
  //����: ��һ��2��,�������1.5��,�����ķ�ʽ�������ݻ�ʹ�ÿ����ܴ�,ÿһ�ν������ݶ�Ҫ����,//1.���ռ�2.���ƿ���3.�ͷſռ�
// // ������ǰ���ÿռ���ô�����С����
//string s1;
//int cap = s1.capacity();
//cout << "capacity:" << cap << endl;
//for (int i = 0; i < 100; i++) {
//	s1.push_back(i);
//	if (cap != s1.capacity()) {
//		cap = s1.capacity();
//		cout << "capacity:" << cap << endl;
//	}
//}
//		}
//
//		int main() {
//			test1();
//			system("color A");
//			system("pause");
//			return 0;
//		}

    //��ǰ���ÿռ�: 
	string s1;
	int cap = s1.capacity();
	cout << "capacity:" << cap << endl;

	s1.reserve(100); //��С�����ݵĿ���
	cout << "capacity:" << s1.capacity() << endl;

	for (int i = 0; i < 100; i++) {
		s1.push_back(i);
		if (cap != s1.capacity()) {
			cap = s1.capacity();
			cout << "capacity:" << cap << endl;
		}
	}

}

int main () {
	test1();
    system("color A");
    system ("pause");
    return 0;
}