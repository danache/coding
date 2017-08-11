//
//  main.cpp
//  leetcode152
//
//  Created by 萧天牧 on 17/5/10.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int maxProduct(vector<int>& nums) {
    if (nums.size() == 0)
        return 0;
    vector<int> maxvec(nums.size());
    vector<int> minvec(nums.size());
    maxvec[0] = minvec[0] = nums[0];
    for(int i = 1; i < nums.size(); i++){
        maxvec[i] = max(max(nums[i],int (nums[i] * maxvec[i - 1])),int( nums[i] * minvec[i - 1]));
        minvec[i] = min(min(nums[i],int (nums[i] * maxvec[i - 1])), int(nums[i] * minvec[i - 1]));
    }
    
    int maxval = INT_MIN;
    for(int i = 0; i < maxvec.size(); i++)
        maxval = max(maxval, maxvec[i]);
    return maxval;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a = {2};
    //int a = max(1,2);
    //cout << a;
    std::cout << maxProduct(a);
    return 0;
}
