#pragma once
#include<iostream>
using namespace std;

namespace zyh
{
	template<class Key,class V>
	class BSTNode
	{
	public:
		BSTNode(const Key& key, const V& value)
			:_key(key)
			, _value(value)
			, _left(nullptr)
			, _right(nullptr)
		{}

		BSTNode* _left;
		BSTNode* _right;
		V _value;
		Key _key;
	};

	template<class Key,class V>
	class BSTree
	{
		//typedef BSTNode<Key> Node;
		using Node = BSTNode<Key,V>;
	public:
		//默认构造
		BSTree() = default;

		//拷贝构造
		BSTree(const BSTree<Key,V>& t)
		{
			_root = copy(t._root);
		}

		//析构
		~BSTree()
		{
			Destroy(_root);
			_root = nullptr;
		}

		bool insert(const Key& key,const V& value)
		{
			if (_root == nullptr)
			{
				_root = new Node(key,value);
				return true;
			}

			Node* parent = nullptr;
			Node* cur = _root;
			while (cur != nullptr)
			{
				if (key > cur->_key)//大于向右走
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (key < cur->_key)//小于向左走
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					//如果键值已经存在，则返回失败
					return false;
				}
			}

			if (key > parent->_key)
			{
				parent->_right = new Node(key,value);
			}
			else
			{
				parent->_left = new Node(key,value);
			}
			return true;
		}

		void _InOrder()
		{
			InOrder(_root);
			cout << endl;
		}

		Node* find(const Key& x)
		{
			Node* cur = _root;
			while (cur != nullptr)
			{
				if (cur->_key > x)
				{
					cur = cur->_left;
				}
				else if (cur->_key < x)
				{
					cur = cur->_right;
				}
				else
				{
					return cur;//找到了
				}
			}
			return nullptr;//没有找到
		}

		bool erase(const Key& x)
		{
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key > x)
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (cur->_key < x)
				{
					parent = cur;
					cur = cur->_right;
				}
				else//找到被删除的值的节点
				{
					if (cur->_left == nullptr)//没有左孩子
					{
						if (parent == nullptr)//删除根的情况
						{
							_root = cur->_right;
						}
						else
						{
							//判断cur是parent的左孩子还是右孩子
							if (parent->_left == cur)
							{
								parent->_left = cur->_right;
							}
							else
							{
								parent->_right = cur->_right;
							}
						}
						delete cur;
					}
					else if (cur->_right == nullptr)//没有右孩子
					{
						if (parent == nullptr)//删除根节点
						{
							_root = cur->_left;
						}
						else
						{
							if (parent->_left == cur)
							{
								parent->_left = cur->_left;
							}
							else
							{
								parent->_right = cur->_left;
							}
						}
						delete cur;
					}
					else//左右孩子都是非空的情况
					{
						Node* replaceParent = cur;
						Node* replace = cur->_right;
						//找右子树的最小值（左）
						while (replace->_left)
						{
							replaceParent = replace;
							replace = replace->_left;
						}

						cur->_key = replace->_key;
						//replace不一定是其parent的左孩子
						//例如上图删除3时，replace(4)是parent(6)左孩子
						//而删除8时，replace(10)是parent(8)的右孩子
						if (replaceParent->_left == replace)
						{
							//replace是最左节点，没有左孩子，但可能有右孩子
							replaceParent->_left = replace->_right;
						}
						else
						{
							replaceParent->_right = replace->_right;
						}
						delete replace;
					}
					return true;
				}
			}
			return false;
		}

		Node* copy(Node* root)
		{
			if (root == nullptr)
				return nullptr;
			Node* newRoot = new Node(root->_key,root->_value);
			newRoot->_left = copy(root->_left);
			newRoot->_right = copy(root->_right);
			return newRoot;
		}

		void Destroy(Node* root)
		{
			if (root == nullptr)
				return;

			Destroy(root->_left);
			Destroy(root->_right);
			delete root;
		}

	private:

		void InOrder(Node* root)
		{
			if (root == nullptr) return;
			InOrder(root->_left);
			cout << root->_key << " " << root->_value << endl;
			InOrder(root->_right);
		}

		Node* _root = nullptr;
	};
}
