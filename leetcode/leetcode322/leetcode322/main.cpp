//
//  main.cpp
//  leetcode322
//
//  Created by 萧天牧 on 17/8/9.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
bool getmin(vector<int>& coins, int leftValue, int nowpick, int& minpick){
    if(leftValue == 0){
        minpick = min(minpick, nowpick);
        return true;
    }
    for(int i = coins.size() - 1; i >= 0; i--){
        if (coins[i] > leftValue)
            continue;
        if(getmin(coins, leftValue - coins[i], nowpick + 1, minpick))
            return true;
    }
    return false;
}
int coinChange(vector<int>& coins, int amount) {
    int nowpick = 0, minpick = INT_MAX;
    sort(coins.begin(), coins.end());
    if (getmin(coins, amount, nowpick, minpick))
        return minpick;
    return -1;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a = {186,419,83,408};
    cout << coinChange(a, 6249) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
