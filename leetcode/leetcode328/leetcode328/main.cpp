//
//  main.cpp
//  leetcode328
//
//  Created by 萧天牧 on 17/4/10.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* oddEvenList(ListNode* head) {
    if(!head)
        return head;
    ListNode* p1 = head;
    ListNode* phead = head -> next;
    ListNode* p2 = phead;
    while(p2 && p2 -> next){
        p1 -> next = p1 -> next -> next;
        p2 -> next = p2 -> next -> next;
        p1 = p1 -> next;
        p2 = p2 -> next;
    }
    p1 -> next = phead;
    return head;
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
    ListNode *head = new ListNode(0);
    ListNode* tmp = head;
    
    for(int i = 1; i < 6; i++){
        tmp -> next = new ListNode(i);
        tmp = tmp->next;
    }
    showRes(head);
    showRes(oddEvenList(head));
    return 0;
}

