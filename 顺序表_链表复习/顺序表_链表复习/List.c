#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"

Node* CreateNode(ListDatatype x)
{
	Node* tmp = (Node*)malloc(sizeof(Node));
	if (tmp == NULL)
	{
		printf("malloc fail");
		exit(1);
	}
	tmp->val = x;
	tmp->next = NULL;
	return tmp;
}

void Print(Node* p)
{
	while (p)
	{
		printf("%d->", p->val);
		p = p->next;
	}
	printf("NULL\n");
}

void PushBack(Node** head, ListDatatype x)
{
	if (*head == NULL)
	{
		*head = CreateNode(x);
	}
	else
	{
		Node* pcur = *head;
		while (pcur->next != NULL)
		{
			pcur = pcur->next;
		}
		pcur->next = CreateNode(x);
	}
}
void PushFront(Node** head, ListDatatype x)
{
	if (*head == NULL)
	{
		*head = CreateNode(x);
	}
	else
	{
		Node* tmp = CreateNode(x);
		tmp->next = *head;
		*head = tmp;
	}
}

void PopBack(Node** head)
{
	assert(head);
	assert(*head);
	Node* tmp = *head;
	if (tmp->next == NULL)
	{
		free(tmp);
		*head = NULL;
	}
	else
	{
		while (tmp->next->next != NULL)
		{
			tmp = tmp->next;
		}
		free(tmp->next);
		tmp->next = NULL;
	}
	
}
void PopFront(Node** head)
{
	assert(head);
	assert(*head);
	Node* tmp = *head;
	if (tmp->next == NULL)
	{
		free(tmp);
		*head = NULL;
	}
	else
	{
		*head = tmp->next;
		free(tmp);
	}
}

Node* Find(Node* head,ListDatatype x)
{
	assert(head);
	while (head && head->val != x)
	{
		head = head->next;
	}
	return head;
}

void Insert(Node** head, ListDatatype x,Node* pos)
{
	assert(head);
	if (*head == NULL)
	{
		PushBack(head, x);
	}
	else
	{
		Node* tmp = *head;
		while (tmp->next != pos)
		{
			tmp = tmp->next;
		}
		Node* new = CreateNode(x);
		tmp->next = new;
		new->next = pos;
	}
}