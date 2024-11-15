#pragma once
#include<iostream>
#include<vector>
using namespace std;

enum State
{
	EMPTY,//��
	EXIST,//��������
	DELETE//���ݱ�ɾ��
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
		//���ݣ�����������0.7��0.8������͸�������
		if (_table.size() = 0 || 10 * _size / _table.size() >= 7)
		{
			size_t newSize = _table.size() == 0 ? 10 : _table.size() * 2;
			HashTable<K, V> newTable;
			newTable._table.resize(newSize);
			//���ɱ����ݵ����±�
			for (auto e : _table)
			{
				if (e._state == EXIST)
				{
					newTable.insert(e._kv);
				}
			}
			_table.swap(newTable._table);
		}

		//���������ϣ����Ҳ������Ϊ������������
		size_t index = kv.first & _table.size();//����ģcapacity

		//��������̽��
		while (_table[index]._state == EXIST)
		{
			index++;
			index %= _table.size();//����size��Χ�����»ص����0
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