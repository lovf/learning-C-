//�ҵ�ֻ����һ�ε�����

//����1. for+operator[]
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
//����2:��Χfor
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








