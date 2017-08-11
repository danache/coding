//
//  main.cpp
//  leetcode145
//
//  Created by 萧天牧 on 17/4/23.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
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


vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    if(!root)
        return result;
    stack<pair<TreeNode*, int>> sta;
    sta.push(make_pair(root,0));
    TreeNode* pNode = NULL;
    while(!sta.empty()){
        pNode = sta.top().first;
        int time = sta.top().second;
        sta.pop();
        if(time == 0){
            sta.push(make_pair(pNode,1));
            if(pNode -> right)
                sta.push(make_pair(pNode -> right,0));
            if(pNode -> left)
                sta.push(make_pair(pNode -> left,0));
            
        }
        else{
            result.push_back(pNode -> val);
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    TreeNode* root = new TreeNode(0);
    root -> left =new TreeNode(1);
    root -> left -> left =new TreeNode(2);
    vector<int> res = preorderTraversal(root);
    for(int i = 0 ; i< res.size(); i++)
        cout <<res[i] <<" ";
    return 0;
}
