#include <iostream>
#ifndef MESSAGE_H
#define MESSAGE_H
//定义信息类 用于错误时传递错误信息
class message {
 public:
  // 状态码
  int code;
  // 存储数据
  int data;
  // 构造函数
  message(int code, int data);
  // 重载输出流
  friend std::ostream &operator<<(std::ostream &output, const message &a);
};

#endif