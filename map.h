#include "match.h"
#ifndef MAP_H
#define MAP_H
class map{
    public:
    Match *mat[1000000];
    int len;
    map();
    void add(int key, int value);
    void remove(int key);
    int operator[](int key);
    void clear();
};
#endif