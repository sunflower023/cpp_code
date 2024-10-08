#pragma once
#include<iostream>
#include<assert.h>
#include<string>
using namespace std;

namespace zyh
{
	class string
	{
	public:
		
		//string()
		//	:_str(new char[1]{'\0'})
		//	,_size(0) 
		//	,_capacity(0)
		//{}

		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			//capactiy不包含'\0'
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		/*string(const string& s)
		{
			_size = s._size;
			_capacity = s._capacity;
			_str = new char[_capacity + 1];
			strcpy(_str, s._str);
		}*/
		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}

		string(const string& s)
		{
			string tmp(s._str);
			swap(tmp);
		}

		string& operator=(const string& s)
		{
			if (this != &s)
			{
				delete[] _str;
				_size = s._size;
				_capacity = s._capacity;
				_str = new char[_capacity + 1];
				strcpy(_str, s._str);
			}
			return *this;
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		const char* c_str()const
		{
			return _str;
		}

		//access
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}
		const char& operator[](size_t pos)const
		{
			assert(pos >= 0 && pos < _size);
			return _str[pos];
		}

		//迭代器
		typedef char* iterator;
		typedef const char* const_iterator;
		iterator begin()
		{
			return &_str[0];
		}
		iterator end()
		{
			return &_str[_size];
		}
		const_iterator begin()const
		{
			return _str;
		}
		const_iterator end()const
		{
			return _str + _size;
		}

		//modify调整
		void push_back(char c);
		string& operator+=(char c);
		void append(const char* str);
		string& operator+=(const char* str);
		void clear();
		//void swap(string& s);
		
		//capacity
		size_t size()const
		{
			return _size;
		}
		size_t capacity()const
		{
			return _capacity;
		}
		bool empty()const
		{
			return (_size == 0);
		}
		void resize(size_t n, char c = '\0');
		void reserve(size_t n);

		//relational operators
		bool operator<(const string& s);
		bool operator<=(const string& s);
		bool operator>(const string& s);
		bool operator>=(const string& s);
		bool operator==(const string& s);
		bool operator!=(const string& s);

		// 返回c在string中第一次出现的位置
		size_t find(char c, size_t pos = 0) const;
		// 返回子串s在string中第一次出现的位置
		size_t find(const char* s, size_t pos = 0) const;
		// 在pos位置上插入字符c/字符串str，并返回该字符的位置
		string& insert(size_t pos, char c);
		string& insert(size_t pos, const char* str);
		// 删除pos位置上的元素，并返回该元素的下一个位置
		string& erase(size_t pos, size_t len);

		friend ostream& operator<<(ostream& _cout, const zyh::string& s);
		friend istream& operator>>(istream& _cin, zyh::string& s);
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
		static const size_t npos;
	};

	void string_test();
}