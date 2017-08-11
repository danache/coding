//
//  main.cpp
//  删除重复节点
//
//  Created by 萧天牧 on 17/5/11.
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
ListNode* deleteDuplication(ListNode* pHead)
{
    if(!pHead)
        return pHead;
    ListNode* shaobing = new ListNode(0);
    shaobing -> next = pHead;
    ListNode * pnext = shaobing;
    ListNode* pcur = pHead;
    while(pcur){
        ListNode* ptmp = pcur -> next;
        bool issame = false;
        while(ptmp && ptmp -> val == pcur -> val ){
            ptmp = ptmp -> next;
            issame = true;
        }
        if(!issame){
            pnext -> next = pcur;
            pnext = pnext -> next;
        }
        if(!ptmp)
            pnext -> next = NULL;
        pcur = ptmp;
    }
    return shaobing -> next;
}
int main(int argc, const char * argv[]) {
    ListNode *a1 = new ListNode(1);
    ListNode *a2 = new ListNode(2);
    ListNode *a3 = new ListNode(2);
    ListNode *a4 = new ListNode(3);
    ListNode *a5 = new ListNode(4);
    ListNode *a6 = new ListNode(5);
    ListNode *a7 = new ListNode(5);
    ListNode *a8 = new ListNode(5);
    a1 -> next = a2;
    a2 -> next = a3;
    a3 -> next = a4;
    a4 -> next = a5;
    a5 -> next = a6;
    a6 -> next = a7;
    a7 -> next = a8;
    ListNode* ph = deleteDuplication(a1);
    while(ph){
        cout << ph -> val <<" ";
        ph = ph -> next;
    }
    
    std::cout << "Hello, World!\n";
    return 0;
}
