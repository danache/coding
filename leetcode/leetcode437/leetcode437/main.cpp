//
//  main.cpp
//  leetcode437
//
//  Created by 萧天牧 on 17/8/18.
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

void getNum(TreeNode* root, int sum, bool caina, int &res){
    if(!root)
        return;
    if(root -> val == sum)
        res++;
    
    getNum(root ->left, sum - root -> val,true, res);
    getNum(root ->right, sum - root -> val,true, res);
    
    if(!caina){
        getNum(root ->left, sum, false,res);
        getNum(root ->right, sum,false, res);
    }
}

int pathSum(TreeNode* root, int sum) {
    if(!root)
        return 0;
    int res = 0;
    getNum(root, sum, false, res);
    return res;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    TreeNode *node0 = new TreeNode(10);
    TreeNode *node1 = new TreeNode(5);
    TreeNode *node2 = new TreeNode(-3);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(2);
    TreeNode *node5 = new TreeNode(11);
    TreeNode *node6 = new TreeNode(3);
    TreeNode *node7 = new TreeNode(-2);
    TreeNode *node8 = new TreeNode(1);
    node0 ->left = node1;
    node0 ->right = node2;
    node1 ->left = node3;
    node1 ->right = node4;
    node2 -> right = node5;
    node3 -> left = node6;
    node3 -> right = node7;
    node4 -> right = node8;
    cout << pathSum(node0, 8);
    
    
    
    std::cout << "Hello, World!\n";
    return 0;
}
