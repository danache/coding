//
//  main.cpp
//  leetcode095
//
//  Created by 萧天牧 on 17/4/13.
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

vector<TreeNode*> getTree(int start, int end){
    vector<TreeNode*> result;
    if(start > end){
        result.push_back(NULL);
        return result;
    }
    for(int i = start; i <= end; i++){
        vector<TreeNode*> left = getTree(start, i - 1);
        vector<TreeNode*> right = getTree(i + 1, end);
        for (int j = 0; j < left.size(); j++){
            for (int k = 0; k < right.size(); k++){
                TreeNode* root = new TreeNode(i);
                root -> left = left[j];
                root -> right = right[k];
                result.push_back(root);
            }
        }
    }
    return result;
}
vector<TreeNode*> generateTrees(int n) {
    vector<TreeNode*> result;
    if(n == 0)
        return result;
    else
        return getTree(1, n);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<TreeNode*> res;
    int n;
    while ((cin >> n)) {
        res = generateTrees(n);
        cout << res.size() << endl;
    }

    return 0;
}
