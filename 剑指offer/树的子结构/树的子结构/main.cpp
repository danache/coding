//
//  main.cpp
//  树的子结构
//
//  Created by 萧天牧 on 17/5/15.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
    val(x), left(NULL), right(NULL) {
    }
};
bool isSubtree(TreeNode* pRootA, TreeNode* pRootB) {
    if (pRootB == NULL) return true;
    if (pRootA == NULL) return false;
    if (pRootB->val == pRootA->val) {
        return isSubtree(pRootA->left, pRootB->left)
        && isSubtree(pRootA->right, pRootB->right);
    } else return false;
}
bool HasSubtree(TreeNode* pRootA, TreeNode* pRootB)
{
    if (pRootA == NULL || pRootB == NULL) return false;
    return isSubtree(pRootA, pRootB) ||
    HasSubtree(pRootA->left, pRootB) ||
    HasSubtree(pRootA->right, pRootB);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
