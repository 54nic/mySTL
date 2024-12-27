#include "message.h"
#include "node.h"
#ifndef PRIQUEUE_H
#define PRIQUEUE_H
class priqueue
{
    // 堆数组与长度
    int heap[1000000], len;

public:
    // 构造容器
    priqueue();
    // 析构函数
    ~priqueue();
    // 返回堆中最大值
    message top();
    // 将堆清空
    void clear();
    // 入队
    void push(int num);
    // 出队
    void pop();
};

#endif