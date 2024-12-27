#include "queue.h"

#include <stddef.h>

#include "message.h"
#include "node.h"
queue::queue() {
  this->head = nullptr;
  this->tail = nullptr;
}
queue::~queue() { this->clear(); }
message queue::front() {
  // 尾指针存在 则返回其对应值
  if (this->tail) return *new message(1, this->tail->data);
  // 否则返回错误信息
  return *new message(-1, NULL);
}
void queue::clear() {
  Node *n = this->head;
  // 头指针遍历到尾指针
  while (n != this->tail) {
    // 一个个删除
    n = n->next;
    n->last->deleteNode();
  }
  // 头尾设为空指针
  this->head = nullptr;
  this->tail = nullptr;
}
void queue::push(int num) {
  // 尾指针存在 则在队尾新增节点
  if (this->tail) {
    this->tail->addNode(num);
    this->tail = this->tail->next;
  }
  // 队列为空 新建头节点
  else {
    this->head = new Node(num);
    this->tail = this->head;
  }
}
message queue::pop() {
  // 队列不为空
  if (this->head) {
    // 仅存在一个元素 pop使队列为空
    if (this->tail == this->head) {
      int data = this->head->data;
      this->tail = nullptr;
      this->head = nullptr;
      return *new message(1, data);
    }
    // 删除头节点
    else {
      int data = this->head->data;
      this->head = this->head->next;
      this->head->last->deleteNode();
      return *new message(1, data);
    }
  }
  // 队列为空
  else {
    return *new message(-1, 0);
  }
}
