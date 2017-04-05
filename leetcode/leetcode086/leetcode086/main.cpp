//
//  main.cpp
//  leetcode086
//
//  Created by 萧天牧 on 17/4/2.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* partition(ListNode* head, int x) {
    if(!head)
        return head;
    ListNode* l1_head = new ListNode(0);
    ListNode* l2_head = new ListNode(0);
    ListNode* l1 = new ListNode(0);
    ListNode* l2 = new ListNode(0);
    l1_head -> next = l1;
    l2_head -> next = l2;
    while(head){
        if(head -> val < x){
            l1 -> next = head;
            l1 = l1 ->next;
        }
        else{
            l2 -> next = head;
            l2 = l2 ->next;
        }
        head = head -> next;
    }
    l2 -> next = NULL;
    l1->next = l2_head -> next->next;
    return l1_head -> next->next;
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
    int a[] = {1,4,3,2,5,2};
    for(int i = 0; i < 6; i++){
        tmp ->next = new ListNode(a[i]);
        tmp = tmp->next;
    }
    showRes(head->next);
    ListNode * res = partition(head->next,3);
    showRes(res);
    return 0;
}
