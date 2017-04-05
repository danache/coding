//
//  main.cpp
//  leetcode141
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
bool hasCycle(ListNode *head) {
    if (!head || !(head ->next))
        return false;
    ListNode *l1 = head;
    ListNode *l2 = head;
    while(l1->next && l1 ->next->next){
        l1 = l1 ->next->next;
        l2 = l2 ->next;
        if(l1 == l2)
            return true;
    }
    return false;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
