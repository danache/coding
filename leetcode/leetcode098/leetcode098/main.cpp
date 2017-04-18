//
//  main.cpp
//  leetcode098
//
//  Created by 萧天牧 on 17/4/18.
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

//bool isValidBST(TreeNode* root) {
//    if(!root)
//        return true;
//    stack<TreeNode*> sta;
//    vector<int> vec;
//    TreeNode* nowNode = root;
//    while(!sta.empty() || nowNode){
//        if(nowNode){
//            while(nowNode){
//                sta.push(nowNode);
//                nowNode = nowNode -> left;
//            }
//        }
//        else{
//            nowNode = sta.top();
//            sta.pop();
//            vec.push_back(nowNode->val);
//            nowNode = nowNode -> right;
//        }
//        
//    }
//    for(int i = 0; i < vec.size() - 1; i++){
//        if (vec[i] > vec[i + 1])
//            return false;
//    }
//    return true;
//}


bool isValidBST(TreeNode* root, TreeNode* min_val, TreeNode* max_val) {
    if(!root) return true;
    if((min_val && root -> val <= min_val -> val) || (max_val && root -> val >= max_val -> val))
       return false;
    return (isValidBST(root -> left, min_val, root) && (isValidBST(root -> right, root, max_val)));
}
bool isValidBST(TreeNode* root) {
    return isValidBST(root, NULL, NULL);
}

int main(int argc, const char * argv[]) {
    TreeNode* root = new TreeNode(3);
    TreeNode* l1 = new TreeNode(1);
    TreeNode* l2 = new TreeNode(2);
    TreeNode* l5 = new TreeNode(5);
    TreeNode* l4 = new TreeNode(4);
    root->left = l1;
    l1 -> right = l2;
    root -> right = l5;
    l5 -> left = l4;
    // insert code here...
    cout << isValidBST(root);
    return 0;
}

