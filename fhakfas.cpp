//���ַ����е�һ��ֻ����һ�ε�����

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <string>
#include <iostream>
using namespace  std;

//�ҳ��ַ����е�һ��ֻ����һ�ε��ַ�
void find_char(string str) {
	char s; //��һ�γ��ֵ��ַ�
	int count[256] = { 0 };//�洢�����ַ����ֵĴ���
	for (auto& ch : str) { // ����ÿһ���ַ���
		count[ch]++;//����һ�Σ��ͼ�һ
	}
	for (int i = 0; i < str.size(); i++) { //ͳ��ÿһ���ַ������ֵĴ���
		if (count[str[i]] == 1) {
			s = str[i];
			break; //����ѭ���������ظ���ֵ������¼��һ��ֻ����һ�ε��ַ�
		}
	}

	if (s != NULL) {  //���粻����NULL֤�����ڸ��ַ� 
		cout << s << endl;
	}
	else {
		cout << -1 << endl;
	}

}


int main() {
	//����һ���ַ���
	string str;
	while (getline(cin, str)) { //���ϳ����������ַ���
		find_char(str); //���ò����ַ�����
	}
	return 0;
}