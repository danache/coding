//
//  main.cpp
//  leetcode442
//
//  Created by 萧天牧 on 17/8/18.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
/*
 *由于是1-n,因此把所有nums[i] - 1对应位置标记为负数，如果一个位置的num已经是负数
 *说明重复
 *
 */
vector<int> findDuplicates(vector<int>& nums) {
    vector<int> res;
    for(int i = 0; i < nums.size(); i++){
        int index = abs(nums[i]) - 1;
        if(nums[index] < 0){
            res.push_back(index+1);
        }
        nums[index] = -nums[index];
    }
    return res;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
