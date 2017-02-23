//
//  main.cpp
//  leetcode002
//
//  Created by dan on 16/11/15.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *pHead  = new ListNode(0);
    ListNode *pTail = pHead;
    int num = 0,carry = 0;
    while(l1 && l2){
        num = l1 -> val + l2 -> val + carry;
        carry = num / 10;
        num = num % 10;
        ListNode *pCur = new ListNode(num);
        pTail -> next = pCur;
        pTail = pCur;
        l1 = l1 -> next;
        l2 = l2 ->next;
    }
    ListNode *p = (l1 == NULL) ? l2 : l1;
    while (p) {
        num = p -> val + carry;
        carry = num / 10;
        num = num % 10;
        ListNode *pCur = new ListNode(num);
        pTail -> next = pCur;
        pTail = pCur;
        p = p -> next;
    }
    if (carry){
        ListNode *pCur = new ListNode(carry);
        pTail -> next = pCur;
        pTail = pCur;
    }
    return pHead -> next;
};


int main(int argc, const char * argv[]) {
    //[2,4,3]
    //[5,6,4]
    ListNode *l1 = new ListNode(2);
    ListNode *l12 = new ListNode(4);
    l1 ->next = l12;
    ListNode * l13 = new ListNode(3);
    l12 -> next = l13;
    
    ListNode *l2 =new ListNode(5);
    ListNode *l22 = new ListNode(6);
    l2 ->next = l22;
    ListNode * l23 = new ListNode(4);
    l22 -> next = l23;
    
    ListNode * res ;
    res = addTwoNumbers(l1, l2);
    while(res != NULL){
        cout << res ->val << endl;
        res = res -> next;
    }
}
//每次new一个节点
