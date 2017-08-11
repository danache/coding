//
//  main.cpp
//  合并丽娜表
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
ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
    if(!pHead1)
        return pHead2;
    if(!pHead2)
        return pHead1;
    ListNode* res = new ListNode(0);
    ListNode* shaob = res;
    ListNode* p1 = pHead1;
    ListNode* p2 = pHead2;
    while(p1 && p2){
        if(p1 -> val < p2 -> val){
            res -> next = p1;
            res = res -> next;
            p1 = p1 -> next;
        }
        else{
            res -> next = p2;
            res = res -> next;
            p2 = p2 -> next;
        }
    }

    res -> next = p1;
    return shaob -> next;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2);
    a -> next =new ListNode(4);
    a -> next -> next=new ListNode(5);
    b -> next =new ListNode(2);
    b -> next->next =new ListNode(3);
    ListNode *rtes = Merge(a, b);
    while(rtes){
        cout <<rtes -> val<<" ";
        rtes = rtes -> next;
    }
    std::cout << "Hello, World!\n";
    return 0;
}
