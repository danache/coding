//
//  main.cpp
//  leetcode018
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
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *firstNode = head, *secondNode = head , *tmpNode = head;
    while(n -- & (firstNode != NULL))
        firstNode = firstNode -> next;
    while (firstNode != NULL) {
        tmpNode = secondNode;
        firstNode = firstNode -> next;
        secondNode = secondNode -> next;
    }
    if(secondNode == head)
        head = head -> next;
    else{
        tmpNode -> next = secondNode -> next;
    }
    return head;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
