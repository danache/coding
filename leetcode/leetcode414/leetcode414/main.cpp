//
//  main.cpp
//  leetcode414
//
//  Created by 萧天牧 on 17/8/16.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
int thirdMax(vector<int>& nums) {
    
    priority_queue<int> a;
    map<int,int> mp;
    for(auto n : nums){
        if (mp.count(n) == 0){
            a.push(n);
            mp[n] = 1;
        }
    }
    if(a.size() < 3){
        int top1 = a.top();
        a.pop();
        return max(top1, a.top());
    }
    a.pop();
    a.pop();
    return a.top();
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a {1,2,2,3};
    cout << thirdMax(a)<<endl;
    std::cout << "Hello, World!\n";
    return 0;
}
