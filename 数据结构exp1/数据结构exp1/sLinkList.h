#ifndef CHAPTER2_SLINKLIST_H
#define CHAPTER2_SLINKLIST_H

#include <iostream>

#include "list.h"
using namespace std;

template <class elemType>
class sLinkList : public list<elemType> {
private:
	struct node {
		elemType data;
		node* next;
		node* prev;
		node(const elemType& x, node* n = nullptr, node* p = nullptr) {
			data = x;
			next = n;
			prev = p;
		}
		node() : next(nullptr), prev(nullptr) {}
		~node() {};
	};

	node* head;
	int currentLength;
	node* find(int i) const;

public:
	sLinkList() {
		head = new node;  // 申请头结点
		head->next = head;
		head->prev = head;
		currentLength = 0;
	}
	~sLinkList() {
		clear();
		delete head;  // 删除头结点
	}
	void clear();
	int length() const { return currentLength; }
	void insert(int i, const elemType& x);
	void remove(int i);
	int search(const elemType& x) const;
	elemType visit(int i) const;
	void traverse() const;
};

template <class elemType>
void sLinkList<elemType>::insert(int i, const elemType& x) {
	node* pos;
	pos = find(i - 1); 
	node* newnode = new node(x);
	newnode->prev = pos;
	newnode->next = pos->next;
	pos->next->prev = newnode;
	pos->next = newnode;
	++currentLength;
}

template <class elemType>
void sLinkList<elemType>::remove(int i) {
	node* delp = find(i);
	delp->prev->next = delp->next;
	delp->next->prev = delp->prev;
	delete delp;
	--currentLength;
}

// 按序删除头结点以外的所有真的包含元素的结点
template <class elemType>
void sLinkList<elemType>::clear() {
	node* cur = head->next, * tmp;
	head->next = head;
	head->prev = head;
	while (cur != head)
	{
		tmp = cur->next;
		delete cur;
		cur = tmp;
	}
	currentLength = 0;
}

// 返回第i个结点的地址
template <class elemType>
typename sLinkList<elemType>::node* sLinkList<elemType>::find(
	int i) const {
	node* p = head;
	while (i-- >= 0) p = p->next;
	return p;
}

template <class elemType>
int sLinkList<elemType>::search(const elemType& x) const {
	node* p = head->next;
	int i = 0;
	while (p != head && p->data != x) {
		p = p->next;
		++i;
	}
	if (p == head)
		return -1;
	else
		return i;
}

template <class elemType>
elemType sLinkList<elemType>::visit(int i) const {
	return find(i)->data;  // 找到第i个结点的地址，访问其中的data
}

template <class elemType>
void sLinkList<elemType>::traverse() const {
	node* p = head->next;
	while (p != head) {
		cout << p->data << "  ";
		p = p->next;
	}
	cout << endl;

	////测试双向是否成立，从后往前遍历
	//node* p = head->prev;
	//while (p != head) {
	//	cout << p->data << "  ";
	//	p = p->prev;
	//}
	cout << endl;
}

#endif  // CHAPTER2_SLINKLIST_H
