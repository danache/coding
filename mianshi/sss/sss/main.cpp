//
//  main.cpp
//  sss
//
//  Created by 萧天牧 on 17/3/29.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int dp[1000][1000];
    int value[1000];
    int weight[1000];
    int n;
    cin >> n;
    for(int j = 0; j < n; j++){
        cin >> value[j];
    }
    for(int k = 0; k < n; k++){
        cin >> weight[k];
    }
    int total = 0;
    cin >> total;
    int maxReward = -1;
    for(int i = n - 1; i >= 0 ; i--){
        for(int j = 0;j <=total;j++){
            if(j < weight[i])
                dp[i][j] = dp[i+1][j];
            else{
                dp[i][j] = max(dp[i+1][j], dp[i+1][j - weight[i]] + value[i]);
                
            }
        }
    }
    cout << dp[0][total];
    return 0;
}
