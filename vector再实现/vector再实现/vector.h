#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

namespace zyh
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		//无参构造
		vector()
			:_start(nullptr)
			,_finish(nullptr)
			,_end_of_storage(nullptr)
		{}
		//带参构造，用n个value来初始化vector
		vector(int n, const T& value = T())
			/*:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)*/
		{
			reserve(n);
			for (int i = 0; i < n; i++)
			{
				push_back(value);
			}
		}
		//拷贝构造
		vector(const vector& v)
			/*:_start(nullptr)
			,_finish(nullptr)
			,_end_of_storage(nullptr)*/
		{
			//易错点：这里并没有进行初始化
			reserve(v.size());
			for (auto e : v)
			{
				push_back(e);
			}
		}

		//赋值重载
		void swap(vector& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}
		vector& operator=(vector v)
		{
			swap(v);
			return *this;
		}

		//迭代器区间构造
		template<class InputIterator>
		vector(InputIterator first, InputIterator last)
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}
		
		//iterator
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const_iterator begin()const
		{
			return _start;
		}
		const_iterator end()const
		{
			return _finish;
		}

		//capacity
		size_t size()const
		{
			return _finish - _start;
		}
		size_t capacity()const
		{
			return _end_of_storage - _start;
		}
		bool empty()const
		{
			return size() == 0;
		}
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				//记录原本的数据个数
				size_t old_size = size();
				iterator tmp = new T[n];
				memcpy(tmp, _start, old_size * sizeof(T));
				delete[] _start;
				_start = tmp;
				_finish = tmp + old_size;
				_end_of_storage = tmp + n;
			}
		}
		void resize(size_t n, const T& value = T()) 
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				reserve(n);
				while (_finish != _start + n)
				{
					*_finish = value;
					_finish++;
				}
			}
		}
		
		//modify
		void push_back(const T& x)
		{
			if (_finish == _end_of_storage)
			{
				reserve(capacity() == 0 ? 4 : 2 * capacity());
			}
			*_finish = x;
			++_finish;
		}
		void pop_back()
		{
			assert(size() > 0);
			--_finish;
		}
		iterator insert(iterator pos, const T& x)
		{
			assert(pos >= _start);
			assert(pos <= _finish);
			if (_finish == _end_of_storage)
			{
				//注意这里扩容会使原有的pos迭代器失效
				//因此这里使用len计算相对长度，更新迭代器
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : 2 * capacity());
				pos = _start + len;
			}
			iterator end = _finish;
			while (end > pos)
			{
				*end = *(end - 1);
				end--;
			}
			*pos = x;
			++_finish;
			return pos;
		}
		void erase(iterator pos)
		{
			assert(pos >= _start);
			assert(pos < _finish);
			iterator it = pos + 1;
			while (it < _finish)
			{
				*(it - 1) = *it;
				it++;
			}
			--_finish;
		}

		//access
		T& operator[](size_t i)
		{
			assert(i < size());
			return _start[i];
		}
		const T& operator[](size_t i)const
		{
			assert(i < size());
			return _start[i];
		}

		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _end_of_storage = nullptr;
			}
		}

	private:
		/*iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _end_of_storage = nullptr;*/
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};


	template<class T>
	void print_vector(const vector<T>& v)
	{
		//规定，从没有实例化的类模版中取东西
		//编译器不能区分const_iterator是类型还是静态成员变量，因此要加typename
		//当然也可以更简单写为auto it  = v.begin();
		typename vector<T>::const_iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	template<class container>
	void print_container(const container& v)
	{
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void vector_test3()
	{
		vector<int> v1(2, 1);
		vector<int> v2;
		v2 = v1;
	}
}