//
//  main.cpp
//  leetcode094
//
//  Created by 萧天牧 on 17/4/13.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inorderTraversal(TreeNode* root) {
    stack<TreeNode*> s;
    vector<int> result;
    if(!root)
        return result;
    TreeNode* pNode = root;
    while(pNode||!s.empty()){
        if(pNode){
            s.push(pNode);
            pNode = pNode -> left;
        }
        else{
            pNode = s.top();
            s.pop();
            result.push_back(pNode -> val);
            pNode = pNode -> right;
        }
    }

    return result;
}
int main(int argc, const char * argv[]) {
    TreeNode* root = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(5);
    TreeNode* n6 = new TreeNode(6);
    root -> left = n2;
    root -> right = n3;
    n2 -> left = n4;
    n2 -> right = n5;
    n4 -> right = n6;
    vector<int> res = inorderTraversal(root);
    for(int i = 0; i < res.size(); i++){
        cout << res[i] <<" ";
    }
    cout << endl;
    return 0;
}
