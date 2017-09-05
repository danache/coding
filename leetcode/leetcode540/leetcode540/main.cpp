//
//  main.cpp
//  leetcode540
//
//  Created by 萧天牧 on 17/8/29.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int singleNonDuplicate(vector<int>& nums) {
    if(nums.empty())
        return 0;
    int begin = 0, end = nums.size() - 1;
    while(begin < end){
        int mid = ((end - begin) >> 1) + begin;
        if(mid == 0){
            if (nums[mid] != nums[mid + 1])
                return 0;
            else
                begin = mid + 1;
        }
        if(mid == nums.size() - 1){
            if (nums[mid] != nums[mid - 1])
                return mid;
            else
                end = mid - 1;
        }
        else{
            if(nums[mid] != nums[mid - 1] && nums)
        }
    }
    return 0;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    return 0;
}
