//
//  main.cpp
//  unionset
//
//  Created by dan on 16/9/22.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
#include <random>
#define MAXN 1000
using namespace std;
/*
int father[MAXN];
int ranks[MAXN];

void init(int n ){
    for (int i = 0; i < n; i++){
        father[i] = i;
        ranks[i] = 0;
    }
}

int find(int x){
    if (father[x] == x)
        return x;
    else
        return find(father[x]);
}

void unit(int x, int y ){
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    if (ranks[x] < ranks[y]){
        father[x] = y;
    }
    else
    {
        father[y] = x;
        if (ranks[y] == ranks[x])
            ranks[x]++;
    }

    
}*/
///////////////////////////////////////////////
int father[MAXN];
int ranks[MAXN];
void inti(int num){
    for (int i = 0; i < num; i++){
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

void unite(int x, int y){
    x = find(x);
    y = find(y);
    if (x == y)
        return ;
    if (ranks[x] < ranks[y])
        ranks[x] = y;
    else
    {
        ranks[y] = ranks[x];
        if (ranks[y] == ranks[x])
            ranks[x]++;
    }
}