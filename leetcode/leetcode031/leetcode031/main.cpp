//
//  main.cpp
//  leetcode031
//
//  Created by 萧天牧 on 17/2/28.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
void nextPermutation(vector<int>& nums) {
    int leftPos ,rightPos;
    for (leftPos = nums.size() - 2; leftPos >=0 ; leftPos--){
        if (nums[leftPos] < nums[leftPos + 1])
            break;
    }
    if (leftPos == -1){
        reverse(nums.begin(), nums.end());
        return;
    }
    int tarPos = leftPos + 1;
    int minVal = 9999;
    for (rightPos = leftPos + 1; rightPos < nums.size(); rightPos++){
        if (nums[rightPos] > nums[leftPos] && (nums[rightPos] - nums[leftPos] <= minVal)){
            minVal = nums[rightPos] - nums[leftPos];
            tarPos = rightPos;
        }
    }
    swap(nums[leftPos], nums[tarPos]);
    reverse(nums.begin() + leftPos + 1, nums.end());
    return;
        
}

void print_res(vector<int> nums){
    for (int i = 0; i < nums.size(); i++)
        cout <<nums[i]<<" ";
    cout << endl;
}
int main(int argc, const char * argv[]) {
    vector<int> nums = {1,3,2};
    nextPermutation(nums);
    print_res(nums);
    return 0;
}
