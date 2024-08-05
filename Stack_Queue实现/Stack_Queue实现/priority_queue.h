#pragma once

template<class T>
class Less
{
public:
	bool operator()(const T& x, const T& y)
	{
		return x < y;
	}
};

template<class T>
class Greater
{
public:
	bool operator()(const T& x, const T& y)
	{
		return x > y;
	}
};

namespace zyh
{
	template<class T, class con = vector<T>, class compare = Less<T>>
	class priority_queue
	{
	public:
		priority_queue() = default;

		void AdjustUp(int child)
		{
			int parent = (child - 1) / 2;
			while (child > 0)
			{
				if (_com(_c[parent], _c[child]))
				{
					swap(_c[child], _c[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}

		void push(const T& x)
		{
			_c.push_back(x);
			AdjustUp(_c.size() - 1);
		}

		void AdjustDown(int parent)
		{
			int child = parent * 2 + 1;
			while (child < _c.size())
			{
				if (child + 1 < _c.size() && _com(_c[child], _c[child + 1]))
				{
					child++;
				}
				if (_com(_c[parent], _c[child]))
				{
					swap(_c[child], _c[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}
		
		void pop()
		{
			swap(_c[0], _c[_c.size() - 1]);
			_c.pop_back();
			AdjustDown(0);
		}

		const T& top()
		{
			return _c[0];
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
		compare _com;
	};

	void test03()
	{
		//priority_queue<int,vector<int>,Greater<int>> pq;

		//小于less是建大堆
		priority_queue<int> pq;
		pq.push(0);
		pq.push(1);
		pq.push(2);
		pq.push(3);
		pq.push(4);

		while (!pq.empty())
		{
			cout << pq.top() << " ";
			pq.pop();
		}
		cout << endl;

	}

}


namespace bit
{
	// 默认是大堆
	template<class T, class Container = vector<T>, class Compare = Less<T>>
	class priority_queue
	{
	public:
		void AdjustUp(int child)
		{
			Compare com;
			int parent = (child - 1) / 2;
			while (child > 0)
			{
				//if (_con[parent] < _con[child])
				if (com(_con[parent], _con[child]))
				{
					swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}

		void push(const T& x)
		{
			_con.push_back(x);

			AdjustUp(_con.size() - 1);
		}

		void AdjustDown(int parent)
		{
			// 先假设左孩子小
			size_t child = parent * 2 + 1;

			Compare com;
			while (child < _con.size())  // child >= n说明孩子不存在，调整到叶子了
			{
				// 找出小的那个孩子
				//if (child + 1 < _con.size() && _con[child] < _con[child + 1])
				if (child + 1 < _con.size() && com(_con[child], _con[child + 1]))
				{
					++child;
				}

				//if (_con[parent] < _con[child])
				if (com(_con[parent], _con[child]))
				{
					swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}

		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			AdjustDown(0);
		}

		const T& top()
		{
			return _con[0];
		}

		size_t size() const
		{
			return _con.size();
		}

		bool empty() const
		{
			return _con.empty();
		}

	private:
		Container _con;
	};

	void test03()
	{
		//priority_queue<int,vector<int>,Greater<int>> pq;
		priority_queue<int> pq;
		pq.push(0);
		pq.push(1);
		pq.push(2);
		pq.push(3);
		pq.push(4);

		while (!pq.empty())
		{
			cout << pq.top() << " ";
			pq.pop();
		}
		cout << endl;

	}
}