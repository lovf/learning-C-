//红黑树:
//1.根是黑色的
//2.每一个节点不是红色就是黑色
//3.如果一个节点是红色的,则它的两个孩子的节点是黑色的
//4.红色不能连续,黑色可以连续
//5.每一条路径上,黑色节点个数相同
//6.最长路径是最短路径的两倍   最长:红黑相间  最短:全黑

#include<utility>
#include <iostream>
using namespace std;

enum Color{  //利用枚举来代表红黑颜色
	BLACK,
	RED
};

template<class K, class V>

struct RBNode{
	pair<K, V> _value;
	Color _color; //节点颜色
	RBNode<K, V>* _parent;
	RBNode<K, V>* _left;
	RBNode<K, V>* _right;

	RBNode(const pair<K, V>& value = pair<K, V>())
		:_value(value)
		, _color(RED)
		, _parent(nullptr)
		, _left(nullptr)
		, _right(nullptr)
	{}
};

template<class K, class V>
class RBTree{
public:
	typedef RBNode<K, V> Node;
	//创建空节点
	RBTree()
		:_header(new Node)

	{
		_header->_left = _header->_right = _header;
	}

	bool insert(const pair<K, V>& val) {
		//空树
		if (_header->_parent == nullptr) {
			//创建第一个根节点
			Node* root = new Node(val);
			//根节点始终为黑色
			root->_color = BLACK;

			//新创建的一个节点
			_header->_parent = root;
			root->_parent = _header; //
			//将新创建的_header重新连接起来
			_header->_left = root;
			_header->_right = root;

			return true;
		}
		//非空树
		Node* cur = _header->_parent;
		Node* parent = nullptr;
		while (cur) {
			parent = cur;
			//按照K值进行比较:pair.first
			if (cur->_value.first == val.first) //说明二者的K是相同的
				return false;

			if (cur->_value.first < val.first)
				cur = cur->_right;
			else
				cur = cur->_left;
		}
		cur = new Node(val);
		if (parent->_value.first < val.first)
			parent->_right = cur;
		else
			parent->_left = cur; ////////////////////////
		cur->_parent = parent;
		//调整:  修改颜色 + 旋转    如果g不是根节点,则不能改变当前结构中每一条路径黑色节点的个数,
		while (cur != _header->_parent && cur->_parent->_color == RED) {
			Node* p = cur->_parent;
			Node* g = p->_parent;
			if (g->_left == p) {
				Node* u = g->_right;
				if (u && u->_color == RED) {
					//修改颜色
					u->_color = p->_color = BLACK;
					g->_color = RED;
					//继续向上查看
					cur = g;
				}
				else {
					//u不存在/u存在且为黑色
					if (cur == p->_right) {

						RotateL(p);
						swap(cur, p);
					}
					//cur在p的左边,右旋
					RotateR(g);
					//修改颜色
					p->_color = BLACK;
					g->_color = RED;
					break;
				}
			}
			else {
				Node* u = g->_left;
				if (u && u->_color == RED) {
					//修改颜色
					u->_color = p->_color = BLACK;
					g->_color = RED;
					//继续向上查看
					cur = g;
				}
				else {
					//u不存在/u存在且为黑色
					if (cur == p->_left) {
						RotateR(p);
						swap(cur, p);
					}
					//cur在p的左边,右旋
					RotateL(g);
					//修改颜色
					p->_color = BLACK;
					g->_color = RED;
					break;
				}
			}
		}
		//根颜色置为黑色
		_header->_parent->_color = BLACK;
		//更新_header的左,右
		_header->_left = leftMost();
		_header->_right = rightMost();
		return true;
	}
	Node* leftMost() {
		Node* cur = _header->_parent;//从根节点开始
		while (cur && cur->_left)
			cur = cur->_left;

		return cur;
	}

	Node* rightMost() {
		Node* cur = _header->_parent;//从根节点开始
		while (cur && cur->_right)
			cur = cur->_right;
		return cur;
	}
	//左旋转和右旋转
	void RotateR(Node* parent) {
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		subL->_right = parent;
		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;
		if (parent == _header->_parent) {
			_header->_parent = subL;
			subL->_parent = _header;
		}
		else {
			Node* g = parent->_parent;
			subL->_parent = g;
			if (g->_left == parent)
				g->_left == subL;
			else
				g->_right = subL;
		}

		parent->_parent = subL;

	}

	void RotateL(Node* parent) {
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		subR->_left = parent;
		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;
		if (parent == _header->_parent) {
			_header->_parent = subR;
			subR->_parent = _header;
		}
		else {
			Node* g = parent->_parent;
			subR->_parent = g;
			if (g->_left == parent)
				g->_left == subR;
			else
				g->_right = subR;
		}

		parent->_parent = subR;

	}
	void inorder() {
		_inorder(_header->_parent);
		cout << endl;
	}
	void _inorder(Node* root) {
		if (root) {
			_inorder(root->_left);
			cout << root->_value.first << " ";
			_inorder(root->_right);
		}
	}

private:
	Node* _header;
};


void test1() {
	RBTree<int, int> rbt;
	rbt.insert(make_pair(1, 1));
	rbt.insert(make_pair(2, 1));
	rbt.insert(make_pair(3, 1));
	rbt.insert(make_pair(4, 1));
	rbt.insert(make_pair(5, 1));
	rbt.insert(make_pair(0, 1));
	rbt.insert(make_pair(9, 1));
	rbt.insert(make_pair(8, 1));
	rbt.insert(make_pair(7, 1));
	rbt.insert(make_pair(6, 1));
	rbt.inorder();
}
int main() {
	test1();
	system("pause");
	return 0;
}

//红黑树的插入:
//1.搜索树的插入
//2.判断是否调整:红色连续,
//     关键是叔叔节点: u;
//     涉及到的点: cur,p,g,u;    
//   a.  p:g->_left   u:g->_right  
//       u存在且为红  
//         p,u: 黑  
//         g:红
//         cur=g,继续向上调整
//      u不存在/存在且为黑
//        if(cur == p->_right)
//          左旋: p为轴
//          swap(cur,p)
//          右旋: g为轴
//          p:黑色,g:红
//      结束调整
/////////////////////////////////////////////////////////////////
//   b.  p:g->_right   u:g->_left  
//       u存在且为红  
//         p,u: 黑  
//         g:红
//         cur=g,继续向上调整
//      u不存在/存在且为黑
//        if(cur == p->_left)
//          右旋: p为轴
//          swap(cur,p)
//          左旋: g为轴
//          p:黑色,g:红
//      结束调整
//








