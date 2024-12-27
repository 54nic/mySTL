#include "map.h"

#include "match.h"
map::map() {
  // 初始化长度为0
  this->len = 0;
}
map::~map() { this->clear(); }
void map::remove(int key) {
  // 遍历mat数组，找到匹配的key
  for (int i = 0; i < this->len; i++) {
    // 如果key等于mat数组中存放的key
    if (this->mat[i]->key == key) {
      delete this->mat[i];
      // 删除此位置，并使后面的位置向前移动
      for (int k = i; k < this->len; k++) {
        this->mat[k] = this->mat[k + 1];
      }
      // 将总长度减一
      this->len--;
    }
  }
}
void map::add(int key, int value) {
  // 先遍历整个数组 找是否存在key
  for (int i = 0; i < this->len; i++) {
    // 若存在 则之间改变其value
    if (this->mat[i]->key == key) {
      this->mat[i]->value = value;
      return;
    }
  }
  // 否则新建一个match对象
  this->mat[this->len++] = new Match(key, value);
}

int map::operator[](int key) {
  // 遍历整个数组，找到key
  for (int i = 0; i < this->len; i++) {
    // 找到key 返回对应的value
    if (this->mat[i]->key == key) return this->mat[i]->value;
  }
  return 0;
}
void map::clear() {
  // 遍历清空所有match对象
  for (int i = 0; i < this->len; i++) {
    delete this->mat[i];
  }
  this->len = 0;
}