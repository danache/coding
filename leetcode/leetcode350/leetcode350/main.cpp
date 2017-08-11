//
//  main.cpp
//  leetcode350
//
//  Created by 萧天牧 on 17/6/29.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
#include<map>
#include<set>
using namespace std;
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    map<int, int> mp1;
    map<int, int>mp2;
    vector<int> res;
    
    if(nums1.empty() || nums2.empty())
        return res;
    for(int i = 0; i < nums1.size(); i++)
        mp1[nums1[i]]++;
    for(int i = 0; i < nums2.size(); i++)
        mp2[nums2[i]]++;
    for(auto it = mp1.begin(); it!=mp1.end(); it++){
        if(mp2.count(it->first) > 0){
            for(int i = 0; i <min(mp2[it->first], it->second);i++ )
                res.push_back(it -> first);
        }
    }
return res;
}
int main(int argc, const char * argv[]) {
    vector<int> a = {1,2,2,1};
    vector<int> b = {1,1};
    intersect(a, b);
    std::cout << "Hello, World!\n";
    return 0;
}
