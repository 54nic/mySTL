#include "list.h"

#include <stddef.h>

#include "message.h"
#include "node.h"
list::list() {
  this->head = new Node(NULL);
  this->tail = this->head;
}
list::~list() {
  this->clear();
  this->head->deleteNode();
}
message list::getData(int pos) {
  // 索引小于0则返回空message对象
  if (pos <= 0) return *new message(-1, NULL);
  Node *ptr = this->head;
  // 得到索引位的位置指针
  for (int i = 0; i < pos; i++) {
    // 判断是否存在下一位
    if (ptr->next) ptr = ptr->next;
    // 没有则返回空message对象
    else
      return *new message(-1, NULL);
  }
  // 返回索引位指针对应数据
  return *new message(1, (*ptr).data);
}
void list::clear() {
  Node *n = this->tail;
  this->tail = this->head;
  // 删除最后一位退出循环（剩下头节点的空指针）
  while (n != this->head) {
    n = n->last;
    n->next->deleteNode();
  }
}
void list::insert(int pos, int num) {
  // 索引小于0则返回空message对象
  if (pos <= 0) return;
  Node *ptr = this->head;
  // 得到索引位的位置指针
  for (int i = 0; i < pos - 1; i++) {
    // 判断是否存在下一位
    if (ptr->next) ptr = ptr->next;
    // 没有则返回空
    else
      return;
  }
  // 分该位置存在下一位 与该位置不存在下一位判断
  if (ptr->next) {
    // 存在下一位则调整此位和下一位的指针
    Node *node = new Node(num);
    node->next = ptr->next;
    ptr->next->last = node;
    ptr->next = node;
    node->last = ptr;
  }
  // 不存在下一位则只调整此位的指针
  else {
    ptr->next = new Node(num);
    this->tail = ptr->next;
    this->tail->last = ptr;
  }
}
message list::remove(int pos) {
  // 索引小于0则返回空message对象
  if (pos <= 0) return *new message(-1, NULL);
  Node *ptr = this->head;
  for (int i = 0; i < pos; i++) {
    // 判断是否存在下一位
    if (ptr->next) ptr = ptr->next;
    // 没有则返回空message对象
    else
      return *new message(-1, NULL);
  }
  int data = ptr->data;
  // 分该位置存在下一位 与该位置不存在下一位判断
  // 存在下一位则调整上一位和下一位的指针
  if (ptr->next) {
    ptr->next->last = ptr->last;
    ptr->last->next = ptr->next;
    ptr->deleteNode();
  }
  // 不存在下一位则只调整上一位的指针
  else {
    ptr->last->next = nullptr;
    this->tail = ptr->last;
    ptr->deleteNode();
  }
  return *new message(1, data);
}
