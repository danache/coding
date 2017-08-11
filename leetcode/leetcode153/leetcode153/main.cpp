//
//  main.cpp
//  leetcode153
//
//  Created by 萧天牧 on 17/5/10.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int findMin(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while(left < right - 1){
        int mid = left +( (right - left) >> 1);
        if(nums[left] <= nums[mid])
            left = mid ;
        else if (nums[mid] <= nums[right])
            right = mid;
    }
    return nums[right];
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
