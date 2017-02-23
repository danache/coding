//
//  main.cpp
//  POJ2528
//
//  Created by dan on 16/10/3.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
#include <algorithm>

#define MAXN 20000
using namespace std;

bool hashtable[MAXN];
int li[MAXN] , ri[MAXN];
int X[MAXN*3];  /*最多3倍~*/
int color[MAXN<<4];  /*2X的空间复杂度是普通的四倍*/
int cnt;

void pushDown(int i){
    if (color[i] != -1){
        color[i << 1] = color [i << 1 | 1] = color[i];
        color[i] = -1;
    }//令非叶结点的color为-1，每次向下更新时将父节点的信息更新到子节点中。在查找的过程中只要当前节点有颜色，说明起和其子节点的颜色都为color[savPos].
}

void update(int begin, int end, int colo, int l, int r, int savPos){
    if ( begin <= l && r <= end){
        color[savPos] = colo;
        return;
    }//找到当前区间直接更新，否则分段递归更新
    pushDown(savPos);
    int m = (r + l) >> 1;
    if (begin <= m)
        update(begin, end, colo, l, m, savPos << 1);
    if (m < end)
        update(begin, end, colo, m + 1, r, (savPos << 1 | 1));
}

void query(int l, int r, int savPos){
    if (color[savPos] != -1){//如果当前节点有颜色且没有出现过，则结果+1，同时对该颜色进行表姐
        if (!hashtable[color[savPos]]){
            cnt++;
        }
        hashtable[color[savPos]] = true;
        return;
    }//如果当前节点有颜色那么其子节点和他的颜色一致
    if (l == r)//空的叶结点
        return;
    int m = (r + l) >> 1;
    query(l, m, savPos << 1);
    query(m + 1, r, savPos << 1 | 1);
}

int binHash(int key, int n, int *X){
    int l = 0, r = n - 1;
    while(l <= r){
        int m = (l + r) >> 1;
        if (X[m] == key)
            return m;
        else if (X[m] < key)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

int main(){
    int caseNum, n;
    scanf("%d", &caseNum);
    while(caseNum--){
        scanf("%d", &n);
        int nn = 0;
        for (int i = 0; i < n; i++){
            scanf("%d%d", &li[i], &ri[i]);
            X[nn++] = li[i];
            X[nn++] = ri[i];
        }
        sort(X,X + nn);//将所有的左右区间进行hash化

        int m = 1;
        for (int i = 1; i < nn; i++){
            if (X[i] != X[i - 1])
                X[m++] = X[i];
        }//技巧，去重，数据结构C++版中讲过
        for (int i = m - 1; i > 0; i--){
            if (X[i] != X[i - 1] + 1)
                X[m++] = X[i - 1] + 1;
        }//技巧，离散hash，防止边界重复的情况出现。
        sort(X, X + m);
        memset(color, -1, sizeof(color));
        for (int i = 0; i < n; i++){
            int l = binHash(li[i], m, X);
            int r = binHash(ri[i], m, X);
            update(l, r, i, 0, m, 1);

        }
        cnt = 0;
        memset(hashtable, false, sizeof(hashtable));
        query(0, m, 1);
        printf("%d\n", cnt);
    }
}