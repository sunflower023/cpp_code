#pragma once
#include<iostream>
using namespace std;

//仿函数控制大小堆
struct Less
{
	bool operator()(const int& x,const int& y)
	{
		return x < y;
	}
};

struct Greater
{
	bool operator()(const int& x, const int& y)
	{
		return x > y;
	}
};

template<class T,class Compare>
class priorityQueue
{
public:
	priorityQueue(int capacity = 100)
	{
		data = new T[capacity];
		maxSize = capacity;
		currentSize = 0;
	}

	priorityQueue(const T* value, int size)
		:maxSize(size+10)
		,currentSize(size)
	{
		data = new T[maxSize];
		for (int i = 0; i < size; i++)
		{
			data[i + 1] = value[i + 1];
		}
		buildHeap();
	}

	~priorityQueue()
	{
		delete[] data;
		data = nullptr;
		maxSize = currentSize = 0;
	}

	bool isEmpty()
	{
		return currentSize == 0;
	}

	void enQueue(const T& x)
	{
		if (currentSize == maxSize - 1)
			doubleSpace();

		int hole = ++currentSize;
		while (hole > 1 && com(x, data[hole / 2]))
		{
			data[hole] = data[hole / 2];
			hole /= 2;
		}
		data[hole] = x;
	}

	T deQueue()
	{
		T top = data[1];
		data[1] = data[currentSize--];
		percolateDown(1);
		return top;
	}

private:
	int currentSize;
	int maxSize;
	T* data;
	Compare com;

	void doubleSpace()
	{
		maxSize *= 2;
		T* newdata = new T[maxSize];
		memcpy(newdata, data, sizeof(T) * (currentSize + 1));
		delete[] data;
		data = newdata;
	}
	
	void buildHeap()
	{
		for (int i = currentSize / 2; i > 0; i--)
		{
			percolateDown(i);
		}
	}

	void percolateDown(int hole)
	{
		T tmp = data[hole];
		int child = hole * 2;
		while (child <= currentSize)
		{
			if (child + 1 <= currentSize && com(data[child + 1], data[child]))
				child++;

			if(com(data[child],tmp))
				data[hole] = data[child];
			else
				break;

			hole = child;
			child = 2 * hole;
		}
		data[hole] = tmp;
	}
};