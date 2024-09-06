#pragma once
#include<iostream>
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
		//节点的默认构造是为了哨兵卫使用
		list_node(const T& x = T())
			:_data(x)
			,_prev(nullptr)
			,_next(nullptr)
		{}
	};

	template<class T,class Ref,class Ptr>
	struct list_iterator
	{
		typedef list_node<T> Node;
		typedef list_iterator<T,Ref,Ptr> Self;

		Node* _node;
		list_iterator(Node* node)
			:_node(node)
		{}
		

		Ref operator*()
		{
			return _node->_data;
		}
		Ptr operator->()
		{
			return &_node->_data;
		}

		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		Self operator++(int)
		{
			Self tmp(*this);
			_node = _node->_next;
			return tmp;
		}
		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		Self operator--(int x)
		{
			Self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}

		bool operator!=(const Self& s)const
		{
			return _node != s._node;
		}
		bool operator==(const Self& s)const
		{
			return _node == s._node;
		}

	};


	template<class T>
	class list
	{
		typedef list_node<T> Node;
	public:
		//迭代器要加到public来，是要用来访问的
		typedef list_iterator<T,T&,T*> iterator;
		typedef list_iterator<T,const T&,const T*> const_iterator;

		void empty_init()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
			_size = 0;
		}

		list()
		{
			empty_init();
		}

		//迭代器区间构造
		template<class InputIterator>
		list(InputIterator first, InputIterator last)
		{
			empty_init();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		list(const list& x)
		{
			empty_init();
			list tmp(x.begin(), x.end());
			std::swap(_head, tmp._head);
			std::swap(_size, tmp._size);
		}

		/*list(const list<T>& x)
		{
			empty_init();
			for (auto e : x)
			{
				push_back(e);
			}
		}*/

		void swap(list<T>& l)
		{
			std::swap(_head, l._head);
			std::swap(_size, l._head);
		}

		list<T>& operator=(list<T> tmp)
		{
			swap(tmp);
			return *this;
		}

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		iterator begin()
		{
			//调用构造
			//return iterator(_head->_next);
			return _head->_next;
		}
		iterator end()
		{
			return _head;
		}
		const_iterator begin()const
		{
			return _head->_next;
		}
		const_iterator end()const
		{
			return _head;
		}

		void push_back(const T& x)
		{
			Node* newnode = new Node(x);
			Node* tail = _head->_prev;
			tail->_next = newnode;
			_head->_prev = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			++_size;
		}

		iterator insert(iterator pos, const T& x)
		{
			Node* prev = pos._node->_prev;
			Node* next = pos._node;

			Node* newnode = new Node(x);
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
			Node* prev = pos._node->_prev;
			Node* next = pos._node->_next;
			prev->_next = next;
			next->_prev = prev;

			delete pos._node;
			--_size;
			return iterator(next);
		}

		void pop_back()
		{
			erase(--end());
		}

		void pop_front()
		{
			erase(begin());
		}

		void clear()
		{
			auto it = begin();
			while (it != end())
			{
				it = erase(it);
			}
			_size = 0;
		}

		size_t size()const
		{
			return _size;
		}
		bool empty()const
		{
			return _size == 0;
		}

	private:
		Node* _head;
		size_t _size;
	};


	void List_test1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.insert(++lt.begin(), 5);
		lt.erase(++lt.begin());
		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
	
	void List_test2()
	{


		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);
		
		auto it = lt.begin();
		while (it != lt.end())
		{
			if (*it % 2 == 0)
			{
				it = lt.erase(it);
			}
			else
			{
				it++;
			}
		}


		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;
	}


	void print(const list<int>& l)
	{
		for (auto e : l)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void List_test3()
	{
		list<int> l1;
		l1.push_back(1);
		l1.push_back(2);
		l1.push_back(3);
		l1.insert(++l1.begin(), 4);

		print(l1);
	}
}