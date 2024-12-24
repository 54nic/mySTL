#ifndef NODE_H
#define NODE_H
    class Node{
        public:
        int data;
        Node *next, *last;
        Node(int data);
        void addNode (int data);
        void deleteNode();
    };
    int getNode(Node *node,int index);
#endif

