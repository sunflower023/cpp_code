#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

void Print_int(SL* p)
{
	for (int i = 0; i < p->size; i++)
	{
		printf("%d->", p->arr[i]);
	}
	printf("NULL\n");
}

SL* SLInit(SL* p)
{
	assert(p);
	p->arr = NULL;
	p->capacity = p->size = 0;
}

void SLDestroy(SL* p)
{
	assert(p);
	assert(p->arr);
	free(p->arr);
	p->arr = NULL;
	p->capacity = p->size = 0;
}

void Check(SL* p)
{
	assert(p);
	if (p->size == p->capacity)
	{
		int newcapacity = (p->capacity == 0) ? 4 : (p->capacity) * 2;
		SLdatatype* tmp = (SLdatatype*)realloc(p->arr, sizeof(SLdatatype) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		p->arr = tmp;
		p->capacity = newcapacity;
	}
}


void SLPushBack(SL* p, SLdatatype x)
{
	assert(p);
	Check(p);
	p->arr[p->size] = x;
	p->size++;
}

void SLPushFront(SL* p, SLdatatype x)
{
	assert(p);
	Check(p);
	for (int i = p->size; i > 0; i--)
	{
		p->arr[i] = p->arr[i - 1];
	}
	p->arr[0] = x;
	p->size++;
}

void SLPopBack(SL* p)
{
	assert(p);
	if (p->size == 0)
	{
		printf("SeqList为空，无法删除");
		return;
	}
	p->size--;
}
void SLPopFront(SL* p)
{
	assert(p);
	assert(p->arr);
	for (int i = 0; i < p->size; i++)
	{
		p->arr[i] = p->arr[i + 1];
	}
	p->size--;
}

int SLFind(SL* p, SLdatatype x)
{
	assert(p);
	assert(p->size);
	for (int i = 0; i < p->size; i++)
	{
		if (p->arr[i] == x)
		{
			return i;
		}
	}
	printf("未找到！\n");
	return -1;
}

void SLInsert(SL* p, SLdatatype x, int pos)
{
	assert(p);
	assert(p->size > pos);
	Check(p);
	for (int i = p->size; i > pos; i--)
	{
		p->arr[i] = p->arr[i - 1];
	}
	p->arr[pos] = x;
	p->size++;
}