//
//  main.cpp
//  leetcode144
//
//  Created by 萧天牧 on 17/4/23.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    if(!root)
        return result;
    stack<TreeNode*> sta;
    sta.push(root);
    TreeNode* pNode = NULL;
    while(!sta.empty() || pNode){
        pNode = sta.top();
        sta.pop();
        result.push_back(pNode->val);
        if(pNode -> right)
            sta.push(pNode -> right);
        if(pNode -> left)
            sta.push(pNode -> left);
        pNode = pNode -> left;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    TreeNode* root = new TreeNode(0);
    root -> left =new TreeNode(1);
    root -> left -> left =new TreeNode(2);
    vector<int> res = preorderTraversal(root);
    for(int i = 0 ; i< res.size(); i++)
        cout <<res[i] <<" ";
    return 0;
}
