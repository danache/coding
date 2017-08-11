//
//  main.cpp
//  leetcode341
//
//  Created by 萧天牧 on 17/7/12.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
#include<stack>
#include <queue>
using namespace std;
class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};
//[1,[4,[6]]], [6,[4,[1]]
class NestedIterator {
public:
    stack<NestedInteger> sta;
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(int i = nestedList.size() - 1; i >= 0; i--)
            sta.push(nestedList[i]);
    }
    
    int next() {
        NestedInteger tmp = sta.top();
        sta.pop();
        return tmp.getInteger();
    }
    
    bool hasNext() {
        while (!sta.empty()) {
            NestedInteger tmp = sta.top();
            if(tmp.isInteger())
                return true;
            sta.pop();
            for(int i = tmp.getList().size() - 1; i>=0; i--)
                sta.push(tmp.getList()[i]);
        }
    return false;
    }
    
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
