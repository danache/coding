//
//  main.cpp
//  BSTN
//
//  Created by dan on 16/9/4.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
using namespace std;
const int MAXN = 10000;
class BSTN{
public:
    BSTN* left;
    BSTN* right;
    int key;
    BSTN(){
        left = right = NULL;
        key = 0;
    }
    
};
BSTN pool[MAXN];
int pool_cnt;

BSTN* getNewNode(int key){
    if (pool_cnt >= MAXN)
        return NULL;
    pool[pool_cnt].key = key;
    return &pool[pool_cnt++];
}

bool insert_BSTN(BSTN* p, BSTN *q){
    if (p == NULL || q == NULL)
        return false;
    if (q->key <= p->key){
        if (p->left == NULL){
            p->left = q;
            return true;
        }
        else{
            insert_BSTN(p->left, q);
            return true;
        }
    }
    else{
        if (p->right == NULL){
            p->right = q;
            return true;
        }
        else{
            insert_BSTN(p->right, q);
            return true;
        }
    }
    return false;
}

int midOrder(BSTN* p, int k){
    if (p == NULL)
        return 0;
    int leftnum = 0, rightnum = 0;
    if(p->left != NULL)
        leftnum = midOrder(p->left, k);
    if(leftnum < k){
        cout << p->key <<" ";
        k--;
    }
    if (leftnum < k){
        rightnum = midOrder(p->right, k - leftnum );
    }
    return leftnum + rightnum + 1;
}
int main(int argc, const char * argv[]) {
    int n, x, k;
    BSTN head;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x;
        if(i == 0){
            head.key = x;
            continue;
        }
        insert_BSTN(&head, getNewNode(x));
    }
    while(cin >> k){
        midOrder(&head, k);
    }
    
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
