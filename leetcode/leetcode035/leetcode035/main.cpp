//
//  main.cpp
//  leetcode035
//
//  Created by 萧天牧 on 17/3/1.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int searchInsert(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while(left <= right){
        int mid = (left + right) >> 1;
        if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left ;
}int main(int argc, const char * argv[]) {
    vector<int> a = {1};
    cout << searchInsert(a, 2);
    return 0;
}
