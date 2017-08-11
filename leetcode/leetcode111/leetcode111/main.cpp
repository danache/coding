//
//  main.cpp
//  leetcode111
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

int minDepth(TreeNode* root) {
    if(!root)
        return 0;
    queue<TreeNode*> que;
    que.push(root);
    que.push(NULL);
    int nowDep = 1;
    while(!que.empty()){
        TreeNode* tmp = que.front();
        que.pop();
        if(tmp == NULL){
            nowDep++;
            if(!que.empty()){
                que.push(NULL);
            }
        }
        else{
            if (!tmp -> left && !tmp -> right)
                break;
            else{
                if(tmp -> left)que.push(tmp -> left);
                if(tmp -> right)que.push(tmp -> right);
                
            }
        }
    }
    return nowDep;
}


int main(int argc, const char * argv[]) {
    TreeNode* root = new TreeNode(0);
    root -> left = new TreeNode(1);
    cout << minDepth(root)<<endl;
    return 0;
}
