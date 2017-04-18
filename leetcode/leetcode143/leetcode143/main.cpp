//
//  main.cpp
//  leetcode143
//
//  Created by 萧天牧 on 17/4/5.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {};
};

void showRes(ListNode* head){
    while (head) {
        cout << head -> val <<" ";
        head = head -> next;
    }
    cout << endl;
}
void reorderList(ListNode* head) {
    if(!head)
        return;
    ListNode* l1 = head;
    ListNode* l2 = head -> next;
    while (l2 && l2 -> next) {
        l1 = l1 -> next;
        l2 = l2 -> next -> next;
    }
    ListNode* h2 = new ListNode(0);
    h2 -> next = l1 -> next;
    l1 -> next = NULL;
    l2 = h2 -> next;
    while(l2 && l2 -> next){
        ListNode *tmp = l2 -> next;
        l2 -> next = tmp -> next;
        tmp -> next = h2 -> next;
        h2 -> next = tmp;
    }
    for(l1 = head, l2 = h2 -> next;l1;){
        auto t = l1 -> next;
        l1 -> next = l2;
        l1 = l2;
        l2 = t;
        showRes(head);
        //showRes(l2);
        cout <<"       "<<endl;
    }
    
    //for (p1 = head, p2 = head2; p2; ) {
    //    auto t = p1->next;
    //    p1->next = p2;
    //    p2 = p2->next;
    //    p1 = p1->next->next = t;
    //}
}
int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode *head = new ListNode(0);
    ListNode* tmp = head;
    
    for(int i = 1; i < 6; i++){
        tmp -> next = new ListNode(i);
        tmp = tmp->next;
    }
    //showRes(head);
    reorderList(head);
    //ListNode * res = reverseBetween(head,1,2);
    //showRes(head);
    return 0;
}
