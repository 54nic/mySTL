//
// mySTL @ 2024.12.27 @ 052460114 张浩宇
//
// 实现了 栈stack 队列queue 映射map 双向链表list 优先队列priqueue
//

#include <iostream>

#include "list.h"
#include "map.h"
#include "message.h"
#include "priqueue.h"
#include "queue.h"
#include "stack.h"
int main() {
  //优先队列演示
  std::cout << "\n————heap————" << std::endl;
  priqueue heap;
  heap.push(1);
  std::cout << heap.top() << std::endl;
  heap.push(2);
  heap.push(4);
  heap.push(5);
  std::cout << heap.top() << std::endl;
  heap.push(1);
  std::cout << heap.top() << std::endl;
  heap.push(3);
  std::cout << heap.top() << std::endl;
  heap.pop();
  std::cout << heap.top() << std::endl;
  heap.pop();
  std::cout << heap.top() << std::endl;
  heap.clear();
  std::cout << heap.top() << std::endl;

  //映射演示
  std::cout << "\n————map————" << std::endl;
  map mp;
  mp.add(1, 121);
  mp.add(2, 222);
  std::cout << mp[1] << " " << mp[2] << std::endl;
  mp.remove(11);
  mp.clear();

  //栈演示
  std::cout << "\n————stack————" << std::endl;
  stack stk;
  stk.push(1);
  std::cout << stk.top() << std::endl;
  stk.push(2);
  stk.push(3);
  std::cout << stk.top() << std::endl;
  stk.pop();
  std::cout << stk.top() << std::endl;
  stk.clear();

  //队列演示
  std::cout << "\n————queue————" << std::endl;
  queue que;
  que.push(1);
  que.push(2);
  std::cout << que.front() << std::endl;
  que.push(3);
  que.push(4);
  std::cout << que.front() << std::endl;
  que.pop();
  std::cout << que.front() << std::endl;
  que.clear();

  //列表演示
  std::cout << "————list————" << std::endl;
  list list;
  list.insert(1, 11);
  list.insert(2, 22);
  std::cout << list.getData(1) << " " << list.getData(2) << std::endl;
  list.insert(3, 33);
  list.insert(4, 44);
  list.remove(1);
  std::cout << list.getData(1) << " " << list.getData(2) << std::endl;
  list.clear();

  return 0;
}
