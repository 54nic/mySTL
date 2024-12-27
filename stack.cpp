#include "stack.h"

#include <stddef.h>

#include "message.h"
#include "node.h"
stack::stack() {
  this->head = nullptr;
  this->tail = nullptr;
}
stack::~stack() { this->clear(); }
message stack::top() {
  // 判断栈是否为空
  if (this->tail) return *new message(1, this->tail->data);
  return *new message(-1, NULL);
}
void stack::clear() {
  Node *n = this->head;
  // 从栈底遍历到栈顶
  while (n != this->tail) {
    n = n->next;
    n->last->deleteNode();
  }
  this->head = nullptr;
  this->tail = nullptr;
}
void stack::push(int num) {
  // 判断栈是否为空
  if (this->tail) {
    this->tail->addNode(num);
    this->tail = this->tail->next;
  } else {
    this->head = new Node(num);
    this->tail = this->head;
  }
}
message stack::pop() {
  // 判断栈是否为空
  if (this->tail) {
    // 判断栈中是否只有一个元素 如果是则清空栈
    if (this->tail == this->head) {
      int data = this->tail->data;
      this->tail = nullptr;
      this->head = nullptr;
      return *new message(1, data);
    }
    // 否则前移栈尾
    else {
      int data = this->tail->data;
      this->tail = this->tail->last;
      this->tail->next->deleteNode();
      return *new message(1, data);
    }
  } else {
    return *new message(-1, 0);
  }
}
