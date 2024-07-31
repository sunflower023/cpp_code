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
		size_t size()const
		{
			return _finish - _start;
		}
		size_t capacity()const
		{
			return _end_of_storage - _start;
		}

		//construct and destroy
		//c++11 强制生成默认构造
		vector() = default;

		vector(int n, const T& value = T())
		{
			reserve(n);
			//value都不是容器用范围for肯定要报错
			//for (auto& e : value)
			//{
			//	push_back(e);
			//}
			for (int i = 0; i < n; i++)
			{
				push_back(value);
			}
		}
		
		template<class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		//拷贝构造
		vector(const vector<T>& v)
		{
			reserve(v.size());
			for (auto e : v)
			{
				push_back(e);
			}
		}
		//为什么不能这样写拷贝构造？
		//拷贝构造不能传形参，否则会死循环
		//vector(vector<T> v)
		//{
		//	swap(v);
		//}

		//赋值重载
		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish,v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}
		vector& operator=(vector<T>& v)
		{
			swap(v);
			return *this;
		}

		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _end_of_storage = nullptr;
			}
		}

		//capacity
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				//记录之前start和finish的相对距离
				size_t old_size = size();
				iterator tmp = new T[n];
				memcpy(tmp, _start, sizeof(T) * old_size);
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
					++_finish;
				}
			}
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
			assert(size() >= 0);
			--_finish;
		}

		iterator insert(iterator pos, const T& x)
		{
			assert(pos <= _finish);
			assert(pos >= _start);
			if (_finish == _end_of_storage)
			{
				//扩容的话原本pos就是野指针,因此要计算相对长度得出新pos
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : 2 * capacity());
				pos = _start + len;
			}
			iterator end = _finish;
			while (end > pos)
			{
				*end = *(end - 1);
				--end;
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
			while (it != _finish)
			{
				*(it - 1) = *it;
				++it;
			}
			--_finish;
		}
		
	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _end_of_storage = nullptr;
	};

	template<class T>
	void print_vector(const vector<T>& v)
	{
		//规定，从没有实例化的类模版中取东西
		//编译器不能区分const_iterator是类型还是静态成员变量
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


	void vector_test1()
	{
		vector<int> v;
		v.push_back(100);
		v.push_back(200);
		//v.pop_back();
		v.push_back(300);
		v.insert(v.begin()+3, 400);

		/*for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;*/
		print_vector(v);

	}

	void vector_test2()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);
		v1.push_back(6);
		vector<int> v2(v1.begin(), v1.begin() + 4);
		print_container(v1);
		print_container(v2);
	}

	void vector_test3()
	{
		vector<int> v1(5, 1);
		print_container(v1);
		
		v1.resize(10, 2);
		print_container(v1);
		v1.erase(v1.begin() + 9);
		print_container(v1);
	}
}