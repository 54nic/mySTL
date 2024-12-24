#ifndef NODE_H
#define NODE_H
class Node
{
public:
    int data;
    Node *next, *last;
    Node(int data);
    void addNode(int data);
    void deleteNode();
};
class BTreeNode
{
public:
    int data;
    BTreeNode *left, *right;
};

#endif
