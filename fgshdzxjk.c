//void swap(char *s, int i, int j){
//	char t = s[i];
//	s[i] = s[j];
//	s[j] = t;
//}
//void reverse(char *s, int lo, int hi){
//	for (; lo < hi; lo++, hi--){
//		swap(s, lo, hi);
//	}
//}
//char* reverseLeftWords(char* s, int n){
//	int len = 0;
//	for (; s[len] != '\0';);
//	n %= len;
//
//	reverse(s, 0, len - 1);
//	reverse(s, 0, len - n - 1);
//	reverse(s, len - n, len - 1);
//	return s;
//}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Swap(char str[], int left, int right) {
	char tmp = str[left];
	str[left] = str[right];
	str[right] = tmp;
}

void reverse(char* str, int start, int end) {//���ú��� 
	for (; start < end; start++, end--) {
		Swap(str, start, end);
	}
	
}

void Exchange(char* strChar, int n) {
	///*int len = 0;
	//for (; strChar[len] != '\0';)
	//n %= len;*/
	int len = strlen(strChar);
	reverse(strChar, 0, len - 1);
	reverse(strChar, 0, len - n - 1);
	reverse(strChar, len - n, len - 1);

}

int main() {
	
	int leng;
	printf("������Ҫ���������ַ�\n");
	scanf("%d", &leng);
	char str[] = "ABCDEFG";
	Exchange(str, leng);

	printf("%s\n", str);

	system("color A");
	system("pause");
	return 0;
}

//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//void reverse(char *left, char *right)//���ú���
//{
//	char temp;
//	while (left < right)
//	{
//		temp = *left;
//		*left = *right;
//		*right = temp;
//		left++; right--;
//	}
//}
//void Exchange(char *str, int leng)//��������
//{
//	reverse(str, str + leng - 1); //
//	reverse(str + leng, str + strlen(str) - 1);
//	reverse(str, str + strlen(str) - 1);
//}
//
//int main()
//{
//	int leng;
//	printf("������Ҫ���������ַ�\n");
//	scanf("%d", &leng);
//	char str[] = "ABCDEFG";
//	Exchange(str, leng);
//
//	printf("%s\n", str);
//	system("pause");
//	return 0;
//}

//ʵ���ַ���������
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
////����ת�ǴӺ���ǰ�����ƶ�
//void rightRomateone(char str[], int len) {
//	int tmp = str[len-1];
//	for (int i = len-2; i >=0; i--) {
//		str[i + 1] = str[i];
//	}
//	str[0] = tmp;
//}
//
//void PrintStr(char str[], int len) {
//	for (int i = 0; i < len; i++) {
//		printf("%c", str[i]);
//	}
//	printf("\n");
//}
//
//int main() {
//	//AABCD����һ���ַ��õ�DAABC
//	char str[] = "AABCD";
//	//char str2[] = "BCDAA";
//	int len = strlen(str);
//	rightRomateone(str, len);
//	PrintStr(str, len);
//
//	system("color A");
//	system("pause");
//	return 0;
//}

//ʵ���ַ�����ת����
//����ǰ�����ƶ�
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//void leftRomateone(char str[], int len) {
//	int tmp = str[0];
//	for (int i = 1; i < len; i++) {
//		str[i - 1] = str[i];
//	}
//	str[len - 1] = tmp;
//}
//
//void PrintStr(char str[], int len) {
//	for (int i = 0; i < len; i++) {
//		printf("%c", str[i]);
//	}
//	printf("\n");
//}
//
//int main() {
//
//	char str[] = "AABCD";
//	//char str2[] = "BCDAA";
//	int len = strlen(str);
//	leftRomateone(str, len);
//	PrintStr(str, len);
//
//	system("color A");
//	system("pause");
//	return 0;
//}



//дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//���磺����s1 = AABCD��s2 = BCDAA������1

//����s1 = abcd��s2 = ACBD������0.
//AABCD����һ���ַ��õ�ABCDA
//AABCD���������ַ��õ�BCDAA
//AABCD����һ���ַ��õ�DAABC
//
//

//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//
//void leftRotateone(char str[], int len){
//	char tmp = str[0];
//	for (int i = 1; i < len; i++){
//		str[i - 1] = str[i];
//	}
//	str[len - 1] = tmp;
//}
//
//int  RotateCmp(char str1[], char str2[]) {
//	int len1 = strlen(str1);
//	int len2 = strlen(str2);
//	if (len2 != len2) {
//		return 0;
//	}
//	for (int i = 0; i < len1;i++) {
//		if (strcmp(str1, str2) == 0) {
//			return 1;
//		}
//		else {
//			leftRotateone(str1, len1);
//		}
//	}
//}
//
//int main(){
//	char str1[] = "AABCD";
//	char str2[] = "BCDAA";
//	printf("%d\n", RotateCmp(str1, str2));
//	
//	system("pause");
//	return 0;
//}

//