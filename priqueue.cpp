#include "message.h"
#include "priqueue.h"
#include <iostream>
#include <algorithm>
priqueue::priqueue()
{
    len = 0;
}
// 析构函数
priqueue::~priqueue()
{
}
// 返回栈顶指针下标对应的数据
message priqueue::top()
{
    if (len > 0)
        return *new message(1, heap[1]);
    return *new message(0, 0);
}
void priqueue::clear()
{
    len = 0;
}
void priqueue::push(int num)
{
    heap[++len] = num;
    int l = len;
    while (l != 1)
    {
        if (l % 2 == 0)
        {
            if (heap[l / 2] > heap[l])
                break;
            else
            {
                int tmp = heap[l / 2];
                heap[l / 2] = heap[l];
                heap[l] = tmp;
                l = l / 2;
            }
        }
        else
        {
            if (heap[(l - 1) / 2] > heap[l])
                break;
            else
            {
                int tmp = heap[(l - 1) / 2];
                heap[(l - 1) / 2] = heap[l];
                heap[l] = tmp;
                l = (l - 1) / 2;
            }
        }
    }
}
void priqueue::pop()
{
    if (len <= 0)
        return;
    heap[1] = heap[len--];
    int ptr = 1;
    while (ptr <= len)
    {
        if (ptr * 2 > len)
            break;
        else if (ptr * 2 + 1 > len)
        {
            std::swap(heap[ptr], heap[ptr * 2]);
            ptr = ptr * 2;
            break;
        }
        else
        {
            if (heap[ptr * 2] > heap[ptr * 2 + 1])
            {
                std::swap(heap[ptr], heap[ptr * 2]);
                ptr = ptr * 2;
            }
            else
            {
                std::swap(heap[ptr], heap[ptr * 2 + 1]);
                ptr = ptr * 2 + 1;
            }
        }
    }
}