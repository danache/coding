//
//  main.cpp
//  POJ1182
//
//  Created by dan on 16/9/22.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
#define MAXN 150001
using namespace std;
int father[MAXN];
int ranks[MAXN];
int conclusion[MAXN];
int X[MAXN];
int Y[MAXN];
int K, N;
void init(int n){
    for (int i = 0; i < n; i++){
        father[i] = i;
        ranks[i] = 0;
    }
}
int find (int a){
    while (a != father[a])
        a = father[a];
    return a;
}

bool same(int x, int y){
    return find(x) == find(y);
}
void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y){
        return;
    }
    if (ranks[x] > ranks[y]){
        father[y] = x;
        if(ranks[x] == ranks[y])
            ranks[x]++;
    }
    else
    {
        father[x] = y;
        
    }
}

int solve(){
    int ans = 0;
    init(3 * N);
    for (int i = 0; i < K; i++){
        int t = conclusion[i];
        int x = X[i] - 1;
        int y = Y[i] - 1;
        if( x < 0 || N <= x || y < 0 || N <= y ){
            ans++;
            continue;
        }
        if(t == 1){
            if(same(x, y + 2 * N) || same(x, y + N))
            {
                ans++;
            }
            else{
                unite(x, y);
                unite(x + N, y + N);
                unite(x + 2 * N, y + 2 * N);
            }
        }
        else if (t == 2){
            if (same(x, y) || same(x, y + 2 * N))
                ans++;
            else
            {
                unite(x, y + N);
                unite(x + N, y + 2 * N);
                unite(x + 2 * N, y);
            }
        }
    }
    return ans;
}
int main(int argc, const char * argv[]) {

    scanf("%d%d", &N, &K);
    for(int i = 0; i < K; i++){
        scanf("%d%d%d", &conclusion[i], &X[i], &Y[i]);
    }
    printf("%d\n", solve());
}
