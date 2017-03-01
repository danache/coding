//
//  main.cpp
//  leetcode027
//
//  Created by 萧天牧 on 17/2/27.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int removeElement(vector<int>& nums, int val) {
    sort(nums.begin(), nums.end());
    vector<int>::iterator it = find(nums.begin(), nums.end(),val);
    while (it != nums.end()){
        if (*it == val)
            it = nums.erase(it);
        else break;
    }
    return nums.size();
}
int main(int argc, const char * argv[]) {
    
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
