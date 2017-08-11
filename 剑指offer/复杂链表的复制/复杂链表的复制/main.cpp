//
//  main.cpp
//  复杂链表的复制
//
//  Created by 萧天牧 on 17/5/15.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
    label(x), next(NULL), random(NULL) {
    }
};


RandomListNode* Clone(RandomListNode* pHead)
{
    if(!pHead)
        return NULL;
    RandomListNode* p1 = pHead;
    while(p1){
        RandomListNode* tmp = new RandomListNode(p1->label);
        tmp ->next = p1 -> next;
        p1 -> next = tmp;
        p1 = p1 -> next -> next;
    }
    p1 = pHead;
    while(p1){
        p1 -> next -> random = p1 -> random;
        p1 = p1 -> next -> next;
    }
    RandomListNode* shaobing = new RandomListNode(0);
    RandomListNode* bbbb = shaobing;
    p1 = pHead;
    while(p1){
        bbbb -> next = p1 -> next;
        bbbb= bbbb -> next;
        p1 -> next = p1 -> next -> next;
        p1 = p1 ->next;
    }
    return shaobing -> next;
}

int main(int argc, const char * argv[]) {
    RandomListNode* a = new RandomListNode(1);
    RandomListNode* b = new RandomListNode(2);
    RandomListNode* c = new RandomListNode(3);
    RandomListNode* d = new RandomListNode(4);
    RandomListNode* e = new RandomListNode(5);
    a -> next = b;
    b -> next = c;
    c -> next = d;
    d -> next = e;
    a -> random = c;
    b -> random = e;
    c -> random = a;
    d -> random = b;
    Clone(a);
    std::cout << "Hello, World!\n";
    return 0;
}
