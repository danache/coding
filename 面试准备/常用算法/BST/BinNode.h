//
// Created by dan on 18-4-7.
//

#ifndef BST_BINNODE_H
#define BST_BINNODE_H
#define  BinNodePosi(T) BinNode<T> *

typedef enum{RB_RED,RB_BLACK} RBColor;

template <typename T> struct BinNode{
    T data;
    BinNodePosi(T) parent;
    BinNodePosi(T) lChild;
    BinNodePosi(T) rChild;
    int height;
    RBColor color;
    BinNode():parent(NULL),lChild(NULL),rChild(NULL),height(0),color(RB_RED){};
    BinNode(T e, BinNodePosi(T) p = NULL,BinNodePosi(T) lc = NULL,BinNodePosi(T) rc = NULL,
            int h = 0, RBColor c = RB_RED):
            parent(p),lChild(lc),rChild(rc),height(h),color(c){};


    int size();
    BinNodePosi(T) insertAsLC(T const &);
    BinNodePosi(T) insertAsRC(T const &);
    BinNodePosi(T) succ();

    template <typename VST> void travLevel(VST&);
    template <typename VST> void travPre(VST&);
    template <typename VST> void travIn(VST&);
    template <typename VST> void travPost(VST&);


};



#endif //BST_BINNODE_H
