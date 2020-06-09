//验证回文串
//给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
//
//说明：本题中，我们将空字符串定义为有效的回文串。
//
//示例 1:
//
//输入 : "A man, a plan, a canal: Panama"
//输出 : true
//	 示例 2 :
//
// 输入 : "race a car"
//  输出 : false

class Solution {
public:
	bool isNumber(const char& ch) {
		return  (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z');
	}

	bool isPalindrome(string s) {
		if (s.empty())
			return true;
		//预处理:大小写字母转换)(大转小)
		for (char& ch : s) {
			if (ch >= 'A' && ch <= 'Z')
				ch += 32;
		}
		int begin = 0;
		int end = s.size() - 1;
		while (begin < end) {
			//假如不是数字和小写字符,直接往后面跳跃
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
		//预处理:大小写字母转换)(大转小)     
		for (char& ch : s) {
			if (ch >= 'A' && ch <= 'Z')
				ch += 32;
		}
		int begin = 0;
		int end = s.size() - 1;
		while (begin < end) {
			//假如不是数字和小写字符,直接往后面跳跃
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








