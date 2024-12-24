#include "message.h"
#include "node.h"
#ifndef QUEUE_H
#define QUEUE_H
class queue
{
    // 数据头指针
    Node *head;
    // 数据尾指针
    Node *tail;

public:
    // 构造容器
    queue();
    // 析构函数
    ~queue();
    // 返回栈顶指针下标对应的数据
    message front();
    // 将栈顶指针变为-1
    void clear();
    // 入队
    void push(int num);
    // 出队
    message pop();
};

#endif