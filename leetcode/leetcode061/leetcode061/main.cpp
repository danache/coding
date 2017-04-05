//
//  main.cpp
//  leetcode061
//
//  Created by 萧天牧 on 17/3/27.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
using namespace std;
//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* rotateRight(ListNode* head, int k) {
    if (!head)
        return head;
    int len = 1;
    ListNode* tail = head;
    ListNode* newHead = head;
    while(tail -> next){
        tail = tail -> next;
        len++;
    }
    tail -> next = head;
    if(k %= len)
        for(int i = 0;i < len - k; i++)
            tail = tail -> next;
    newHead = tail -> next;
    tail -> next = NULL;
    return newHead;
}

void showRes(ListNode* head){
    while (head) {
        cout << head -> val <<" ";
        head = head -> next;
    }
    cout << endl;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode *head = new ListNode(1);
    ListNode* tmp = head;
    
    for(int i = 2; i < 6; i++){
        tmp ->next = new ListNode(i);
        tmp = tmp->next;
    }
    showRes(head);
    ListNode * res = rotateRight(head, 2);
    showRes(res);
    return 0;
}
