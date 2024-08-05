#pragma once
namespace zyh
{
	template<class T,class con = deque<T>>
	class queue
	{
	public:
		queue() = default;
		
		void push(const T& x)
		{
			_c.push_back(x);
		}

		void pop()
		{
			_c.pop_front();
		}

		T& back()
		{
			return _c.back();
		}

		const T& back()const
		{
			return _c.back();
		}

		T& front()
		{
			return _c.front();
		}

		const T& front()const
		{
			return _c.front();
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

	void test02()
	{
		queue<int> q;
		q.push(1);
		q.push(2);
		q.push(3);
		q.push(4);
		while (!q.empty())
		{
			cout << q.front() << " ";
			q.pop();
		}
		cout << endl;

	}
}