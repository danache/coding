#include <iostream>
#include <vector>
using namespace std;
/**
 * Definition for a binary tree node.
 *
 */
struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     };

    void get(TreeNode* root,vector<int>now,  vector<vector<int>>& vec){
        now.push_back(root -> val);
        if (!root->left && !root -> right){
            vec.push_back(now);
            return;
        }


        if(root ->left)
            get(root -> left, now, vec);
        if(root->right)
             get(root -> right, now, vec);

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> now;
        vector<vector<int>> vec;
        get(root,now,vec);
        vector<string> res;
        for(auto v : vec){
            string s= "";
            for(int i = 0; i < v.size(); i++){
                s += to_string(v[i]);
                if(i != v.size() - 1)
                    s +="->";
            }
            res.push_back(s);
        }

    return res;
    }

int main() {
    TreeNode *root = new TreeNode(1);
    TreeNode *l1 = new TreeNode(2);
    TreeNode *r1 = new TreeNode(3);
    root -> left = l1;
    l1 -> right = r1;
    binaryTreePaths(root);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}