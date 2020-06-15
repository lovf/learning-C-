//找到只出现一次的数字

//方法1. for+operator[]
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//     int result=0;
//      for(int i=0;i<nums.size();i++) {
//       result ^= nums.operator[](i);

//      }
//     return result;
//     }
// };
//方法2:范围for
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int result = 0;
		for (auto e : nums) {
			result ^= e;
		}
		return result;
	}
};
//








