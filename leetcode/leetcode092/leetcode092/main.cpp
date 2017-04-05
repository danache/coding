//
//  main.cpp
//  leetcode092
//
//  Created by 萧天牧 on 17/4/2.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void showRes(ListNode* head){
    while (head) {
        cout << head -> val <<" ";
        head = head -> next;
    }
    cout << endl;
}
ListNode* reverseBetween(ListNode* head, int m, int n) {
    if(!head)
        return head;
    ListNode* shaobing = new ListNode(0);
    shaobing -> next = head;
    ListNode *l1 = shaobing;
    int step = m - 1;
    int num = n - m;
    while(step--)
        l1 = l1 -> next;
    ListNode *ph = l1;
    l1 = l1 ->next;
    while(num--){
        ListNode* tmp = l1 -> next;
        l1 -> next = tmp -> next;
        tmp ->next = ph -> next;
        ph -> next = tmp;
        //showRes(ph);
    }
    return shaobing -> next;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode *head = new ListNode(0);
    ListNode* tmp = head;
    
    for(int i = 1; i < 2; i++){
        tmp ->next = new ListNode(i);
        tmp = tmp->next;
    }
    showRes(head);
    ListNode * res = reverseBetween(head,1,2);
    showRes(res);
    return 0;
}
