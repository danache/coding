//
//  main.cpp
//  leetcode105
//
//  Created by 萧天牧 on 17/4/18.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* getTree(vector<int>& preorder, vector<int>& inorder, int preBegin,int preEnd, int inoBegin, int inoEnd){
    if(preBegin > preEnd || inoBegin > inoEnd)
        return NULL;
    int root_num = preorder[preBegin];
    int root_index;
    for(root_index = inoBegin; root_index <= inoEnd; root_index++){
        if(inorder[root_index] == root_num)
            break;
    }
    TreeNode* root = new TreeNode(root_num);
    TreeNode* left = getTree(preorder, inorder, preBegin + 1, preBegin + root_index - inoBegin ,inoBegin , root_index - 1);
    TreeNode* right = getTree(preorder, inorder, preBegin + root_index - inoBegin + 1, preEnd, root_index + 1, inoEnd);
    root ->left = left;
    root -> right = right;
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if(preorder.empty() || inorder.empty())
        return NULL;
    return getTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
}


int main(int argc, const char * argv[]) {
    vector<int> a = {1,2,3};
    vector<int> b = {2,3,1};
    buildTree(a, b);
    return 0;
}
