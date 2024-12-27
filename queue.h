#include "message.h"
#include "node.h"
#ifndef QUEUE_H
#define QUEUE_H
class queue {
  // 数据头指针
  Node *head;
  // 数据尾指针
  Node *tail;

 public:
  // 构造函数 使头尾指针为空
  queue();
  // 析构函数
  ~queue();
  // 返回队列尾指针数据
  message front();
  // 清空队列
  void clear();
  // 入队
  void push(int num);
  // 出队
  message pop();
};

#endif