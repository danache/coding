//
//  main.cpp
//  leetcode046
//
//  Created by 萧天牧 on 17/3/6.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
vector<int> next_per(vector<int>& now){
    int i = now.size() - 2;
    for (;i >=0; i--){
        if (now[i] < now[i + 1])
            break;
    }
    if (i == -1){
        reverse(now.begin(), now.end());
        return now;
    }
    int minSub = 9999;
    int endPos = i + 1;
    for(int j = i + 1; j < now.size(); j++){
        if (now[j] > now[i] && (now[j] - now[i] < minSub)){
            minSub = now[j] - now[i];
            endPos = j;
        }
    }
    swap(now[i], now[endPos]);
    reverse(now.begin() + i + 1, )
    return now;
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    vector<int> now = nums;
    while(true){
        vector<int> tmp = next_per(now);
        if (tmp == nums)
            break;
        res.push_back(tmp);
        now = tmp;
    }
    return res;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
