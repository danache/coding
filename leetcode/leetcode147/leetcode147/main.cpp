//
//  main.cpp
//  leetcode147
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

void showRes(ListNode* head){
    while (head) {
        cout << head -> val <<" ";
        head = head -> next;
    }
    cout << endl;
}
ListNode* insertionSortList(ListNode* head) {
    if(!head)
        return head;
    ListNode* re = new ListNode(-1);
    while(head){
        
        ListNode* ph = re;
        while(ph -> next && ph ->next -> val < head -> val){
            ph = ph -> next;
        }
        ListNode *tmp = new ListNode(head -> val);
        tmp -> next = ph -> next;
        ph -> next = tmp;
        head = head -> next;
        //showRes(re);
    }
    return re -> next;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode *head = new ListNode(6);
    ListNode* tmp = head;
    
    for(int i = 1; i < 6; i++){
        tmp -> next = new ListNode(6 - i);
        tmp = tmp->next;
    }
    showRes(head);
    head = insertionSortList(head);
    
    showRes(head);
    return 0;
}

