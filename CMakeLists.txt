cmake_minimum_required(VERSION 3.10)
project(mySTL CXX)

# 添加源文件
add_executable(main main.cc stack.cpp message.cpp queue.cpp node.cpp list.cpp map.cpp match.cpp)