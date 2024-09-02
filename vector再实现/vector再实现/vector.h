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
		//�޲ι���
		vector()
			:_start(nullptr)
			,_finish(nullptr)
			,_end_of_storage(nullptr)
		{}
		//���ι��죬��n��value����ʼ��vector
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
		//��������
		vector(const vector& v)
			/*:_start(nullptr)
			,_finish(nullptr)
			,_end_of_storage(nullptr)*/
		{
			//�״�㣺���ﲢû�н��г�ʼ��
			reserve(v.size());
			for (auto e : v)
			{
				push_back(e);
			}
		}

		//��ֵ����
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

		//���������乹��
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
				//��¼ԭ�������ݸ���
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
				//ע���������ݻ�ʹԭ�е�pos������ʧЧ
				//�������ʹ��len������Գ��ȣ����µ�����
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
		//�涨����û��ʵ��������ģ����ȡ����
		//��������������const_iterator�����ͻ��Ǿ�̬��Ա���������Ҫ��typename
		//��ȻҲ���Ը���дΪauto it  = v.begin();
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