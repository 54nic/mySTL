#include "match.h"
#ifndef MAP_H
#define MAP_H
class map {
 public:
  // 配对的Match数组
  Match *mat[10000];
  // 数组长度
  int len;
  // 构造函数
  map();
  // 析构函数
  ~map();
  // 增加key-value对
  void add(int key, int value);
  // 删除key对应的映射
  void remove(int key);
  // 通过下标访问value
  int operator[](int key);
  // 清空数组
  void clear();
};
#endif