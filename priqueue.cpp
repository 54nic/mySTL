#include "priqueue.h"

#include <algorithm>
#include <iostream>

#include "message.h"

priqueue::priqueue() { len = 0; }
// 析构函数
priqueue::~priqueue() { this->clear(); }
message priqueue::top() {
  // 长度大于0则返回堆顶
  if (len > 0) return *new message(1, heap[1]);
  // 否则返回错误message对象
  return *new message(-1, 0);
}
void priqueue::clear() { len = 0; }
void priqueue::push(int num) {
  heap[++len] = num;
  int l = len;
  // 索引大于1不断循环
  while (l != 1) {
    // 索引为偶数 父节点为l/2
    if (l % 2 == 0) {
      // 父节点更大 满足最大堆
      if (heap[l / 2] > heap[l]) break;
      // 父节点更小 交换
      else {
        std::swap(heap[l / 2], heap[l]);
        l = l / 2;
      }
    }
    // 索引为奇数 父节点为(l-1)/2
    else {
      // 父节点更大 满足最大堆
      if (heap[(l - 1) / 2] > heap[l]) break;
      // 父节点更小 交换
      else {
        std::swap(heap[(l - 1) / 2], heap[l]);
        l = (l - 1) / 2;
      }
    }
  }
}
void priqueue::pop() {
  // 长度小于0退出
  if (len <= 0) return;
  heap[1] = heap[len--];
  int ptr = 1;
  // 索引不大于长度不断循环
  while (ptr <= len) {
    // 索引的子节点大于长度则退出
    if (ptr * 2 > len) break;
    // 右子节点大于长度，说明左子节点不大于长度
    else if (ptr * 2 + 1 > len && heap[ptr * 2 + 1] > heap[ptr]) {
      std::swap(heap[ptr], heap[ptr * 2]);
      ptr = ptr * 2;
      break;
    } else {
      // 索引节点小于左右子节点
      if (heap[ptr] < heap[ptr * 2] && heap[ptr] < heap[ptr * 2 + 1]) {
        // 判断左右子节点哪个更大 和更大的交换
        if (heap[ptr * 2] > heap[ptr * 2 + 1]) {
          std::swap(heap[ptr], heap[ptr * 2]);
          ptr = ptr * 2;
        } else {
          std::swap(heap[ptr], heap[ptr * 2 + 1]);
          ptr = ptr * 2 + 1;
        }
      }
      // 索引节点仅小于左子节点
      else if (heap[ptr] < heap[ptr * 2]) {
        std::swap(heap[ptr], heap[ptr * 2]);
        ptr = ptr * 2;
      }
      // 仅小于右子节点
      else if (heap[ptr] < heap[ptr * 2 + 1]) {
        std::swap(heap[ptr], heap[ptr * 2 + 1]);
        ptr = ptr * 2 + 1;
      }
      // 索引节点大于子节点
      else
        break;
    }
  }
}