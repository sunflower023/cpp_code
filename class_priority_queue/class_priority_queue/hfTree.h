#pragma once
#include"PriorityQueue.h"
#include<iostream>
#include<string>
using namespace std;


template<class T>
class HfTree
{
public:
	struct HfCode
	{
		T data;
		string code;
	};

	HfTree(const T* v, const int* w, int size)
	{
		const int MAX_INT = 32767;
		int min1, min2;
		int x, y;

		length = 2 * size;
		elem = new Node[length];
		for (int i = size; i < length; ++i)
		{
			//给[size,length)节点初始化
			elem[i].weight = w[i - size];
			elem[i].data = v[i - size];
			elem[i].parent = elem[i].left = elem[i].right = 0;

			//给下标
			elem[i].index = i;
		}

		priorityQueue<Node, Node_Less> p(size);
		for (int j = size; j < length; j++)
		{
			p.enQueue(elem[j]);
		}

		//给(0,size-1]节点初始化
		for (int i = size - 1; i > 0; --i)
		{
			min1 = min2 = MAX_INT;
			x = y = 0;

			Node tmp = p.deQueue();
			min1 = tmp.weight;
			x = tmp.index;

			tmp = p.deQueue();
			min2 = tmp.weight;
			y = tmp.index;
			
			elem[i].weight = min1 + min2;
			elem[i].left = x;
			elem[i].right = y;
			elem[i].parent = 0;
			elem[i].index = i;

			//新节点入队列
			p.enQueue(elem[i]);

			elem[x].parent = elem[y].parent = i;
		}
	}

	void GetCode(HfCode* result)
	{
		int size = length / 2;
		for (int i = size; i < length; i++)
		{
			result[i - size].data = elem[i].data;
			string& c = result[i - size].code;

			int parent = elem[i].parent;
			int son = i;
			while (parent)
			{
				if (son == elem[parent].left)
					c += "0";
				else
					c += "1";

				son = parent;
				parent = elem[parent].parent;
			}
			reverse(c.begin(), c.end());
		}
	}

	~HfTree()
	{
		delete[] elem;
	}

private:
	struct Node
	{
		T data;
		int weight;
		int parent, left, right;

		//保留原本的下标
		int index;
	};

	class Node_Less
	{
	public:
		bool operator()(Node p1, Node p2)
		{
			//parent为0的优先级更高
			if (p1.parent == 0)
			{
				if (p2.parent == 0)
					return p1.weight < p2.weight;
				else
					return true;
			}
		}
	};

	Node* elem;
	int length;
};