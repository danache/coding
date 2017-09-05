//
//  main.cpp
//  leetcode477
//
//  Created by 萧天牧 on 17/8/25.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
//对于每一位来说，统计当前位1的个数，则其对总的res贡献在 count * (n - count)
int totalHammingDistance(vector<int>& nums) {
    int res = 0;
    int n = nums.size();
    for(int i = 0; i < 32; i++){
        int count = 0;
        for(auto n : nums){
            count += (n >> i) & 1;
        }
        res += count * (n - count);
    }
    return res;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
