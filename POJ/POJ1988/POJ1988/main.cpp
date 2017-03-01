//
//  main.cpp
//  POJ1988
//
//  Created by dan on 16/9/27.
//  Copyright © 2016年 dan. All rights reserved.
//
//本题借鉴了其他博主的思路http://blog.csdn.net/ascii991/article/details/7536826
//本题属于并查集，与之前并查集相比，多了一些内容，如当前节点到根节点的距离以及根节点总孩子数
//此外，根据题意，(M a b)实际上是将a作为b的孩子，可以想象b为一个箱子，将a放到b上，从下往上是一棵树
//因此在unite时先找到a,b对应的祖先，再将其连接起来。
#include <iostream>
using namespace std;
#define MAXN 30001
int father[MAXN];
int dis[MAXN];
int size[MAXN];

void initSS(){
    for (int i = 1; i <= MAXN; i++){
        father[i] = i;
        dis[i] = 0;
        size[i] = 1;
    }
}

int find(int x){
    if (x == father[x])
        return x;
    int tmp = father[x];
    father[x] = find(father[x]);
    dis[x] += dis[tmp];
    //可以如此递归的想，在当前执行过程中，获取当前子节点在数组中存储的父亲节点。然后递归的对父亲节点
    //查找其祖先，找到之后统一进行更新。同时每次查找将当前节点距离其祖先的距离更新。即当前节点的相对距离
    return father[x];
}
void unite(int x, int y){
    x = find(x);
    y = find(y);
    father[x] = y;
    dis[x] += size[y];
    size[y] += size[x];
    size[x] = 0;
}

int main(){
    int i,x,y,p;
    char ch;
    initSS();
    scanf("%d\n",&p);
    for (i=1;i<=p;i++)
    {
        scanf("%c",&ch);
        getchar();
        if (ch=='M')
        {
            scanf("%d%d\n",&x,&y);
            unite(x,y);
        }
        else
        {
            scanf("%d\n",&x);
            find(x);
            printf("%d\n",dis[x]);
        }
    }
    return 0;
}