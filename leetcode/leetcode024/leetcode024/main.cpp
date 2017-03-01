//
//  main.cpp
//  leetcode024
//
//  Created by 萧天牧 on 17/2/27.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* swap(ListNode* A,ListNode* B){
    if(B == NULL)
        return A;
    A->next = B -> next;
    B->next = A;
    return B;
}
ListNode* swapPairs(ListNode* head) {
    if(head == NULL || head -> next == NULL)
        return head;
    ListNode *shaobing  = new ListNode(0);
    shaobing ->next = head;
    ListNode *tmp = shaobing;
    while(tmp && tmp->next){
        tmp -> next = swap(tmp ->next, tmp -> next -> next);
        tmp = tmp ->next -> next;
    }
    return shaobing->next;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
