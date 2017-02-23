//
//  main.cpp
//  mianshi161002
//
//  Created by dan on 16/10/2.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
using namespace std;
#define MAXN 1005
int query(int m){
    return 1;
}
bool ischoose[MAXN];
int value[MAXN];
bool status[MAXN][MAXN];

bool isconnected(int m, int n){
    return status[m][n];
}

int getMax(int n, int *p){
    if (n == 1){
        int tag = -1;
        int temp = 0;
        for(int i = 1; i <= MAXN; i++){
            if (!p[i] && value[i] > temp){
                tag = i;
                temp = value[i];
            }
            else if (value[i] == 0)
                break;
        }
        p[tag] = true;
        return temp;
    }
    else{
        
    }
}

int main(int argc, const char * argv[]) {
    int n, m;
    for (int i = 1; i <= n; i++){
        scanf("%d", &value[i]);
    }
    int a, b;
    memset(status, false, sizeof(status));
    memset(ischoose, false, sizeof(ischoose));
    for (int i = 1; i<= n; i++){
        scanf("%d%d", &a, &b);
        status[a][b] = status[b][a] = 1;
    }
}