/*��ת�ַ���
��дһ���������������ǽ�������ַ�����ת�����������ַ������ַ����� char[] ����ʽ������

��Ҫ�����������������Ŀռ䣬�����ԭ���޸��������顢ʹ�� O(1) �Ķ���ռ�����һ���⡣

����Լ��������е������ַ����� ASCII ����еĿɴ�ӡ�ַ���*/

//��1:���ÿ��еĺ���
 class Solution {
 public:
     void reverseString(vector<char>& s) {
        return reverse(s.begin(),s.end()); 
     }
 };
//��2.
 class Solution {
 public:
     void reverseString(vector<char>& s) { 
     for (int i = 0;i < s.size()/2;i++) {
       char temp = s[i];
       s[i] = s[s.size() - i - 1 ];
       s[s.size() - 1 - i] = temp;
        }
     }
 };
 //*****************************************************************************************************************************************
//��3.˫ָ�룬����ͷβ����ָ����ָ������λ�õ�ֵ��ָ�����м��ƶ�һ��λ�ã��ظ����ϲ�����ֱ������ָ�뽻��
 class Solution {
 public:
   void reverseString(vector<char>& s) {
   int begin=0;
   int end= s.size()-1;
     while (begin < end) {
       swap(s[begin],s[end]);
       ++begin;
       --end;
     } 
   }
 };

















