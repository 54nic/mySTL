#include "message.h"

#include <iostream>
message::message(int code, int data) {
  this->code = code;
  this->data = data;
}
std::ostream &operator<<(std::ostream &output, const message &a) {
  // 若状态码为1 返回对应数据
  if (a.code == 1) output << a.data;
  // 状态码为-1 返回错误
  else if (a.code == -1)
    output << "Error";
  return output;
}
