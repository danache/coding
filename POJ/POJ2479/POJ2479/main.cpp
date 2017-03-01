//
//  main.cpp
//  POJ2479
//
//  Created by dan on 16/9/12.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;
const int MAXN = 50001;
int a[MAXN];
int la[MAXN];
int ra[MAXN];
int lmax[MAXN];
int rmax[MAXN];

int getMax(int left, int right, int *p){
    int res = -1;
    for (int i = left; i <= right; i++){
        res = max(res, p[i]);
    }
    return res;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int count;
    scanf("%d", &count);
    int n;
    while(count--){
        
        scanf("%d", &n);
        if(n < 2)
            break;
        int smax = -999999;
        for (int i = 0; i < n; i++){
            scanf("%d", &a[i]);
            if( i == 0){
                lmax[0] = la[0] = a[0];
                smax = max(0, a[0]);
            }
            else{
                if (la[i - 1] < 0){
                    la[i] = a[i];
                }
                else
                {
                    la[i] = la[i - 1] + a[i];
                }
                if(la[i] > smax){
                    smax = la[i];
                }
                smax = max(0, smax);
                lmax[i] = smax;
            }
        }
        smax = -999999;
        rmax[n - 1] = ra[n - 1] = a[n - 1];
        smax = max(rmax[n -1], smax);
        for (int j = n - 2; j >= 0; j--){
            if(ra[j + 1] < 0)
                ra[j] = a[j];
            else
                ra[j] = ra[j + 1] + a[j];
            if(ra[j] > smax){
                smax = ra[j];
            }
            smax = max(0, smax);
            rmax[j] = smax;
        }
        int res = -1;
        if (n == 2)
            res = a[0] + a[1];
        else{
            for (int i = 0; i < n - 1; i++){
                res = max(lmax[i] + rmax[i + 1], res);
            }
        }
        printf("%d\n", res);
    }
    
}
