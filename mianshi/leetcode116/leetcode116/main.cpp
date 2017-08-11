//
//  main.cpp
//  leetcode116
//
//  Created by 萧天牧 on 17/4/23.
//  Copyright © 2017年 萧天牧. All rights reserved.
//
//Definition for binary tree with next pointer.
#include <iostream>
#include <queue>
using namespace std;
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect(TreeLinkNode *root) {
    if(!root)
        return;
    queue<TreeLinkNode*> que;
    que.push(root);
    que.push(NULL);
    TreeLinkNode* last = NULL;
    TreeLinkNode* tmp;
    
    while(!que.empty()){
        tmp = que.front();
        que.pop();
        if(last){
            last -> next = tmp;
            last = last -> next;
        }
        else{
            last = tmp;
        }
        
        if(tmp == NULL){
            if(!que.empty())
                que.push(NULL);
        }
        else{

            if(tmp -> left) que.push(tmp -> left);
            if(tmp -> right) que.push(tmp -> right);
        }
    }

};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    TreeLinkNode* root = new TreeLinkNode(0);
    root -> left = new TreeLinkNode(1);
    root -> right = new TreeLinkNode(2);
    connect(root);
    root;
    return 0;
}
