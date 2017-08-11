//
//  main.cpp
//  从头到尾打印链表
//
//  Created by 萧天牧 on 17/5/7.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
    val(x), next(NULL) {
    }
};
using namespace std;
vector<int> printListFromTailToHead(ListNode* head) {
    vector<int> res;
    if (head == NULL)
        return res;
    stack<int> sta;
    ListNode* p = head;
    while(p){
        sta.push(p->val);
        p = p->next;
    }
    while(!sta.empty()){
        res.push_back(sta.top());
        sta.pop();
    }
    return res;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
