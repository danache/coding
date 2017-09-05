//
//  main.cpp
//  leetcode554
//
//  Created by 萧天牧 on 17/8/30.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;
int leastBricks(vector<vector<int>>& wall) {
    if(wall.empty() || wall[0].empty())
        return 0;
    map<int, int> mp;
    for (auto vec : wall){
        int sum = 0;
        for(int i = 0; i < vec.size() - 1; i++){
            sum += vec[i];
            mp[sum]++;
        }
    }
    map<int, int>::iterator it = mp.begin();
    int maxnum = 0;
    while (it != mp.end()) {
        
        maxnum = max(maxnum, it -> second);
        
        ß
        it++;
    }
    return wall.size() - maxnum;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>> a = {{1,2,2,1},{3,1,2},{1,3,2},{2,4},{3,1,2},{1,3,1,1}};
    std::cout << leastBricks(a);
    return 0;
}
