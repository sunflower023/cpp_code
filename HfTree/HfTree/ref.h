#pragma once
#pragma once
#include<iostream>
#include<string>
using namespace std;

template<class Type>
class hfTree
{
public:
	struct hfCode
	{
		Type data;
		string code;
	};

	template <class Type>
	hfTree(const Type* v, const int* w, int size)
	{
		const int MAX_INT = 32767;
		int min1, min2;    //最小树、次最小树的权值
		int x, y;     //最小树、次最小树的下标

		//置初值 
		length = 2 * size;
		elem = new Node[length];
		for (int i = size; i < length; ++i)
		{
			elem[i].weight = w[i - size];
			elem[i].data = v[i - size];
			elem[i].parent = elem[i].left = elem[i].right = 0;
		}
		// 构造新的二叉树
		for (int i = size - 1; i > 0; --i)
		{
			min1 = min2 = MAX_INT; x = y = 0;
			for (int j = i + 1; j < length; ++j)
				if (elem[j].parent == 0)
					if (elem[j].weight < min1)
					{
						min2 = min1; min1 = elem[j].weight;
						x = y; y = j;
					}
					else if (elem[j].weight < min2)
					{
						min2 = elem[j].weight; x = j;
					}
			elem[i].weight = min1 + min2;
			elem[i].left = x; elem[i].right = y; elem[i].parent = 0;
			elem[x].parent = i; elem[y].parent = i;
		}
	}



	void getCode(hfCode result[])
	{
		int size = length / 2;
		int p, s; // s是追溯过程中正在处理的结点，p是s的父结点下标
		for (int i = size; i < length; ++i)
		{
			result[i - size].data = elem[i].data;
			result[i - size].code = "";
			p = elem[i].parent; s = i;
			while (p) {
				if (elem[p].left == s)
					result[i - size].code = '0' + result[i - size].code;
				else result[i - size].code = '1' + result[i - size].code;
				s = p; p = elem[p].parent;
			}
		}
	}

	~hfTree()
	{
		delete[] elem;
	}

private:
	struct Node
	{
		Type data;
		int weight;
		int parent, left, right;
	};

	Node* elem;
	int length;
};