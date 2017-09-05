//
//  main.cpp
//  leetcode565
//
//  Created by 萧天牧 on 17/8/30.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;
void getnum(vector<int>& nums, int nowpos, vector<int> now,map<int, int>& mp){
    
    int nextpos = nums[nowpos];
    if(nextpos < 0){
        int tmp =mp[nowpos];
        for(auto c : now){
            mp[c] = now.size() + tmp;
        }
    }
    else{
        nums[nowpos] = -nums[nowpos];
        now.push_back(nowpos);
        getnum(nums, nextpos, now, mp);
    }
}
int arrayNesting(vector<int>& nums) {
    map<int, int> mp;
    for(int i = 0; i < nums.size(); i++)
        nums[i] += 1;
    for(int i = 0; i < nums.size();i++){
        if(mp.count(i) == 0){
            vector<int> tmp;
            getnum(nums, i,tmp, mp);
        }
    }
    map<int,int>::iterator it = mp.begin();
    int maxnum = 0;
    while(it != mp.end()){
        maxnum = max(maxnum, it->second);
        it++;
    }
    return maxnum;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a ={0,1,2};
    cout <<arrayNesting(a) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
