//string��ʵ�ֵĽӿ�:

//������ؽӿ�: �ص�resize, resize
#include <string>
#include <iostream>
using namespace  std;


void test1() {
	string str = "1234";
	cout << str.size() << endl;
	cout << str.capacity() << endl;
	//clear:��size���0,���ı�����
	//str.clear(); 
	//cout << str.size() << endl;
	//cout << str.capacity() << endl;

	/*str.resize(100);
	cout << "resize:" << endl;
	cout << str.size() << endl;
	cout << str.capacity() << endl;*/

	str.reserve(50);
	cout << "reserve(50):" << endl;
	cout << str.size() << endl;
	cout << str.capacity() << endl;

	str.reserve(6);  //reserve(n):n > size n<=15 ,����ʼ�ն���15
	cout << "reserve(5)" << endl;
	cout << str.size() << endl;
	cout << str.capacity() << endl;

	//str.shrink_to_fit(); //������>size�������,��������С�����ʵ�size,��Ҫ�Ŀռ��ʵ������ı������ϴ�ʱ,
	//cout << str.size() << endl;
	//cout << str.capacity() << endl;
}
int main() {
	test1();
	system("color A");
	system("pause");
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//front back 

#include <string>
#include <iostream>
using namespace  std;


void test2() {

	//string s1 = "1234";
	//cout << s1 << endl;
	////front:��ȡ��һ��Ԫ�ص��ַ� ����ֵΪ����,���ǿɶ���д�Ľӿ�
	//s1.front() = 'a';
	//cout << s1 << endl;

	////back;��ȡ���һ��Ԫ�ص��ַ� ����ֵΪ����,���ǿɶ���д�Ľӿ�
	//s1.back() = 'b';
	//cout << s1 << endl;

	////const front/back  ���ǿɶ��Ľӿ�,���ܶ�ֵ�����޸�
	///*const string s2 = "1234";
	//s2.front() = 'a';
	//s2.back() = 'b';
	//cout << s2 << endl;*/


	//at�ӿ�:�ܶ���Ч��Χ��Ԫ�ؽ����޸�,����Ԫ�ص��±�Խ��,��ô�����쳣
	string s = "1234";
	cout << s << endl;

	s.at(0) = 'a';
	s.at(1) = 'b';
	cout << s << endl;

	//at λ��Խ��,���쳣
	/*s.at(5) = 'a';
	cout << s << endl;*/
	const string s2 = "1234";
	cout << s2 << endl;
	cout << s2.at(2) << endl; //��ȡС��Ϊ2��Ӧ��Ԫ��

}

int main() {

	test2();
	system("color A");
	system("pause");
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//�ַ�������

//operator[] ���� :�ӿڼ���const,Ҳ�з�const�ӿ�
//operator []λ��Խ��: 1.deBug�汾��assert����  2.release�汾������

#include <string>
#include <iostream>
using namespace  std;

void test3() {
	string s = "1234";
	cout << s << endl;
	//operator[] ���������
	//s[]<--->s.operator[] ���ߵȼ� 

	s[0] = 'a';
	s[1] = 'b';
	s.operator[](2) = 'c';
	cout << s << endl;
	//operator[]���ַ������б���

	for (int i = 0; i < s.size(); i++) {
		cout << s[i] << " ";
		s[i] = 'p';
	}
	cout << endl;

	for (int i = 0; i < s.size(); i++) {
		cout << s[i] << " ";

	}
	cout << endl;
}

int main() {
	test3();
	system("color A");
	system("pause");
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <string>
#include <iostream>
using namespace  std;

		//�ַ����ı���

		//1.������:һ��Ԫ�ص�ͨ�÷��ʻ���,��һ�����ģʽ.
		//
		//begin������:ָ�������еĵ�һ��Ԫ����һ��λ��
		//begin��end�����������÷�Χ:����ҿ�[begin,end)
		//cbegin,cend,begin,end

		//void PrintString(const string& s) {
		//	//iterator begin()    ��const�ӿ�
		//	//const_iterator begin() const
		//	//iterator end() 
		//	//const_iterator end() const
		//
		//	cout << "const_iterator:" << endl;
		//	string::const_iterator it = s.begin();
		//	while (it != s.end()) {
		//		cout << *it << " ";
		//		++it;
		//	}
		//	cout << endl;
		//}


void test4() {
			//1.operator[]
			cout << "operator[]:" << endl;
			string s = "1234";
			for (int i = 0; i < s.size(); i++) {
				cout << s[i] << " ";
			}
			cout << endl;

			////2.�ɶ���д������
			//cout << "iterator:" << endl;
			//string::iterator it = s.begin();
			//while (it != s.end()) {
			//	cout << *it << " ";
			//	*it = 'a';
			//	++it;
			//}
			//cout << endl;

			//cout << "iterator�޸ĺ�:" << endl;
			//it = s.begin();
			//while (it != s.end()) {
			//	cout << *it << " ";

			//	++it;
			//}
			//cout << endl;

			//ֻ��������
			//cout << "const_iterator:" << endl;
			//string::const_iterator it = s.cbegin();
			//while (it != s.cend()) {
			//	cout << *it << " ";
			//	//*it = 'a';
			//	++it;
			//}
			//cout << endl;
			//PrintString(s);
			//��������: 
			//rbegin:ָ�����һ��Ԫ�ص�λ�� �ɶ���д
			//rend:ָ���һ��Ԫ�ص�ǰһ��λ�� �ɶ���д

			//cout << "reverse_iterator:" << endl;
			//string::reverse_iterator rit = s.rbegin();
			//while (rit != s.rend()) {
			//	cout << *rit << " ";
			//	//�ƶ���ǰһ��λ��
			//	rit++;
			//}
			//cout << endl;
			//	//3.��Χfor
			//	//�����ķ�Χfor��д: 
			//	//1.ֻ���� for(const auto& ch:����:��Ҫ����������)
			//	//2.�ɶ���д  for(auto& ch:����:��Ҫ����������)
			//
			//	//��Χfor�ײ�ʵ��: ͨ��������ʵ��
			//	cout << "��Χfor:" << endl;
			//	for (char ch:s) { //û��ʹ������,��ֵ�ں��治�ܽ����޸�
			//		cout << ch << " ";
			//		ch = 'a';
			//	}
			//	cout << endl;
			//
			//	cout << "iterator:" << endl;
			//	string::iterator it = s.begin();
			//	while (it != s.end()) {
			//		cout << *it << " ";
			//		++it;
			//	}
			//	cout << endl;
			//
			//	cout << "��Χfor&:" << endl;
			//	for (char& ch : s) { //ʹ������,��ֵ�ں������޸�
			//		//for (char& ch : s) { �ɶ���д
			//		//for (const auto& ch : s) ֻ������
			//		cout << ch << " ";
			//		ch = 'a';
			//	}
			//	cout << endl;
			//
			//	cout << "iterator:" << endl;
			//	it = s.begin();
			//	while (it != s.end()) {
			//		cout << *it << " ";
			//		*it = 'a';
			//		++it;
			//	}
			//	cout << endl;
			//
			//}


			int main() {

				test4();
				system("color A");
				system("pause");
				return 0;
			}
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


			//��ɾ���
			//operator+=ʱ�临�Ӷ�O(1) (���)
			//append()ʱ�临�Ӷ�O(1)
			//push_back() ʱ�临�Ӷ�O(1)
			//assign();  ʱ�临�Ӷ�O(1)
			//insert()  ʱ�临�Ӷ�O(n)  ��ĩλ�ý��в���ɾ�� (��������)
			//erase();  ʱ�临�Ӷ�O(n)  ��ĩλ�ý��в���ɾ�� (��������)
			//pop_back() ʱ�临�Ӷ�O(1) (���)
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
			using namespace  std;


			void test6() {
				string s;
				s.push_back(1);
				s.push_back(2);
				s.push_back(3);
				s.push_back(4);
				s.push_back(5);

				string s2 = "abc";
				s.append(s2); //12345abc
				s.append(s2, 2, 1);//12345abcc
				s.append("xyz");//12345abcxyz
				s.append("opq", 2);  // ��"opq"��2��Ԫ�ز��뵽s�� //12345abcxyzop
				s.append(3, '1'); //12345abcxyzop111
				s.append(s2.begin(), s2.end()); // 12345abcxyzop111abc

				char Arr[] = "6789";
				s.append(Arr + 1, Arr + 3);//12345abcxyzop111abc78
				//�����õ��ַ�

			}

			int main() {


				test6();
				system("color A");
				system("pause");
				return 0;
			}

			//operator+=  (���ݹ����ӿ�ʵ��)��������غ��� operator+=--->����ַ�����ƴ��
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
			using namespace  std;

			//string+=��������غ�����operator+=--->����ַ�����ƴ��
			void test7() {
				string s;
				s += '1';
				s += "bc";
				string s2 = "678";
				s += s2;

			}

			int main() {

				test7();
				system("color A");
				system("pause");
				return 0;
			}
			//insert: (���ݹ����ӿ�ʵ��)����λ�õĲ���
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
			using namespace  std;

			void test8() {
				string s1;
				string s2 = "123";
				s1.insert(0, s2);//123
				s1.insert(1, s2);//112323
				string s3 = "abc";
				s1.insert(2, s2, 1, 2);//11bc2323 ��s1���±�Ϊ2��λ��ǰ�濪ʼ������s2�д��±�1��ʼ��2��Ԫ��
				s1.insert(4, "def");//11bcdef2323
				s1.insert(5, "ghi", 1); //11bcdgef2323
				s1.insert(9, 3, 'f');//11bcdgef2fff323
				s1.insert(s1.begin(), 2, '0');  //0011bcdgef2fff323
				s1.insert(s1.end(), 3, '4'); //0011bcdgef2fff323444
				s1.insert(s1.begin() + 1, 'a'); //0a011bcdgef2fff323444
			}

			int main() {
				test8();
				system("color A");
				system("pause");
				return 0;
			}

			//assign:���и�ֵ�Ĳ������ȼ���operator
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
			using namespace  std;

			void test9() {
				string s1 = "abc";
				string s2 = "123";
				s1.assign(s2);
				s1.assign(s2, 1, 2);  //23  ��s2�е��±��1��ʼ��2��Ԫ�ظ�ֵ��s1
				s1.assign("789");  // 789
				s1.assign("abcdefg", 5); // abcde
			}
			int main() {


				test9();
				system("color A");
				system("pause");
				return 0;
			}

			//erase
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
			using namespace  std;

			void test10() {
				string s = "123456789";
				s.pop_back();//12345678 ִ��βɾ����
				s.erase(0, 1);  // 2345678 ���±�Ϊ0��ʼɾ��1��Ԫ��
				s.erase(3, 2);  // 23478   ���±�Ϊ3��ʼɾ��2��Ԫ��


			}
			int main() {


				test10();
				system("color A");
				system("pause");
				return 0;
			}

			// replace �滻�ӿ�
#include <string>
#include <iostream>
			using namespace  std;

			void test11(){
				string s1 = "123";

				string s2 = "abc";

				s1.replace(1, 1, s2); //1abc3
				cout << s1 << endl;

				s1.replace(1, 2, s2); //1abcc3 //�ӵ�һԪ�ؿ�ʼ,�滻��s1�е������ַ�,��s2�����н���
				cout << s1 << endl;
			}

			int main() {


				test11();
				system("color A");
				system("pause");
				return 0;
			}
			void test11(){
				string s1 = "123";

				string s2 = "abc";

				s1.replace(1, 1, s2); //1abc3
				cout << s1 << endl;

				s1.replace(1, 2, s2); //1abcc3 //�ӵ�һԪ�ؿ�ʼ,�滻��s1�е������ַ�,��s3�����н���
				cout << s1 << endl;
			}

			//swap()
#include <string>
#include <iostream>
			using namespace  std;

			void test12() {

				string s1 = "123";
				string s2 = "ab";
				cout << "����ǰ:" << endl;
				cout << s1 << endl;
				cout << s2 << endl;
				//��Ա����
				cout << "��Ա�����н�����:" << endl;

				s1.swap(s2);
				cout << s1 << endl;
				cout << s2 << endl;
				/* string ��Ա����:
				void Swap(String& str) {
				swap(_ptr, str._ptr);
				}

				ͨ��ģ��:
				template<class  T>
				void Swap(T& str1,T& str2) {
				T tmp = str1;
				str1 = str2;
				str2 = tmp;
				}
				string �ǳ�Ա���� :
				template<class T>
				void Swap(basic_string<T>& a, basic_string<T>& b) {
				a.swap(b);
				}*/


				//�ǳ�Ա����
				cout << "�ǳ�Ա�����н�����:" << endl;
				swap(s1, s2);
				cout << s1 << endl;
				cout << s2 << endl;
				int a = 1;
				int b = 2;
				cout << "����ǰ:" << endl;
				cout << a << endl;
				cout << b << endl;

				cout << "������:" << endl;
				swap(a, b);
				cout << a << endl;
				cout << b << endl;

			}


			int main() {

				test12();
				system("color A");
				system("pause");
				return 0;
			}
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <string>
#include <iostream>
			using namespace  std;

			void test13() {
				string s = "12345";
				cout << s << endl;
				cout << s.c_str() << endl;
				//c_str(): ����ֵΪconst char*,����ͨ�����ص�ָ���޸�����
				//const char* ptr = s.c_str();

			}
			int main() {

				test13();
				system("color A");
				system("pause");
				return 0;
			}
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			//copy �˽�  find rfind
#include <string>
#include <iostream>
			using namespace  std;

			////substr: ����һ�����ַ������н�ȡ����
			void test15() {
				string s = "https://www.bitedu.vip/login";
				size_t pos = s.find("://");
				if (pos != string::npos) {
					size_t pos2 = s.find("/", pos + 3);
					if (pos2 != string::npos) {
						pos += 3;
						string sub = s.substr(pos, pos2 - pos);
						cout << sub << endl; //v.bitedu.vip
					}
				}
			}

			int main() {


				test15();
				system("color A");
				system("pause");
				return 0;
			}

			compare

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
				using namespace  std;


			void test16() {
				//�ַ����ȽϹ���: ��ǰ���,����ÿһ���ַ���ASSCI��ֵ���бȽ�
				int ret1 = strcmp("1", "12");
				int ret2 = strcmp("345", "92");
				cout << ret1 << endl;//-1
				cout << ret2 << endl;//-1

				//������������غ������бȽ�
				string str1 = "1";
				string str2 = "12";
				string str3 = "345";
				string str4 = "92";
				int rit1 = str1 > str2;  //���õ�����������غ���
				int rit2 = str3 > str4;
				cout << rit1 << endl; //0 ��
				cout << rit2 << endl; //0 ��
			}
			int main() {


				test16();
				system("color A");
				system("pause");
				return 0;
			}
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			//operator+(string)
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
			using namespace  std;

			void test17() {
				string str1 = "123";
				string str2 = "abc";
				str1 += str2; //123abc һ��ʹ��+=���м���
				string rs1 = str1 + str2; //123abcabc

				//string str3 = "123";
				//string str4 = "abc";
				//string& rs2 = str3 + str4; //����ֵ��Ҫ����,Ч�ʵ�
			}

			int main() {

				test17();
				system("color A");
				system("pause");
				return 0;
			}
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <string>
#include <iostream>
			using namespace  std;

			void test18() {
			cin: �����ַ���, �����ո����.

				string s;
				 cin >> s;
				 operator>>(cin, s);
				 cout << s << endl;
			 getline:
				 getline(cin, s); //Ĭ�϶�ȡһ�е�����,�м�����пո�,
				 getline(������, string����, ָ����������ķָ���)
					 getline(cin, s, ',');//��ȡ������,������ȡ
			}

			int main() {
				test18();
				system("color A");
				system("pause");
				return 0;
			}

			//���:
			//������: begin/end
			//capacity:size,resize,capacity,reserve,clear, empty
			//operator[]
			//��ɾ���: operator+=/swap

			//c_str,find,rfind,substr,

		//��ϵ�����:operator>>, operator<<, getline



























































