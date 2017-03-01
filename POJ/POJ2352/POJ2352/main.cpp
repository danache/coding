//
//  main.cpp
//  POJ2352
//
//  Created by dan on 16/10/19.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#define MAXN 32005

int c[MAXN];
int cnt[MAXN];

int lowBit(int k){
    return k & (-k);
}
int sum(int i){
    int res = 0;
    while(i > 0){
        res += c[i];
        i -= lowBit(i);
    }
    return res;
}
void add(int i, int addNum){
    while(i < MAXN){
        c[i] += addNum;
        i += lowBit(i);
    }
}
int main(int argc, const char * argv[]) {
    int N, x, y;
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        scanf("%d%d", &x, &y);
        int temp = x + 1;
        int re = sum(temp);
        printf("%d\n", sum(temp));
        cnt[re]++;
        add(temp, 1);
    }
    for (int i = 0; i <N; i++)
        printf("%d\n", cnt[i]);
}
