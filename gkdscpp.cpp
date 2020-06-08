//字符串里最后一个单词的长度
#include <iostream>
#include <string>
using namespace std;

int main() {
	string line;
	while (getline(cin, line)) {
		size_t pos = line.rfind(' ');
		cout << line.size() - pos - 1 << endl;
	}
	system("pause");
	return 0;
}
//*****************************************************************************************
#include <iostream>
#include <string>
using namespace std;

int main() {
	string line;
	getline(cin, line);
	size_t pos = line.rfind(' ');
	if (pos == string::npos) {
		cout << line.size() << endl;
	}
	else{
		cout << line.size() - pos - 1 << endl;
	}
	system("pause");
	return 0;
}







