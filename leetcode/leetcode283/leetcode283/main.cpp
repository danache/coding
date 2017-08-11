//
//  main.cpp
//  leetcode283
//
//  Created by 萧天牧 on 17/8/4.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
void moveZeroes(vector<int>& nums) {
    int index = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] != 0){
            nums[index] = nums[i];
            index++;
        }
    }
    for(index;index < nums.size(); index++)
        nums[index] = 0;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a = {0,1,2,0,3,4,9};
    moveZeroes(a);
    for(auto n : a)
        cout << n << " ";
    std::cout << "Hello, World!\n";
    return 0;
}
