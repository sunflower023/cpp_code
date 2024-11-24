

#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string.h>

#include "GraphList.h"
#include"GraphMatrix.h"
using namespace std;

void test1()
{
		// 邻接表实现的图类的测试程序
	// 插入边：insert
	// 查询边：exist
	// 移除： remove
	// 退出：exit
	// 广度优先搜索：bfs
	// 深度优先搜索：dfs
	// 样例输入：
	// 请输入图的顶点个数：4
	// 请输入操作：
	// insert 0 1 0.1
	// insert 1 2 1
	// insert 0 3 0.5
	// insert 3 2 0.5
	// insert 1 0 0.9
	// exist 1 2
	// exist 2 3
	// bfs
	// dfs
	// remove 1 2
	// exist 1 2
	// exit

	// 样例输出：
	// true
	// false
	// 当前图的BFS序列为：
	// 0    3   1   2
	// 当前图的DFS序列为：
	// 0    3   2   1
	// false
	cout << "请输入图的顶点个数：";
	int verSize;
	cin >> verSize;
	int* d = new int[verSize];
	for (int i = 0; i < verSize; i++) d[i] = i;
	adjListGraph<int, double>* adj_list_graph =
		new adjListGraph<int, double>(verSize, d);
	cout << "\n请输入操作：" << endl;
	int u, v;
	double w;
	while (true) {
		char op[10];
		cin >> op;
		if (strcmp(op, "insert") == 0) {
			cin >> u >> v >> w;
			adj_list_graph->insert(u, v, w);
		}
		else if (strcmp(op, "remove") == 0) {
			cin >> u >> v;
			adj_list_graph->remove(u, v);
		}
		else if (strcmp(op, "exist") == 0) {
			cin >> u >> v;
			cout << (adj_list_graph->exist(u, v) ? "true" : "false")
				<< endl;
		}
		else if (strcmp(op, "bfs") == 0) {
			adj_list_graph->bfs();
		}
		else if (strcmp(op, "dfs") == 0) {
			adj_list_graph->dfs();
		}
		else if (strcmp(op, "exit") == 0) {
			break;
		}
		else {
			cout << "Invalid Operation!" << endl;
		}
	}
}

void test2()
{
	// 邻接表实现的拓扑排序的测试程序
// 样例输入（以图9-12为例）：
// 请输入图的顶点个数：8
// 请依次输入有向图的边(-1 -1表示输入完毕)：
// 0 1
// 1 2
// 1 3
// 3 5
// 2 5
// 2 4
// 2 6
// 3 7
// 5 6
// 6 4
// 5 7
// -1 -1
// 样例输出：
// 拓扑排序为：
// 0  1 3 2 5 6 7 4
	cout << "请输入图的顶点个数：";
	int verSize;
	cin >> verSize;
	int* d = new int[verSize];
	for (int i = 0; i < verSize; i++) d[i] = i;
	adjListGraph<int, double>* adj_list_graph =
		new adjListGraph<int, double>(verSize, d);
	cout << "请依次输入有向图的边(-1 -1表示输入完毕)：";
	while (true) {
		int u, v;

		cin >> u >> v;
		if (u == -1) {
			break;
		}
		else {
			adj_list_graph->insert(u, v, 1);
		}
	}

	adj_list_graph->topSort();

}

int main() {

	//test1();
	test2();
	return 0;
}