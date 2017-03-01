//
//  main.cpp
//  POJ2777
//
//  Created by dan on 16/10/9.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
#include <set>
#define MAXN 100005
using namespace std;

struct Node{
    int flag;
    int color;
};
Node sum[MAXN << 2];

void pushUp(int i){
    sum[i].color = sum[i << 1].color | sum[i << 1 | 1].color;
}

void build(int i, int l, int r){
    sum[i].color = sum[i].flag = 0;
    if (l == r){
        sum[i].color = 1;
        return;
    }
    int m = ( r + l ) / 2;
    build(i << 1, l, m);
    build(i << 1 | 1,m + 1, r);
    pushUp(i);
}

void pushDown(int i){
    if (sum[i].flag){
        sum[i << 1].flag = sum[ i << 1 | 1].flag = sum[i].flag;
        sum[i << 1].color= sum[ i << 1 | 1].color = sum[i].flag;
        sum[i].flag = 0;
    }
}

void update(int begin, int end,int colorNum, int l, int r, int savPos){
    if (l > end || r < begin)
        return;
    if (begin <= l && r <= end){
        sum[savPos].color = sum[savPos].flag = 1 << (colorNum - 1);
        return;
    }
    pushDown(savPos);
    int m = (r + l) >> 1;
    if (begin <= m)
        update(begin, end, colorNum, l, m, savPos << 1);
    if (m < end)
        update(begin, end, colorNum, m + 1, r, savPos << 1 | 1);
    pushUp(savPos);
    return;
}

int query(int begin, int end, int l, int r, int savPos){
    if (end < l || r < begin)
        return 0;
    if (begin <= l && r <= end){
        return sum[savPos].color;
    }
    pushDown(savPos);
    int m = (r + l) >> 1;
    return query(begin, end, l, m, savPos << 1) | query(begin, end , m + 1, r, savPos << 1 | 1);
}
int ans(int x)
{
    int aa = 0 ;
    while(x)
    {
        if(x & 1)
            aa++ ;
        x >>= 1 ;
    }
    return aa ;
}

int main(int argc, const char * argv[]) {
    int L, T, O;
    scanf("%d%d%d", &L, &T, &O);
    int l, r, x;
    build(1, 1, L);
    char str[10];
    while(O--){
        scanf("%s", str);
        if(str[0] == 'C')
        {
            scanf("%d %d %d", &l, &r, &x);
            if(l > r)
                swap(l,r);
            update(l, r, x, 1, L,1);
        }
        else
        {
            scanf("%d %d", &l, &r);
            if(l > r)
                swap(l,r);
            printf("%d\n",ans( query(l, r, 1, L, 1) ) );
        }
    }
}
