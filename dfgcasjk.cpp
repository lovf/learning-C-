// 字符串里面最后一个单词的长度
#include <iostream>
#include <string> 
using namespace  std;

int main() {
	string str;
	getline(cin, str);
	size_t pos = str.rfind(' ');//从后想向前找第一个出现空格的位置
	if (pos == string::npos)   //假如等于 pos == string::npos 说明不存在空格
		cout << str.size() << endl;
	else {
		cout << str.size() - 1 - pos << endl;
	}

	system("color A");
	system("pause");
	return 0;
}

//虽然可以使用 cin 和 >> 运算符来输入字符串，但它可能会导致一些需要注意的问题。
//当cin读取数据时,它会传递并忽略任何前导白色空格字符(空格,制表符或者换行).一旦它接触到第一个非空格字符即开始阅读，
//当它读取到下一个空白字符时，它将停止读取。以下面的语句为例：

#include <iostream>
#include <string> 
using namespace std;

int main() {
	string name;
	string city;
	cout << "Please enter your name: ";
	cin >> name; //当输入的内容有空格式会停止继续读,

	cout << "Enter the city you live in: ";
	cin >> city;

	cout << "Hello, " << name << endl;
	cout << "You live in " << city << endl;
	system("color A");
	system("pause");
	return 0;
}
//加入有空格之类的 cin 遇到就直接停止读写
//Please enter your name： John Doe
//Enter the city you live in : Hello, John
//You live in Doe
//
//请注意，在这个示例中，用户根本没有机会输入 city 城市名。因为在第一个输入语句中，当 cin 读取到 John 和 Doe 之间的空格时，
//它就会停止阅读，只存储 John 作为 name 的值。在第二个输入语句中， cin 使用键盘缓冲区中找到的剩余字符，并存储 Doe 作为 city 的值。

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

//借助getline的好处是遇到有空格仍然能继续进行读写
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//仅仅反转字母

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
//验证一个字符串是不是回文数


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
//找出字符串中只出现一次的字符

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

