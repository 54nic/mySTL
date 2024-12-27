#include "message.h"
#include "node.h"
#ifndef LIST_H
#define LIST_H
class list {
  // 数据头指针
  Node *head;
  // 数据尾指针
  Node *tail;

 public:
  // 构造函数，使头节点为空指针
  list();
  // 析构函数，删除头节点
  ~list();
  // 清除列表
  void clear();
  // 返回pos位的数据
  message getData(int pos);
  // 在pos为后插入num数据
  void insert(int pos, int num);
  // 移除pos位的数据
  message remove(int pos);
};

#endif