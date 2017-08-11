//
//  main.cpp
//  leetcode173
//
//  Created by 萧天牧 on 17/4/23.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>
using namespace std;
/**
 * Definition for binary tree
 */ struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class BSTIterator {
    stack<TreeNode *> myStack;
public:
    BSTIterator(TreeNode *root) {
        pushAll(root);
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !myStack.empty();
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode *tmpNode = myStack.top();
        myStack.pop();
        pushAll(tmpNode->right);
        return tmpNode->val;
    }
    
private:
    void pushAll(TreeNode *node) {
        for(; node!= NULL; myStack.push(node), node = node -> left);
    }
};
/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
