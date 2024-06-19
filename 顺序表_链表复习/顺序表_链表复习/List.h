#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int ListDatatype;
typedef struct ListNode
{
	ListDatatype val;
	struct ListNode* next;
}Node;

void PushBack(Node** head, ListDatatype x);
void PushFront(Node** head, ListDatatype x);

void PopBack(Node** head);
void PopFront(Node** head);

Node* Find(Node* head,ListDatatype x);

void Insert(Node** head, ListDatatype x,Node* pos);