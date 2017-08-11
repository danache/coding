//
//  main.cpp
//  leetcode155
//
//  Created by 萧天牧 on 17/7/11.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> sta;
    stack<int> minsta;
    MinStack() {
        
    }
    
    void push(int x) {
        if (minsta.empty()){
            sta.push(x);
            minsta.push(x);
        }
        else{
            sta.push(x);
            if (x <= minsta.top())
                minsta.push(x);
        }
    }
    
    void pop() {
        int x = sta.top();
        sta.pop();
        if(x == minsta.top())
            minsta.pop();
    }
    
    int top() {
        return sta.top();
    }
    
    int getMin() {
        return minsta.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
