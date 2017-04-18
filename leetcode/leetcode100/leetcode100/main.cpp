//
//  main.cpp
//  leetcode100
//
//  Created by 萧天牧 on 17/4/18.
//  Copyright © 2017年 萧天牧. All rights reserved.
//
#include <iostream>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


bool isSameTree(TreeNode* p, TreeNode* q) {
    if(!p){
        if(!q)
            return true;
        else
            return false;
    }
    if(!q)
        return false;
    bool flag = true;
    if(p->val != q->val)
        flag = false;
    return flag && isSameTree(p->left, q->left) && isSameTree(p -> right, q->right);
}

int main(int argc, const char * argv[]) {

}
