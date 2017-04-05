//
//  main.cpp
//  leetcode082
//
//  Created by 萧天牧 on 17/3/27.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    if(!head)
        return head;
    ListNode* shaobing = new ListNode(0);
    shaobing -> next = head;
    ListNode* ppre = shaobing;
    ListNode* pcur = head;
    ListNode* pnext;
    
   
    bool flag;
    while(pcur){
        pnext = pcur -> next;
        flag = false;
        while(pnext && pnext -> val == pcur -> val){
            flag = true;
            ppre -> next = pnext;
            pcur = pnext;
            pnext = pcur -> next;
        }
        if(flag){
            ppre -> next = pnext;
        }
        else{
            ppre = pcur;
        }
        pcur = pnext;
    }
    return shaobing -> next;
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
        tmp ->next = new ListNode(i);
        tmp = tmp->next;
    }
    showRes(head);
    ListNode * res = deleteDuplicates(head);
    showRes(res);
    return 0;
}
