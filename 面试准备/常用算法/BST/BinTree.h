#include <form.h>//
// Created by dan on 18-4-7.
//
#include "BinNode.h"
#ifndef BST_BINTREE_H
#define BST_BINTREE_H


template <typename T>class BinTree {
protected:
    int _size;
    BinNodePosi(T) _root;
    virtual int updateHeight(BinNodePosi(T) x);
    void updateHeightAbove(BinNodePosi(T) x);

public:
    BinTree():_size(0),_root(NULL){};
//    ~BinTree(){
//        if(0 < _size)
//            remove(_root);
//    }
    int size(){ return _size;};
    bool empty()const{return !_root};
    BinNodePosi(T) root() const {return _root};


};


#endif //BST_BINTREE_H
