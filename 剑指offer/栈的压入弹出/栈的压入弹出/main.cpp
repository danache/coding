//
//  main.cpp
//  栈的压入弹出
//
//  Created by 萧天牧 on 17/5/15.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
bool IsPopOrder(vector<int> pushV,vector<int> popV) {
    if(pushV.size() != popV.size())
        return false;
    stack<int> tmp;
    int i = 0, j = 0;
    while(j < popV.size()){
        int a = popV[j];
                    j++;
        if(!tmp.empty() && tmp.top() == a){
            tmp.pop();

        }
        else{
            while(i < pushV.size() && pushV[i] != a){
                tmp.push(pushV[i]);
                i++;
            }
            if(i == pushV.size())
                return false;
            else
                i++;
        }
    }
    return true;
}
int main(int argc, const char * argv[]) {
    vector<int> a = {4,3,5,1,2};
    vector<int> b = {1,2,3,4,5};
    
    std::cout << IsPopOrder(b,a);
    return 0;
}
