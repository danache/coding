//
//  main.cpp
//  公共节点
//
//  Created by 萧天牧 on 17/5/15.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
    val(x), next(NULL) {
    }
};
ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
    if(!pHead1 || !pHead2)
        return NULL;
    int l1 = 0, l2 = 0;
    ListNode* p1 = pHead1;
    ListNode* p2 = pHead2;
    while(p1){
        l1++;
        p1 = p1 -> next;
    }
    while(p2){
        l2++;
        p2 = p2 -> next;
    }
    p1 = pHead1;
    p2 = pHead2;
    if(l1 >= l2){
        for(int i = 0; i < l1 - l2; i++)
            p1 = p1 -> next;
    }
    else{
        for(int i = 0; i < l2 - l1; i++)
            p2 = p2 -> next;
    }
    while(p1 && p2){
        if(p1 == p2)
            return p1;
        else{
            p1 = p1 -> next;
            p2 = p2 -> next;
        }
    }
    return NULL;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
