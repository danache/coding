//
//  main.cpp
//  leetcode021
//
//  Created by 萧天牧 on 17/2/27.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
using namespace std;

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == NULL && l2 == NULL) {
        return NULL;
    }
    
    if (l1 == NULL) {
        return l2;
    }
    
    if (l2 == NULL) {
        return l1;
    }

    ListNode* p = new ListNode(0);
    ListNode* head = p;
    while(l1 != NULL && l2 != NULL){
        if(l1->val < l2 ->val){
            p->next = l1;
            p = p -> next;
            l2 = l2 -> next;
        }
        else {
            p->next = l2;
            p = p -> next;
            l1 = l1 -> next;
        }
    }
    if(l1 != NULL)
        p->next = l1;
    else
        p->next = l2;
    return head->next;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
