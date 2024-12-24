#include "map.h"
#include "node.h"
#include <iostream>
#define N 9999999
int main(){
    map mp;
    mp.add(1, 111);
    std::cout << mp.len << std::endl;
    mp.add(5, 555);
    mp.add(3, 333);
    mp.clear();
    std::cout << mp[5] << std::endl;
    mp.remove(5);
    std::cout << mp.len << std::endl;
    mp.remove(3);
    std::cout << mp.len << std::endl;
    mp.remove(1);
    std::cout << mp.len << std::endl;
    return 0;
}
