#include <iostream>
#include <string>
using namespace std;

typedef struct Node{
	struct Node* left;
	struct Node* right;
	char val;
	Node(char x)
		:val(x)
		,left(NULL)
		,right(NULL)
	{}

}Node;

//�������Ĵ���: 
string str;
Node* BinaryTreeCreat(int* idx) {
	if (str[*idx] != '#') {
		Node* root = new Node(str[*idx]); //ǰ�����
		++(*idx);
		root->left = BinaryTreeCreat(idx);
		++(*idx);
		root->right = BinaryTreeCreat(idx);
		return root;
	}
	else
		return NULL;
}

//�������������
void _inOrderTree(Node* root) {
	if (root) {
		_inOrderTree(root->left);
		cout << root->val << " ";
		_inOrderTree(root->right);
	}
}
int main() {
	while (cin >> str) {
		int idx = 0;
		Node* root = BinaryTreeCreat(&idx);
		_inOrderTree(root);
	}
	system("pause");
	return 0;
}