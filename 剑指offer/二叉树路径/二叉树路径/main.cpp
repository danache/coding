//
//  main.cpp
//  二叉树路径
//
//  Created by 萧天牧 on 17/5/15.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
    val(x), left(NULL), right(NULL) {
    }
};
void find(TreeNode* root, int leftnum,vector<int> select, vector<vector<int>>& res){
    if(!root)
        return;
    if(root -> val > leftnum)
        return;
    else if(root -> val == leftnum){
        if (root -> left|| root ->right)
            return;
        else{
            select.push_back(leftnum);
            res.push_back(select);
        }
    }
    else{
        vector<int> tmp = select;
        tmp.push_back(root -> val);
        find(root -> left, leftnum - root -> val, tmp, res);
        find(root -> right, leftnum - root -> val, tmp, res);
    }
    
}
vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
    vector<vector<int>> res;
    if(!root)
        return res;
    vector<int> select;
    find(root, expectNumber, select, res);
    return res;
    
}

int main(int argc, const char * argv[]) {
    //{10,5,12,4,7},22
    TreeNode* a = new TreeNode(10);
    a->left = new TreeNode(5);
    a->right = new TreeNode(12);
    a->left->left = new TreeNode(4);
    a->left->right = new TreeNode(7);
    FindPath(a,22);
    std::cout << "Hello, World!\n";
    return 0;
}
