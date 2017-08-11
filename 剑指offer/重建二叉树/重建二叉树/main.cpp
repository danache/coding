//
//  main.cpp
//  重建二叉树
//
//  Created by 萧天牧 on 17/5/7.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* initTree(vector<int> pre, vector<int> vin, int preBegin, int preEnd, int vinBegin, int vinEnd){
    if(preBegin > preEnd || vinBegin > vinEnd)
        return NULL;
    if(preEnd == preBegin && vinEnd  == vinBegin){
        TreeNode* root = new TreeNode(pre[preBegin]);
        return root;
    }
    else{
        TreeNode* root = new TreeNode(pre[preBegin]);
        int index = vinBegin;
        for(index; index <= vinEnd; index++)
            if(vin[index] == pre[preBegin])
                break;
        TreeNode* left = initTree(pre, vin, preBegin + 1, preBegin + index - vinBegin , vinBegin, index - 1);
        TreeNode* right = initTree(pre, vin, preBegin + index - vinBegin + 1, preEnd, index + 1, vinEnd);
        root -> left = left;
        root -> right = right;
        return root;
    }
}
TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
    if(pre.size() == 0 || vin.size() == 0 || pre.size() != vin.size())
        return NULL;
    TreeNode* res = initTree(pre, vin, 0, pre.size() - 1, 0, vin.size() - 1);
    return res;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
