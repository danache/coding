//
//  main.cpp
//  leetcode347
//
//  Created by 萧天牧 on 17/6/29.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;
vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> res;
    map<int, int> mp;
    for(int i = 0; i < nums.size(); i++)
        mp[nums[i]]++;
    priority_queue<pair<int, int>> que;
    for(auto it = mp.begin(); it != mp.end(); it++){
        que.push(make_pair(it -> second, it -> first));
        if(que.size() > mp.size() - k){
            res.push_back(que.top().second);
            que.pop();
        }
    }
    return res;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
