#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

namespace zyh
{
	class string
	{
	public:
		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size,s._size);
			std::swap(_capacity, s._capacity);
		}

		string(const string& s)
		{
			//注意这里是调用构造，不要直接用s拷贝构造
			string tmp(s._str);
			swap(tmp);
		}

		string& operator=(string tmp)
		{
			swap(tmp);
			return *this;
		}

		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
				_size = _capacity = 0;
			}
		}

		char* c_str()
		{
			return _str;
		}

	private:
		char* _str = nullptr;
		size_t _size = 0;
		size_t _capacity = 0;
	};
}

int main()
{
	zyh::string s1("hello");
	zyh::string s2(s1);
	zyh::string s3;
	s3 = s2;
	cout << s1.c_str() << endl;
	cout << s2.c_str() << endl;
	cout << s3.c_str() << endl;

	return 0;
}