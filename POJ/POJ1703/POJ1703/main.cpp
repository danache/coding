//
//  main.cpp
//  POJ1703
//
//  Created by dan on 16/9/23.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
using namespace std;
#define MAXN 100000 * 2 + 16
int father[MAXN];
int ranks[MAXN];

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
bool issame(int x, int y){
    return find(x) == find(y);
}

void unite(int x, int y){
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    if (ranks[x] < ranks[y])
        father[x] = y;
    else{
        father[y] = x;
        if (ranks[x] == ranks[y])
            ranks[x]++;
    }
}


int main(int argc, const char * argv[]) {
    //    1
    //    5 5
    //    A 1 2
    //    D 1 2
    //    A 1 2
    //    D 2 4
    //    A 1 4
    int ncase, n, m, x, y;
    char s;
    scanf("%d", &ncase);
    while(ncase--){
        scanf("%d%d", &n, &m);
        init(2 * n);
        getchar();
        for (int i = 0; i < m; i++){
            scanf("%c%d%d%*c", &s, &x, &y);
            if (s == 'D'){
                unite(x , y + n);
                unite(x + n, y);
            }
            else if (s == 'A'){
                if (issame(x, y + n))
                    printf("%s\n","In different gangs.");
                else if (issame(x, y))
                    printf("%s\n","In the same gang.");
                else
                    printf("%s\n","Not sure yet.");
            }
        }
    }
}

