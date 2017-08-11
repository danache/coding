//
//  main.cpp
//  leetcode162
//
//  Created by 萧天牧 on 17/6/2.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int findPeakElement(vector<int>& nums) {
    if(nums.size() == 0)
        return 0;
    int index = 1;
    bool down = true;
    for(;index < nums.size(); index++){
        if(nums[index] < nums[index - 1]){
            if(down)
                continue;
            else
                break;
        }
        else{
            down = false;
        }
    }
    if(down)
        return 0;
    else
        return index - 1;
        
}
int main(int argc, const char * argv[]) {
    vector<int> a = {1,2,3,4};
    cout << findPeakElement(a)<<endl;
    std::cout << "Hello, World!\n";
    return 0;
}
