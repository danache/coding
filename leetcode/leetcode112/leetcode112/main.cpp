//
//  main.cpp
//  leetcode112
//
//  Created by 萧天牧 on 17/4/22.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <queue>
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
bool hasPathSum(TreeNode* root, int sum) {
    if (!root)
        return false;
    if (root -> val == sum &&(!root -> left) && (!root -> right))
        return true;
    return hasPathSum(root -> left,  sum - root -> val) || hasPathSum(root -> right,sum - root -> val );
}
int main(int argc, const char * argv[]) {
    // insert code here...
    TreeNode* root = new TreeNode(1);
    root -> left = new TreeNode(2);
    hasPathSum(root, 3);
    return 0;
}
