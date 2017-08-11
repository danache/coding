//
//  main.cpp
//  链表倒数第k个
//
//  Created by 萧天牧 on 17/5/15.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
    val(x), next(NULL) {
    }
};

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    if(!pListHead)
        return pListHead;
    if(k == 0)
        return NULL;
    ListNode* p1 = pListHead;
    ListNode* p2 = pListHead;
    while(k--){
        if(p1 == NULL)
            return NULL;
        p1 = p1 -> next;
    }
    while(p1 != NULL){
        p1 = p1 -> next;
        p2 = p2 -> next;
    }
    return p2;
}

int main(int argc, const char * argv[]) {
    ListNode* a = new ListNode(0);
    a -> next = new ListNode(1);
    a -> next ->next = new ListNode(2);
    a -> next ->next ->next= new ListNode(3);
    ListNode* p1 = FindKthToTail(a, 0);
    cout << FindKthToTail(a, 1)->val;
    cout << FindKthToTail(a, 2)->val;
    cout << FindKthToTail(a, 3)->val;
    cout << FindKthToTail(a, 4)->val;
    return 0;
}
