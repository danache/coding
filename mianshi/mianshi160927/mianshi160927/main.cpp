//
//  main.cpp
//  mianshi160927
//
//  Created by dan on 16/9/27.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
#include<queue>
using namespace std;
struct Node{
    int index;
    Node* father;
    int nogo = 0;
    bool visit;
};
int getRes(int n){
    queue<Node*> que;
    Node *end = new Node();
    end->index = n;
    end->father = NULL;
    end->visit = true;
    que.push(end);
    int allnum = 0;
    while(!que.empty()){
        Node * now = que.front();
        que.pop();
        if (now->index == 1)
            allnum++;
        if(!(now->index == 1)){
            Node *next1 = new Node();
            next1->father = now;
            next1->index = now->index - 1;
            next1->visit = true;
            next1->nogo = 0;
            que.push(next1);
            if (!(now->nogo == 2)){
                Node *next2 = new Node();
                next2->father = now;
                next2->index = now->index - 1;
                next2->visit = false;
                next2->nogo = now->nogo + 1;
                que.push(next2);
            }
        }
        
    }
    return allnum;
}
int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    cout <<getRes(n) << endl;
}
