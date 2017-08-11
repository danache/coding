//
//  main.cpp
//  leetcode055
//
//  Created by 萧天牧 on 17/4/27.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

bool canJump(vector<int>& nums) {
    int i = 0, maxreach = 0;
    int n = nums.size();
    for(i = 0; i < n && i <= maxreach; i++)
        maxreach = max(maxreach, nums[i] + i);
    return i == n;
}
int main(int argc, const char * argv[]) {
    vector<int> a={3,2,1,0,4};
    cout << canJump(a)<<endl;
}

