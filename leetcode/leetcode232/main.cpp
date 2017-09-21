#include <iostream>
#include <stack>
using namespace std;
class MyQueue {
public:
    stack<int> sta1;
    stack<int> sta2;
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        sta1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int x = peek();
        sta2.pop();
        return x;
    }

    /** Get the front element. */
    int peek() {
        if(sta2.empty()){
            while(!sta1.empty()) {
                sta2.push(sta1.top());
                sta1.pop();
            }
        }
        int x = sta2.top();
        return x;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return sta1.empty() && sta2.empty();
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}