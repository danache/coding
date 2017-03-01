//
//  test.cpp
//  POJ3468
//
//  Created by dan on 16/9/30.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
#include <stdio.h>
const int MAXN = 111111;
using namespace std;

struct Node{
    long long value;
    long long addnum;
} sum[MAXN<<2];

long long sav[MAXN<<2];
//本题为求和，在上行更新时更新节点值为两个孩子的值之和
void pushUp(int i){
    sum[i].value = sum[ i << 1 | 1].value + sum[i << 1].value;
}
//简历树和之前一样，递归的建立
void build(int index, int l, int r){
    sum[index].addnum = 0;
    if (l == r)
    {
        sum[index].value = sav[l];
        return ;
    }
    int m = (l + r) >> 1;
    build(2 * index, l, m);
    build(2 * index + 1, m + 1, r);
    pushUp(index);
}
//下行更新发生在查询和插入到节点的时候，对所有节点一视同仁，一起进行插入（虽然叶子节点没啥用）。首先判断当前节点是否有延迟插入的标记（即addnum属性），若有的的话，对其两个孩子同样加上该标记，m参数代表该区间元素个数，由于求和，因此区间内的每个元素都要加上addnum值，左孩子加了(m - m / 2)个，右孩子加了m / 2个，因此对应的value应该加上数量*单值。最后将标记清零。
void pushDown(int index, int m){
    long long tmp = sum[index].addnum;
    if (tmp){
        //设置左右孩子节点的标志域，因为孩子节点可能被多次延迟标记又没有向下传递
        //所以是 “+=”
        sum[index << 1].addnum += tmp;
        sum[index << 1 | 1].addnum += tmp;
        sum[index << 1].value += tmp * (m - (m >> 1));
        sum[index << 1 | 1].value += tmp * (m >> 1);
        sum[index].addnum = 0;
    }
}
//由于这里是区间更新，因此与单个稍微不同，当时当l== r时即为单值插入。操作时，对对应区间的addnum添加，同时如PushDown中所说，该区间的和
//要加上个数*单值。如果查询区间不在范围内，那么递归的进行处理，先进行pushdown，然后分别对左右孩子进行更新。
void update(int begin, int end, int addnum,int l, int r, int savPos){
    if (begin <=l && r <= end){
        sum[savPos].addnum += addnum;
        sum[savPos].value += addnum * (r - l + 1);
        return;
    }
    pushDown(savPos, r - l + 1);
    int m = (r + l) >> 1;
    if (m >= begin)
        update(begin, end, addnum, l, m, savPos << 1);
    if (m < end)
        update(begin, end, addnum, m + 1, r, savPos << 1 | 1);
    pushUp(savPos);
}
//查询和之前类似。
long long query(int begin, int end, int l, int r, int savPos){
    if (begin <=l && r <= end){
        return sum[savPos].value;
    }
    pushDown(savPos, r- l + 1);
    int m = (r + l) >> 1;
    long long res = 0;
    if (m >= begin)
        res += query(begin, end, l, m, savPos << 1);
    if (m < end)
        res += query(begin, end, m + 1, r, savPos << 1|1);
    return res;
}
int main(){
    int N, Q;
    scanf("%d%d", &N, &Q);
    for (int i = 1; i <= N; i++){
        scanf("%lld", &sav[i]);
    }
    build(1, 1, N);

    while(Q--){
        char op[2];
        int a, b, c;
        scanf("%s", op);
        if (op[0] == 'Q'){
            scanf("%d%d", &a, &b);
            printf("%lld\n", query(a, b,1, N, 1));
        }
        else{
            scanf("%d%d%d", &a, &b, &c);
            update(a, b, c, 1, N, 1);
        }
    }
}