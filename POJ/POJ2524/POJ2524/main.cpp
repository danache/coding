//
//  main.cpp
//  POJ2524
//
//  Created by dan on 16/9/22.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <set>
using namespace std;
#define MAXN 50010

int father[MAXN];
int ranks[MAXN];
int religous[MAXN];
int res[MAXN];
int ans;
set<int> se;
void init(int n){
    for (int i = 0; i <= n; i++){
        father[i] = i;
        ranks[i] = 0;
    }
}

int find(int x){
    if (x == father[x])
        return x;
    else
        return father[x] = find(father[x]);
}

bool same(int x, int y){
    return find(x) == find(y);
}

void unite(int x, int y){
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    ans--;
    if(ranks[x] < ranks[y]){
        father[x] = y;
    }
    else{
        father[y] = x;
        if(ranks[x] == ranks[y])
            ranks[x]++;
    }
}
void solve(int x, int y){
    unite(x, y);
}

int getDiffirentReligious(int n){
    for(int i = 1; i <= n; i++)
    {
            se.insert(father[i]);
    }
    
    return int(se.size());
}
int main(int argc, const char * argv[]) {
    int n, m, a, b;
    int casenum = 1;
    while(true){
        
        memset(religous, 0, sizeof(religous));
        memset(father, 0, sizeof(father));
        memset(ranks, 0, sizeof(ranks));
        
        scanf("%d%d", &n, &m);
        if(n == 0 && m == 0)
            break;
        init(n);
        ans = n;
        for(int i = 0; i < m; i++){
            scanf("%d%d", &a, &b);
            solve(a, b);

        }
        printf("Case %d: %d\n", casenum++ ,ans);
    }
}
