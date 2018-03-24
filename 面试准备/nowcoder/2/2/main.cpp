#include <iostream>
#include <vector>
#include <string>




//   Problem 1 Prefix tree
//   problem 2 一个数组中字数组最大Xor值

using namespace std;
class TreeNode{
public:
    int path;
    int end;
    vector<TreeNode*> mp ;;
    TreeNode() {
        path = 0;
        end = 0;
        mp = vector<TreeNode*>(26);
    }
};
class prefixTree{
private:
    TreeNode* root;
public:
    prefixTree(){
        root = new TreeNode();
    }
    void insert(string s){
        if (s == "")
            return ;
        TreeNode* Node = root;
        for(auto c : s){
            int index = c - 'a';
            if (Node -> mp[index] == NULL){
                Node -> mp[index] = new TreeNode();
            }
            Node = Node -> mp[index] ;
            Node->path++;
        }
        Node -> end++;
    }

    bool search(string s){
        if (s == "")
            return false;
        TreeNode* Node = root;
        for(auto c : s){
            int index = c - 'a';
            if (Node -> mp[index] == NULL){
                return false;
            }
            Node = Node -> mp[index] ;
        }
        return Node -> end > 0;
    }

    void del(string s){
        if(!search(s))
            return;
        TreeNode* Node = root;
        for(auto c : s){
            int index = c - 'a';
            if (Node ->mp[index]->path-- == 1){
                Node -> mp[index] = NULL;
                return;
            }
            Node = Node -> mp[index] ;
        }
        Node -> end --;
    }

    int prefixNum(string s){
        if(s == "")
            return 0;
        TreeNode* Node = root;

        for(auto c : s){
            int index = c - 'a';
            if (Node ->mp[index] == NULL){
                return 0 ;
            }
            Node = Node -> mp[index] ;
        }
        return Node -> path;

    }
};

class NumNode{
public:
    vector<NumNode*> next;

    NumNode(){
        next = vector<NumNode*>(2);
    }
};
class Problem2{
    NumNode* root = new NumNode();
    void add(int val){
        int res = 0;
        NumNode* now = root;
        for(int move = 31; move >= 0; move--){
            int path = (val >> move) & 1;
            now -> next[path] = now->next[path] == NULL ? new NumNode() : now->next[path];
        }
    }
};


int main() {
    prefixTree* trie = new prefixTree();
    cout<< trie->search("zuo") <<endl;
    trie->insert("zuo");
    cout<< trie->search("zuo")<<endl;

    trie->del("zuo");
    cout<< trie->search("zuo")<<endl;

    trie->insert("zuo");
    trie->insert("zuo");
    trie->del("zuo");
    cout<< trie->search("zuo")<<endl;

    trie->del("zuo");
    cout<< trie->search("zuo")<<endl;


    trie->insert("zuoa");
    trie->insert("zuoac");
    trie->insert("zuoab");
    trie->insert("zuoad");
    trie->del("zuoa");
    cout<< trie->search("zuoa") << endl;
    cout<< trie->prefixNum("zuo")<< endl;;

    return 0;
}