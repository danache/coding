//
//  main.cpp
//  HDU1166
//
//  Created by dan on 16/9/29.
//  Copyright © 2016年 dan. All rights reserved.
//
/*
#include <iostream>
#define M 50005
using namespace std;
int sav[M];
int sum[M<<2];

inline void pushUp(int i){
    sum[i] = sum[i * 2] + sum[i * 2 + 1];
}

void build(int index, int l, int r){
    if (l == r){
        sum[index] = sav[l];
        return;
    }
    build(index * 2, l, (l + r) / 2);
    build(index * 2 + 1, (l + r) / 2 + 1, r);
    pushUp(index);
}
void update(int index, int addnum, int l, int r, int savindex){
    if (l == r){
        sum[savindex] += addnum;
        return;
    }
    else{
        int m = (r + l) / 2;
        if (index <= m){
            update(index, addnum, l, m, savindex * 2);
        }
        else
        {
            update(index, addnum, m + 1, r, savindex * 2 + 1);
        }
        pushUp(savindex);
    }
    
}

int query(int begin, int end, int l, int r, int index){
    if (l > end || r < begin)
        return -1;
    else if (l >= begin && r <= end){
        return sum[index];
    }
    else{
        int m = (r + l) / 2;
        int ans=0;
        if(begin <= m )
            ans += query(begin,end,l, m, index * 2);
        if(end > m)
            ans += query(begin,end,m + 1, r, index * 2 + 1);
        
        return ans;
    }
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
            scanf("%d",&sav[i]);
        }
        build(1,1,n);
        
        char op[10];
        
        while( scanf("%s",op) &&op[0]!='E' )
        {
            
            scanf("%d %d", &a, &b);
            if(op[0] == 'Q')
                printf("%d\n",query(a,b,1,n,1));
            else if(op[0] == 'S')
                update(a,-b,1,n,1);
            else
                update(a,b,1,n,1);
            
        }
    }  
    return 0;  
}
*/