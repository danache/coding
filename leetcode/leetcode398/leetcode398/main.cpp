//
//  main.cpp
//  leetcode398
//
//  Created by 萧天牧 on 17/8/14.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <random>
using namespace std;
class Solution {
public:
    vector<int> vec;
    map<int, vector<int>> mp;
    Solution(vector<int> nums) {
        vec = nums;
        for(int  i = 0;  i< vec.size(); i++){
            int n = vec[i];
            if(mp.count(n) == 0){
                vector<int> a = {i};
                mp[n] = a;
            }
            else
                mp[n].push_back(i);
        }
            
    }
    
    int pick(int n) {
        int sz = mp[n].size();
        int rd = rand() % sz;
        int res =mp[n][rd];
        return res;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = vector<int> {1,2,3,3,3};
    Solution *solution = new Solution(nums);
    std::cout << solution->pick(3);
    std::cout << solution->pick(3);
    std::cout << solution->pick(3);
    std::cout << solution->pick(3);
    std::cout << solution->pick(3);
    std::cout << solution->pick(3);
    std::cout << solution->pick(3);
    std::cout << solution->pick(3);std::cout << solution->pick(3);
    std::cout << solution->pick(3);
    std::cout << solution->pick(3);
    std::cout << solution->pick(3);std::cout << solution->pick(3);
    std::cout << solution->pick(3);
    std::cout << solution->pick(3);
    std::cout << solution->pick(3);
    return 0;
}
