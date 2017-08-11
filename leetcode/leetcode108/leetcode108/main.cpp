//
//  main.cpp
//  leetcode108
//
//  Created by 萧天牧 on 17/4/21.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* sortedArrayToBST(vector<int>& nums) {
    int len = nums.size();
    if (len == 0)
        return NULL;
    if (len == 1)
        return new TreeNode(nums[0]);
    int middle = len >> 1;
    vector<int> left(nums.begin(), nums.begin() + middle);
    vector<int> right(nums.begin() + middle + 1 , nums.end());
    TreeNode* root = new TreeNode(nums[middle]);
    root -> left = sortedArrayToBST(left);
    root -> right = sortedArrayToBST(right);
    return root;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    TreeNode * root = new TreeNode(2);
    insertBST(root, 7);
    insertBST(root, 1);
    insertBST(root, 4);
    TreeNode *right = root -> right;
    if(!right)
        cout << "null";
    else
        cout << right -> val;
    return 0;
}
