//
//  main.cpp
//  leetcode053
//
//  Created by 萧天牧 on 17/4/25.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int maxSubArray(vector<int>& nums) {
    if(nums.empty())
        return 0;
    vector<int> result;
    int now = 0;
    for(int i = 0; i < nums.size(); i++){
        if(now + nums[i] > nums[i]){
            result.push_back(now + nums[i]);
            now =now + nums[i];
        }
        else{
            result.push_back(nums[i]);
            now = nums[i];
        }
    }
    return *max_element(result.begin(), result.end());
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> tmp = {-2,1,-3,4,-1,2,1,-5,4};
    std::cout << maxSubArray(tmp);
    return 0;
}
