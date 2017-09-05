//
//  main.cpp
//  leetcode421
//
//  Created by 萧天牧 on 17/8/17.
//  Copyright © 2017年 萧天牧. All rights reserved.
//
//https://segmentfault.com/a/1190000007283296
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int findMaximumXOR(vector<int>& nums) {
    int mask = 0, maxnum = 0;
    for(int i = 31; i >= 0; i--) {
        mask |= 1 << i;
        map<int, int> mp;
        for(auto n : nums){
            mp[n & mask] = 1;
        }
        int tmp = maxnum | 1 << i;
        map<int,int>::iterator it = mp.begin();
        while(it != mp.end()){
            if(mp.count(tmp ^ it -> first) >= 1){
                maxnum = tmp;
                break;
            }
                
            it++;
        }
    }
    return maxnum;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a= {3,10,5,25,2,8};
    std::cout << findMaximumXOR(a);
    return 0;
}
