//
//  main.cpp
//  两个栈实现队列
//
//  Created by 萧天牧 on 17/5/7.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;
stack<int> stack1;
stack<int> stack2;
void push(int node) {
    stack1.push(node);
}

int pop() {
    if(!stack2.empty()){
        int res = stack2.top();
        stack2.pop();
        return res;
    }
    else{
        while(!stack1.empty()){
            int tmp = stack1.top();
            stack1.pop();
            stack2.push(tmp);
        }
        int tmp = stack2.top();
        stack2.pop();
        return tmp;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
