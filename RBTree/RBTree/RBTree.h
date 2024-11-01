#pragma once
#include<iostream>
using namespace std;

//枚举红黑颜色
enum Color
{
	RED,
	BLACK
};

template<class K,class V>
struct RBTreeNode
{
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;

	Color _col;
	pair<K, V> _kv;

	RBTreeNode(const pair<K,V>& kv)
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_col(RED)//新插入的节点一定是红色，黑色会直接破坏规则
		,_kv(kv)
	{}
};

template<class K,class V>
class RBTree
{
	using Node = RBTreeNode<K, V>;
public:
	bool insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			//新创建的节点是红色的，但根节点一定是黑的，需要更新
			_root->_col = BLACK;
			return true;
		}

		//找到插入点
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (kv.first > cur->_kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (kv.first < cur->_kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		//将新节点和父节点连接起来
		cur = new Node(kv);
		if (kv.first < parent->_kv.first)
			parent->_left = cur;
		else
			parent->_right = cur;
		cur->_parent = parent;

		//更新到parent为空或parent不为红为止（g变为c，这里的p是实际原来g的parent）
		while (parent && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;
			if (parent == grandfather->_left)//uncle在右
			{
				//	g
				//p   u
				Node* uncle = grandfather->_right;
				if (uncle && uncle->_col == RED)//uncle存在且为红
				{
					grandfather->_col = RED;
					parent->_col = uncle->_col = BLACK;

					//继续向上更新
					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_left)//cur在p的左(包含了uncle为黑和空的情况）
					{
						//		g
						//	 p	   u
						//c 
						RotateR(grandfather);
						grandfather->_col = RED;
						parent->_col = BLACK;
					}
					else
					{
						//		g
						//	 p	   u
						//	   c
						RotateL(parent);
						RotateR(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}

					break;
				}
			}
			else//uncle在左，其余逻辑全部相同
			{
				//	g
				//u   p
				Node* uncle = grandfather->_left;
				if (uncle && uncle->_col == RED)//uncle存在且为红
				{
					grandfather->_col = RED;
					parent->_col = uncle->_col = BLACK;

					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_left)
					{
						//		g
						//	 u	   p
						//		 c
						RotateR(parent);
						RotateL(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						//		g
						//	 u	   p
						//	          c
						RotateL(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}

					break;
				}
			}
		}
		_root->_col = BLACK;

		return true;
	}

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		Node* pparent = parent->_parent;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		subL->_right = parent;
		parent->_parent = subL;
		if (parent == _root)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			if (parent == pparent->_left)
			{
				pparent->_left = subL;
			}
			else
			{
				pparent->_right = subL;
			}
			subL->_parent = pparent;
		}
	}

	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		Node* pparent = parent->_parent;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		subR->_left = parent;
		parent->_parent = subR;

		if (parent == _root)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (parent == pparent->_left)
			{
				pparent->_left = subR;
			}
			else
			{
				pparent->_right = subR;
			}
			subR->_parent = pparent;
		}
	}

	void InOrder()
	{
		_InOrder(_root);
	}

	int Height()
	{
		return _Height(_root);
	}

	int Size()
	{
		return _Size(_root);
	}

	Node* Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (key < cur->_kv.first)
			{
				cur = cur->_left;
			}
			else if (key > cur->_kv.first)
			{
				cur = cur->_right;
			}
			else
			{
				return cur;
			}
		}
		return nullptr;
	}

	bool IsBalance()
	{
		if (_root == nullptr)
			return true;
		if (_root->_col == RED)
			return false;

		int refNum = 0;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_col == BLACK)
				++refNum;
			cur = cur->_left;
		}

		return Check(_root, 0, refNum);
	}

private:
	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		_InOrder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second << endl;
		_InOrder(root->_right);
	}

	int _Height(Node* root)
	{
		if (root == nullptr)
			return 0;

		int LeftHeight = _Height(root->_left);
		int RightHeight = _Height(root->_right);

		return (LeftHeight > RightHeight) ? LeftHeight + 1 : RightHeight + 1;
	}

	int _Size(Node* root)
	{
		if (root == nullptr)
			return 0;

		return _Size(root->_left) + _Size(root->_right) + 1;
	}

	bool Check(Node* root, int blackNum, const int refNum)
	{
		if (root == nullptr)
		{
			if (blackNum != refNum)
			{
				cout << "存在黑色节点数量不等的路径" << endl;
				return false;
			}
			return true;
		}

		if (root->_col == RED && root->_parent->_col == RED)
		{
			cout << root->_kv.first << "存在连续的红色节点" << endl;
			return false;
		}

		if (root->_col == BLACK)
		{
			blackNum++;
		}

		return Check(root->_left, blackNum, refNum) && Check(root->_right, blackNum, refNum);
	}

	Node* _root = nullptr;
};