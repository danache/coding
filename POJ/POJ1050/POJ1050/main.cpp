//
//  main.cpp
//  POJ1050
//
//  Created by dan on 16/9/17.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <string>
#include <stdio.h>
using namespace std;
#define MAXN 1000
int a[MAXN][MAXN];
int b[MAXN];
int getMax(int n){
    int nmax = -999;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum > 0)
            sum += b[i];
        else
            sum = b[i];
        nmax = max(nmax, sum);
    }
    return nmax;
}

int dp(int n){
    int ans = 0;
    for (int i = 0; i < n; i++){
        memset(b, 0, sizeof(b));
        for (int j = i; j < n; j++){
            for(int k = 0; k < n; k++){
                b[k] += a[j][k];
            }
            ans = max(ans, getMax(n));
            
        }
        
    }
    return ans;
}
int main(int argc, const char * argv[]) {
    int n;
    while(cin >> n){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >>a[i][j];
            }
        }
        
        cout << dp(n) << endl;;
    }
}
