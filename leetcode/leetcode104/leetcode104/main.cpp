//
//  main.cpp
//  leetcode104
//
//  Created by 萧天牧 on 17/4/18.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode* root) {
    
    if(!root)
        return 0;
    queue<TreeNode*> que;
    
    que.push(root);
    que.push(NULL);
    int count = 1;
    while(!que.empty()){
        TreeNode* tmp = que.front();
        que.pop();
        if(tmp == NULL){
            
            if(!que.empty()){
                que.push(NULL);
                count++;
            }
        }
        else{
            if(tmp ->left) que.push(tmp -> left);
            if(tmp -> right) que.push(tmp -> right);
        }
    }
    return count;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
