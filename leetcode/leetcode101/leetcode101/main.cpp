//
//  main.cpp
//  leetcode101
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



bool judge(TreeNode* p, TreeNode* q){
    if(!p && !q)
        return true;
    else if(!p || !q)
        return false;
    if(p->val != q -> val)
        return false;
    return judge(p->left, q -> right) && judge(p -> right, q -> left);
}
bool isSymmetric(TreeNode* root) {
    return judge(root->left, root -> right);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
