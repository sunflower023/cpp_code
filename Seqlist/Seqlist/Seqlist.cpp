#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include "seqLIst.h"

using namespace std;
template <class elemType>

seqLIst<elemType>::seqLIst(int initSize)
{
    data = new elemType[initSize];
    maxSize = initSize;
    currentLength = 0;
}
template <class elemType>
int seqLIst<elemType>::search(const elemType& x) const
{
    int i;
    for (i = 0; i < currentLength && data[i] != x; i++);
    if (i == currentLength) return -1;
    else return i;
}

template <class elemType>
void seqLIst<elemType>::traverse() const
{
    for (int i = 0; i < currentLength; i++)
        cout << data[i] << " ";
    cout << endl;

}

template <class elemType>
void seqLIst<elemType>::insert(int i, const elemType& x)
{
    if (currentLength == maxSize) doubleSpace();
    for (int j = currentLength; j > i; j--) data[j] = data[j - 1];
    data[i] = x;
    currentLength++;
}

template <class elemType>
void seqLIst<elemType>::doubleSpace()
{
    elemType* tmp = data;
    maxSize *= 2;
    data = new elemType[maxSize];
    for (int i = 0; i < currentLength; i++)
        data[i] = tmp[i];
    delete[] tmp;
}

template <class elemType>
void seqLIst<elemType>::remove(int i)
{
    for (int j = i; j < currentLength - 1; j++)
        data[j] = data[j + 1];
    currentLength--;
}