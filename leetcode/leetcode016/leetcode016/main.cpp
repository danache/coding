//
//  main.cpp
//  leetcode016
//
//  Created by 萧天牧 on 17/2/26.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int threeSumClosest(vector<int>& nums, int target) {
    int minabs = 999999;
    int result = 999999;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size() - 2; i++){
        if (i == 0 || nums[i] != nums[i - 1]){
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                int tmpabs = abs(sum - target);
                if(tmpabs < minabs){
                    minabs = tmpabs;
                    result = sum;
                }
                if(tmpabs == 0)
                    return target;
                else if (sum < target){
                    while(left < right && nums[left] == nums[left + 1])
                        left++;
                    left++;
                }
                else if (sum < target){
                    while(left < right && nums[right] == nums[right - 1])
                        right--;
                    right++;
                }
                    
            }
        }
    }
    return result;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
