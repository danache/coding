//
//  main.cpp
//  leetcode015
//
//  Created by 萧天牧 on 17/2/25.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    if(nums.empty() || nums.size() < 3)
        return result;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size() - 2;i++){
        if(i == 0 || nums[i] != nums[i - 1]){
            int target = - nums[i];
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right){
                int tmpres = nums[left] + nums[right];
                if (tmpres == target){
                    result.push_back({nums[i], nums[left], nums[right]});
                    while(left < right && nums[left] == nums[left + 1])
                        left++;
                    while(left < right && nums[right] == nums[right - 1])
                        right--;
                    left++;
                    right--;
                }
                else if(tmpres < target)
                    left++;
                else
                    right--;
            }
        }
    }
    return result;
}
void printRes(vector<int>& nums){
    vector<vector<int>>  res = threeSum(nums);
    for (int i = 0; i < res.size(); i++){
        for (int j = 0; j < res[i].size(); j++){
            cout << res[i][j] <<" ";
        }
        cout << endl;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a = {-1,0,1,2,-1,-4};
    printRes(a);
    return 0;
}
