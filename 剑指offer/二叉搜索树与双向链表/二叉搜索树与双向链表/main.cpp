//
//  main.cpp
//  二叉搜索树与双向链表
//
//  Created by 萧天牧 on 17/5/16.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
    val(x), left(NULL), right(NULL) {
    }
};
TreeNode* Convert(TreeNode* pRootOfTree){
    if(!pRootOfTree)
        return pRootOfTree;
    TreeNode* p = pRootOfTree;
    TreeNode* pre = NULL;
    stack<TreeNode*> sta;
    //sta.push(pRootOfTree);
    bool first = true;
    while(p || !sta.empty()){
        while(p){
            sta.push(p);
            p = p -> left;
        }
        p = sta.top();
        sta.pop();
        if(first){
            first = false;
            pRootOfTree = p;
            pre = p;
        }
        else{
            pre -> right = p;
            p -> left = pre;
            pre = p;
        }
        p = p -> right;
    }
    return pRootOfTree;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
