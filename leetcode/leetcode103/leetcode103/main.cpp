//
//  main.cpp
//  leetcode103
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
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if(!root)
        return result;
    queue<TreeNode*> que;
    vector<int> now_vec;
    que.push(root);
    que.push(NULL);
    bool odd = false;
    while(!que.empty()){
        TreeNode* tmp = que.front();
        que.pop();
        if(tmp == NULL){
            if(odd){
                reverse(now_vec.begin(), now_vec.end());
            }
            odd = !odd;
            result.push_back(now_vec);
            now_vec.clear();
            if(!que.empty())
                que.push(NULL);
        }
        else{
            now_vec.push_back(tmp -> val);
            if(tmp ->left) que.push(tmp -> left);
            if(tmp -> right) que.push(tmp -> right);
        }
    }
    return result;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
