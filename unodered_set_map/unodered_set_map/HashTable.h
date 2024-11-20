#pragma once
#include<vector>
#include<string>
using namespace std;

enum State
{
	EMPTY,
	EXIST,
	DELETE
};

//��ϣ��洢������
template<class K,class V>
struct HashDate
{
	pair<K, V> _kv;
	State _state = EMPTY;
};

//ת��Ϊ����
template<class K>
struct HashFunc
{
	size_t operator()(const K& key)
	{
		return (size_t)key;
	}
};

template<>
struct HashFunc<string>
{
	size_t operator()(const string& s)
	{
		// BKDR
		size_t hash = 0;
		for (auto ch : s)
		{
			hash += ch;
			hash *= 131;
		}

		return hash;
	}
};
//��������ϣ������ʱʹ�ð���һ����������
inline unsigned long __stl_next_prime(unsigned long n)
{
	// Note: assumes long is at least 32 bits.
	static const int __stl_num_primes = 28;
	static const unsigned long __stl_prime_list[__stl_num_primes] = {
		53, 97, 193, 389, 769,
		1543, 3079, 6151, 12289, 24593,
		49157, 98317, 196613, 393241, 786433,
		1572869, 3145739, 6291469, 12582917, 25165843,
		50331653, 100663319, 201326611, 402653189, 805306457,
		1610612741, 3221225473, 4294967291
	};
	const unsigned long* first = __stl_prime_list;
	const unsigned long* last = __stl_prime_list + __stl_num_primes;
	const unsigned long* pos = lower_bound(first, last, n);
	return pos == last ? *(last - 1) : *pos;
}

namespace hash_bucket
{
	template<class T>
	struct HashNode
	{
		T _data;
		HashNode<T>* _next;

		HashNode(const T& data)
			:_data(data)
			,_next(nullptr)
		{}
	};

	//ǰ���������ú���ʵ�ֵ�HashTable������֪����HashTable�����
	template<class K, class T, class KeyOfT, class Hash>
	class HashTable;

	template<class K,class T,class Ref,class Ptr,class KeyOfT,class Hash>
	struct HTIterator
	{
		typedef HashNode<T> Node;
		typedef HashTable<K, T, KeyOfT, Hash> HT;
		typedef HTIterator<K, T, Ref, Ptr, KeyOfT, Hash> Self;
		
		Node* _node;
		const HT* _ht;

		HTIterator(Node* node,const HT* ht)
			:_node(node)
			,_ht(ht)
		{}

		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &_node->_data;
		}

		bool operator!=(const Self& s)
		{
			return _node != s._node;
		}

		Self& operator++()
		{
			if (_node->_next)
			{
				//��ǰͰ�������ݣ��ߵ���Ͱ����һ���ڵ�
				_node = _node->_next;
			}
			else
			{
				//��ǰͰ�����ˣ�����һ����Ϊ�յ�Ͱ
				KeyOfT kot;
				Hash hash;
				size_t hashi = hash(kot(_node->_data)) % _ht->_table.size();
				++hashi;
				while (hashi < _ht->_table.size())
				{
					_node = _ht->_table[hashi];
					if (_node)
						break;
					else
						hashi++;
				}

				if (hashi == _ht->_table.size())
				{
					_node = nullptr;
				}
			}
			return *this;
		}
	};

	template<class K, class T, class KeyOfT, class Hash>
	class HashTable
	{
		typedef HashNode<T> Node;
		//��Ԫ����
		template<class K,class T,class Ref,class Ptr,class KeyOfT,class Hash>
		friend struct HTIterator;

	public:

		HashTable()
			:_table(__stl_next_prime(0))
			,_n(0)
		{}

		~HashTable()
		{
			for (int i = 0; i < _table.size(); i++)
			{
				Node* cur = _table[i];
				while (cur)
				{
					Node* next = cur->_next;
					delete cur;
					cur = next;
				}

				_table[i] = nullptr;
			}
		}

		typedef HTIterator<K, T, T&, T*, KeyOfT, Hash> Iterator;
		typedef HTIterator<K, T, const T&, const T*, KeyOfT, Hash> ConstIterator;

		Iterator Begin()
		{
			if (_n == 0)
				return End();

			for (size_t i = 0; i < _table.size(); i++)
			{
				Node* cur = _table[i];
				if (cur)
					return Iterator(cur, this);
			}

			return End();
		}

		Iterator End()
		{
			return Iterator(nullptr, this);
		}

		ConstIterator Begin() const
		{
			if (_n == 0)
				return End();

			for (size_t i = 0; i < _table.size(); i++)
			{
				Node* cur = _table[i];
				if (cur)
				{
					return ConstIterator(cur, this);
				}
			}

			return End();
		}

		ConstIterator End() const
		{
			return ConstIterator(nullptr, this);
		}

		pair<Iterator, bool> Insert(const T& data)
		{
			KeyOfT kot;
			Hash hash;

			Iterator it = Find(kot(data));
			if (it != End())
				return { it,false };

			//����
			if (_n == _table.size())
			{
				vector<Node*> newTable(__stl_next_prime(_table.size() + 1));
				for (int i = 0; i < _table.size(); i++)
				{
					Node* cur = _table[i];
					while (cur)
					{
						Node* next = cur->_next;
						size_t hashi = hash(kot(cur->_data)) % newTable.size();
						cur->_next = newTable[hashi];
						newTable[hashi] = cur;
						cur = next;
					}
					_table[i] = nullptr;
				}
				_table.swap(newTable);
			}

			size_t hashi = hash(kot(data)) % _table.size();
			//ͷ��
			Node* newnode = new Node(data);
			newnode->_next = _table[hashi];
			_table[hashi] = newnode;
			++_n;

			return { Iterator(newnode,this),false };
		}

		Iterator Find(const K& key)
		{
			KeyOfT kot;
			Hash hash;

			size_t hashi = hash(key) & _table.size();
			Node* cur = _table[hashi];
			while (cur)
			{
				if (kot(cur->_data) == key)
					return Iterator(cur, this);

				cur = cur->_next;
			}
			return End();
		}

		bool Erase(const K& key)
		{
			KeyOfT kot;
			Hash hash;

			size_t hashi = hash(key) % _table.size();
			Node* prev = nullptr;
			Node* cur = _table[hashi];
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					if (prev == nullptr)//ͷ���
					{
						_table[hashi] = cur->_next;
					}
					else
					{
						prev->_next = cur->_next;
					}

					delete cur;
					--_n;
					return true;
				}
				else
				{
					prev = cur;
					cur = cur->_next;
				}
			}

			return false;
		}

	private:
		vector<Node*> _table;
		size_t _n = 0;
	};

}