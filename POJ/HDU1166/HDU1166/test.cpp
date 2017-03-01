//
//  test.cpp
//  HDU1166
//
//  Created by dan on 16/9/29.
//  Copyright © 2016年 dan. All rights reserved.
//

#include "test.hpp"
#include <cstring>
#include <iostream>
#define MAXN 50005
using namespace std;
int sav[MAXN];
int sum[MAXN * 4];

void pushUp(int i){
    sum[i] = sum[i * 2] + sum[i * 2 + 1];
}

void build(int index, int l, int r){
    if (l == r)
    {
        sum[index] = sav[l];//叶子节点
        return;
    }
    else{
        build(index * 2, l , (l + r) / 2); //递归的对他的儿子结点构造，由于是完美二叉树，孩子节点
        //为index << 1与 index <<1 | 1,相应的，令 m = (r +l) / 2;
        //对应区间为(l, m / 2), (m + 1, r);最后更新父亲节点的值，无论是最小值还是求和
        build(index * 2 + 1, (l + r) / 2 + 1, r);
        pushUp(index);
    }
    
}

void update(int bianhao, int addnum, int l, int r, int cunchu){
    if (l == r)
        sum[cunchu] += addnum;
    else{
        int m = (l + r) / 2;
        if (bianhao <= m){//这里的目的是找到bianhao对应的数组位置.
            update(bianhao, addnum, l, m, 2 * cunchu);
        }
        else
            update(bianhao, addnum, m + 1, r , 2 * cunchu + 1);
        pushUp(cunchu);
    }
}

int query(int begin, int end, int l, int r, int index){
    if (l >= begin && r <= end){
        return sum[index];
    }
    int m = (l + r) / 2;
    int ans = 0;
    if (begin <= m){
        ans += query(begin, end, l, m, index * 2);
    }
    if ( m < end ){
        ans += query(begin, end, m + 1, r, index * 2 + 1);
    }
    return ans;
}

int main()
{
    int T, n, a, b;
    scanf("%d",&T);
    for( int i = 1; i <= T; ++i )
    {
        printf("Case %d:\n",i);
        scanf("%d",&n);
        for (int i = 1; i <= n; i++){
            scanf("%d", &sav[i]);
        }
        build(1,1, n);
        
        char op[10];
        
        while( scanf("%s",op) &&op[0]!='E' )
        {
            
            scanf("%d %d", &a, &b);
            if(op[0] == 'Q')
                printf("%d\n",query(1,n,a,b,1));
            else if(op[0] == 'S')
                update(a,-b,1,n,1);
            else
                update(a,b,1,n,1);
            
        }
    }  
    return 0;
}