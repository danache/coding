//
//  main.cpp
//  leetcode122
//
//  Created by 萧天牧 on 17/5/10.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int maxProfit(vector<int>& prices) {
    if(prices.size() == 0)
        return 0;
    int res = 0;
    int minpos = 0, maxpos = 0;
    for(int i = 1; i < prices.size(); i++){
        if(prices[i] < prices[i - 1] ){
            maxpos = i - 1;
            res += prices[maxpos] - prices[minpos];
            minpos = i;
        }
    }
    if(prices[prices.size() - 1] > prices[minpos])
        res += prices[prices.size() - 1] - prices[minpos];
    return res;
}
int main(int argc, const char * argv[]) {
    vector<int> a = {7, 6, 4, 3, 1};
    std::cout << maxProfit(a);
    return 0;
}
