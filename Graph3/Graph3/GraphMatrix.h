#pragma once
#include "Graph.h"
template <class TypeOfVer, class TypeOfEdge>
class adjMatrixGraph : public graph<TypeOfVer, TypeOfEdge> {
public:
    adjMatrixGraph(int vSize, const TypeOfVer d[], const TypeOfEdge noEdgeFlag);
    void insert(TypeOfVer x, TypeOfVer y, TypeOfEdge w);
    void remove(TypeOfVer x, TypeOfVer y);
    bool exist(TypeOfVer x, TypeOfVer y) const;
    ~adjMatrixGraph();

private:
    TypeOfEdge** edge;  // �����ڽӾ���
    TypeOfVer* ver;     // ���涥��ֵ
    TypeOfEdge noEdge;  // �ڽӾ�����û�бߵı�ʾֵ
    int find(TypeOfVer v) const {
        for (int i = 0; i < this->Vers; ++i)
            if (ver[i] == v) return i;
    }
};

template <class TypeOfVer, class TypeOfEdge>
adjMatrixGraph<TypeOfVer, TypeOfEdge>::adjMatrixGraph(
    int vSize, const TypeOfVer d[], const TypeOfEdge noEdgeFlag) {
    int i, j;
    this->Vers = vSize;
    this->Edges = 0;
    noEdge = noEdgeFlag;
    // �洢���������ĳ�ʼ��
    ver = new TypeOfVer[vSize];
    for (i = 0; i < vSize; ++i) ver[i] = d[i];
    // �ڽӾ���ĳ�ʼ��
    edge = new TypeOfEdge * [vSize];
    for (i = 0; i < vSize; ++i) {
        edge[i] = new TypeOfEdge[vSize];
        for (j = 0; j < vSize; ++j) edge[i][j] = noEdge;
        edge[i][i] = 0;
    }
}
template <class TypeOfVer, class TypeOfEdge>
adjMatrixGraph<TypeOfVer, TypeOfEdge>::~adjMatrixGraph() {
    delete[] ver;
    for (int i = 0; i < this->Vers; ++i)
        delete[] edge[i];  // �ͷ��ڽӾ����е�ÿһ��
    delete[] edge;
}
template <class TypeOfVer, class TypeOfEdge>
void adjMatrixGraph<TypeOfVer, TypeOfEdge>::insert(
    TypeOfVer x, TypeOfVer y, TypeOfEdge w) {
    int u = find(x), v = find(y);
    edge[u][v] = w;
    ++this->Edges;
}
template <class TypeOfVer, class TypeOfEdge>
void adjMatrixGraph<TypeOfVer, TypeOfEdge>::remove(
    TypeOfVer x, TypeOfVer y) {
    int u = find(x), v = find(y);
    edge[u][v] = noEdge;
    --this->Edges;
}
template <class TypeOfVer, class TypeOfEdge>
bool adjMatrixGraph<TypeOfVer, TypeOfEdge>::exist(
    TypeOfVer x, TypeOfVer y) const {
    int u = find(x), v = find(y);
    if (edge[u][v] == noEdge)
        return false;
    else
        return true;
}