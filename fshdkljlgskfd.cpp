//����������----һ��������ڸ��ڵ�Ͳ����
//�����������ֳ�Ϊ����������������������:
//1.��������������Ϊ��,���������ϵ����нڵ��ֵ��С�ڸ��ڵ��ֵ
//2.��������������Ϊ��,���������ϵ����нڵ��ֵ�����ڸ��ڵ��ֵ
//3.������������Ҳ�ֱ�Ϊ����������

//1.ʵ�ֵĲ���:
//1>��������------�ӽ����ֵĲ���(�������ص����)------ƽ�����Ҵ���(logn)
//2>����:��������Ѿ�������Ҫ���������,���ظ�����
//�����λ��:Ҷ��,��������ȫ�ķ�Ҷ�ӽڵ�(��Ϊ0�Ͷ�Ϊ1�Ľڵ�)

//3>ɾ������

//������:�����������ҽڵ������������������Ľڵ�
//������:������������ڵ�����������������С�Ľڵ�


//ɾ����Ϊ2�Ľڵ�:
//  1.�ҵ��˽ڵ��������������ҽڵ����������������ڵ�
//  2.Ҫɾ���Ľڵ�val�滻������ڵ�������ҽڵ��val
//  3.������Ҫɾ����Ϊ����������ҽڵ�-------ת����ɾ����Ϊ0���߶�Ϊ1�Ľڵ�
//����������------�����������(��-->��--->��)--�õ�����˳��

//4>.��������-----------�������
//�������������һ��-----------------------------------------------------------------------------------------------
//#include <string>
//#include <iostream>
//using namespace std;
//
//template<class T>
//struct BSTNode{
//
//	T _val; //�ڵ�
//	BSTNode<T>* _left;
//	BSTNode<T>* _right;
//
//	BSTNode(const T& val = T()) 
//		:_val(val)
//		, _left(nullptr)
//		, _right(nullptr)
//	{}
//};
//
//template<class T>
//class BSTree{
//
//public:
//	typedef BSTNode<T> Node;//BSTNode<T>����+����-----
//	//����һ����ֵ
//	//1>��������------�ӽ����ֵĲ���(�������ص����)------ƽ�����Ҵ���(logn)
//	Node* find(const T& val) {
//		Node* cur = _root;
//		while (cur) {
//			if (cur->_val == val)
//				return cur;
//			else if (cur->_val < val)
//				cur = cur ->right;
//			else
//				cur = cur->_left;
//		}
//		return nullptr;
//	}
//
//	//2>����:��������Ѿ�������Ҫ���������,���ظ�����-------���ƻ����е�����,�ı��µ����ӹ�ϵ
//	//�����λ��:Ҷ��,��������ȫ�ķ�Ҷ�ӽڵ�(��Ϊ0�Ͷ�Ϊ1�Ľڵ�)
//
//	bool insert(const T& val) {
//		if (_root == nullptr) {
//			_root = new Node(val);
//			return true;
//		}
//
//		Node* cur = _root;//��ǰ�ĸ��ڵ�
//		Node* parent = nullptr;//��һ���ڵ���Ҫ��¼�ߵ�·��----�տ�ʼ���ڿ�ָ���λ��
//		//1.�Ȳ��ҿյĲ����λ��
//		while (cur) { //���ҵ��յ�λ��
//			parent = cur;
//			if (cur->_val == val)
//				return false;
//			else if (cur->_val < val)
//				cur = cur->_right;
//			else
//				cur = cur->_left;
//		}
//		//2.�������ݵĲ���
//		//��һ��ѭ��������ʱ��cur==nullptr
//		//��ʱ�����µĽڵ�
//		cur = new Node(val);
//		//�жϷŵ�parent����һ��
//		if (parent->_val < val)
//			parent->_right = cur;
//		else
//			parent->_left = cur;
//		return true;
//	}
//	//ɾ������-------����ɾ��4�������ֵ
//	//----ֱ��ɾ�����ƻ��ṹ,�����һ�����������ǰ����ĵ�
//	bool erase(const T& val) {
//		//����
//		Node* cur = _root;//��ǰ�ĸ��ڵ�
//		Node* parent = nullptr;//��һ���ڵ���Ҫ��¼�ߵ�·��----�տ�ʼ���ڿ�ָ���λ��
//		while (cur) { 
//			if (cur->_val == val)
//				break;
//			else if (cur->_val < val) {
//				parent = cur;
//				cur = cur->_right;
//			}
//			else{
//				parent = cur;
//				cur = cur->_left;
//			}
//		}
//	//�ж��Ƿ��ҵ�����Ҫɾ���Ľڵ�
//		if (cur == nullptr)
//			return false;
//	//ɾ��
//		//1.Ҷ�� ��Ϊ0�Ľڵ�
//		if (cur->_left == nullptr && cur->_right == nullptr) {
//
//			if (cur == _root) { //�������,ֻ��һ���ڵ�
//				//����Ǹ��ڵ�,���¸��ڵ�
//				_root = nullptr;
//			}
//
//			if (parent->_left == cur)
//				parent->_left = nullptr;
//			else 
//				parent->_right = nullptr;
//
//			delete cur;
//		}
//		else if (cur->_left == nullptr) { //2.ɾ����Ϊ1 �Ľڵ�
//		//2.����Ϊ��,ֻ��������
//			if (cur == _root) {
//				_root = cur->_right;
//			}
//			else {
//				if (parent->_left == cur)
//					parent->_left = cur->_right;
//				else
//					parent->_right = cur->_right;
//			}
//			delete cur;
//		}
//		else if (cur->_right == nullptr) {
//		//3.�Һ���Ϊ��,ֻ��������
//			if (cur == _root) {
//				_root = cur->_left;
//			}
//			else {
//				if (parent->_left == cur)
//					parent->_left = cur->_left;
//				else
//					parent->_right = cur->_left;
//			}
//			delete cur;
//		}
//		else {
//		//4.���Һ��Ӷ�����
//			//a.������������ҽڵ�
//			//������������ڵ�
//			Node* leftMostChild = cur->_right;
//			Node* parent = cur;
//			while (leftMostChild->_left) {
//				parent = leftMostChild;
//				leftMostChild = leftMostChild->_left;
//			}
//			//b.ֵ�滻
//			cur->_val = leftMostChild->_val;
//			//c.ɾ������������ҽڵ� 
//			if (parent->_left == leftMostChild)
//				parent->_left = leftMostChild->_right;
//			else 
//			parent->_right = leftMostChild->_right;
//			delete leftMostChild;
//		}
//		return true;
//	}
//	//�������====�ݹ�ʵ��
//	void inorder() {
//		_inorder(_root);
//		cout << endl;
//	}
//	void _inorder(Node* root) {
//		if (root) {
//			_inorder(root->_left);
//			cout << root->_val << " ";
//			_inorder(root->_right);
//		}
//	}
//	//���ٲ���
//	void destory(Node* root) {
//		if (root) {
//			destory(root->_left);
//			destory(root->_right);
//			delete root;
//		}
//	}
//	//��������----
//	~BSTree() {
//		destory(_root);
//	}
//	////����1
//	//void copyTree(Node* root) { //�����Ĺ�����һ������Ĺ���
//	//	if (root){
//	//		insert(root->_val);
//	//		copyTree(root->_left);
//	//		copyTree(root->_right);
//	//	}
//	//}
//	//����2-------����2�߼��ϱȿ���1����һ��
//	Node* copyTree(Node* root) { 
//		if (root){
//			Node* cur = new Node(root->_val);
//			cur->_left = copyTree(root->_left);
//			cur->_right = copyTree(root->_right);
//			return cur;
//		}
//		return nullptr;
//	}
//
//	//Ĭ�Ϲ���
//	BSTree() 
//		:_root(nullptr)
//	{}
//
//	//��������
//	BSTree(const BSTree<T>& bst) 
//		:_root(nullptr)
//	{
//		copyTree(bst._root);
//	}
//private:
//	Node* _root = nullptr;
//};
//
//void test1() {
//	BSTree<int> bst;
//	bst.insert(5);
//	bst.insert(3);
//	bst.insert(4);
//	bst.insert(1);
//	bst.insert(2);
//	bst.insert(0);
//	bst.insert(7);
//	bst.insert(6);
//	bst.insert(8);
//	bst.insert(9);
//	bst.inorder();
//
//	bst.erase(0);
//	bst.inorder();
//	bst.erase(8);
//	bst.inorder();
//	bst.erase(3);
//	bst.inorder();
//	bst.erase(2); 
//	bst.inorder();
//	bst.erase(1);
//	bst.inorder();
//	bst.erase(4);
//	bst.inorder();
//	bst.erase(5); 
//	bst.inorder();
//
//}
//void test2() {
//	BSTree<int> bst;
//	bst.insert(5);
//	bst.insert(3);
//	bst.insert(4);
//	bst.insert(1);
//	bst.insert(2);
//	bst.insert(0);
//	bst.insert(7);
//	bst.insert(6);
//	bst.insert(8);
//	bst.insert(9);
//	bst.inorder();
//
//	BSTree<int> copy(bst);
//	bst.inorder();
//}
//int main() {
//	//test1();
//	test2();
//	system("pause");
//	return 0;
//}

//����������Ӧ��----------------------------------------------------------------------------------------------------------------
//�������������Ե�ȱ��-------���ڲ������ֵ�˳��ͬ������Ҳ�᲻��ͬ
#include <string>
#include <string>
#include <iostream>
using namespace std;

template<class K, class V>//�����K�൱������
struct BSTNode{
	K _key;//K�൱������
	V _val; //�ڵ�
	BSTNode<K, V>* _left;
	BSTNode<K, V>* _right;

	BSTNode(const K& key = K(), const V& val = V())
		:_key(key)
		, _val(val)
		, _left(nullptr)
		, _right(nullptr)
	{}
};

template<class K, class V>
class BSTree{

public:
	typedef BSTNode<K, V> Node;//BSTNode<T>����+����-----
	//����һ����ֵ
	//1>��������------�ӽ����ֵĲ���(�������ص����)------ƽ�����Ҵ���(logn)
	Node* find(const K& key) {
		Node* cur = _root;
		while (cur) {
			if (cur->_key == key)
				return cur;
			else if (cur->_key < key)
				cur = cur->right;
			else
				cur = cur->_left;
		}
		return nullptr;
	}

	//2>����:��������Ѿ�������Ҫ���������,���ظ�����-------���ƻ����е�����,�ı��µ����ӹ�ϵ
	//�����λ��:Ҷ��,��������ȫ�ķ�Ҷ�ӽڵ�(��Ϊ0�Ͷ�Ϊ1�Ľڵ�)

	bool insert(const K& key, const V& val) {
		if (_root == nullptr) {
			_root = new Node(key, val);
			return true;
		}
		Node* cur = _root;//��ǰ�ĸ��ڵ�
		Node* parent = nullptr;//��һ���ڵ���Ҫ��¼�ߵ�·��----�տ�ʼ���ڿ�ָ���λ��
		//1.�Ȳ��ҿյĲ����λ��
		while (cur) { //���ҵ��յ�λ��
			parent = cur;
			if (cur->_key == key)
				return false;
			else if (cur->_key < key)
				cur = cur->_right;
			else
				cur = cur->_left;
		}
		//2.�������ݵĲ���
		//��һ��ѭ��������ʱ��cur==nullptr
		//��ʱ�����µĽڵ�
		cur = new Node(key, val);
		//�жϷŵ�parent����һ��
		if (parent->_key < key)
			parent->_right = cur;
		else
			parent->_left = cur;
		return true;
	}
	//ɾ������-------����ɾ��4�������ֵ
	//----ֱ��ɾ�����ƻ��ṹ,�����һ�����������ǰ����ĵ�
	bool erase(const K& key) {
		//����
		Node* cur = _root;//��ǰ�ĸ��ڵ�
		Node* parent = nullptr;//��һ���ڵ���Ҫ��¼�ߵ�·��----�տ�ʼ���ڿ�ָ���λ��
		while (cur) {
			if (cur->_key == key)
				break;
			else if (cur->_key < key) {
				parent = cur;
				cur = cur->_right;
			}
			else{
				parent = cur;
				cur = cur->_left;
			}
		}
		//�ж��Ƿ��ҵ�����Ҫɾ���Ľڵ�
		if (cur == nullptr)
			return false;
		//ɾ��
		//1.Ҷ�� ��Ϊ0�Ľڵ�
		if (cur->_left == nullptr && cur->_right == nullptr) {

			if (cur == _root) { //�������,ֻ��һ���ڵ�
				//����Ǹ��ڵ�,���¸��ڵ�
				_root = nullptr;
			}

			if (parent->_left == cur)
				parent->_left = nullptr;
			else
				parent->_right = nullptr;

			delete cur;
		}
		else if (cur->_left == nullptr) { //2.ɾ����Ϊ1 �Ľڵ�
			//2.����Ϊ��,ֻ��������
			if (cur == _root) {
				_root = cur->_right;
			}
			else {
				if (parent->_left == cur)
					parent->_left = cur->_right;
				else
					parent->_right = cur->_right;
			}
			delete cur;
		}
		else if (cur->_right == nullptr) {
			//3.�Һ���Ϊ��,ֻ��������
			if (cur == _root) {
				_root = cur->_left;
			}
			else {
				if (parent->_left == cur)
					parent->_left = cur->_left;
				else
					parent->_right = cur->_left;
			}
			delete cur;
		}
		else {
			//4.���Һ��Ӷ�����
			//a.������������ҽڵ�
			//������������ڵ�
			Node* leftMostChild = cur->_right;
			Node* parent = cur;
			while (leftMostChild->_left) {
				parent = leftMostChild;
				leftMostChild = leftMostChild->_left;
			}
			//b.ֵ�滻
			cur->_val = leftMostChild->_val;
			//c.ɾ������������ҽڵ� 
			if (parent->_left == leftMostChild)
				parent->_left = leftMostChild->_right;
			else
				parent->_right = leftMostChild->_right;
			delete leftMostChild;
		}
		return true;
	}
	//�������====�ݹ�ʵ��
	void inorder() {
		_inorder(_root);
		cout << endl;
	}
	void _inorder(Node* root) {
		if (root) {
			_inorder(root->_left);
			cout << root->_key << "-->" << root->_val << " ";
			_inorder(root->_right);
		}
	}
	//���ٲ���
	void destory(Node* root) {
		if (root) {
			destory(root->_left);
			destory(root->_right);
			delete root;
		}
	}
	//��������----
	~BSTree() {
		destory(_root);
	}
	////����1
	void copyTree(Node* root) { //�����Ĺ�����һ������Ĺ���
		if (root){
			insert(root->_key, root->_val);
			copyTree(root->_left);
			copyTree(root->_right);
		}
	}
	////����2-------����2�߼��ϱȿ���1����һ��
	//Node* copyTree(Node* root) {
	//	if (root){
	//		Node* cur = new Node(root->_key, root->_val);
	//		cur->_left = copyTree(root->_left);
	//		cur->_right = copyTree(root->_right);
	//		return cur;
	//	}
	//	return nullptr;
	//}

	//Ĭ�Ϲ���
	BSTree()
		:_root(nullptr)
	{}

	//��������
	BSTree(const BSTree<K, V>& bst)
		:_root(nullptr)
	{
		copyTree(bst._root);
	}
private:
	Node* _root = nullptr;
};

void test1() {
	BSTree<int, string> bst;
	bst.insert(5, "five");
	bst.insert(3, "three");
	bst.insert(4, "four");
	bst.insert(1, "one");
	bst.insert(2, "two");
	bst.insert(0, "zero");
	bst.insert(7, "seven");
	bst.insert(6, "two");
	bst.insert(8, "one");
	bst.insert(9, "nine");
	bool ret = bst.insert(8, "eight");//����ʧ��,��ΪKey��ֵ�Ѿ�����
	cout << ret << endl;
	bst.inorder();

	BSTree<int, string> copy(bst);
	bst.inorder();
}

void test2() {
	//�������������Ե�ȱ��-------���ڲ������ֵ�˳��ͬ������Ҳ�᲻��ͬ
	BSTree<int, string> bst;
	bst.insert(0, "zero");
	bst.insert(1, "one");
	bst.insert(2, "two");
	bst.insert(3, "three");
	bst.insert(4, "four");
	bst.insert(5, "five");
	bst.insert(6, "two");
	bst.insert(7, "seven");
	bst.insert(8, "one");
	bst.insert(9, "nine");
	bool ret = bst.insert(8, "eight");//����ʧ��,��ΪKey��ֵ�Ѿ�����
	cout << ret << endl;
	bst.inorder();

	BSTree<int, string> copy(bst);
	bst.inorder();
}
int main() {
	//test1();
	test2();
	system("pause");
	return 0;
}

