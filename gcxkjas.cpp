/*反转字符串
编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。

不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。

你可以假设数组中的所有字符都是 ASCII 码表中的可打印字符。*/

//法1:调用库中的函数
 class Solution {
 public:
     void reverseString(vector<char>& s) {
        return reverse(s.begin(),s.end()); 
     }
 };
//法2.
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
//法3.双指针，交换头尾两个指针所指的两个位置的值，指针向中间移动一个位置，重复以上操作，直到两个指针交错；
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

















