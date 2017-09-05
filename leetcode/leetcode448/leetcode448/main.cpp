//
//  main.cpp
//  leetcode448
//
//  Created by 萧天牧 on 17/8/18.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
vector<int> findDisappearedNumbers(vector<int>& nums) {
    for(int i = 0; i < nums.size(); i++){
        int index = abs(nums[i]) - 1;
        if(nums[index] < 0)
            continue;
        nums[index] = -nums[index];
    }
    vector<int> res;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] > 0){
            res.push_back(i + 1);
        }
    }
    return res;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a ={4,3,2,7,8,2,3,1};
  findDisappearedNumbers(a);
    std::cout << "Hello, World!\n";
    return 0;
}
