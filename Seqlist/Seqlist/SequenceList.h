#pragma once
#include"List.h"

template<class T>
class SeqList
{
public:
	SeqList(int n = 10)
	{
		data = new T[n];
		capacity = n;
		size = 0;
	}
	void clear()
	{
		size = 0;
	}
	int length()const
	{
		return size;
	}
	void insert(int pos, const T& x)
	{
		assert(pos >= 0 && pos <= size);
		if (size == capacity) reserve();
		for (int i = size; i > pos; i--)
		{
			data[i] = data[i - 1];
		}
		data[pos] = x;
		size++;
	}

	void remove(int pos)
	{
		assert(pos >= 0 && pos < size);
		for (int i = pos; i < size - 1; i++)
		{
			data[i] = data[i + 1];
		}
		size--;
	}

	int search(const T& x)const
	{
		for (int i = 0; i < size; i++)
		{
			if (data[i] == x) return i;
		}
	}

	T visit(int pos)const
	{
		return data[pos];
	}

	void traverse()
	{
		for (int i = 0; i < size; i++)
		{
			cout << data[i] << " ";
		}
		cout << endl;
	}

	~SeqList()
	{
		delete data;
		data = nullptr;
		size = capacity = 0;
	}
protected:

	//À©ÈÝ
	void reserve()
	{
		int newcapacity = (capacity == 0) ? 4 : 2 * capacity;
		T* new_data = new T[newcapacity];
		memcpy(new_data,data,sizeof(T)*size);
		delete data;
		data = new_data;
		capacity = newcapacity;
	}

	T* data;
	int capacity;
	int size;
};