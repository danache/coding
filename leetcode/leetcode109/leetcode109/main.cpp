//
//  main.cpp
//  leetcode109
//
//  Created by 萧天牧 on 17/4/21.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int getTreeHeight(TreeNode* root){
    if (!root)
        return 0;
    else if (!root -> left && !root->right)
        return 1;
    else if(!root -> left){
        return getTreeHeight(root -> right) + 1;
    }
    else if(!root -> right)
        return getTreeHeight(root -> left) + 1;
    else return max(getTreeHeight(root -> left), getTreeHeight(root -> right)) + 1;
}
bool isBalanced(TreeNode* root) {
    if(!root)
        return true;
    
    if (abs(getTreeHeight(root -> left) - getTreeHeight(root -> right)) > 1){
        return false;
    }
    else{
        return isBalanced(root -> left) && isBalanced(root -> right);
    }
}

int main(int argc, const char * argv[]) {
    TreeNode *root = new TreeNode(0);
    int n1 = getTreeHeight(root);
    root -> left = new TreeNode(1);
    int n2 = getTreeHeight(root);
    root -> right= new TreeNode(3);
    int n3 = getTreeHeight(root);
    
    root -> left->right = new TreeNode(1);
    int n4 =getTreeHeight(root);
    cout << n1 <<" "<<n2 <<" "<<n3 <<" "<<n4<<endl;
}
