//
//  main.cpp
//  leetcode473
//
//  Created by 萧天牧 on 17/8/23.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
bool makesquare(vector<int>& nums) {
    if( nums.size() < 4)
        return false;
    int all = 0;
    int ave = 0;
    for(auto n : nums)
        all += n;
    ave = all / 4;
    if (ave * 4 != all)
        return false;
    for(auto n : nums){
        if (n > ave)
            return false;
    }
    vector<int>::iterator it;
    for(it=nums.begin();it!=nums.end();)
    {
        if(*it  == ave)
            it=nums.erase(it);    //删除元素，返回值指向已删除元素的下一个位置
        else
            ++it;    //指向下一个位置
    }
    
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
