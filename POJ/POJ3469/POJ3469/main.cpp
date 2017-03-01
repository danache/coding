//
//  main.cpp
//  POJ3469
//
//  Created by dan on 16/9/30.
//  Copyright © 2016年 dan. All rights reserved.
//
/*
#include <iostream>
using namespace std;
#define MAXN 100000 + 5
int sum[4 * MAXN];
int sav[MAXN];
void pushUp(int i){
    sum[i] = sum[2 * i] + sum[2 * i + 1];
}

void build(int index, int l, int r){
    if (r == l)
    {
        sum[index] = sav[l];
        return;
    }
    build(index * 2, l, (l + r) / 2);
    build(index * 2 + 1, (l + r) / 2 + 1, r);
    pushUp(index);
}

void update(int index, int addnum, int l, int r, int savPos){
    if (l == r){
        sum[savPos] += addnum;
        return;
    }
    int m = (r + l) / 2;
    if (index <= m)
        update(index, addnum, l, m, savPos * 2);
    else
        update(index, addnum, m + 1, r, savPos * 2 + 1);
    pushUp(savPos);
}

int query(int begin, int end, int lpos, int rpos, int index){
    if (lpos >= begin && rpos <= end)
        return sum[index];
    int m = (lpos + rpos) / 2;
    int ans = 0;
    if (m >= begin){
        ans += query(begin, end, lpos, m, index * 2);
    }
    if (m < end){
        ans += query(begin, end, m + 1, rpos,  index * 2 + 1);
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    int n, Q;
    scanf("%d%d", &n, &Q);
    for (int i = 1; i <= n; i++){
        scanf("%d", &sav[i]);
    }
    build(1, 1, n);
    for (int i = 1; i <= 4 * n; i++){
        cout << "i = " << i << " "<<sum[i] << endl;
    }
    char c;
    int a, b, addnum;
    for (int j = 0;j < Q; j++){
        cin >> c;
        if (c == 'Q'){
            cin >> a >> b;
            cout << query(1, n, a, b, 1) << endl;
        }
        else if (c == 'C'){
            cin >> a >> b >> addnum;
            for (int i = a; i <=b; i++){
                update(i, c, 1, n, 1);
            }
        }
    }
}
*/