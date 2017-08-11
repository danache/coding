//
//  main.cpp
//  leetcode169
//
//  Created by 萧天牧 on 17/6/2.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int majorityElement(vector<int>& nums) {
    int count = 1;
    int nownum = nums[0];
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] != nownum){
            count --;
            if(count == 0){
                nownum = nums[i];
                count = 1;
            }
        }
        else
            count++;
    }
    return nownum;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
