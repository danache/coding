//
//  main.cpp
//  包含min的栈
//
//  Created by 萧天牧 on 17/5/15.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
#include<stack>
using namespace std;
stack<int> sta;
stack<int> fz;
int min() {
    return fz.top();
}
void push(int value) {
    sta.push(value);
    if(fz.empty())
        fz.push(value);
    else{
        int tmp = fz.top();
        if(value <= tmp)
            fz.push(value);
    }
}
void pop() {
    int tmp = sta.top();
    sta.pop();
    int tmp2 = fz.top();
    if(tmp == tmp2)
        fz.pop();
}
int top() {
    return sta.top();
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
