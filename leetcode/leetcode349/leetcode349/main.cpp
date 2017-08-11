//
//  main.cpp
//  leetcode349
//
//  Created by 萧天牧 on 17/6/29.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    map<int, int> mp;
    vector<int> res;
    set<int> st;
    if(nums1.empty() || nums2.empty())
        return res;
    for(int i = 0; i < nums1.size(); i++)
        mp[nums1[i]]++;
    for(int i = 0; i < nums2.size(); i++){
        if(mp.count(nums2[i]) > 0){
            st.insert(nums2[i]);
        }
    }
    for(auto it = st.begin(); it != st.end();it++)
        res.push_back(*it);
    return res;
}
int main(int argc, const char * argv[]) {
    vector<int> a = {1,2,2,1};
    vector<int> b = {2,2};
    vector<int> c = intersection(a, b);
    for(int i = 0; i< c.size(); i++)
        cout << c[i]<<endl;
    return 0;
}
