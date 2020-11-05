//找字符串中第一个只出现一次的数字

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <string>
#include <iostream>
using namespace  std;

//找出字符串中第一个只出现一次的字符
void find_char(string str) {
	char s; //第一次出现的字符
	int count[256] = { 0 };//存储各个字符出现的次数
	for (auto& ch : str) { // 遍历每一个字符串
		count[ch]++;//出现一次，就加一
	}
	for (int i = 0; i < str.size(); i++) { //统计每一个字符串出现的次数
		if (count[str[i]] == 1) {
			s = str[i];
			break; //跳出循环，避免重复赋值，仅记录第一个只出现一次的字符
		}
	}

	if (s != NULL) {  //假如不等于NULL证明存在该字符 
		cout << s << endl;
	}
	else {
		cout << -1 << endl;
	}

}


int main() {
	//定义一个字符串
	string str;
	while (getline(cin, str)) { //不断持续的输入字符串
		find_char(str); //调用查找字符函数
	}
	return 0;
}