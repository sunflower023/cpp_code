#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
#include"List.h"

void testSeqlist()
{
	SL s;
	SLInit(&s);
	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	SLPushFront(&s, 5);
	SLPushFront(&s, 6);
	SLPushFront(&s, 7);
	Print_int(&s);

	//SLPopBack(&s);
	//SLPopFront(&s);
	//SLPopFront(&s);

	int ret = SLFind(&s, 1);
	if (ret > 0)
		printf("%d\n", s.arr[ret]);

	SLInsert(&s, 88, ret);
	Print_int(&s);
}

testList()
{
	Node* l = NULL;
	PushBack(&l, 1);
	PushBack(&l, 2);
	PushBack(&l, 3);
	PushFront(&l, 5);
	PushFront(&l, 6);
	PushFront(&l, 7);
	Print(l);

	//PopBack(&l);
	//PopFront(&l);
	//PopFront(&l);
	Node* ret = Find(l, 1);
	printf("%d\n", ret->val);
	Insert(&l, 88, ret);

	Print(l);
}

int main()
{
	//testSeqlist();
	testList();

	return 0;
}