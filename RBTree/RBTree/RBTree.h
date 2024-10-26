#pragma once
#include<iostream>
#include<utility>


//ö�ٺ����ɫ
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
		,_col(RED)//�²���Ľڵ�һ���Ǻ�ɫ����ɫ��ֱ���ƻ�����
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
			//�´����Ľڵ��Ǻ�ɫ�ģ������ڵ�һ���Ǻڵģ���Ҫ����
			_root->_col = BLACK;
			return true;
		}

		//�ҵ������
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

		//���½ڵ�͸��ڵ���������
		cur = new Node(kv);
		if (kv.first < parent->_kv.first)
			parent->_left = cur;
		else
			parent->_right = cur;
		cur->_parent = parent;

		//���µ�parentΪ�ջ�parent��Ϊ��Ϊֹ��g��Ϊc�������p��ʵ��ԭ��g��parent��
		while (parent && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;
			if (parent == grandfather->_left)//uncle����
			{
				//	g
				//p   u
				Node* uncle = grandfather->_right;
				if (uncle && uncle->_col == RED)//uncle������Ϊ��
				{
					grandfather->_col = RED;
					father->_col = uncle->_col = BLACK;

					//�������ϸ���
					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_left)//cur��p����(������uncleΪ�ںͿյ������
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
			else//uncle���������߼�ȫ����ͬ
			{

			}
		}
	}

private:
	Node* _root = nullptr;
};