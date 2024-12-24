#include "queue.h"
#include "message.h"
#include "node.h"
#include <stddef.h>
queue::queue()
{
    this->head = nullptr;
    this->tail = nullptr;
}
queue::~queue()
{
    this->clear();
}
message queue::front()
{
    if (this->tail)
        return *new message(1, this->tail->data);
    return *new message(-1, NULL);
}
void queue::clear()
{
    Node *n = this->head;
    while (n != this->tail)
    {
        n = n->next;
        n->last->deleteNode();
    }
    this->head = nullptr;
    this->tail = nullptr;
}
void queue::push(int num)
{
    if (this->tail)
    {
        this->tail->addNode(num);
        this->tail = this->tail->next;
    }
    else
    {
        this->head = new Node(num);
        this->tail = this->head;
    }
}
message queue::pop()
{
    if (this->head)
    {
        if (this->tail == this->head)
        {
            int data = this->head->data;
            this->tail = nullptr;
            this->head = nullptr;
            return *new message(1, data);
        }
        else
        {
            int data = this->head->data;
            this->head = this->head->next;
            this->head->last->deleteNode();
            return *new message(1, data);
        }
    }
    else
    {
        return *new message(0, 0);
    }
}
