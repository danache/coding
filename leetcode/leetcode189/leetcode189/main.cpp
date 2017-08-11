//
//  main.cpp
//  leetcode189
//
//  Created by 萧天牧 on 17/8/1.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
void reverseVec(vector<int>& nums, int begin, int end){
    if(begin >= nums.size() || end < 0 || end >= nums.size() || begin < 0)
        return;
    while(begin < end){
        int tmp = nums[begin];
        nums[begin] = nums[end];
        nums[end]  = tmp;
        begin++;
        end--;
    }
}
void rotate(vector<int>& nums, int k) {
    int n=nums.size();
    k=k%n;
    if(k==0)
        return ;
    
    reverseVec(nums,0,n-k-1);
    reverseVec(nums,n-k,n-1);
    reverseVec(nums,0,n-1);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a = {1,2};
    rotate(a, 0);
    
    std::cout << "Hello, World!\n";
    return 0;
}
