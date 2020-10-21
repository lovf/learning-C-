// �ַ����������һ�����ʵĳ���
#include <iostream>
#include <string> 
using namespace  std;

int main() {
	string str;
	getline(cin, str);
	size_t pos = str.rfind(' ');//�Ӻ�����ǰ�ҵ�һ�����ֿո��λ��
	if (pos == string::npos)   //������� pos == string::npos ˵�������ڿո�
		cout << str.size() << endl;
	else {
		cout << str.size() - 1 - pos << endl;
	}

	system("color A");
	system("pause");
	return 0;
}

//��Ȼ����ʹ�� cin �� >> ������������ַ������������ܻᵼ��һЩ��Ҫע������⡣
//��cin��ȡ����ʱ,���ᴫ�ݲ������κ�ǰ����ɫ�ո��ַ�(�ո�,�Ʊ�����߻���).һ�����Ӵ�����һ���ǿո��ַ�����ʼ�Ķ���
//������ȡ����һ���հ��ַ�ʱ������ֹͣ��ȡ������������Ϊ����

#include <iostream>
#include <string> 
using namespace std;

int main() {
	string name;
	string city;
	cout << "Please enter your name: ";
	cin >> name; //������������пո�ʽ��ֹͣ������,

	cout << "Enter the city you live in: ";
	cin >> city;

	cout << "Hello, " << name << endl;
	cout << "You live in " << city << endl;
	system("color A");
	system("pause");
	return 0;
}
//�����пո�֮��� cin ������ֱ��ֹͣ��д
//Please enter your name�� John Doe
//Enter the city you live in : Hello, John
//You live in Doe
//
//��ע�⣬�����ʾ���У��û�����û�л������� city ����������Ϊ�ڵ�һ����������У��� cin ��ȡ�� John �� Doe ֮��Ŀո�ʱ��
//���ͻ�ֹͣ�Ķ���ֻ�洢 John ��Ϊ name ��ֵ���ڵڶ�����������У� cin ʹ�ü��̻��������ҵ���ʣ���ַ������洢 Doe ��Ϊ city ��ֵ��

#include <iostream>
#include<string>

using namespace  std;

int main() {
	string name;
	string city;
	cout << "your name: ";
	getline(cin, name);

	cout << "your live in: ";
	getline(cin, city);

	cout << endl;
	cout << "hello,My name is: " << name << endl;
	cout << "I live in: " << city << endl;

	system("color A");
	system("pause");
	return 0;
}
//your name : Det Jo
//your live in : Wei nan
//
//hello, My name is : Det Jo
//I live in : Wei nan

//����getline�ĺô��������пո���Ȼ�ܼ������ж�д
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//������ת��ĸ

#include <iostream>
#include <string>

using namespace  std;

class Solution{
public:
	bool Ischar(const char&  ch) {
		return (ch >= 'A' && ch <= 'Z') ||
			(ch >= 'a' && ch <= 'z');
	}

	string reverseChar(string str) {
		int begin = 0;
		int end = str.size() - 1;
		while (begin < end) {

			while (begin < end && !Ischar(str[begin])) {
				++begin;
			}
			while (begin < end && !Ischar(str[end])) {
				--end;
			}
			if (begin < end) {
				swap(str[begin], str[end]);
				++begin;
				--end;
			}
		}
		return str;
	}
};

int main() {
	Solution  S;
	string s;
	getline(cin, s);
	cout << S.reverseChar(s) << endl;

	system("color A");
	system("pause");
	return 0;
}
//��֤һ���ַ����ǲ��ǻ�����


#include <iostream>
#include <string>
using namespace  std;

class Solution {
public:

	bool IsnumberOrchar(char ch) {
		return (ch >= 'A' && ch <= 'Z') ||
			(ch <= 'z' && ch >= 'a') ||
			('0' <= ch <= '9');

	}
	bool reverseChar(string s) {
		for (char& ch : s) {
			if (ch >= 'A' && ch <= 'Z')
				ch += 'a' - 'A';
		}
		int begin = 0;
		int end = s.size() - 1;
		while (begin < end) {

			while (begin < end && !IsnumberOrchar(s[begin]))
				++begin;

			while (begin < end && !IsnumberOrchar(s[end]))
				--end;
			if (s[begin] != s[end])  {
				return false;
			}
			else {
				++begin;
				--end;
			}
		}
		return true;
	}
};

int main() {
	Solution S;
	string s;
	getline(cin, s);
	cout << S.reverseChar(s) << endl;


	system("color A");
	system("pause");
	return 0;
}
//�ҳ��ַ�����ֻ����һ�ε��ַ�

#include <iostream>
#include <string>

using namespace  std;

class Solution {

public:
	char firstChar(string str) {
		int cout[256] = { 0 };
		for (char& ch : str) {
			cout[ch]++;
		}
		/*	for (int i = 0; i < str.size();i++) {
		cout[str[i]]++;
		}*/
		for (int i = 0; i < str.size(); i++) {
			if (1 == cout[str[i]])
				return str[i];

		}
	}
};

int main() {

	Solution S;
	string s;
	getline(cin, s);
	cout << S.firstChar(s) << endl;

	system("color A");
	system("pause");
	return 0;
}

