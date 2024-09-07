#pragma once
#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;

namespace zyh
{
	template<class T>
	struct list_node
	{
		T _data;
		list_node* _prev;
		list_node* _next;

		list_node(const T& x = T())
			:_data(x)
			, _prev(nullptr)
			, _next(nullptr)
		{}
	};

	template<class T, class Ref, class Ptr>
	struct list_iterator
	{
		typedef list_node<T> node;
		typedef list_iterator iterator;

		//��Ա����
		node* _node;

		//���캯��
		list_iterator(node* node)
			:_node(node)
		{}

		//ǰ��++
		iterator operator++()
		{
			_node = _node->_next;
			return *this;
		}
		//����++
		iterator operator++(int)
		{
			iterator tmp = *this;
			_node = _node->_next;
			return tmp;
		}
		//ǰ��--
		iterator operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		//����--
		iterator operator--(int)
		{
			iterator tmp = *this;
			_node = _node->_prev;
			return tmp;
		}

		//����
		bool operator==(const iterator& it)const
		{
			return _node == it._node;
		}
		//������
		bool operator!=(const iterator& it)const
		{
			return _node != it._node;
		}

		Ref operator*()
		{
			return _node->_data;
		}
		Ptr operator->()
		{
			return &_node->_data;
		}

	};

	template<class T>
	class list
	{
		typedef list_node<T> node;
	public:

		typedef list_iterator<T, T&, T*> iterator;
		typedef list_iterator<T, const T&, const T*> const_iterator;
		iterator begin()
		{
			//ʹ����������
			return iterator(_head->_next);
		}
		iterator end()
		{
			return iterator(_head);
		}
		const_iterator begin()const
		{
			return const_iterator(_head->_next);
		}
		const_iterator end()const
		{
			return const_iterator(_head);
		}

		//��������ʼ���ڱ���ͷ��㣬���������Ϳ�������
		void emptyinit()
		{
			_head = new node;
			_head->_prev = _head;
			_head->_next = _head;
			_size = 0;
		}

		//�޲ι���
		list()
		{
			emptyinit();
		}
		//���������乹��
		template<class InputIterator>
		list(InputIterator first, InputIterator last)
		{
			emptyinit();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		//��������
		/*list(const list& x)
		{
			empty_init();
			for (auto e : x)
			{
				push_back(e);
			}
		}*/

		//������ʱ���󿽱�����
		list(const list& x)
		{
			emptyinit();
			//���õ��������乹���һ����ʱ����tmp
			list tmp(x.begin(), x.end());
			std::swap(_head, tmp._head);
			std::swap(_size, tmp._size);
		}

		//��ճ���ͷ�ڵ��������
		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);//erase�᷵����һ���ڵ�ĵ�����
			}
			_size = 0;
		}
		//����ͷ�ڵ�
		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		void push_back(const T& x)
		{
			node* newnode = new node(x);
			node* tail = _head->_prev;
			tail->_next = newnode;
			_head->_prev = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			++_size;
		}

		iterator insert(iterator pos, const T& x)
		{
			//pos�ǹ����࣬�ڲ���_node������.����
			node* prev = pos._node->_prev;
			node* next = pos._node;

			node* newnode = new node(x);
			newnode->_prev = prev;
			newnode->_next = next;
			prev->_next = newnode;
			next->_prev = newnode;

			++_size;
			return iterator(newnode);
		}

		iterator erase(iterator pos)
		{
			assert(pos != end());
			node* prev = pos._node->_prev;
			node* next = pos._node->_next;
			prev->_next = next;
			next->_prev = prev;

			delete pos._node;
			--_size;
			return iterator(next);
		}

		//ֱ�Ӹ���erase
		void pop_back()
		{
			erase(--end());
		}
		void pop_front()
		{
			erase(begin());
		}

	private:
		node* _head;
		size_t _size;
	};

	void test()
	{

	}

}