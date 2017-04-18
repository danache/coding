//
//  main.cpp
//  leetcode160
//
//  Created by 萧天牧 on 17/4/6.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(!headA || ! headB)
        return NULL;
    int m = 0, n = 0;
    ListNode* l1 = headA;
    ListNode* l2 = headB;
    
    while(l1){
        m ++;
        l1 = l1 -> next;
    }
    while(l2){
        n++;
        l2 = l2 -> next;
    }
    l1 = headA;
    l2 = headB;
    if(m < n){
        int tmp = n - m;
        while (tmp) {
            l2 = l2 -> next;
            tmp--;
        }
    }
    else{
        int tmp = m - n;
        while (tmp) {
            l1 = l1 -> next;
            tmp--;
        }
    }
    while(l1 && l2){
        if(l1 == l2)
            return l1;
        l1 = l1 -> next;
        l2 = l2 -> next;
    }
    return NULL;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
