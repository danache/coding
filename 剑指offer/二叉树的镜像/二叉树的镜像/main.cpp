//
//  main.cpp
//  二叉树的镜像
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

void Mirror(TreeNode *pRoot) {
    if(!pRoot)
        return;
    TreeNode* tmp = pRoot -> left;
    pRoot -> left = pRoot -> right;
    pRoot -> right = tmp;
    Mirror(pRoot -> left);
    Mirror(pRoot -> right);
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
