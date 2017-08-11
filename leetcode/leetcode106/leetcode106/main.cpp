//
//  main.cpp
//  leetcode106
//
//  Created by 萧天牧 on 17/4/18.
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

TreeNode* getTree(vector<int>& inorder, vector<int>& postorder ,int Begin0, int End0, int Begin1, int End1){
    if(Begin0 < 0 || Begin1 < 0)
        return NULL;
    if(Begin0 > End0 || Begin1 > End1)
        return NULL;
    int root_num = postorder[End1];
    int root_index;
    for(root_index = End0; root_index >= Begin0; root_index--){
        if(inorder[root_index] == root_num)
            break;
    }
    TreeNode* root = new TreeNode(root_num);
    TreeNode* left = getTree(inorder, postorder, Begin0, root_index - 1, Begin1,   root_index - Begin0 + Begin1 - 1);
    TreeNode* right = getTree(inorder, postorder,root_index+1, End0, root_index - Begin0 + Begin1, End1-1);
    root ->left = left;
    root -> right = right;
    return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if(inorder.empty() || postorder.empty())
        return NULL;
    return getTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a = {1,2,3};
    vector<int> b = {2,3,1};
    buildTree(a, b);
    std::cout << "Hello, World!\n";
    return 0;
}
