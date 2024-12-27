#ifndef NODE_H
#define NODE_H
class Node {
 public:
  // 节点存储数据
  int data;
  // 下一个、上一个节点指针
  Node *next, *last;
  // 构造函数
  Node(int data);
  // 在下一个位增加节点
  void addNode(int data);
  // 删除此节点
  void deleteNode();
};
class BTreeNode {
 public:
  int data;
  BTreeNode *left, *right;
  void addLeft(int data);
  void addRight(int data);
  BTreeNode(int data);
};

#endif
