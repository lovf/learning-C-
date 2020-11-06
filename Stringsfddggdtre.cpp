//String���ģ��ʵ����ϰ
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace  std;

class String{
public:

	////�޲ι���
	//String(char* str=" ") 
	//	:_ptr(new char[strlen(str)+1])
	//
	//{
	//	strcpy(_ptr, str);
	//}
	//���ο������쿽��
	String(char* str)
		:_ptr(new char[strlen(str) + 1])

	{
		strcpy(_ptr, str);
	}

	////�������� ��ͳ
	//String(String& str) 
	//	:_ptr(new char[strlen(str._ptr)+1])
	//{
	//	strcpy(_ptr, str._ptr);
	//}
	//�������� �ִ�д��
	String(String& str) 
		:_ptr(nullptr)
	{
		String tmp(str._ptr);
		swap(_ptr, tmp._ptr);
	}

	//////��ֵ���������  ��ͳ
	//String& operator=(String& str){
	//	if (this != &str) {
	//	//1.���ռ�
	//		char* tmp = new char[strlen(str._ptr) + 1];
	//	//2.����
	//		strcpy(tmp, str._ptr);
	//	//3.�ͷ�ԭ�пռ�
	//		delete[] _ptr;
	//	//����
	//		_ptr = tmp;
	//	
	//	}
	//	return *this;
	//}
	//��ֵ���������  �ִ�
	String& operator=(String& str) {
		swap(_ptr, str._ptr);
		return *this;
	}

	//��������
	~String(){
		if (_ptr) {
			delete[] _ptr;
			_ptr = nullptr;
		}
	
	}

private:
	char* _ptr;
};

void test1() {
	String s1 = "1234";
	String s2 = "6789";

	String s3(s1);
	cout << "��������" << endl;
	s1 = s2;
	cout << "��ֵ���������" << endl;

}

int main () {


	test1();
    system("color A");
    system ("pause");
    return 0;
}
// class Solution {
// public:
//     int firstUniqChar(string s) {
//     int cout[1024]={0};
//     for(const auto& ch : s ) {
//     cout[ch]++;
//     }
//     for (int i=0;i<s.size();i++) {

//     if (cout[s[i]] == 1)
//     return i;
//     }
//     return -1;
//   }   
// };
// class Solution {
// public:
//    int firstUniqChar(string s) {
//       int cout[218]={0};
//       for (int i=0;i<s.size();i++) {
//         cout[s[i]]++;
//       }
//       for (int i=0;i<s.size();i++) {
//         if (cout[s[i]] == 1) {
//         return i;
//         }
//       }
//       return -1;
//      }
// };
// class Solution {
// public:
//    int firstUniqChar(string s) {
//       int cout[218]={0};
//       for (const auto& ch:s) {
//         cout[ch-'a']++;
//       }
//       for (int i=0;i<s.size();i++) {
//         if (cout[s[i] - 'a'] == 1) {
//         return i;
//         }
//       }
//       return -1;
//      }
// };

