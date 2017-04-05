//
//  main.cpp
//  leetcode138
//
//  Created by 萧天牧 on 17/4/5.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>

//Definition for singly-linked list with a random pointer.
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head)
            return head;
        RandomListNode *result, *l1, *l2;
        for(l1 = head; l1 != NULL; l1 = l1 -> next -> next){
            l2 = new RandomListNode(l1 -> label);
            l2 -> next = l1 -> next;
            l1 -> next = l2;
        }
        result = head -> next;
        for(l1 = head; l1 != NULL; l1 = l1 ->next -> next){
            if(l1 -> random != NULL)
                l1 ->next -> random = l1 -> random -> next;
        }
        for(l1 = head; l1 != NULL; l1 = l1 -> next){
            l2 = l1 -> next;
            l1 -> next = l2 -> next;
            if(l2 -> next != NULL)
                l2 -> next = l2 -> next ->next;
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
