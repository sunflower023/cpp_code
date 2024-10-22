#pragma once
#include<iostream>
#include<utility>
#include<string>
#include<assert.h>
using namespace std;

template<class K, class V>
struct AVLTNode
{
	using Node = AVLTNode<K, V>;

	AVLTNode(const pair<K, V>& kv)
		: _prev(nullptr)
		, _left(nullptr)
		, _right(nullptr)
		, _bf(0)
		, _kv(kv)
	{}

	Node* _prev;
	Node* _left;
	Node* _right;
	int _bf;//balance_factor
	pair<K, V> _kv;
};

template<class K, class V>
class AVLTree
{
public:
	using Node = AVLTNode<K, V>;

	AVLTree() = default;

	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}

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
		cur = new Node(kv);
		if (kv.first > parent->_kv.first)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		cur->_prev = parent;

		//update
		while (parent)
		{
			if (cur == parent->_left)
			{
				parent->_bf--;
			}
			else
			{
				parent->_bf++;
			}

			if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				//rotate
				if (parent->_bf == 2 && cur->_bf == 1)
				{
					RotateL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == -1)
				{
					RotateR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == -1)
				{
					RotateRL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == 1)
				{
					RotateLR(parent);
				}
				else
				{
					assert(false);
				}
				//！！这个break不能忘记
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				cur = parent;
				parent = parent->_prev;
			}
			else
			{
				assert(false);
			}
		}

		return true;
	}

	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
			subRL->_prev = parent;

		subR->_left = parent;
		Node* pparent = parent->_prev;
		parent->_prev = subR;
		subR->_prev = pparent;

		if (pparent == nullptr)
		{
			_root = subR;
		}
		else
		{
			if (pparent->_left == parent)
			{
				pparent->_left = subR;
			}
			else
			{
				pparent->_right = subR;
			}
		}

		//update balance factor
		subR->_bf = 0;
		parent->_bf = 0;
	}

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_prev = parent;

		subL->_right = parent;
		Node* pparent = parent->_prev;
		parent->_prev = subL;
		subL->_prev = pparent;

		if (pparent == nullptr)
		{
			_root = subL;
		}
		else
		{
			if (pparent->_left == parent)
			{
				pparent->_left = subL;
			}
			else
			{
				pparent->_right = subL;
			}
		}

		subL->_bf = 0;
		parent->_bf = 0;
	}

	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;

		RotateL(subL);
		RotateR(parent);

		if (bf == -1)
		{
			subLR->_bf = 0;
			subL->_bf = 0;
			parent->_bf = 1;
		}
		else if (bf == 1)
		{
			subLR->_bf = 0;
			subL->_bf = -1;
			parent->_bf = 0;
		}
		else if (bf == 0)
		{
			subLR->_bf = 0;
			subL->_bf = 0;
			parent->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}

	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;

		RotateR(subR);
		RotateL(parent);

		if (bf == -1)
		{
			subRL->_bf = 0;
			subR->_bf = 1;
			parent->_bf = 0;
		}
		else if (bf == 1)
		{
			subRL->_bf = 0;
			subR->_bf = 0;
			parent->_bf = -1;
		}
		else if (bf == 0)
		{
			subRL->_bf = 0;
			subR->_bf = 0;
			parent->_bf = 0;
		}
		else
		{
			assert(false);
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

	bool IsBalanceTree()
	{
		return _IsBalanceTree(_root);
	}

private:
	void _InOrder(Node* root)
	{
		if (root == nullptr) return;

		_InOrder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second << endl;
		_InOrder(root->_right);
	}

	int _Height(Node* root)
	{
		if (root == nullptr) return 0;

		int LeftHeight = _Height(root->_left);
		int RightHeight = _Height(root->_right);
		return (LeftHeight > RightHeight) ? LeftHeight + 1 : RightHeight + 1;
	}

	int _Size(Node* root)
	{
		if (root == nullptr) return 0;
		return _Size(root->_left) + _Size(root->_right) + 1;
	}

	bool _IsBalanceTree(Node* root)
	{
		if (root == nullptr) return true;

		int LeftHeight = _Height(root->_left);
		int RightHeight = _Height(root->_right);
		int dif = RightHeight - LeftHeight;

		if (abs(dif) >= 2)
		{
			cout << root->_kv.first << "高度差异常" << endl;
			return false;
		}

		if (root->_bf != dif)
		{
			cout << root->_kv.first << "平衡因子异常" << endl;
			return false;
		}

		return _IsBalanceTree(root->_left) && _IsBalanceTree(root->_right);
	}

private:
	Node* _root = nullptr;
};
