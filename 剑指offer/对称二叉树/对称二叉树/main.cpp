//
//  main.cpp
//  对称二叉树
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
bool judge(TreeNode* p1, TreeNode* p2){
    if(!p1 && !p2)
        return true;
    if(!p1 || !p2)
        return false;
    if(p1 -> val != p2 -> val)
        return false;
    return judge(p1 -> left, p2 -> right) && judge(p1 -> right, p2 -> left);
}
bool isSymmetrical(TreeNode* pRoot)
{
    return judge(pRoot, pRoot);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
