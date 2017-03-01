//
//  main.cpp
//  POJ2828
//
//  Created by dan on 16/10/19.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
#define MAXN 200005
int sum[MAXN << 2];
int ans[MAXN << 2];
int pos[MAXN], value[MAXN];

void build(int l, int r, int savPos){
    sum[savPos] = r - l + 1;
    if (l == r)
        return;
    int m = (l + r) >> 1;
    build(l, m, savPos << 1);
    build(m + 1, r, savPos << 1 | 1);
}

void pushUp(int i){
    sum[i] = sum[i << 1] + sum[i << 1 | 1];
}

void update(int kongwei, int addNum, int l, int r, int savPos){
    if(l == r){
        sum[savPos]--;
        ans[savPos] = addNum;
        return;
    }
    int m = (l + r) >> 1;
    if (kongwei <= sum[savPos << 1])
        update(kongwei, addNum, l, m, savPos << 1);
    else
        update(kongwei - sum[savPos << 1], addNum, m + 1, r, savPos << 1 | 1);
    pushUp(savPos);
}

void print(int l, int r, int savPos){
    if (l == r){
        printf("%d ", ans[savPos]);
        return;
    }
    int m = (r + l) >> 1;
    print(l, m, savPos << 1);
    print(m + 1, r, savPos << 1 | 1);
}
int main(int argc, const char * argv[]) {
    int n;
    while(~scanf("%d", &n)){
        for (int i = 0; i < n; i++)
            scanf("%d%d", &pos[i], &value[i]);
        build(1, n, 1);
        for (int i = n - 1; i >= 0; i--){
            update(pos[i] + 1, value[i], 1, n, 1);
        }
        print(1, n, 1);
        printf("\n");
    }
    return 0;
}
