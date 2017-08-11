//
//  main.cpp
//  leetcode287
//
//  Created by 萧天牧 on 17/8/4.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int findDuplicate(vector<int>& nums) {
    int middlenum = nums.size() - 1;
    int left = 0, right = middlenum ;
    while(left < right){
        
        int mid = ((left + right) >> 1);
        int numless = 0;
        int numequal = 0;
        for(auto n : nums){
            if(n <= mid)
                numless++;
            else if (n == mid)
                numequal++;
        }
        
        if(numequal > 1)
            return mid;
        if(numless > mid){
            right = mid;
        }
        else{
            left = mid + 1;
        }
            
        
    }
    return left;
}
int main(int argc, const char * argv[]) {
    vector<int> a = {1,2,1};
    findDuplicate(a);
    std::cout << "Hello, World!\n";
    return 0;
}
