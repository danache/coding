//
//  main.cpp
//  leetcode222
//
//  Created by 萧天牧 on 17/4/23.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <queue>
using namespace std;
/**
 * Definition for a binary tree node.
 */ struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };



int countNodes(TreeNode* root) {
    if(!root)
        return 0;
    TreeNode* l = root;
    TreeNode* r = root;
    int hl = 0, hr = 0;
    while(l){
        l = l -> left;
        hl++;
    }
    while(r){
        r = r -> right;
        hr++;
    }
    if(hl == hr){
        return pow(2, hl) -1;
    }
    else
        return 1 + countNodes(root -> left) + countNodes(root -> right);
};
int main(int argc, const char * argv[]) {
    TreeNode* root = new TreeNode(1);
    root -> left = new TreeNode(2);
    std::cout << countNodes(root);;
    return 0;
}
