//
//  main.cpp
//  leetcode142
//
//  Created by 萧天牧 on 17/4/5.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *detectCycle(ListNode *head) {
    if(!head)
        return head;
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast && fast -> next){
        fast = fast -> next -> next;
        slow = slow -> next;
        if(fast == slow)
            break;
    }
    if (fast ==NULL || fast -> next == NULL)
        return NULL;
    slow = head;
    while(slow != fast){
        slow = slow -> next;
        fast = fast -> next;
    }
    return slow;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
