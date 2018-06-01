cmake_minimum_required(VERSION 3.7)
project(BST)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp BinNode.cpp BinNode.h BinTree.cpp BinTree.h)
add_executable(BST ${SOURCE_FILES})