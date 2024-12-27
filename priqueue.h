#include "message.h"
#include "node.h"
#ifndef PRIQUEUE_H
#define PRIQUEUE_H
class priqueue {
  // 堆数组与长度
  int heap[1000000], len;

 public:
  // 构造函数
  priqueue();
  // 析构函数
  ~priqueue();
  // 返回堆中最大值
  message top();
  // 将堆清空
  void clear();
  // 入堆
  void push(int num);
  // 出堆
  void pop();
};

#endif