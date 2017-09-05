//
//  main.cpp
//  leetcode645
//
//  Created by 萧天牧 on 17/8/25.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
vector<int> findErrorNums(vector<int>& nums) {
    vector<int> res;
    for(int i = 0; i < nums.size(); i++){
        int pos = abs(nums[i] - 1）;
        if(nums[pos] < 0)
            res.push_back(pos + 1);
        else
            nums[pos] = -nums[pos];
    }
    for(int i = 0; i < nums.size();i++){
        if (nums[i] > 0){
            res.push_back(i + 1);
            break;
        }
    }
    return res;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {2,2};
    vector<int> res = findErrorNums(nums);
    for (auto n : res)
        cout << n <<" ";
    std::cout << "Hello, World!\n";
    return 0;
}
