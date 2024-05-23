#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

class LinkList
{
private:
	struct Node
	{
		int val;
		Node* next;
	};

	Node* head = nullptr;

public:
	//构造函数
	LinkList()
	{
		//head->next = nullptr;
		//head->val = 0;
	}
	//析构函数
	~LinkList()
	{
		Node* pcur = head;
		while (pcur)
		{
			Node* tmp = pcur->next;
			delete pcur;
			pcur = tmp;
		}
		head = nullptr;
	}

	//头插
	void PushFront(int x)
	{
		Node* newnode = new Node();
		newnode->val = x;
		if (head == nullptr)
		{
			head = newnode;
		}
		else
		{
			newnode->next = head;
			head = newnode;
		}
	}

	//尾插
	void PushBack(int x)
	{
		Node* newnode = new Node();
		newnode->val = x;
		if (head == nullptr)
		{
			head = newnode;
		}
		else
		{
			Node* pcur = head;
			while (pcur->next)
			{
				pcur = pcur->next;
			}
			pcur->next = newnode;
		}
	}

	//头删
	void PopFront()
	{
		if (head == nullptr)
			throw - 1;
		Node* pcur = head->next;
		free(head);
		head = pcur;
	}

	//打印
	void print()
	{
		Node* pcur = head;
		while (pcur)
		{
			printf("%d->", pcur->val);
			pcur = pcur->next;
		}
		printf("nullptr\n");
	}

	//拷贝构造函数
	LinkList(const LinkList& o)
	{
		head = nullptr;
		Node* pcur = o.head;
		while (pcur)
		{
			PushBack(pcur->val);
			pcur = pcur->next;
		}
	}

	//赋值运算符重载
	LinkList& operator=(const LinkList& o)
	{
		head = nullptr;
		Node* pcur = o.head;
		while (pcur)
		{
			PushBack(pcur->val);
			pcur = pcur->next;
		}
		return *this;
	}
};

int main()
{
	LinkList l;
	l.PushFront(7);
	l.PushFront(6);
	l.PushFront(5);
	//l.print();
	l.PushBack(8);
	l.PushBack(9);
	l.print();
	//l.PopFront();
	//l.PopFront();
	//l.print();

	LinkList l2 = l;
	l2.print();

	LinkList l3 = l;
	l3.print();

	return 0;
}