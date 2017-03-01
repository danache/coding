//
//  main.cpp
//  POJ1611
//
//  Created by dan on 16/9/23.
//  Copyright © 2016年 dan. All rights reserved.
//
/*
 100 4
 2 1 2
 5 10 13 11 12 14
 2 0 1
 2 99 2
 200 2
 1 5
 5 1 2 3 4 5
 1 0
 0 0
 */

#include <iostream>
#define MAXN 30005
using namespace std;
int father[MAXN];
int ranks[MAXN];
int input[501];
void init(int n ){
    for (int i = 0; i< n; i++){
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
    if (x == y)
        return ;
    else{
        if (ranks[x] < ranks[y])
            father[x] = y;
        else {
            father[y] = x;
            if(ranks[x] == ranks[y])
                ranks[x]++;
        }
    }
}
bool issame(int x, int y){
    return find(x) == find(y);
}
int getRes(int n){
    int ans = 0;
    int find0 = find(0);
    for(int i = 0; i < n; i++){
        if (find(i) == find0)
            ans++;
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int N, M, num, a;
    while(true){
        scanf("%d%d", &N, &M);
        if (N == 0 && M == 0)
            break;
        init(N);
        for (int i = 0; i < M; i++){
            scanf("%d", &num);
            int tmp = 0;
            for(int j = 0; j < num; j++){
                scanf("%d", &a);
                if(j == 0){
                    tmp = a;
                }
                else{
                    unite(tmp, a);
                }
            }
        }
        cout << getRes(N) << endl;
        
    }
    
}
