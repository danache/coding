//
//  main.cpp
//  leetcode219
//
//  Created by 萧天牧 on 17/6/27.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    if(k < 0 || nums.size() == 0)
        return false;
    map<int, int> mp;
    for(int i = 0; i < nums.size(); i++){
        if(mp.count(nums[i]) == 0)
            mp[nums[i]] = i;
//int t =i - mp[nums[i]];
         else if (i - mp[nums[i]] <= k){
            
            return true;
        }
        else mp[nums[i]] = i;
    }
    return false;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a = {-1,-1};
    cout<<containsNearbyDuplicate(a, 1);
    return 0;
}
