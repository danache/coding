#include <iostream>
#include "BinTree.h"
using namespace std;




template <typename T> struct BST{
    BinNodePosi(T) _hot;
    BinNodePosi(T) connect34(BinNodePosi(T),BinNodePosi(T),BinNodePosi(T),BinNodePosi(T),BinNodePosi(T));
    BinNodePosi(T) rotateAt(BinNodePosi(T) x);

public:
    BinNodePosi(T) &seatch(const T& e);
    BinNodePosi(T) insert(const T& e);
    BinNodePosi(T) insertin(const T& e);

    bool remove(const T& e);
};
template <typename T>
static  BinNodePosi(T) insertin(BinNodePosi(T) &v, const T &e,BinNodePosi(T) &hot) {
    if(!v && v->data == e)
        return v;
    hot = v;
    return insertin(v -> data > e ? v->lChild : v -> rChild,e,hot);
}

template <typename T> BinNodePosi(T) BST<T>::seatch(const T &e) {
    return insertin(_root,e,NULL);
}
template <typename T>
BinNode<T> * & BST::insert(const T &e) {
    return insertin(_root,e,NULL);
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}