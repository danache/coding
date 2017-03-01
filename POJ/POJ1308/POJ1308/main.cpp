//
//  main.cpp
//  POJ1308
//
//  Created by dan on 16/9/25.
//  Copyright © 2016年 dan. All rights reserved.
//
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define N 100

using namespace std;

int fa[N];
int deep[N];
int n;
int x,y;
bool flag=0;
bool kright=0;
bool book[N];

void init()
{
    for(int i=1;i<N;i++)
    {
        fa[i]=i;
        deep[i]=1;
    }
    memset(book,0,sizeof(book));
}

int find(int x)
{
    if(x==fa[x]) return x;
    else return fa[x]=find(fa[x]);
}

void unit(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y) return ;
    else
    {
        if(deep[x]>deep[y]) fa[y]=x;
        else
        {
            if(deep[x]==deep[y]) deep[y]++;
            fa[x]=y;
        }
    }
}

bool same(int x,int y)
{
    return find(x)==find(y);
}

int main()
{
    int t=0;
    while(1)
    {
        kright=true;
        t++;
        init();
        while(scanf("%d%d",&x,&y)&&x!=0&&y!=0)
        {
            if(x==-1&&y==-1)
            {
                flag=1;
                break;
            }
            if(find(x)==find(y)) kright=0;
            unit(x,y);
            book[x]=book[y]=1;
        }
        if(flag==1) break;
        int sum=0;
        for(int i=1;i<N;i++)
        {
            if(fa[i]==i&&book[i]==1) sum++;
        }
        if(sum!=1&&sum!=0) kright=0;
        if(kright) printf("Case %d is a tree.\n",t);
        else printf("Case %d is not a tree.\n",t);
    }
    return 0;
}