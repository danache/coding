//
//  main.cpp
//  链表
//
//  Created by 萧天牧 on 17/3/20.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
using namespace std;
class Node{

public:
    Node(int v):value(v){};
    int value;
    Node* next;
};
//链表翻转
Node* Preverse(Node* pHead, int from, int to){
    Node* pCur = pHead->next;
    for (int i = 0; i < from ; i++){
        pHead = pCur;
        pCur = pCur -> next;
    }
    for(int i = 0; i < to - from; i++){
        Node *tmp = pCur -> next;
        pCur -> next = pCur -> next ->next;
        tmp ->next = pHead ->next;
        pHead -> next = tmp;
    }
    return pHead;
}
///////////////////////////////////////////
void Print(Node* pHead){
    pHead = pHead ->next;
    while(pHead){
        cout << pHead->value <<" ";
        pHead = pHead->next;
    }
    cout << endl;
}


int main(int argc, const char * argv[]) {
    
    Node *phead = new Node(0);
    int i;
    for(i = 0; i < 10; i++){
        Node *p = new Node(rand() % 100);
        p->next = phead->next;
        phead->next = p;
    }
    Print(phead);
    Preverse(phead, 0, 4);
    Print(phead);
    return 0;
}
