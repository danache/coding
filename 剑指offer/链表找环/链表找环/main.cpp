//
//  main.cpp
//  链表找环
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

ListNode* EntryNodeOfLoop(ListNode* pHead)
{
    if(!pHead)
        return NULL;
    ListNode* p1 = pHead;
    ListNode* p2 = pHead;
    while(p1 && p1 -> next){
        p1 = p1 ->next -> next;
        p2 = p2 -> next;
        if(p1 == p2)
            break;
    }
    if(!p1 || !p1 ->next)
        return NULL;
    p1 = pHead;
    while(p1 != p2){
        p1 = p1 -> next;
        p2 = p2 -> next;
    }
    return p1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
