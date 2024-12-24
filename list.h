#include "message.h"
#include "node.h"
#ifndef LIST_H
#define LIST_H
class list{
        //数据头指针
        Node* head;
        //数据尾指针
        Node* tail;
    public:
        //构造容器
        list();
        //析构函数
        ~list();
        //将栈顶指针变为-1
        void clear();
        //返回pos位的数据
        message getData(int pos);
        //入队
        void insert(int pos, int num);
        //出队
        message remove(int pos);
};

#endif