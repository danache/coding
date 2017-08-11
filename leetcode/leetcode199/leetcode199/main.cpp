//
//  main.cpp
//  leetcode199
//
//  Created by 萧天牧 on 17/4/23.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
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

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root)
            return res;
        queue<TreeNode*> que;
        que.push(root);
        que.push(NULL);
        while(!que.empty()){
            TreeNode* tmp = que.front();
            que.pop();
            if(tmp == NULL){
                if(!que.empty())
                    que.push(NULL);
            }
            else{
                if(que.front() == NULL)
                    res.push_back(tmp -> val);
                if(tmp -> left)
                    que.push(tmp -> left);
                if(tmp -> right)
                    que.push(tmp -> right);
                
            }
        }
        return res;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
