#include "node.h"

Node::Node(int data) { this->data = data; }
void Node::addNode(int data) {
  // 存在下一个节点的情况
  if (this->next) {
    Node *tmp = new Node(data);
    (*tmp).next = this->next;
    this->next->last = tmp;
    this->next = tmp;
    this->next->last = this;
  }
  // 不存在下一个节点的情况
  else
    this->next = new Node(data);
  this->next->last = this;
}
void Node::deleteNode() {
  Node *del = this;
  // 若存在上一个节点 则调整上一个节点指针
  if (this->last) {
    this->last->next = this->next;
  }
  // 若存在下一个节点 则调整下一个节点指针
  if (this->next) {
    this->next->last = this->last;
  }
  delete del;
}

void BTreeNode::addLeft(int data) { this->left = new BTreeNode(data); }
void BTreeNode::addRight(int data) { this->right = new BTreeNode(data); }
BTreeNode::BTreeNode(int data) { this->data = data; }