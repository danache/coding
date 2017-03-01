//
//  main.cpp
//  leetcode033
//
//  Created by 萧天牧 on 17/2/28.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while(left < right){
        int mid = (left + right) >> 1;
        if (nums[mid] > nums[right])
            left = mid + 1;
        else
            right = mid;
    }
    int rot = left;
    left = 0, right = nums.size() - 1;
    while(left <= right){
        int mid = (right + left) >> 1;
        int realMid = (mid + rot) % nums.size();
        if (nums[realMid] == target)
            return realMid;
        else if (nums[realMid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a = {1,3};
    cout << search(a,3);
    return 0;
}
