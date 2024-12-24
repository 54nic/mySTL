#include "node.h"

Node::Node(int data)
{
    this->data = data;
}
void Node::addNode(int data)
{

    if (this->next)
    {
        Node *tmp = new Node(data);
        (*tmp).next = this->next;
        this->next->last = tmp;
        this->next = tmp;
        this->next->last = this;
    }
    else
        this->next = new Node(data);
    this->next->last = this;
}
void Node::deleteNode()
{
    Node *del = this;
    if (this->last)
    {
        this->last->next = this->next;
    }
    if (this->next)
    {
        this->next->last = this->last;
    }
    delete del;
}
int getNode(Node *node, int index)
{
    for (int i = 0; i < index; i++)
    {
        if ((*node).next)
            node = (*node).next;
    }
    return (*node).data;
}