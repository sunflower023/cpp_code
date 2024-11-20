#pragma once
#include"HashTable.h"
#include<iostream>
using namespace std;

// MyUnorderedMap.h

template<class K, class V, class Hash = HashFunc<K>>
class unordered_map
{
	struct MapKeyOfT
	{
		const K& operator()(const pair<K, V>& kv)
		{
			return kv.first;
		}
	};
public:

	typedef typename hash_bucket::HashTable<K, pair<const K, V>, MapKeyOfT, Hash>::Iterator iterator;
	typedef typename hash_bucket::HashTable<K, pair<const K, V>, MapKeyOfT, Hash>::ConstIterator const_iterator;

	iterator begin()
	{
		return _ht.Begin();
	}

	iterator end()
	{
		return _ht.End();
	}

	const_iterator begin() const
	{
		return _ht.Begin();
	}

	const_iterator end() const
	{
		return _ht.End();
	}

	V& operator[](const K& key)
	{
		pair<iterator, bool> ret = insert({ key, V() });
		return ret.first->second;
	}

	pair<iterator, bool> insert(const pair<K, V>& kv)
	{
		return _ht.Insert(kv);
	}

	iterator Find(const K& key)
	{
		return _ht.Find(key);
	}

	bool Erase(const K& key)
	{
		return _ht.Erase(key);
	}

private:
	hash_bucket::HashTable<K, pair<const K, V>, MapKeyOfT, Hash> _ht;
};

void test_map1()
{
	unordered_map<string, string> dict;
	dict.insert({ "sort", "����" });
	dict.insert({ "�ַ���", "string" });

	dict.insert({ "sort", "����" });
	dict.insert({ "left", "���" });
	dict.insert({ "right", "�ұ�" });

	dict["left"] = "��ߣ�ʣ��";
	dict["insert"] = "����";
	dict["string"];

	for (auto& kv : dict)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
	cout << endl;

	unordered_map<string, string>::iterator it = dict.begin();
	while (it != dict.end())
	{
		// �����޸�first�������޸�second
		//it->first += 'x';
		it->second += 'x';
		cout << it->first << ":" << it->second << endl;
		++it;
	}
	cout << endl;
}
