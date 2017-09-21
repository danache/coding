#include <iostream>
using namespace std;
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root || p == root || q == root)
        return root;
    TreeNode* lres = lowestCommonAncestor(root -> left, p, q);
    TreeNode* rres = lowestCommonAncestor(root -> right, p, q);
    if(lres && rres)
        return root;
    return lres ==NULL ? rres:lres;

}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}