#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<int> middle(TreeNode *root){
    vector<int> vec;
    stack<TreeNode *> sta;
    TreeNode *p =root;
    while( !sta.empty() || p){
        while(p){
            sta.push(p);
            p = p->left;
        }
        if(!sta.empty()){
            p = sta.top();
            sta.pop();
            vec.push_back(p->val);
            p = p -> right;
        }
    }
    return vec;p
}

int kthSmallest(TreeNode* root, int k) {

    vector<int> vec = middle(root);
    return vec[k - 1];

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}