//
//  main.cpp
//  从上往下打印二叉树
//
//  Created by 萧天牧 on 17/5/15.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
    val(x), left(NULL), right(NULL) {
    }
};
vector<int> PrintFromTopToBottom(TreeNode* root) {
    queue<TreeNode*> que;
    vector<int> res;
    if(!root)
        return res;
    que.push(root);
    while(!que.empty()){
        TreeNode* tmp = que.front();
        que.pop();
        if(!tmp){
            if(!que.empty())
                que.push(NULL);
        }
        else{
            res.push_back(tmp->val);
            if(tmp -> left)
                que.push(tmp -> left);
            if(tmp -> right)
                que.push(tmp -> right);
        }
    }
    return res;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
