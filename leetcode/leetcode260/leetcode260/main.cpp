//
//  main.cpp
//  leetcode260
//
//  Created by 萧天牧 on 17/8/2.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
vector<int> singleNumber(vector<int>& nums) {
    vector<int> ret;
    if(nums.empty())
        return ret;
    int res = 0;
    for(auto n : nums)
        res ^= n;
    int count = 0;
    while(!(res & 1)){
        res >>= 1;
        count++;
    }

    int num1 = 0, num2 = 0;
    for(auto n : nums){
        if(n >>count & 1)
            num1 ^= n;
        else
            num2 ^= n;
    }
    ret.push_back(num1);
    ret.push_back(num2);
    return ret;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
