//
//  main.cpp
//  leetcode206
//
//  Created by 萧天牧 on 17/4/6.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* reverseList(ListNode* head) {
    if (!head)
        return head;
    ListNode* shaobing = new ListNode(-1);
    shaobing -> next = head;
    ListNode* pcur = shaobing -> next;
    ListNode* ph = shaobing;
    
    while(pcur -> next){
        ListNode* tmp = pcur -> next;
        pcur -> next = tmp -> next;
        tmp -> next = ph -> next;
        ph -> next = tmp;
    }
    return shaobing -> next;
}


void showRes(ListNode* head){
    while (head) {
        cout << head -> val <<" ";
        head = head -> next;
    }
    cout << endl;
}int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode *head = new ListNode(0);
    ListNode* tmp = head;
    
    for(int i = 1; i < 6; i++){
        tmp -> next = new ListNode(i);
        tmp = tmp->next;
    }
    showRes(head);
    //reorderList(head);
    head = reverseList(head);
    showRes(head);
    return 0;
}

