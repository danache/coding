//
//  main.cpp
//  leetcode137
//
//  Created by 萧天牧 on 17/7/28.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int singleNumber(vector<int>& nums) {
    int counterOne = 0;
    int counterTwo = 0;
    
    for (int i = 0; i < nums.size(); i++){
        counterOne = (~counterTwo) & (counterOne ^ nums[i]);
        counterTwo = (~counterOne) & (counterTwo ^ nums[i]);
    }
    return counterOne;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
