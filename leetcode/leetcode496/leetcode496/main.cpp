//
//  main.cpp
//  leetcode496
//
//  Created by 萧天牧 on 17/7/18.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;
vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
    vector<int> res;
    stack<int> sta;
    map<int,int>mp;
    if(findNums.size() == 0)
        return res;
    sta.push(nums[0]);
    for(int i = 1; i < nums.size(); i++){
        if(sta.empty()){
            sta.push(nums[i]);
        }
        else{
            int tmp = nums[i];
            while(!sta.empty() && sta.top() < tmp){
                mp[sta.top()] = tmp;
                sta.pop();
            }
            sta.push(tmp);
        }
    }
    while(!sta.empty()){
        mp[sta.top()] = -1;
        sta.pop();
    }
    for(int i = 0; i < findNums.size(); i++)
        res.push_back(mp[findNums[i]]);
    return res;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a = {4,2}, b = {1,2,3,4};
    nextGreaterElement(a, b);
    return 0;
}
