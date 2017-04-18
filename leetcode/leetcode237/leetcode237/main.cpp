//
//  main.cpp
//  leetcode237
//
//  Created by 萧天牧 on 17/4/6.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode* node) {
    auto next = node->next;
    *node = *next;
    delete next;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
