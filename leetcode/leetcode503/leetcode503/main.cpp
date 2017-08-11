//
//  main.cpp
//  leetcode503
//
//  Created by 萧天牧 on 17/7/18.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;
vector<int> nextGreaterElements(vector<int>& nums) {
    vector<int> res;
    if(nums.empty())
        return res;
    
    stack<int> sta;
    map<int, int> mp;
    sta.push(nums[0]);
    for(int i = 1; i < nums.size(); i++){
        if(sta.empty())
            sta.push(nums[i]);
        else{
            int tmp = nums[i];
            while(!sta.empty() && sta.top() < tmp){
                mp[sta.top()] = tmp;
                sta.pop();
            }
            sta.push(tmp);
        }
    }
    for(
}
int  main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
