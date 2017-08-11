//
//  main.cpp
//  leetcode238
//
//  Created by 萧天牧 on 17/8/2.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> res;
    if(nums.empty())
        return res;
    int nowval = 1;
    for(int i = 0; i < nums.size(); i++){

        res.push_back(nowval);
        nowval *= nums[i];
    }
    nowval = 1;
    for(int i = nums.size() - 1; i >= 0; i--){

        res[i] *= nowval;
                nowval *= nums[i];
    }
    
    return res;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> a = {1,2,3,4};
    productExceptSelf(a);
    return 0;
}
