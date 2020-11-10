#include <stdio.h>
#include <stdlib.h>

int main() {
	int arr[10][10] = { 0 };

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || i == j) {
				arr[i][j] = 1;
			}
			else {
				arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j <= i; j++) {
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}

//杨辉三角

//class Solution {
//public:
//	vector<vector<int>> generate(int numRows) {
//		vector<vector<int>> Mat; //申请一数组变量
//		Mat.resize(numRows); //申请行数的空间大小
//		for (int i = 0; i < numRows; i++) {
//			Mat[i].resize(i + 1); // 申请列的空间个数 防止空间越界
//			for (int j = 0; j <= i; j++) {
//				if (j == 0 || i == j) {
//					Mat[i][j] = 1;
//				}
//				else{
//					Mat[i][j] = Mat[i - 1][j] + Mat[i - 1][j - 1];
//				}
//			}
//		}
//		return Mat;
//	}
//};

