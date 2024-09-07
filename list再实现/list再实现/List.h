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

		//成员变量
		node* _node;

		//构造函数
		list_iterator(node* node)
			:_node(node)
		{}

		//前置++
		iterator operator++()
		{
			_node = _node->_next;
			return *this;
		}
		//后置++
		iterator operator++(int)
		{
			iterator tmp = *this;
			_node = _node->_next;
			return tmp;
		}
		//前置--
		iterator operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		//后置--
		iterator operator--(int)
		{
			iterator tmp = *this;
			_node = _node->_prev;
			return tmp;
		}

		//等于
		bool operator==(const iterator& it)const
		{
			return _node == it._node;
		}
		//不等于
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
			//使用匿名对象
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

		//创建并初始化哨兵卫头结点，方便给构造和拷贝复用
		void emptyinit()
		{
			_head = new node;
			_head->_prev = _head;
			_head->_next = _head;
			_size = 0;
		}

		//无参构造
		list()
		{
			emptyinit();
		}
		//迭代器区间构造
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
		//拷贝构造
		/*list(const list& x)
		{
			empty_init();
			for (auto e : x)
			{
				push_back(e);
			}
		}*/

		//利用临时对象拷贝构造
		list(const list& x)
		{
			emptyinit();
			//利用迭代器区间构造出一个临时对象tmp
			list tmp(x.begin(), x.end());
			std::swap(_head, tmp._head);
			std::swap(_size, tmp._size);
		}

		//清空出了头节点外的数据
		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);//erase会返回下一个节点的迭代器
			}
			_size = 0;
		}
		//清理头节点
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
			//pos是公开类，内部的_node可以用.访问
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

		//直接复用erase
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