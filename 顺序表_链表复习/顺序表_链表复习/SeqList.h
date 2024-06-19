#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int SLdatatype;
typedef struct SeqList
{
	SLdatatype* arr;
	int size;
	int capacity;
}SL;

SL* SLInit(SL* p);
void SLDestroy(SL* p);

void SLPushBack(SL* p, SLdatatype x);
void SLPushFront(SL* p, SLdatatype x);

void SLPopBack(SL* p);
void SLPopFront(SL* p);

int SLFind(SL* p, SLdatatype x);

void SLInsert(SL* p, SLdatatype x, int pos);