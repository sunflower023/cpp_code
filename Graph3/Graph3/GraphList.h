#pragma once
#include <iostream>
#include "linkQueue.h"//�Ҵ��룬�����½�������ʽ����
#include "Graph.h"

using namespace std;
struct EulerNode {
    int NodeNum;
    EulerNode* next;
    EulerNode(int ver) {
        NodeNum = ver;
        next = nullptr;
    }
};
template <class TypeOfVer, class TypeOfEdge>
class adjListGraph : public graph<TypeOfVer, TypeOfEdge> {
public:
    adjListGraph(int vSize, const TypeOfVer d[]); //����
    void insert(TypeOfVer x, TypeOfVer y, TypeOfEdge w); //�����
    void remove(TypeOfVer x, TypeOfVer y); //ɾ����
    bool exist(TypeOfVer x, TypeOfVer y) const; //�ж���������Ƿ��ڽ�
    void dfs() const;  //�������
    void bfs() const; //�������
    void EulerCircuit(TypeOfVer start); //ŷ����·
    void topSort() const;  //��������
    void criticalPath() const; //�ؼ�·��
    ~adjListGraph();

private:
    struct edgeNode {     // �ڽӱ��д洢����
        int end;            // �յ���
        TypeOfEdge weight;  // �ߵ�Ȩֵ
        edgeNode* next;
        edgeNode(int e, TypeOfEdge w, edgeNode* n = nullptr) {
            end = e;
            weight = w;
            next = n;
        }
    };
    struct verNode {   // ���涥�����������
        TypeOfVer ver;   // ����ֵ
        edgeNode* head;  // ��Ӧ�ĵ������ͷָ��
        verNode(edgeNode* h = nullptr) { head = h; }
    };
    verNode* verList;  //�ڽӱ�  ��һά����ṹ������

    int find(TypeOfVer v) const {
        for (int i = 0; i < this->Vers; ++i)
            if (verList[i].ver == v) return i;
    }
    void dfs(int start, bool visited[]) const;  //��������ڲ�����
    verNode* clone() const;
    void EulerCircuit(int start, EulerNode*& beg, EulerNode*& end);
};

template <class TypeOfVer, class TypeOfEdge>
adjListGraph<TypeOfVer, TypeOfEdge>::adjListGraph(
    int vSize, const TypeOfVer d[]) {
    this->Vers = vSize;
    this->Edges = 0;
    verList = new verNode[vSize];
    for (int i = 0; i < this->Vers; ++i) verList[i].ver = d[i];
}

template <class TypeOfVer, class TypeOfEdge>
adjListGraph<TypeOfVer, TypeOfEdge>::~adjListGraph() {
    edgeNode* p;
    for (int i = 0; i < this->Vers; ++i)  // �ͷŵ�i������ĵ�����
        while ((p = verList[i].head) != nullptr) {
            verList[i].head = p->next;
            delete p;
        }
    delete[] verList;
}

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::insert(TypeOfVer x, TypeOfVer y, TypeOfEdge w) {
    int u = find(x), v = find(y);
    verList[u].head = new edgeNode(v, w, verList[u].head);
    ++this->Edges;
}

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::remove(
    TypeOfVer x, TypeOfVer y) {
    int u = find(x), v = find(y);
    edgeNode* p = verList[u].head, * q;
    if (p == nullptr) return;  // ����uû�������ı�
    if (p->end == v) {  // �������еĵ�һ�������Ǳ�ɾ���ı�
        verList[u].head = p->next;
        delete p;
        --this->Edges;
        return;
    }
    while (p->next != nullptr && p->next->end != v)
        p = p->next;             // ���ұ�ɾ���ı�
    if (p->next != nullptr) {  // ɾ��
        q = p->next;
        p->next = q->next;
        delete q;
        --this->Edges;
    }
}

template <class TypeOfVer, class TypeOfEdge>
bool adjListGraph<TypeOfVer, TypeOfEdge>::exist(TypeOfVer x, TypeOfVer y) const {
    int u = find(x), v = find(y);
    edgeNode* p = verList[u].head;
    while (p != nullptr && p->end != v) p = p->next;
    if (p == nullptr)
        return false;
    else
        return true;
}

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::dfs() const {
    bool* visited = new bool[this->Vers];  // ��¼ÿ�������Ƿ��ѱ�����
    for (int i = 0; i < this->Vers; ++i) visited[i] = false;
    cout << "��ǰͼ��DFS��������Ϊ��" << endl;
    for (int i = 0; i < this->Vers; ++i) {
        if (visited[i] == true) continue;
        dfs(i, visited);
        cout << endl;
    }
}

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::dfs(int start, bool visited[]) const {
    edgeNode* p = verList[start].head;
    cout << verList[start].ver << '\t';  // ���ʶ���
    visited[start] = true;
    while (p != nullptr) {  // ��start�ĺ�̶������dfs
        if (visited[p->end] == false)
            dfs(p->end, visited);
        p = p->next;
    }
}

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::bfs() const {
    bool* visited = new bool[this->Vers];
    int currentNode;
    linkQueue<int> q;  //��������
    edgeNode* p;
    for (int i = 0; i < this->Vers; ++i)
        visited[i] = false;  // ��ʼ������Ԫ��Ϊδ����
    cout << "��ǰͼ��BFS����Ϊ��" << endl;
    for (int i = 0; i < this->Vers; ++i) {
        if (visited[i] == true) continue;
        q.enQueue(i);
        while (!q.isEmpty()) {
            currentNode = q.deQueue();
            if (visited[currentNode] == true) continue;
            cout << verList[currentNode].ver << '\t';
            visited[currentNode] = true;
            p = verList[currentNode].head;
            while (p != nullptr) {  // ��currentNode�ĺ�̶������
                if (visited[p->end] == false) q.enQueue(p->end);
                p = p->next;
            }
        }
        cout << endl;
    }
}

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::EulerCircuit(
    int start, EulerNode*& beg, EulerNode*& end) {
    int nextNode;
    beg = end = new EulerNode(start);  // ����ʼ�������ŷ����·
    while (verList[start].head != nullptr) {  // start�������б�δ������
        nextNode = verList[start].head->end;
        remove(start, nextNode);
        remove(nextNode, start);
        start = nextNode;
        end->next = new EulerNode(start);
        end = end->next;
    }
}

template <class TypeOfVer, class TypeOfEdge>
typename adjListGraph<TypeOfVer, TypeOfEdge>::verNode*
adjListGraph<TypeOfVer, TypeOfEdge>::clone() const {
    verNode* tmp = new verNode[this->Vers];
    edgeNode* p;
    for (int i = 0; i < this->Vers; ++i) { // ����ÿ���������ڽӱ��е���Ϣ
        tmp[i].ver = verList[i].ver;  // �����±�Ϊi�Ķ���
        p = verList[i].head;
        while (p != nullptr) {  // �����±�Ϊi�Ķ����Ӧ�ıߵ���Ϣ
            tmp[i].head = new edgeNode(p->end, p->weight, tmp[i].head);
            p = p->next;
        }
    }
    return tmp;
}

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::EulerCircuit(
    TypeOfVer start) {
    // beg��end�ֱ�Ϊŷ����·�������յ�
    EulerNode* beg, * end, * p, * q, * tb, * te;
    int numOfDegree;
    edgeNode* r;
    verNode* tmp;
    // ����Ƿ����ŷ����·
    if (this->Edges == 0) {
        cout << "������ŷ����·" << endl;
        return;
    }
    for (int i = 0; i < this->Vers; ++i) {
        numOfDegree = 0;
        r = verList[i].head;
        while (r != 0) {
            ++numOfDegree;
            r = r->next;
        }
        if (numOfDegree % 2) {
            cout << "������ŷ����·" << endl;
            return;
        }
    }
    // Ѱ����ʼ����ı��
    int i = find(start);
    tmp = clone();  // ����һ���ڽӱ�ı���
    // Ѱ�Ҵ�i������·����·���������յ��ַ�ֱ���beg��end
    EulerCircuit(i, beg, end);
    while (true) {
        p = beg;
        while (p->next != nullptr)  // ���p�ĺ�̶����Ƿ��б���δ������
            if (verList[p->next->NodeNum].head != nullptr)
                break;
            else
                p = p->next;
        if (p->next == nullptr) break;  // ���б߶��ѱ�����
        q = p->next;                    // ����δ�����ʱߵĶ���
        EulerCircuit(q->NodeNum, tb, te);  // �Ӵ˶��㿪ʼѰ��һ��·��
        te->next = q->next;  // ����������·��ƴ�ӵ�ԭ����·����
        p->next = tb;
        delete q;
    }
    // �ָ�ԭͼ
    delete[] verList;
    verList = tmp;
    // ��ʾ�õ���ŷ����·
    cout << "ŷ����·�ǣ�" << endl;
    while (beg != nullptr) {
        cout << verList[beg->NodeNum].ver << '\t';
        p = beg;
        beg = beg->next;
        delete p;
    }
    cout << endl;
}

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::topSort() const {
    linkQueue<int> q;
    edgeNode* p;
    int current;
    int* inDegree = new int[this->Vers];
    for (int i = 0; i < this->Vers; ++i) { inDegree[i] = 0; }
    for (int i = 0; i < this->Vers; ++i) {  // ����ÿ����������
        for (p = verList[i].head; p != nullptr; p = p->next)
            ++inDegree[p->end];
    }
    for (int i = 0; i < this->Vers; ++i)  // �����Ϊ0�Ķ������
        if (inDegree[i] == 0) q.enQueue(i);
    cout << "��������Ϊ��" << endl;
    while (!q.isEmpty()) {
        current = q.deQueue();
        cout << verList[current].ver << '\t';
        for (p = verList[current].head; p != nullptr; p = p->next)
            if (--inDegree[p->end] == 0) q.enQueue(p->end);
    }
    cout << endl;
}

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::criticalPath() const {
    TypeOfEdge* ee = new TypeOfEdge[this->Vers],
        * le = new TypeOfEdge[this->Vers];
    // top ������������
    int* top = new int[this->Vers], * inDegree = new int[this->Vers];
    linkQueue<int> q;
    int i;
    edgeNode* p;
    // �ҳ��������У���������top
    for (i = 0; i < this->Vers; ++i) {  // ����ÿ����������
        inDegree[i] = 0;
    }
    for (int i = 0; i < this->Vers; ++i) {
        for (p = verList[i].head; p != nullptr; p = p->next)
            ++inDegree[p->end];
    }

    for (i = 0; i < this->Vers; ++i)  // �����Ϊ0�Ķ������
        if (inDegree[i] == 0) q.enQueue(i);
    i = 0;
    while (!q.isEmpty()) {
        top[i] = q.deQueue();
        for (p = verList[top[i]].head; p != nullptr; p = p->next)
            if (--inDegree[p->end] == 0)
                q.enQueue(p->end);
        ++i;
    }
    // �����緢��ʱ��
    for (i = 0; i < this->Vers; ++i) ee[i] = 0;
    for (i = 0; i < this->Vers; ++i) {  // �ҳ����緢��ʱ�䲢����������ee��
        for (p = verList[top[i]].head; p != nullptr; p = p->next)
            if (ee[p->end] < ee[top[i]] + p->weight)
                ee[p->end] = ee[top[i]] + p->weight;
    }
    // ����ٷ���ʱ��
    for (i = 0; i < this->Vers; ++i) le[i] = ee[this->Vers - 1];
    for (i = this->Vers - 1; i >= 0; --i)  // �ҳ���ٷ���ʱ�䲢����������le��
        for (p = verList[top[i]].head; p != nullptr; p = p->next)
            if (le[p->end] - p->weight < le[top[i]])
                le[top[i]] = le[p->end] - p->weight;

    cout << "��ǰͼ�Ĺؼ�·���ǣ�";
    for (i = 0; i < this->Vers; ++i)  // �ҳ��ؼ�·��
        if (le[top[i]] == ee[top[i]])
            cout << "(" << verList[top[i]].ver << ", " << ee[top[i]] << ") ";
}