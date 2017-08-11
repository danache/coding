//
//  main.cpp
//  leetcode129
//
//  Created by 萧天牧 on 17/4/23.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
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

int str2int(string s){
    int result = 0;
    for(int i = 0; i < s.length(); i++){
        result *= 10;
        result += s[i] - '0';
    }
    return result;
}

void countNum(TreeNode* root, string s, vector<string>& res){
    if(!root)
        return;
    char c = root->val + '0';
    string tmp = s + char(c);

    if(!root -> left && !root -> right){
            res.push_back(tmp);
        return;
    }
    countNum(root -> left, tmp, res);
    countNum(root -> right, tmp, res);
}
int sumNumbers(TreeNode* root) {
    vector<string> res;
    if (!root)
        return 0;
    int result = 0;
    string s = "";
    countNum(root,s, res);
    for(int i = 0; i < res.size(); i++){
        result += str2int(res[i]);
    }
    return result;
}

int main(int argc, const char * argv[]) {
    TreeNode* root = new TreeNode(1);
    root -> left =new TreeNode(2);
    root -> right =new TreeNode(3);
    cout << sumNumbers(root);
}
