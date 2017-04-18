//
//  main.cpp
//  leetcode203
//
//  Created by 萧天牧 on 17/4/6.
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
ListNode* removeElements(ListNode* head, int val) {
    ListNode **list = &head;
    
    while (*list != nullptr)
    {
        if ((*list)->val == val)
        {
            *list = (*list)->next;
        }
        else
        {
            list = &(*list)->next;
        }
    }
    
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
    ListNode *head = new ListNode(1);
    ListNode* tmp = head;
    
    for(int i = 1; i < 6; i++){
        tmp -> next = new ListNode(i);
        tmp = tmp->next;
    }
    showRes(head);
    head = removeElements(head,1);
    //ListNode * res = reverseBetween(head,1,2);
    showRes(head);
    return 0;
}
