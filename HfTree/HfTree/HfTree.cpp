//#include"HfTree.h"
//
//template<class T>
//HfTree<T>::HfTree(const T* x, const int* w, int size)
//{
//	int min1, min2;
//	int z, y;
//
//	length = 2 * size;
//	elem = new Node[length];
//	for (int i = size; i < length; i++)
//	{
//		//给[size,length)节点初始化
//		elem[i].weight = w[i - size];
//		elem[i].data = x[i - size];
//		elem[i].parent = elem[i].left = elem[i].right = 0;
//	}
//
//	//给(0,size-1]节点初始化
//	for (int i = size - 1; i > 0; i--)
//	{
//		const int MAX_INT = 32767;
//		min1 = min2 = MAX_INT;
//		z = y = 0;
//		
//		//从[i+1,length]中parent=0的节点中找出最小和次小
//		for (int j = i + 1;j < length; j++)
//		{
//			if (elem[j].parent = 0)
//			{
//				if (elem[j].weight < min1)
//				{
//					min2 = min1;
//					y = z;
//					min1 = elem[j].weight;
//					z = j;
//				}
//				else if (elem[j].weight < min2)
//				{
//					min2 = elem[j].weight;
//					y = j;
//				}
//			}
//
//			elem[i].weight = min1 + min2;
//			elem[i].left = z;
//			elem[i].right = y;
//
//			elem[z].parent = elem[y].parent = i;
//		}
//	}
//}
//
//template<class T>
//void HfTree<T>::GetCode(HfCode* result)
//{
//	for (int i = size; i < length; i++)
//	{
//		result[i - size].data = elem[i].data;
//		string& c = result[i - size].code;
//
//		int parent = elem[i].parent;
//		int son = i;
//		while (parent)
//		{
//			if (son == elem[parent].left)
//				c += "0";
//			else
//				c += "1";
//
//			son = parent;
//			parent = elem[parent].parent;
//		}
//		reverse(c.begin(), c.end());
//	}
//}
