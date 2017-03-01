//
//  main.cpp
//  POJ2492
//
//  Created by dan on 16/9/25.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
#define MAXN 1000005
int father[MAXN];
int ranks[MAXN];
using namespace std;
void init(int n){
    for (int i = 1; i <= n; i++){
        father[i] = i;
        ranks[i] = 0;
    }
}

int find(int n){
    if (n == father[n])
        return n;
    else
        return father[n] = find(father[n]);
}

void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y)
        return;
    if (ranks[x] < ranks[y])
        father[x] = y;
    else{
        father[y] = x;
        if (ranks[x] == ranks[y])
            ranks[x]++;
    }
}

bool issame(int x, int y){
    return find(x) == find(y);
}


int main(int argc, const char * argv[]) {
    int ncase, n , m, a, b;
    scanf("%d", &ncase);
    for (int i = 0; i < ncase; i++){
        bool flag = false;
        scanf("%d%d", &n, &m);
        init(n * 2);
        for (int j = 0; j < m; j++){
            scanf("%d%d", &a, &b);
            if (issame(a, b) || issame(a+n, b+n))
                flag = true;
            if(!flag){
                unite(a, b + n);
                unite(a + n, b);
            }
            
        }
        if(!flag)
        {
            printf("Scenario #%d:\nNo suspicious bugs found!\n\n", i + 1);
        }
        else
        {
            printf("Scenario #%d:\nSuspicious bugs found!\n\n", i + 1);
        }
    }
}
