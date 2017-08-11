//
//  main.cpp
//  leetcode113
//
//  Created by 萧天牧 on 17/4/22.
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
void getRes(TreeNode* root, int sum_left, vector<int> now_select, vector<vector<int>>& result){
    if (!root)
        return;
    if (root -> val == sum_left && (!root -> left) && (!root -> right)){
        now_select.push_back(sum_left);
        result.push_back(now_select);
        return;
    }
    else {
        now_select.push_back(root -> val);
        getRes(root -> left, sum_left - root -> val, now_select, result);
        getRes(root -> right, sum_left - root -> val, now_select, result);
        
    }
}
vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> result;
    if(!root)
        return result;
    vector<int> now_select;
    getRes(root, sum, now_select, result);
    return result;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
