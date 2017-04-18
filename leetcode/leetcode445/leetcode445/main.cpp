//
//  main.cpp
//  leetcode445
//
//  Created by 萧天牧 on 17/4/10.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if(!l1)
        return l2;
    if(!l2)
        return l1;
    stack<int> s1, s2;
    
    while(l1){
        s1.push(l1 -> val);
        l1 = l1 -> next;
    }
    while(l2){
        s2.push(l2 -> val);
        l2 = l2 -> next;
    }
    int jinwei = 0;
    ListNode* phead = new ListNode(-1);
    while(!s1.empty() && !s2.empty()){
        int res = s1.top() + s2.top() + jinwei;
        ListNode* tmp = new ListNode(res % 10);
        tmp -> next = phead -> next;
        phead -> next = tmp;
        jinwei = res / 10;
        s1.pop();
        s2.pop();
    }
    stack<int> s3 = s1.empty()? s2:s1;
    while(!s3.empty() || jinwei){
        int res = jinwei;
        if(!s3.empty()){
            res += s3.top();
            s3.pop();
        }
        ListNode* tmp = new ListNode(res % 10);
        tmp -> next = phead -> next;
        phead -> next = tmp;
        jinwei = res / 10;
    }
    return phead -> next;
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
    ListNode *head2 = new ListNode(0);
    ListNode* tmp2 = head2;
    
    for(int i = 1; i < 6; i++){
        tmp2 -> next = new ListNode(i);
        tmp2 = tmp2->next;
    }
    showRes(head);
    showRes(head2);
    showRes(addTwoNumbers(head, head2));
    return 0;
}

