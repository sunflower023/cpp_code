#define _CRT_SECURE_NO_WARNINGS 1
#include"string.h"
namespace zyh
{
	const size_t string::npos = -1;

	void string::reserve(size_t n)
	{
		if (n > _capacity)
		{
			char* tmp = new char[n + 1];
			_capacity = n;
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
		}
	}
	void string::push_back(char c)
	{
		if (_size == _capacity)
		{
			reserve(_capacity == 0 ? 4 : _capacity * 2);
		}

		_str[_size++] = c;
		_str[_size] = '\0';
	}
	string& string::operator+=(char c)
	{
		push_back(c);
		return *this;
	}
	void string::append(const char* str)
	{
		size_t len = strlen(str);
		if (_size + len > _capacity)
		{
			reserve(_size + len);
		}
		strcpy(_str + _size, str);
		_size = _size + len;
	}
	string& string:: operator+=(const char* str)
	{
		append(str);
		return *this;
	}
	void string::clear()
	{
		char* tmp = new char[_capacity + 1];
		tmp[0] = '\0';
		_str = tmp;
		_size = 0;
	}
	void string::swap(string& s)
	{
		string tmp = s;
		s = *this;
		*this = tmp;
	}
	
	void string::resize(size_t n, char c)
	{
		if (n > _size)
		{
			int i = n - _size;
			while (i--)
			{
				push_back(c);
			}
		}
		_size = n;
	}

	bool string::operator<(const string& s)
	{
		return strcmp(_str, s._str) < 0;
	}
	bool string::operator<=(const string& s)
	{
		return (*this < s) || (*this == s);
	}
	bool string::operator>(const string& s)
	{
		return !(*this <= s);
	}
	bool string::operator>=(const string& s)
	{
		return !(*this < s);
	}
	bool string::operator==(const string& s)
	{
		return strcmp(_str, s._str) == 0;
	}
	bool string::operator!=(const string& s)
	{
		return !(*this == s);
	}

	size_t string::find(char c, size_t pos) const
	{
		assert(pos < _size);
		for (size_t i = pos; i < _size; i++)
		{
			if (_str[i] == c)
			{
				return i;
			}
			return npos;
		}
	}
	size_t string::find(const char* s, size_t pos) const
	{
		assert(pos < _size);
		const char* ptr = strstr(_str + pos, s);
		if (ptr == nullptr)
		{
			return npos;
		}
		else
		{
			return ptr - _str;
		}
	}
	string& string::insert(size_t pos, char c)
	{
		assert(pos <= _size);
		if (_size == _capacity)
		{
			reserve((_capacity == 0) ? 4 : 2 * _capacity);
		}
		size_t end = _size + 1;
		while (end > pos)
		{
			_str[end] = _str[end - 1];
			end--;
		}
		_str[pos] = c;
		_size++;
		return *this;
	}
	string& string::insert(size_t pos, const char* str)
	{
		assert(pos <= _size);
		size_t len = strlen(str);
		if (_size + len > _capacity)
		{
			reserve(_size + len);
		}

		size_t end = _size + len;
		while (end > pos + len - 1)
		{
			_str[end] = _str[end - len];
			end--;
		}
		for (size_t i = 0; i < len; i++)
		{
			_str[pos + i] = str[i];
		}
		_size += len;
		return *this;
	}

	string& string::erase(size_t pos, size_t len)
	{
		assert(pos < _size);
		if (len >= _size - pos)
		{
			_str[pos] = '\0';
			_size = pos;
		}
		else
		{
			for (size_t i = pos + len; i <= _size; i++)
			{
				_str[i - len] = _str[i];
			}
			_size -= len;
		}
		return *this;
	}
	ostream& operator<<(ostream& _cout, const zyh::string& s)
	{
		for (auto ch : s)
		{
			_cout << ch;
		}
		return _cout;
	}
	istream& operator>>(istream& _cin, zyh::string& s)
	{
		s.clear();

		const int N = 256;
		char buff[N];
		int i = 0;

		char ch = _cin.get();
		while (ch != ' ' && ch != '\n')
		{
			buff[i++] = ch;
			if (i == N - 1)
			{
				buff[i] = '\0';
				s += buff;
				i = 0;
			}
			//s += ch;
			ch = _cin.get();
		}
		buff[i] = '\0';
		s += buff;

		return _cin;
	}
	void string_test()
	{
		//string s1("hello");
		//cout << s1.c_str() << endl;
		/*string::iterator it = s1.begin();
		while (it != s1.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;*/
		/*string s2(s1);
		cout << s2.c_str() << endl;
		s2.append("xxxxxx");
		cout << s2.c_str() << endl;

		s1.swap(s2);
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;*/

		string s1("bbcdefg");
		string s2("abcdefg");
		//reverse(s.begin() + 0, s.begin() + 2);
		//s2.insert(7,'x');
		//s2.erase(2, 2);
		cout << s2.c_str() << endl;
		cout << s2 << endl;
		cin >> s2;
		cout << s2 << endl;

	}
}