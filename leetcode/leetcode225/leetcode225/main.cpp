//
//  main.cpp
//  leetcode225
//
//  Created by 萧天牧 on 17/7/11.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> que1;
    queue<int> que2;
    

    MyStack() {
            }
    
    /** Push element x onto stack. */
    void push(int x) {
        que1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {

        if(que1.size() == 1){
            int tmp = que1.front();
            que1.pop();
            while(!que2.empty()){
                que1.push(que2.front());
                que2.pop();
            }
            return tmp;
        }
        else{
            while(que1.size() != 1){
                que2.push(que1.front());
                que1.pop();
            }
            int tmp = que1.front();
            que1.pop();
            while(!que2.empty()){
                que1.push(que2.front());
                que2.pop();
            }
            return tmp;
        }
        
    }
    
    /** Get the top element. */
    int top() {
        if(empty())
            return 0;
        if(que1.size() == 1)
            return que1.front();
        else{
            while(que1.size() != 1){
                que2.push(que1.front());
                que1.pop();
            }
            int tmp = que1.front();
            return tmp;
        }
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return que1.empty() && que2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
int main(int argc, const char * argv[]) {
    MyStack *obj = new MyStack();
    obj->push(1);
    obj->push(2);
    int param_3 = obj->top();
    obj->push(3);
    in param_4 = obj->top();
    std::cout << param_3;
    std::cout << param_4;
    
    return 0;
}
