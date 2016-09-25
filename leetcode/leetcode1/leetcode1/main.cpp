//
//  main.cpp
//  leetcode1
//
//  Created by dan on 16/9/25.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
    map<int ,int> ndex;
    vector<int> res;
    for(int i = 0; i < nums.size(); i++){
        if(ndex.count(nums[i]) == 0){
            ndex.insert(pair<int, int>(nums[i], i));
        }
        
        if(ndex.count(target - nums[i]) == 1)
        {
            int n = ndex[target - nums[i]];
            if ( n < i){

                res.push_back(n );
                res.push_back(i);
                break;
            }
        }
        
    }
    return res;
}



int main(int argc, const char * argv[]) {
    vector<int> tmp;
    tmp.push_back(0);
    tmp.push_back(4);
    tmp.push_back(3);
    tmp.push_back(0);
    
    vector<int> res = twoSum(tmp, 0);
    for (int i = 0; i< res.size(); i++)
    cout << res[i] << endl;
    int n;
    cin >> n;
    
}
