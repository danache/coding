//
//  main.cpp
//  leetcode080
//
//  Created by 萧天牧 on 17/5/9.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int removeDuplicates(vector<int>& nums) {
    if(nums.empty())
        return 0;
    int count = 0;
    int i = 0, j = 0;
    for(; j < nums.size(); j++){
        if(j == 0 || nums[j] != nums[j - 1]){
            nums[i++] = nums[j];
            count = 0;
        }
        else if (nums[j] == nums[j - 1] && count == 0){
            nums[i++] = nums[j];
            count ++;
        }
    }
    return i;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    vector<int> a = {1,1,2,2,3,3,3};
    cout << removeDuplicates(a);
    return 0;
}
