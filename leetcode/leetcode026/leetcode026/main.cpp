//
//  main.cpp
//  leetcode026
//
//  Created by 萧天牧 on 17/2/27.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int removeDuplicates(vector<int>& nums) {
    int result = 0;
    int i = 0;
    for(;i < nums.size();i++){
        if(i == 0 ||nums[i] != nums[i - 1]){
            nums[result++] = nums[i];
        }
    }
    return result;
}
int main(int argc, const char * argv[]) {
    vector<int> a = {1,1,2,3,4,4,5,6,7};
    std::cout << removeDuplicates(a);
    return 0;
}
