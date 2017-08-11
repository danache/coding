//
//  main.cpp
//  leetcode268
//
//  Created by 萧天牧 on 17/7/4.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
//int missingNumber(vector<int>& nums) {
//    sort(nums.begin(), nums.end());
//    int left = 0, right = nums.size() ;
//    while(left < right){
//        int mid = left + ((right - left) >> 1);
//        if(mid  < nums[mid])
//            right = mid;
//        else (left = mid + 1);
//    }
//    return left ;
//}
int missingNumber(vector<int>& nums) {
    int xosr = 0, i = 0;
    for(; i < nums.size() ;i ++)
        xosr = xosr ^ i ^ nums[i];
    return (xosr ^ i) ;
}
int main(int argc, const char * argv[]) {
    vector<int> a = {0,2};
    std::cout << missingNumber(a);
    return 0;
}
