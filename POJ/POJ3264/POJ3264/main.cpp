//
//  main.cpp
//  POJ3264
//
//  Created by dan on 16/10/1.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
#define MAXN 200000
using namespace std;

struct node{
    long long maax;
    long long miin;
    node(){
        maax = 0;
        miin = 0;
    }
};

node sum[MAXN << 2];
long long res[MAXN << 2];
void pushUp(int index){
    sum[index].maax = max(sum[index * 2].maax, sum[index * 2 + 1].maax);
    sum[index].miin = min(sum[index * 2].miin, sum[index * 2 + 1].miin);
    
}

void build(int index, int l, int r){
    if (l == r){
        sum[index].miin = sum[index].maax = res[l];
        return;
    }
    int m = (l + r) >> 1;
    build(index * 2, l, m);
    build(index * 2 + 1, m + 1, r);
    pushUp(index);
}

node query(int begin, int end, int l, int r, int index){
    if (l >= begin && r <= end){
        return sum[index];
    }
    int m = (l + r) >> 1;
    node tmp1, tmp2;
    node res;
    if (m >= begin)
        tmp1 = query(begin, end, l, m, index << 1);
    if ( m < end)
        tmp2 = query(begin, end, m + 1, r, index << 1 | 1);
    if (tmp1.maax == 0 && tmp1.miin == 0 && tmp2.maax != 0 && tmp2.miin != 0)
        res = tmp2;
    else if(tmp2.maax == 0 && tmp2.miin == 0 && tmp1.maax != 0 && tmp1.miin != 0)
        res = tmp1;
    else {
        res.maax = max(tmp1.maax, tmp2.maax);
        res.miin = min(tmp1.miin, tmp2.miin);
    }
    return res;
    
    
}
int main(int argc, const char * argv[]) {
    int N, Q;
    scanf("%d%d", &N, &Q);
    for (int i = 1; i <= N; i++){
        scanf("%lld", &res[i]);
    }
    build(1, 1, N);
    
    while(Q--){
        int a, b;
        scanf("%d%d", &a, &b);
        node tmp = query(a,b, 1, N, 1);
        printf("%lld\n", tmp.maax - tmp.miin);
    }
}
