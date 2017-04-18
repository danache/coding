//
//  main.cpp
//  leetcode096
//
//  Created by 萧天牧 on 17/4/18.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
using namespace std;

void initCatalan(){

    
}
int numTrees(int n) {
    int dp[100000];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= 1000; i++){
        int sum = 0;
        for(int j = 0; j < (i); j++){
            sum += dp[j] * dp[i - 1 - j];
        }
        dp[i] = sum;
    }
    return dp[n];
}
int main(int argc, const char * argv[]) {
    initCatalan();
    // insert code here...
    for(int i = 1; i < 5; i++)
        cout << numTrees(i)<<endl;;
    return 0;
}
