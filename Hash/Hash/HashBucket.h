#pragma once
#include<iostream>
#include<vector>
using namespace std;

template<class K, class V>
struct HashNode
{
	pair<K, V> _kv;
	HashNode<K, V>* _next;

	HashNode(const pair<K, V>& kv)
		:_kv(kv)
		, _next(nullptr)
	{}
};

template<class K, class V>
class HashTable
{
	typedef HashNode<K, V> Node;
	typedef HashTable<K, V> Self;
public:
	
	bool insert(const pair<K, V>& kv)
	{
		//去重
		if (find(kv.first))
			return false;
		//扩容，负载因子到0就扩容
		if (_size == _table.size())
		{
			vector<Node*> newTable;
			size_t newSize = _table.size() == 0:10 : _table.size() * 2;
			newTable.resize(newSize, nullptr);
			//将旧表数据导入新表
			for (int i = 0; i < _table.size(); i++)
			{
				Node* cur = _table[i];
				while (cur)
				{
					Node* next = cur->_next;
					//获取新表的哈希映射值
					size_t pos = cur->_kv.first % newTable.size();
					cur->_next = newTable[pos];
					newTable[pos] = cur;
					cur = next;
				}
				_table[i] = nullptr;
			}
			_table.swap(newTable);
		}
		size_t pos = kv.first % _table.size();
		//头插
		Node* newnode = new Node(kv);
		newnode->_next = _table[pos];
		_table[pos] = newnode;
		++_size;

		return true;
	}

	Node* find(const K& key)
	{
		if (_table.size() == 0)
			return nullptr;

		size_t pos = key & _table.size();
		Node* cur = _table[pos];
		while (cur)
		{
			if (cur->_kv.first == key)
				return cur;
			cur = cur->_next;
		}
		return nullptr;
	}

	bool erase(const K& key)
	{
		Node* ret = find(key);
		if (ret == nullptr)
			return false;
		size_t pos = key % _table.size();
		Node* cur = _table[pos];
		Node* prev = nullptr;
		//找到要删除的节点
		while (cur && cur->_kv.fisrt != key)
		{
			prev = cur;
			cur = cur->_next;
		}
		Node* next = cur->_next;
		if (cur == _table[pos])
			_table[pos] = next;
		else
			prev->_next = next;

		delete cur;
		cur = nullptr;
		_size--;

		return true;
	}

private:
	vector<Node*> _table;
	size_t _size = 0;
};