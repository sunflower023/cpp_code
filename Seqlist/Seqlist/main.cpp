#define _CRT_SECURE_NO_WARNINGS 1
#include"SequenceList.h"

int main()
{
	SeqList<int> s;
	for (int i = 0; i < 30; i++)
	{
		s.insert(0, i);
	}
	s.remove(0);
	s.traverse();

	return 0;
}