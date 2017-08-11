//
//  main.cpp
//  leetcode114
//
//  Created by 萧天牧 on 17/4/22.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;
/**
 * Definition for a binary tree node.
 */struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

void flatten(TreeNode* &root) {
    if(!root)
        return;
    TreeNode* flag = new TreeNode(0);
    TreeNode* shaobing = flag;
    stack<TreeNode*> sta;
    sta.push(root);
    while(!sta.empty()){
        TreeNode* tmp = sta.top();
        sta.pop();
        shaobing -> right = new TreeNode(tmp->val);
        shaobing  = shaobing -> right;
        if(tmp -> right)
            sta.push(tmp -> right);
        if (tmp -> left)
            sta.push(tmp -> left);
    }
    root= flag -> right;
}

void priOrder(TreeNode* root){
    if(!root)
        return;
    stack<TreeNode*> sta;
    sta.push(root);
    while(!sta.empty()){
        TreeNode* tmp = sta.top();
        sta.pop();
        if(!tmp -> right)
            sta.push(tmp -> right);
        if (!tmp -> left)
            sta.push(tmp -> left);
    }
}

int main(int argc, const char * argv[]) {
    TreeNode* root = new TreeNode(1);
    root -> left = new TreeNode(2);
    flatten(root);
    cout << root->val;
    cout << endl;
}
