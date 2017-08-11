//
//  main.cpp
//  leetcode377
//
//  Created by 萧天牧 on 17/8/11.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
void get(vector<int> nums , int &res, int lefttarget){
    if (lefttarget == 0){
        res++;
        return;
    }
    for(auto n : nums){
        if(n <= lefttarget){
            get(nums, res, lefttarget - n);
        }
        else
            break;
    }
}
int combinationSum4(vector<int>& nums, int target) {
    int res = 0;
    sort(nums.begin(), nums.end());
    get(nums, res, target);
    cout << res;
    return res;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a = {1,2,3};
    cout << combinationSum4(a, 4);
    std::cout << "Hello, World!\n";
    return 0;
}
