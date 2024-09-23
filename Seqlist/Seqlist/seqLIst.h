#pragma once
#include"List.h"
template <class elemType>
class seqLIst :public list<elemType>
{
public:
    seqLIst(int intiSize = 10);
    ~seqLIst() { delete[]data; }
    void clear() { currentLength = 0; }
    int length() const { return currentLength; }
    void insert(int i, const elemType& x);
    void remove(int i);
    int search(const elemType& x) const;
    elemType visit(int i) const { return data[i]; }
    void traverse() const;


private:
    elemType* data;
    int currentLength;
    int maxSize;
    void doubleSpace();
};