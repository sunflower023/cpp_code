

#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string.h>

#include "GraphList.h"
#include"GraphMatrix.h"
using namespace std;

void test1()
{
		// �ڽӱ�ʵ�ֵ�ͼ��Ĳ��Գ���
	// ����ߣ�insert
	// ��ѯ�ߣ�exist
	// �Ƴ��� remove
	// �˳���exit
	// �������������bfs
	// �������������dfs
	// �������룺
	// ������ͼ�Ķ��������4
	// �����������
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

	// ���������
	// true
	// false
	// ��ǰͼ��BFS����Ϊ��
	// 0    3   1   2
	// ��ǰͼ��DFS����Ϊ��
	// 0    3   2   1
	// false
	cout << "������ͼ�Ķ��������";
	int verSize;
	cin >> verSize;
	int* d = new int[verSize];
	for (int i = 0; i < verSize; i++) d[i] = i;
	adjListGraph<int, double>* adj_list_graph =
		new adjListGraph<int, double>(verSize, d);
	cout << "\n�����������" << endl;
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
	// �ڽӱ�ʵ�ֵ���������Ĳ��Գ���
// �������루��ͼ9-12Ϊ������
// ������ͼ�Ķ��������8
// ��������������ͼ�ı�(-1 -1��ʾ�������)��
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
// ���������
// ��������Ϊ��
// 0  1 3 2 5 6 7 4
	cout << "������ͼ�Ķ��������";
	int verSize;
	cin >> verSize;
	int* d = new int[verSize];
	for (int i = 0; i < verSize; i++) d[i] = i;
	adjListGraph<int, double>* adj_list_graph =
		new adjListGraph<int, double>(verSize, d);
	cout << "��������������ͼ�ı�(-1 -1��ʾ�������)��";
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