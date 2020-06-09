//��֤���Ĵ�
//����һ���ַ�������֤���Ƿ��ǻ��Ĵ���ֻ������ĸ�������ַ������Ժ�����ĸ�Ĵ�Сд��
//
//˵���������У����ǽ����ַ�������Ϊ��Ч�Ļ��Ĵ���
//
//ʾ�� 1:
//
//���� : "A man, a plan, a canal: Panama"
//��� : true
//	 ʾ�� 2 :
//
// ���� : "race a car"
//  ��� : false

class Solution {
public:
	bool isNumber(const char& ch) {
		return  (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z');
	}

	bool isPalindrome(string s) {
		if (s.empty())
			return true;
		//Ԥ����:��Сд��ĸת��)(��תС)
		for (char& ch : s) {
			if (ch >= 'A' && ch <= 'Z')
				ch += 32;
		}
		int begin = 0;
		int end = s.size() - 1;
		while (begin < end) {
			//���粻�����ֺ�Сд�ַ�,ֱ����������Ծ
			while (begin < end &&  !isNumber(s[begin]))
				++begin;
			while (begin < end &&  !isNumber(s[end]))
				--end;
			if (begin < end) {
				while (s[begin] != s[end])
					return false;
				++begin;
				--end;
			}
		}
		return true;
	}
};
//*****************************************************************************************************************************************
class Solution {
public:
	bool isNumber(const char& ch) {
		return  (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z');
	}

	bool isPalindrome(string s) {
		if (s.empty())
			return true;
		//Ԥ����:��Сд��ĸת��)(��תС)     
		for (char& ch : s) {
			if (ch >= 'A' && ch <= 'Z')
				ch += 32;
		}
		int begin = 0;
		int end = s.size() - 1;
		while (begin < end) {
			//���粻�����ֺ�Сд�ַ�,ֱ����������Ծ
			while (begin < end &&  !isNumber(s[begin]))
				++begin;
			while (begin < end &&  !isNumber(s[end]))
				--end;
			if (s[begin] != s[end]) {
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








