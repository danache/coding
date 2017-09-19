//
//  main.cpp
//  leetcode209
//
//  Created by 萧天牧 on 17/6/2.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int minSubArrayLen(int s, vector<int>& nums) {
    int begin = 0, end = 0;
    int minnum = INT32_MAX;
    int sum = 0;
    while(begin < nums.size() && end < nums.size()){
        while(sum < s && end < nums.size()){
            sum += nums[end++];
        }
        while(sum >= s && begin <= end){
            minnum = min(minnum, end - begin);
            sum -= nums[begin++];
        }
    }
    return minnum == INT32_MAX ? 0 : minnum;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {1,4,4};
    minSubArrayLen(4,nums);
    std::cout << "Hello, World!\n";
    return 0;
}
