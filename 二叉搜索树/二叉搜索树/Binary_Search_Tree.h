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
		//Ĭ�Ϲ���
		BSTree() = default;

		//��������
		BSTree(const BSTree<Key,V>& t)
		{
			_root = copy(t._root);
		}

		//����
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
				if (key > cur->_key)//����������
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (key < cur->_key)//С��������
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					//�����ֵ�Ѿ����ڣ��򷵻�ʧ��
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
					return cur;//�ҵ���
				}
			}
			return nullptr;//û���ҵ�
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
				else//�ҵ���ɾ����ֵ�Ľڵ�
				{
					if (cur->_left == nullptr)//û������
					{
						if (parent == nullptr)//ɾ���������
						{
							_root = cur->_right;
						}
						else
						{
							//�ж�cur��parent�����ӻ����Һ���
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
					else if (cur->_right == nullptr)//û���Һ���
					{
						if (parent == nullptr)//ɾ�����ڵ�
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
					else//���Һ��Ӷ��Ƿǿյ����
					{
						Node* replaceParent = cur;
						Node* replace = cur->_right;
						//������������Сֵ����
						while (replace->_left)
						{
							replaceParent = replace;
							replace = replace->_left;
						}

						cur->_key = replace->_key;
						//replace��һ������parent������
						//������ͼɾ��3ʱ��replace(4)��parent(6)����
						//��ɾ��8ʱ��replace(10)��parent(8)���Һ���
						if (replaceParent->_left == replace)
						{
							//replace������ڵ㣬û�����ӣ����������Һ���
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
