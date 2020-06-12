//vector µÄÊ¹ÓÃ

#include <iostream>
#include <vector>
using namespace std;



int main() {
	vector<int>v1(10,5);
	for (int i = 0; i < v1.size();i++) {
		cout << v1.operator[](i) << endl;
	
	}
	system("pause");
	return 0;
}
