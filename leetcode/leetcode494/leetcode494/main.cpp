//
//  main.cpp
//  leetcode494
//
//  Created by 萧天牧 on 17/8/29.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int findTargetSumWays(vector<int>& nums, int S) {

    vector<map<int,int>>vec;
    for(int i = 0; i < nums.size(); i++){
        if(i == 0){
            map<int,int> mp;
            mp[nums[0]] += 1;
            mp[-nums[0]] += 1;
            vec.push_back(mp);
        }
        else{
            map<int,int> mp;
            map<int,int>::iterator it = vec[i - 1].begin();
            while(it != vec[i-1].end()){
                mp[it ->first + nums[i]] += it ->second;
                mp[it ->first - nums[i]] += it ->second;
                
                it++;
            }
            vec.push_back(mp);
        }
        
    }
    return vec[vec.size() - 1][S];
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a = {0,0,0,0,0,0,0,0,1};
    cout << findTargetSumWays(a, 1)<<endl;
    std::cout << "Hello, World!\n";
    return 0;
}
