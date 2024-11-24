
#pragma once
template <class elemType>
class linkQueue
{
private:
    struct node {
        elemType  data;
        node* next;
        node(const elemType& x, node* N = NULL)
        {
            data = x; next = N;
        }
        node() :next(NULL) {}
        ~node() {}
    };
    node* front, * rear;
public:
    linkQueue() { front = rear = NULL; }

    ~linkQueue();
    bool isEmpty() { return front == NULL; }
    void enQueue(const elemType& x);
    elemType deQueue();

    elemType getHead() { return front->data; }

};
template <class elemType>
linkQueue<elemType>::~linkQueue() {
    node* tmp;
    while (front != NULL) {
        tmp = front;
        front = front->next;
        delete tmp;
    }
}
template <class elemType>
void linkQueue<elemType>::enQueue
(const elemType& x)
{
    if (rear == NULL)
        front = rear = new node(x);
    else {
        rear->next = new node(x);
        rear = rear->next;
    }
}
template <class elemType>
elemType linkQueue<elemType>::deQueue() {
    node* tmp = front;
    elemType value = front->data;
    front = front->next;
    if (front == NULL) rear = NULL;
    delete tmp;
    return value;
}