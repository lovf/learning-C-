//二叉搜索树----一般情况等于跟节点就不存放
//二叉搜索树又称为二叉排序树具有以下性质:
//1.若它的左子树不为空,则左子树上的所有节点的值都小于根节点的值
//2.若它的右子树不为空,则右字树上的所有节点的值都大于根节点的值
//3.它的左右子树也分别为二叉搜索树

//1.实现的操作:
//1>搜索查找------接近二分的查找(与树的特点相关)------平均查找次数(logn)
//2>插入:如果树中已经存在需要插入的数据,则不重复插入
//插入的位置:叶子,子树不完全的非叶子节点(度为0和度为1的节点)

//3>删除操作

//左子树:左子树的最右节点是所有左子树中最大的节点
//右子树:右子树的最左节点是所有右子树中最小的节点


//删除度为2的节点:
//  1.找到此节点中左子树的最右节点或者右子树的最左节点
//  2.要删除的节点val替换成最左节点或者左右节点的val
//  3.真正需要删除的为最左或者最右节点-------转换成删除度为0或者度为1的节点
//二叉搜索树------中序遍历有序(左-->根--->右)--得到递增顺序

//4>.拷贝操作-----------进行深拷贝
//跟二叉树的深度一样-----------------------------------------------------------------------------------------------
//#include <string>
//#include <iostream>
//using namespace std;
//
//template<class T>
//struct BSTNode{
//
//	T _val; //节点
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
//	typedef BSTNode<T> Node;//BSTNode<T>类名+类型-----
//	//查找一个数值
//	//1>搜索查找------接近二分的查找(与树的特点相关)------平均查找次数(logn)
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
//	//2>插入:如果树中已经存在需要插入的数据,则不重复插入-------不破坏已有的链接,改变新的连接关系
//	//插入的位置:叶子,子树不完全的非叶子节点(度为0和度为1的节点)
//
//	bool insert(const T& val) {
//		if (_root == nullptr) {
//			_root = new Node(val);
//			return true;
//		}
//
//		Node* cur = _root;//当前的根节点
//		Node* parent = nullptr;//上一个节点需要记录走的路径----刚开始处于空指针的位置
//		//1.先查找空的插入的位置
//		while (cur) { //先找到空的位置
//			parent = cur;
//			if (cur->_val == val)
//				return false;
//			else if (cur->_val < val)
//				cur = cur->_right;
//			else
//				cur = cur->_left;
//		}
//		//2.进行数据的插入
//		//上一步循环结束的时候cur==nullptr
//		//此时创造新的节点
//		cur = new Node(val);
//		//判断放到parent的那一边
//		if (parent->_val < val)
//			parent->_right = cur;
//		else
//			parent->_left = cur;
//		return true;
//	}
//	//删除操作-------存在删除4种情况的值
//	//----直接删除会破坏结构,因此找一个可以替代当前情况的点
//	bool erase(const T& val) {
//		//查找
//		Node* cur = _root;//当前的根节点
//		Node* parent = nullptr;//上一个节点需要记录走的路径----刚开始处于空指针的位置
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
//	//判断是否找到了需要删除的节点
//		if (cur == nullptr)
//			return false;
//	//删除
//		//1.叶子 度为0的节点
//		if (cur->_left == nullptr && cur->_right == nullptr) {
//
//			if (cur == _root) { //特殊情况,只有一个节点
//				//如果是根节点,更新根节点
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
//		else if (cur->_left == nullptr) { //2.删除度为1 的节点
//		//2.左孩子为空,只有右子树
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
//		//3.右孩子为空,只有左子树
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
//		//4.左右孩子都存在
//			//a.找最左或者最右节点
//			//找右子树的左节点
//			Node* leftMostChild = cur->_right;
//			Node* parent = cur;
//			while (leftMostChild->_left) {
//				parent = leftMostChild;
//				leftMostChild = leftMostChild->_left;
//			}
//			//b.值替换
//			cur->_val = leftMostChild->_val;
//			//c.删除最左或者最右节点 
//			if (parent->_left == leftMostChild)
//				parent->_left = leftMostChild->_right;
//			else 
//			parent->_right = leftMostChild->_right;
//			delete leftMostChild;
//		}
//		return true;
//	}
//	//中序遍历====递归实现
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
//	//销毁操作
//	void destory(Node* root) {
//		if (root) {
//			destory(root->_left);
//			destory(root->_right);
//			delete root;
//		}
//	}
//	//析构函数----
//	~BSTree() {
//		destory(_root);
//	}
//	////拷贝1
//	//void copyTree(Node* root) { //遍历的过程走一个插入的过程
//	//	if (root){
//	//		insert(root->_val);
//	//		copyTree(root->_left);
//	//		copyTree(root->_right);
//	//	}
//	//}
//	//拷贝2-------拷贝2逻辑上比拷贝1更简单一点
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
//	//默认构造
//	BSTree() 
//		:_root(nullptr)
//	{}
//
//	//拷贝构造
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

//二叉搜索树应用----------------------------------------------------------------------------------------------------------------
//二叉搜索树明显的缺点-------由于插入数字的顺序不同产生的也会不相同
#include <string>
#include <string>
#include <iostream>
using namespace std;

template<class K, class V>//里面的K相当于索引
struct BSTNode{
	K _key;//K相当于索引
	V _val; //节点
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
	typedef BSTNode<K, V> Node;//BSTNode<T>类名+类型-----
	//查找一个数值
	//1>搜索查找------接近二分的查找(与树的特点相关)------平均查找次数(logn)
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

	//2>插入:如果树中已经存在需要插入的数据,则不重复插入-------不破坏已有的链接,改变新的连接关系
	//插入的位置:叶子,子树不完全的非叶子节点(度为0和度为1的节点)

	bool insert(const K& key, const V& val) {
		if (_root == nullptr) {
			_root = new Node(key, val);
			return true;
		}
		Node* cur = _root;//当前的根节点
		Node* parent = nullptr;//上一个节点需要记录走的路径----刚开始处于空指针的位置
		//1.先查找空的插入的位置
		while (cur) { //先找到空的位置
			parent = cur;
			if (cur->_key == key)
				return false;
			else if (cur->_key < key)
				cur = cur->_right;
			else
				cur = cur->_left;
		}
		//2.进行数据的插入
		//上一步循环结束的时候cur==nullptr
		//此时创造新的节点
		cur = new Node(key, val);
		//判断放到parent的那一边
		if (parent->_key < key)
			parent->_right = cur;
		else
			parent->_left = cur;
		return true;
	}
	//删除操作-------存在删除4种情况的值
	//----直接删除会破坏结构,因此找一个可以替代当前情况的点
	bool erase(const K& key) {
		//查找
		Node* cur = _root;//当前的根节点
		Node* parent = nullptr;//上一个节点需要记录走的路径----刚开始处于空指针的位置
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
		//判断是否找到了需要删除的节点
		if (cur == nullptr)
			return false;
		//删除
		//1.叶子 度为0的节点
		if (cur->_left == nullptr && cur->_right == nullptr) {

			if (cur == _root) { //特殊情况,只有一个节点
				//如果是根节点,更新根节点
				_root = nullptr;
			}

			if (parent->_left == cur)
				parent->_left = nullptr;
			else
				parent->_right = nullptr;

			delete cur;
		}
		else if (cur->_left == nullptr) { //2.删除度为1 的节点
			//2.左孩子为空,只有右子树
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
			//3.右孩子为空,只有左子树
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
			//4.左右孩子都存在
			//a.找最左或者最右节点
			//找右子树的左节点
			Node* leftMostChild = cur->_right;
			Node* parent = cur;
			while (leftMostChild->_left) {
				parent = leftMostChild;
				leftMostChild = leftMostChild->_left;
			}
			//b.值替换
			cur->_val = leftMostChild->_val;
			//c.删除最左或者最右节点 
			if (parent->_left == leftMostChild)
				parent->_left = leftMostChild->_right;
			else
				parent->_right = leftMostChild->_right;
			delete leftMostChild;
		}
		return true;
	}
	//中序遍历====递归实现
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
	//销毁操作
	void destory(Node* root) {
		if (root) {
			destory(root->_left);
			destory(root->_right);
			delete root;
		}
	}
	//析构函数----
	~BSTree() {
		destory(_root);
	}
	////拷贝1
	void copyTree(Node* root) { //遍历的过程走一个插入的过程
		if (root){
			insert(root->_key, root->_val);
			copyTree(root->_left);
			copyTree(root->_right);
		}
	}
	////拷贝2-------拷贝2逻辑上比拷贝1更简单一点
	//Node* copyTree(Node* root) {
	//	if (root){
	//		Node* cur = new Node(root->_key, root->_val);
	//		cur->_left = copyTree(root->_left);
	//		cur->_right = copyTree(root->_right);
	//		return cur;
	//	}
	//	return nullptr;
	//}

	//默认构造
	BSTree()
		:_root(nullptr)
	{}

	//拷贝构造
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
	bool ret = bst.insert(8, "eight");//插入失败,因为Key的值已经存在
	cout << ret << endl;
	bst.inorder();

	BSTree<int, string> copy(bst);
	bst.inorder();
}

void test2() {
	//二叉搜索树明显的缺点-------由于插入数字的顺序不同产生的也会不相同
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
	bool ret = bst.insert(8, "eight");//插入失败,因为Key的值已经存在
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

