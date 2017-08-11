//
//  main.cpp
//  leetcode136
//
//  Created by 萧天牧 on 17/7/28.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int singleNumber(vector<int>& nums) {
    if (nums.size() == 0)
        return 0;
    int64_t nownum = 1;
    for(auto num : nums){
        nownum ^= num;
    }
    return nownum^1;
}
int main(int argc, const char * argv[]) {
    vector<int> a = {1,1,2};
    cout << singleNumber(a);
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
