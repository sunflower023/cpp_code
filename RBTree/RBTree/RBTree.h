#pragma once
#include<iostream>
#include<utility>


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
		,_kv(kv)
		,_col(RED)//新插入的节点一定是红色，黑色会直接破坏规则
	{}
};

template<class K,class V>
class RBTree
{
	using Node<K, V> = RBTreeNode<K, V>;
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
					father->_col = uncle->_col = BLACK;

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

			}
		}
	}

private:
	Node* _root = nullptr;
};