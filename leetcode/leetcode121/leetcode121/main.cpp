//
//  main.cpp
//  leetcode121
//
//  Created by 萧天牧 on 17/5/10.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int maxProfit(vector<int>& prices) {
    vector<int> res;
    int nowmin = 99999;
    for(int i = 0; i < prices.size(); i++){
        if(prices[i] < nowmin){
            res.push_back(prices[i]);
            nowmin = prices[i];
        }
        else
            res.push_back(nowmin);
    }
    int maxval = -1;
    for(int i = 0; i < prices.size(); i++){
        maxval = max(prices[i] - res[i], maxval);
    }
    if(maxval == -1)
        return 0;
    else
        return maxval;
}
int main(int argc, const char * argv[]) {
    vector<int> a = {7, 6, 4, 3, 1};
    cout << maxProfit(a);
    std::cout << "Hello, World!\n";
    return 0;
}
