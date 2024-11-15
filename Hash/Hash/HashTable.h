#pragma once
#include<iostream>
#include<vector>
using namespace std;

enum State
{
	EMPTY,//空
	EXIST,//存在数据
	DELETE//数据被删除
};

template<class K,class V>
struct HashDate
{
	pair<K, V> _kv;
	State _state;
	HashDate(const pair<K,V>& kv)
		:_kv(kv)
		,_state(EMPTY)
	{}
};

template<class K,class V>
class HashTable
{
public:

	bool insert(const pair<K, V>& kv)
	{
		//扩容，负载因子在0.7到0.8区间差不多就该扩容了
		if (_table.size() = 0 || 10 * _size / _table.size() >= 7)
		{
			size_t newSize = _table.size() == 0 ? 10 : _table.size() * 2;
			HashTable<K, V> newTable;
			newTable._table.resize(newSize);
			//将旧表数据导入新表
			for (auto e : _table)
			{
				if (e._state == EXIST)
				{
					newTable.insert(e._kv);
				}
			}
			_table.swap(newTable._table);
		}

		//以下这个哈希函数也可以作为函数参数传入
		size_t index = kv.first & _table.size();//不能模capacity

		//进行线性探测
		while (_table[index]._state == EXIST)
		{
			index++;
			index %= _table.size();//超过size范围后重新回到起点0
		}
		_table[index]._kv = kv;
		_table[index]._state = EXIST;
		_size++;
		
		return true;
	}

	HashDate<K, V>* find(const K& key)
	{
		if (_table.size() == 0)
			return nullptr;

		size_t index = key % _table.size();
		int cur = index;
		while (_table[cur]._state != EMPTY)
		{
			if (_table[cur]._kv.first == key && _table[cur]._state == EXIST)
				return &_table[cur];
			cur++;
			cur %= _table.size();

			if (cur == index)
				break;
		}
		return nullptr;
	}

	bool erase(const K& key)
	{
		HashDate<K, V>* ret = find(key);
		if (ret)
		{
			ret->_state = DELETE;
			_size--;
			return true;
		}
		return false;
	}

private:
	vector<HashDate<K, V>> _table;
	size_t _size = 0;
};