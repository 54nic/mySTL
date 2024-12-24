#include "message.h"
#include "node.h"
#ifndef STACK_H
#define STACK_H
class stack
{
    // 栈内数据头指针
    Node *head;
    // 栈内数据尾指针
    Node *tail;

public:
    // 构造容器，将栈顶指针设为-1
    stack();
    // 析构函数
    ~stack();
    // 返回栈顶
    message top();
    // 清空栈
    void clear();
    // 压栈
    void push(int num);
    // 弹栈
    message pop();
};

#endif