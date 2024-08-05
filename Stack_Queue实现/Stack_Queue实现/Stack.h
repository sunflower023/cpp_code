#pragma once
namespace zyh
{
	template<class T, class con = deque<T>>
	class stack
	{
	public:
		stack() = default;

		void push(const T& x)
		{
			_c.push_back(x);
		}

		void pop()
		{
			_c.pop_back();
		}

		T& top()
		{
			return _c.back();
		}

		const T& top()const
		{
			return _c.back();
		}

		size_t size()const
		{
			return _c.size();
		}

		bool empty()const
		{
			return _c.empty();
		}

	private:
		con _c;
	};

	void test01()
	{
		stack<int> s;
		s.push(1);
		s.push(2);
		s.push(3);
		s.push(4);
		while (!s.empty())
		{
			cout << s.top() << " ";
			s.pop();
		}
		cout << endl;
	}
}