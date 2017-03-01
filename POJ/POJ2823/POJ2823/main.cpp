//
//  main.cpp
//  POJ2823
//
//  Created by dan on 16/10/8.
//  Copyright © 2016年 dan. All rights reserved.
//线段树方法未AC

#include <iostream>
#include <queue>
#define MAXN (1000000 + 5)
using namespace std;
struct Node{
    int miin;
    int maax;
    Node(int miin_, int maax_):miin(miin_),maax(maax_){};
    Node(){miin = MAXN;maax = -MAXN;};
};
Node sum[MAXN << 2];
int save[MAXN];
void pushUp(int i){
    
    sum[i].maax = max(sum[i * 2].maax, sum[i * 2 + 1].maax);
    sum[i].miin = min(sum[i * 2].miin, sum[i * 2 + 1].miin);
    
}
void build(int index, int l ,int r){
    if (l == r){
        sum[index].maax =sum[index].miin = save[l];
        return ;
    }
    int m = (l + r) >> 1;
    build(index * 2 , l, m);
    build(index * 2 + 1, m + 1, r);
    
    pushUp(index);
}

Node query(int begin, int end ,int l, int r, int savPos){
    if (begin <= l && r <= end){
        Node p = Node(sum[savPos].miin, sum[savPos].maax);
        return p;
    }
    
    int m = (l + r) >> 1;
    Node  pl, pr;
    if (begin <= m)
        pl = query(begin, end, l, m, savPos * 2);
    if (m < end)
        pr = query(begin, end, m + 1, r, savPos * 2 + 1);
    Node reslt = Node();
    
    reslt.maax = max(pl.maax, pr.maax);
    reslt.miin = min(pl.miin, pr.miin);
    return reslt;
    
}
int main(int argc, const char * argv[]) {
    queue<int> maaxque;
    queue<int> miinque;
    int N, K;
    scanf("%d%d", &N, &K);
    for (int i = 1; i <= N; i++)
        scanf("%d", &save[i]);
    
    build(1, 1, N);


    for (int i = 1; i <= N - K + 1; i++){
        Node p = query(i, i + K - 1, 1, N, 1);
        maaxque.push(p.maax);
        miinque.push(p.miin);
    }
    while (!miinque.empty()){
        int res = miinque.front();
        miinque.pop();
        if(!miinque.empty())
            printf("%d ", res);
        else
            printf("%d", res);
    }
    printf("\n");
    while (!maaxque.empty()){
        int res = maaxque.front();
        maaxque.pop();
        if (!maaxque.empty())
            printf("%d ", res);
        else
            printf("%d", res);
    }
     printf("\n");
  
}
