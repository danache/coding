//
//  main.cpp
//  mianshi160923
//
//  Created by dan on 16/9/23.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
#define MAXN 1005
using namespace std;
struct Node{
    int num;
    Node* lchild;
    Node* rchild;
};
Node* find(int n, Node* root){
    if(root->num == n)
        return root;
    else if(root-> num < n) {
        if (root-> lchild == NULL){
            return NULL;
        }
        else
            return find(n, root->lchild);
    }
    else{
        if (root-> lchild == NULL){
            return NULL;
        }
        else
            return find(n, root->rchild);
    }
    
        
}
void insert(Node *father, Node *child){
    if (father->num > child->num)
        father->lchild = child;
    else
        father->rchild = child;
}
int depth(Node* t)

　　{
    　　if(t == NULL)
        return 0;
　　　　int dl = depth(t->lchild);
    
    　　int dr = depth(t->rchild);
    
    　　return (dl>dr ? dl : dr)+1;
    
    }

int main(){
    int n ,f ,c;
    cin >> n;
    Node * root;
    while(n--){
        cin >> f >> c;
        if (find(f, root) != NULL){
            Node * tmp = find(f, root);
            Node *newnode = new Node();
            newnode->num = c;
            insert(tmp, newnode);
        }
    }
}