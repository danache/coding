//
//  main.cpp
//  线段树
//
//  Created by dan on 16/9/29.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
using namespace std;
/*
 const int MAXN = 1 << 17;
 
 int n, dat[2 * MAXN - 1];
 void init(int _n){
 n = 1;
 while(n < _n)
 n = n * 2;
 for(int i = 0; i < 2 * n - 1; i++){
 dat[i] = MAXN;
 }
 }
 
 void update(int k, int a){
 k += n - 1;
 dat[k] = a;
 while(k > 0){
 k = (k - 1) / 2;
 dat[k] = min (dat[ 2 * k + 1], dat[2 * k + 2]);
 
 }
 }
 
 int query(int a, int b, int k, int l, int r){
 if (r <= a || b <= 1) return MAXN;
 
 if (a <= 1 && r <= b)
 return dat[k];
 else{
 int vl = query(a, b, k * 2 + 1, l , (l + r) / 2);
 int vr = query(a, b, k * 2 + 1, (l + r) / 2, r);
 return min(vl, vr);
 }
 }*/

const int maxn = 256;
int segTree[4 * maxn + 1];
int arr[maxn];

void built(int index, int l, int r){
    if (l == r)
        segTree[index] = arr[l];
    else{
        
        built(2 * index, l, (l + r) / 2);
        built(2 * index + 1, (l + r) / 2 + 1, r);
        segTree[index] = min(segTree[2 * index], segTree[2 * index + 1]);
    }
}
int query(int node, int begin, int end, int left, int right){
    //begin end 为存储区间
    if (left >= end || right < begin)
        return -1;
    
    else if (left >= begin && right <= end)
        return segTree[node];
    else{
        int p1 = query(2 * node, begin, (begin + end) / 2, left, right);
        int p2 = query(2 * node + 1, (begin + end) / 2 + 1, end, left, right);
        if (p1 == -1)
            return p2;
        else if (p2 == -1)
            return p1;
        else return min(p1, p2);
    }
}
int main(int argc, const char * argv[]) {
    arr[0] = 1, arr[1] = 2,arr[2] = 2, arr[3] = 4, arr[4] = 1, arr[5] = 3;
    built(1, 0, 5);
    for(int i = 1; i<=20; ++i)
        cout<< "seg"<< i << "=" <<segTree[i] <<endl;
    return 0;
}
